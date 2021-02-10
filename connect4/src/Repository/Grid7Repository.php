<?php

namespace App\Repository;

use App\Entity\Grid7;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid7|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid7|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid7[]	findAll()
 * @method Grid7[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid7Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid7::class);
	}
}
