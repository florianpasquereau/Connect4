<?php

namespace App\Repository;

use App\Entity\Grid29;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid29|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid29|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid29[]	findAll()
 * @method Grid29[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid29Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid29::class);
	}
}
