<?php

namespace App\Service\ExchangeConnect4;

use App\Exception\Connect4Exception;
use Exception;

class ResponseGrid
{
    private int $columnIaSelected;
    private float $timeSpend;
    private bool $gameFinish;
    private bool $success;
    private string $message;

    /**
     * @param string $objJson
     * @throws Connect4Exception
     */
    public function __construct(string $objJson) {
        if (empty($objJson)) {
            throw new Connect4Exception("ResponseGrid is empty");
        }
        $mappingKeys = [
            "column_ia_selected" => "columnIaSelected",
            "time_spend" => "timeSpend",
            "game_finish" => "gameFinish",
            "success" => "success",
            "message" => "message"
        ];
        $answerGrid = json_decode($objJson);

        foreach ($mappingKeys as $key => $dest) {
            if (!isset($answerGrid, $key)) {
                throw new Connect4Exception(sprintf("ResponseGrid does not contain the key : '%s'", $key));
            }
            $value = $answerGrid->$key;
            $this->$dest = $value;
        }
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

    /**
     * @return bool
     */
    public function isSuccess(): bool
    {
        return $this->success;
    }

    /**
     * @return string
     */
    public function getMessage(): string
    {
        return $this->message;
    }

}