<?php

namespace App\Service\ExchangeConnect4;

use App\Service\Grid\Cell\CellValue;
use App\Service\Grid\Grid;
use Exception;
use JsonSerializable;
use Serializable;

class RequestGrid implements JsonSerializable {
    private Grid $grid;
    private int $colorIa;

    public function __construct(Grid $grid, int $colorIa) {
        $this->grid = $grid;
        $this->colorIa = $colorIa;
    }

    /**
     * @return Grid
     */
    public function getGrid(): Grid
    {
        return $this->grid;
    }

    public function jsonSerialize(): array
    {
        return [
            "grid" => $this->getGrid()->__toSocket(),
            "color_ia" => $this->getColorIa()
        ];
    }

    /**
     * @return int
     */
    public function getColorIa(): int
    {
        return $this->colorIa;
    }
}