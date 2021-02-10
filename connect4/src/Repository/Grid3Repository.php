<?php

namespace App\Repository;

use App\Entity\Grid3;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid3|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid3|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid3[]	findAll()
 * @method Grid3[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid3Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid3::class);
	}
}
