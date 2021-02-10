<?php

namespace App\Repository;

use App\Entity\Grid6;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid6|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid6|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid6[]	findAll()
 * @method Grid6[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid6Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid6::class);
	}
}
