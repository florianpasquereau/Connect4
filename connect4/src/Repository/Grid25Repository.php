<?php

namespace App\Repository;

use App\Entity\Grid25;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid25|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid25|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid25[]	findAll()
 * @method Grid25[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid25Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid25::class);
	}
}
