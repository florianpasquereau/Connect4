<?php

namespace App\Service\Grid\Cell;

class CellValue{
    public const VALUE = [
        self::EMPTY,
        self::RED,
        self::YELLOW,
    ];

    public const EMPTY = 0;
    public const RED = 1;
    public const YELLOW = 2;
}