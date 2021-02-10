<?php

namespace App\Repository;

use App\Entity\Grid11;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid11|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid11|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid11[]	findAll()
 * @method Grid11[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid11Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid11::class);
	}
}
