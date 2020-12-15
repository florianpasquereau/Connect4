<?php

namespace App\Command;

use App\Exception\Connect4Exception;
use App\Exception\Connect4SeleniumException;
use App\Service\Connect4;
use App\Service\Selenium\Connect4Selenium;
use Symfony\Component\Console\Command\Command;
use Symfony\Component\Console\Input\InputArgument;
use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Output\OutputInterface;

class Connect4Command extends Command
{
    protected static $defaultName = 'app:connect4';

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
     * @throws Connect4Exception
     * @throws Connect4SeleniumException
     */
    protected function execute(InputInterface $input, OutputInterface $output): int
    {
        $connect4 = new Connect4($input->getArgument('hostname'), $input->getArgument('port'), $input->getArgument('certificate'));

        $connect4Selenium = new Connect4Selenium();
        $connect4Selenium->startParty('https://www.helpfulgames.com/subjects/brain-training/connect-four.html');
        do {
            $grid = $connect4Selenium->updateGrid();
            $output->writeln($grid->__toString());
            if (($column = $connect4->send($grid->__toSocket())) === null) {
                throw new Connect4Exception('Column empty');
            }
            $connect4Selenium->putCoin((int)$column);

        } while(true);
        sleep(5);
        return Command::SUCCESS;
    }
}
