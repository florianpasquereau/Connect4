<?php

namespace App\Repository;

use App\Entity\Grid36;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid36|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid36|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid36[]	findAll()
 * @method Grid36[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid36Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid36::class);
	}
}
