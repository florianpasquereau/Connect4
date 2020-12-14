<?php

namespace App\Command;

use App\Exception\Connect4Exception;
use App\Service\Connect4;
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
     */
    protected function execute(InputInterface $input, OutputInterface $output): int
    {
        $connect4 = new Connect4($input->getArgument('hostname'), $input->getArgument('port'), $input->getArgument('certificate'));
        $connect4->send("Plop\n");
        $connect4->send("Hello\n");
        $connect4->send("Holla\n");
        $connect4->send("Bonjour\n");
        $connect4->send("Gutten tag\n");
        return Command::SUCCESS;
    }
}
