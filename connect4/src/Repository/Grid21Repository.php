<?php

namespace App\Repository;

use App\Entity\Grid21;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid21|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid21|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid21[]	findAll()
 * @method Grid21[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid21Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid21::class);
	}
}
