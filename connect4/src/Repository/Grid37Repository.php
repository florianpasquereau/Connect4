<?php

namespace App\Repository;

use App\Entity\Grid37;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid37|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid37|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid37[]	findAll()
 * @method Grid37[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid37Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid37::class);
	}
}
