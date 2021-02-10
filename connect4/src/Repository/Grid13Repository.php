<?php

namespace App\Repository;

use App\Entity\Grid13;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid13|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid13|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid13[]	findAll()
 * @method Grid13[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid13Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid13::class);
	}
}
