<?php

namespace App\Repository;

use App\Entity\Grid27;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid27|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid27|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid27[]	findAll()
 * @method Grid27[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid27Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid27::class);
	}
}
