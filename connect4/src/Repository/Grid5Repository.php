<?php

namespace App\Repository;

use App\Entity\Grid5;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid5|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid5|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid5[]	findAll()
 * @method Grid5[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid5Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid5::class);
	}
}
