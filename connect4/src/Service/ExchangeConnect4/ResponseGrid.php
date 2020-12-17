<?php

namespace App\Service\ExchangeConnect4;

use App\Exception\Connect4Exception;
use Exception;

class ResponseGrid
{
    private int $columnIaSelected;
    private float $timeSpend;
    private bool $gameFinish;

    /**
     * @param string $objJson
     * @throws Connect4Exception
     */
    public function __construct(string $objJson) {
        $mappingKeys = [
            "column_ia_selected" => "columnIaSelected",
            "time_spend" => "timeSpend",
            "game_finish" => "gameFinish",
        ];
        $answerGrid = json_decode($objJson);

        foreach ($mappingKeys as $key => $dest) {
            if (!isset($answerGrid, $key)) {
                throw new Connect4Exception(sprintf("ResponseGrid does not contain the key : '%s'", $key));
            }
            $value = $answerGrid->$key;
            $this->$dest = $value;
        }
        dump($this);
    }

    /**
     * @return int
     */
    public function getColumnIaSelected(): int
    {
        return $this->columnIaSelected;
    }

    /**
     * @return float
     */
    public function getTimeSpend(): float
    {
        return $this->timeSpend;
    }

    /**
     * @return bool
     */
    public function isGameFinish(): bool
    {
        return $this->gameFinish;
    }

}