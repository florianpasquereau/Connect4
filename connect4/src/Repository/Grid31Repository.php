<?php

namespace App\Repository;

use App\Entity\Grid31;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid31|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid31|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid31[]	findAll()
 * @method Grid31[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid31Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid31::class);
	}
}
