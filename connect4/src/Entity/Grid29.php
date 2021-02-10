<?php

namespace App\Entity;

use App\Repository\Grid29Repository;
use Doctrine\ORM\Mapping as ORM;

/**
 * @ORM\Entity(repositoryClass=Grid29Repository::class)
 */
class Grid29 extends AbstractGrid
{
	/**
	 * @ORM\Id
	 * @ORM\GeneratedValue
	 * @ORM\Column(type="integer")'
	 */
	private ?int $id;

	public function getId(): ?int
	{
		return $this->id;
	}
}
