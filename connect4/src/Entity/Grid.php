<?php

namespace App\Entity;

use App\Repository\GridRepository;
use Doctrine\ORM\Mapping as ORM;

/**
 * @ORM\Entity(repositoryClass=GridRepository::class)
 */
class Grid
{
    /**
     * @ORM\Id
     * @ORM\GeneratedValue
     * @ORM\Column(type="integer")
     */
    private ?int $id;

    /**
     * @ORM\Column(type="string", length=500)
     */
    private ?string $name;

    /**
     * @ORM\Column(type="integer")
     */
    private int $columnIaSelected;

    /**
     * @ORM\Column(type="bigint")
     */
    private int $score = 0;

    public function getId(): ?int
    {
        return $this->id;
    }

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
}
