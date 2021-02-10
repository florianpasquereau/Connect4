<?php

namespace App\Repository;

use App\Entity\Grid26;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid26|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid26|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid26[]	findAll()
 * @method Grid26[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid26Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid26::class);
	}
}
