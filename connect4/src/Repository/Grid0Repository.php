<?php

namespace App\Repository;

use App\Entity\Grid0;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid0|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid0|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid0[]	findAll()
 * @method Grid0[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid0Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid0::class);
	}
}
