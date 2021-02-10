<?php

namespace App\Command;

use App\Entity\AbstractGrid;
use App\Entity\Grid0;
use App\Exception\Connect4Exception;
use App\Exception\Connect4SeleniumException;
use App\Service\Connect4;
use App\Service\ExchangeConnect4\RequestGrid;
use App\Service\ExchangeConnect4\ResponseGrid;
use App\Service\Grid\Grid;
use App\Service\Selenium\Connect4Selenium;
use Doctrine\ORM\EntityManagerInterface;
use Symfony\Component\Console\Command\Command;
use Symfony\Component\Console\Input\InputArgument;
use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Output\OutputInterface;

class Connect4Command extends Command
{
    protected static $defaultName = 'app:connect4';
    private EntityManagerInterface $entityManager;

    public function __construct(EntityManagerInterface $entityManager)
    {
        parent::__construct(null);
        $this->entityManager = $entityManager;
    }

    protected function configure()
    {
        $this
            ->setDescription('Client Connect 4 to establish the link between the browser and connect4_d')
            ->addArgument('hostname', InputArgument::REQUIRED, 'hostname of connect4_d')
            ->addArgument('port', InputArgument::REQUIRED, 'port of connect4_d')
            ->addArgument('certificate', InputArgument::REQUIRED, 'path to the certificate.pem')
        ;
    }

    /**
     * @param InputInterface $input
     * @param OutputInterface $output
     * @return int
     * @throws Connect4SeleniumException
     * @throws Connect4Exception
     */
    protected function execute(InputInterface $input, OutputInterface $output): int
    {
        $gridPrev = null;
        $connect4 = new Connect4($input->getArgument('hostname'), $input->getArgument('port'), $input->getArgument('certificate'));
        $connect4Selenium = new Connect4Selenium();
        $connect4Selenium->startParty('https://www.helpfulgames.com/subjects/brain-training/connect-four.html');
        do {
            if (($requestGrid = $connect4Selenium->buildRequestGrid($gridPrev)) === null) {
                $output->writeln("IA won. Game finish.");
                break ;
            }
            $output->writeln($requestGrid->getGrid()->__toString());
            $responseGrid = $this->getResponse($connect4, $requestGrid);
            if (!$responseGrid->isSuccess())  {
                $output->writeln('<fg=red>' . $responseGrid->getMessage() . '</>\n');
            } else if ($responseGrid->isGameFinish() === false){
                $connect4Selenium->putCoin($responseGrid);
                $gridPrev = $requestGrid->getGrid();
                $output->writeln(sprintf("IA play column : %d -> %s with the score : %d\n",
                    $responseGrid->getColumnIaSelected(),
                    $responseGrid->getMessage(),
                    $responseGrid->getScore()
                ));
            }
        } while(!$responseGrid->isGameFinish());
        return Command::SUCCESS;
    }

    /**
     * @param Connect4 $connect4
     * @param RequestGrid $requestGrid
     * @return ResponseGrid
     * @throws Connect4Exception
     */
    private function getResponse(Connect4 $connect4, RequestGrid $requestGrid) : ResponseGrid
    {
        $gridPrev = $requestGrid->getGrid();
        $gridEntityName = $this->getEntityGridName($gridPrev);
        $gridEntity = $this->entityManager->getRepository($gridEntityName)->findFromCurrentGridString($gridPrev->__toDatabase());
        if ($gridEntity === null) {
            $responseGrid = $connect4->send($requestGrid);
            $this->storeToDatabase($gridPrev, $responseGrid);
            return $responseGrid;
        }
        return new ResponseGrid(json_encode($gridEntity));
    }

    private function getEntityGridName(Grid $grid) : string
    {
        return sprintf("App\\Entity\\Grid%d", $grid->getCountCellFilled());
    }

    private function storeToDatabase(Grid $gridPrev, ResponseGrid $responseGrid) {
        $gridEntityName = $this->getEntityGridName($gridPrev);
        $gridStore = new $gridEntityName();
        /**@var AbstractGrid $gridStore */
        $gridStore->setName($gridPrev->__toDatabase())
            ->setColumnIaSelected($responseGrid->getColumnIaSelected())
            ->setScore($responseGrid->getScore())
            ->setGameFinish($responseGrid->isGameFinish());
        $this->entityManager->persist($gridStore);
        $this->entityManager->flush();
    }
}
