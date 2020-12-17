<?php

namespace App\Service\Grid;

use App\Service\Grid\Cell\Cell;
use App\Service\Stringable;

class Grid implements Stringable {
    const HEIGHT = 6;
    const WIDTH = 7;

    /**
     * @var Cell[][];
    */
    private array $grid = [];

    public function cetCell(int $y, int $x, int $value) {
        $this->grid[$y][$x] = new Cell($value);
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
            $ret .= "\n";
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