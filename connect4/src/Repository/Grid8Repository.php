<?php

namespace App\Repository;

use App\Entity\Grid8;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid8|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid8|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid8[]	findAll()
 * @method Grid8[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid8Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid8::class);
	}
}
