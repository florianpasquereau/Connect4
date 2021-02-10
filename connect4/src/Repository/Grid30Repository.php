<?php

namespace App\Repository;

use App\Entity\Grid30;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid30|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid30|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid30[]	findAll()
 * @method Grid30[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid30Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid30::class);
	}
}
