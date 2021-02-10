<?php

namespace App\Service\Grid;

use App\Exception\Connect4Exception;
use App\Service\Grid\Cell\Cell;
use App\Service\Grid\Cell\CellValue;
use App\Service\Stringable;

class Grid implements Stringable {
    const HEIGHT = 6;
    const WIDTH = 7;

    /**
     * @var Cell[][];
    */
    private array $grid = [];

    private int $countCellFilled = 0;

    /**
     * @param int $y
     * @param int $x
     * @param int $value
     * @throws Connect4Exception
     */
    public function setCell(int $y, int $x, int $value) {
        if ($y < 0 || $y >= Grid::HEIGHT) {
            throw new Connect4Exception(sprintf("Not possible to access to the row '%s'", $y));
        } else if ($x < 0 || $x >= Grid::WIDTH) {
            throw new Connect4Exception(sprintf("Not possible to access to the column '%s'", $x));
        }
        $this->grid[$y][$x] = new Cell($value);
        if ($value === CellValue::RED || $value === CellValue::YELLOW) {
            $this->countCellFilled ++;
        }
    }

    /**
     * @param int $y
     * @param int $x
     * @return Cell
     * @throws Connect4Exception
     */
    public function getCell(int $y, int $x) : Cell{
        if ($y < 0 || $y >= Grid::HEIGHT) {
            throw new Connect4Exception(sprintf("Not possible to access to the row '%s'", $y));
        } else if ($x < 0 || $x >= Grid::WIDTH) {
            throw new Connect4Exception(sprintf("Not possible to access to the column '%s'", $x));
        }
        return $this->grid[$y][$x];
    }

    /**
     * @return int
     */
    public function getCountCellFilled(): int
    {
        return $this->countCellFilled;
    }



    /**
     * @inheritDoc
    */
    public function __toString(): string
    {
        $ret = "";

        for ($y = 0; $y < Grid::HEIGHT; $y++) {
            for ($x = 0; $x < Grid::WIDTH; $x++) {
                $ret .= $this->grid[$y][$x]->__toString();
            }
            if ($y + 1 < Grid::HEIGHT) {
                $ret .= "\n";
            }
        }
        return $ret;
    }

    public function __toDatabase(): string
    {
        $ret = "";

        for ($y = 0; $y < Grid::HEIGHT; $y++) {
            for ($x = 0; $x < Grid::WIDTH; $x++) {
                $ret .= $this->grid[$y][$x]->__toDatabase();
            }
            if ($y + 1 < Grid::HEIGHT) {
                $ret .= "\n";
            }
        }
        return $ret;
    }

    /**
     * @return int[][]
     * @inheritDoc
     */
    public function __toSocket(): array
    {
        $ret = [];
        for ($y = 0; $y < Grid::HEIGHT; $y++) {
            $row = [];
            for ($x = 0; $x < Grid::WIDTH; $x++) {
                $row[] = $this->grid[$y][$x]->getValue();
            }
            $ret[] = $row;
        }
        return $ret;
    }
}