<?php

namespace App\Service\Grid\Cell;


use App\Service\Stringable;

class Cell implements Stringable {
    private int $value;

    public function __construct(int $value) {
        if (array_key_exists($value, CellValue::VALUE) === false) {
            $value = CellValue::EMPTY;
        }
        $this->value = $value;
    }

    /**
     * @return int
     */
    public function getValue(): int
    {
        return $this->value;
    }

    public function __toString() : string
    {
        if ($this->value === CellValue::EMPTY) {
            return '. ';
        }
        return $this->value === CellValue::RED ? '<fg=red>R </>' : '<fg=yellow>Y </>';
    }

    public function __toSocket(): array
    {
        return [$this->getValue()];
    }

    public function __toDatabase()
    {
        if ($this->value === CellValue::EMPTY) {
            return '0';
        }
        return $this->value === CellValue::RED ? '1' : '2';
    }
}