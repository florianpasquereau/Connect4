<?php

namespace App\Repository;

use App\Entity\Grid35;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid35|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid35|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid35[]	findAll()
 * @method Grid35[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid35Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid35::class);
	}
}
