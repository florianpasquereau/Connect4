<?php

namespace App\Repository;

use App\Entity\Grid2;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid2|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid2|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid2[]	findAll()
 * @method Grid2[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid2Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid2::class);
	}
}
