<?php

namespace App\Repository;

use App\Entity\Grid9;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid9|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid9|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid9[]	findAll()
 * @method Grid9[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid9Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid9::class);
	}
}
