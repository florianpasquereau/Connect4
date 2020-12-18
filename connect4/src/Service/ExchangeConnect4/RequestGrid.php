<?php

namespace App\Service\ExchangeConnect4;

use App\Exception\Connect4Exception;
use App\Service\Grid\Cell\CellValue;
use App\Service\Grid\Grid;
use JsonSerializable;

class RequestGrid implements JsonSerializable {
    private Grid $grid;
    private int $colorIa;
    private int $lastColumnPlayerCoin;

    /**
     * @param Grid $grid
     * @param int $colorIa
     * @param int|null $lastColumnPlayerCoin
     * @throws Connect4Exception
     */
    public function __construct(Grid $grid, int $colorIa, ?int $lastColumnPlayerCoin) {
        if (!array_key_exists($colorIa, CellValue::VALUE)) {
            throw new Connect4Exception(sprintf("'%s' is not a valid %s value", $colorIa, CellValue::class));
        } else if ($lastColumnPlayerCoin !== null && ($lastColumnPlayerCoin < 0 || $lastColumnPlayerCoin >= Grid::WIDTH)) {
            throw new Connect4Exception(sprintf("'%s' is not a valid column", $lastColumnPlayerCoin));
        }
        $this->grid = $grid;
        $this->colorIa = $colorIa;
        $this->lastColumnPlayerCoin = $lastColumnPlayerCoin == null ? -1 : $lastColumnPlayerCoin;
        dump($this);
    }

    /**
     * @return Grid
     */
    public function getGrid(): Grid
    {
        return $this->grid;
    }

    /**
     * @return array
    */
    public function jsonSerialize(): array
    {
        return [
            "grid" => $this->getGrid()->__toSocket(),
            "color_ia" => $this->getColorIa(),
            "last_column_player_coin" => $this->getLastColumnPlayerCoin()
        ];
    }

    /**
     * @return int
     */
    public function getColorIa(): int
    {
        return $this->colorIa;
    }

    /**
     * @return int
     */
    public function getLastColumnPlayerCoin(): int
    {
        return $this->lastColumnPlayerCoin;
    }
}