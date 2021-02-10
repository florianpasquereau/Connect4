<?php

namespace App\Entity;

use App\Repository\Grid12Repository;
use Doctrine\ORM\Mapping as ORM;

/**
 * @ORM\Entity(repositoryClass=Grid12Repository::class)
 */
class Grid12 extends AbstractGrid
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
