<?php

namespace App\Repository;

use App\Entity\Grid22;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid22|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid22|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid22[]	findAll()
 * @method Grid22[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid22Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid22::class);
	}
}
