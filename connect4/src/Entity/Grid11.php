<?php

namespace App\Entity;

use App\Repository\Grid11Repository;
use Doctrine\ORM\Mapping as ORM;

/**
 * @ORM\Entity(repositoryClass=Grid11Repository::class)
 */
class Grid11 extends AbstractGrid
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
