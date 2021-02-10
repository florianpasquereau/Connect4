<?php

namespace App\Repository;

use App\Entity\Grid10;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid10|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid10|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid10[]	findAll()
 * @method Grid10[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid10Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid10::class);
	}
}
