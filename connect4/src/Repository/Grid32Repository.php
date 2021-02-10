<?php

namespace App\Repository;

use App\Entity\Grid32;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid32|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid32|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid32[]	findAll()
 * @method Grid32[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid32Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid32::class);
	}
}
