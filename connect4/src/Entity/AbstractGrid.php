<?php

namespace App\Entity;

use Doctrine\ORM\Mapping as ORM;
use JsonSerializable;

abstract class AbstractGrid implements JsonSerializable
{

    /**
     * @ORM\Column(type="string", length=500)
     */
    protected ?string $name;

    /**
     * @ORM\Column(type="integer")
     */
    protected int $columnIaSelected;

    /**
     * @ORM\Column(type="bigint")
     */
    protected int $score = 0;

    /**
     * @ORM\Column(type="boolean")
     */
    protected bool $gameFinish = false;

    public function getName(): ?string
    {
        return $this->name;
    }

    public function setName(string $name): self
    {
        $this->name = $name;

        return $this;
    }

    public function getColumnIaSelected(): ?int
    {
        return $this->columnIaSelected;
    }

    public function setColumnIaSelected(int $columnIaSelected): self
    {
        $this->columnIaSelected = $columnIaSelected;

        return $this;
    }

    public function getScore(): ?int
    {
        return $this->score;
    }

    public function setScore(int $score): self
    {
        $this->score = $score;

        return $this;
    }

    public function getGameFinish(): ?bool
    {
        return $this->gameFinish;
    }

    public function setGameFinish(bool $gameFinish): self
    {
        $this->gameFinish = $gameFinish;

        return $this;
    }

    public function jsonSerialize() : array
    {
        return [
            "column_ia_selected" => $this->getColumnIaSelected(),
            "time_spend" => 0,
            "game_finish" => $this->getGameFinish(),
            "score" => $this->getScore(),
            "success" => "success",
            "message" => "From Data base"
        ];
    }
}
