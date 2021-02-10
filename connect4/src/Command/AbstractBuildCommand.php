<?php

namespace App\Command;

use Exception;
use Symfony\Component\Console\Command\Command;
use Symfony\Component\Console\Input\InputArgument;
use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Input\InputOption;
use Symfony\Component\Console\Output\OutputInterface;

abstract class AbstractBuildCommand extends Command
{
    protected function configure()
    {
        $this
            ->setDescription('Add a short description for your command')
            ->addArgument('arg1', InputArgument::OPTIONAL, 'Argument description')
            ->addOption('option1', null, InputOption::VALUE_NONE, 'Option description')
        ;
    }

    /**
     * @param InputInterface $input
     * @param OutputInterface $output
     * @return int
     * @throws Exception
     */
    protected function execute(InputInterface $input, OutputInterface $output): int
    {
        for ($i = 0; $i < 42; $i++) {
            $fileName = $this->buildFileName($i);
            $output->writeln(sprintf("Creating %s", $fileName));
            $fd = $this->createFile($fileName);
            $output->writeln(sprintf("Writing Content %s", $fileName));
            $this->writeFile($fd, $i);
            $this->closeFile($fd);
        }

        return Command::SUCCESS;
    }

    /**
     * @param string $fileName
     * @throws Exception
     * @return resource
     */
    protected function createFile(string $fileName)
    {
        if (($fd = fopen($fileName, "w+")) === false) {
            throw new Exception(sprintf("Not possible to create the file '%s'.", $fileName));
        }
        return $fd;
    }

    /**
     * @param resource $fd
     * @param int $index
     * @return int
     */
    protected function writeFile($fd, int $index) : int
    {
        return fprintf($fd, $this->buildFileContent($index));
    }

    /**
     * @param resource $fd
    */
    protected function closeFile($fd)
    {
        fclose($fd);
    }

    abstract protected function buildFileName(int $index) : string;

    abstract protected function buildFileContent(int $index) : string;
}
