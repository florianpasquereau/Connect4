<?php

namespace App\Entity;

use App\Repository\Grid24Repository;
use Doctrine\ORM\Mapping as ORM;

/**
 * @ORM\Entity(repositoryClass=Grid24Repository::class)
 */
class Grid24 extends AbstractGrid
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
