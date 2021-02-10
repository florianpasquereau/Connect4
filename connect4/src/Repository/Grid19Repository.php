<?php

namespace App\Repository;

use App\Entity\Grid19;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid19|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid19|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid19[]	findAll()
 * @method Grid19[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid19Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid19::class);
	}
}
