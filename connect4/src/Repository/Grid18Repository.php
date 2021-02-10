<?php

namespace App\Repository;

use App\Entity\Grid18;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid18|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid18|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid18[]	findAll()
 * @method Grid18[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid18Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid18::class);
	}
}
