<?php

namespace App\Repository;

use App\Entity\Grid33;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid33|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid33|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid33[]	findAll()
 * @method Grid33[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid33Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid33::class);
	}
}
