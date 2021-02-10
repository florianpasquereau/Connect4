<?php

namespace App\Repository;

use App\Entity\Grid24;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid24|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid24|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid24[]	findAll()
 * @method Grid24[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid24Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid24::class);
	}
}
