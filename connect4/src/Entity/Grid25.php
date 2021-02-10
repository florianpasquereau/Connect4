<?php

namespace App\Entity;

use App\Repository\Grid25Repository;
use Doctrine\ORM\Mapping as ORM;

/**
 * @ORM\Entity(repositoryClass=Grid25Repository::class)
 */
class Grid25 extends AbstractGrid
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
