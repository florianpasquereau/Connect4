<?php

namespace App\Repository;

use App\Entity\Grid15;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid15|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid15|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid15[]	findAll()
 * @method Grid15[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid15Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid15::class);
	}
}
