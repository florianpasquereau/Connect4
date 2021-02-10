<?php

namespace App\Repository;

use App\Entity\Grid17;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid17|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid17|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid17[]	findAll()
 * @method Grid17[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid17Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid17::class);
	}
}
