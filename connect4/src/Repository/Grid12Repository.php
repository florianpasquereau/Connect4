<?php

namespace App\Repository;

use App\Entity\Grid12;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid12|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid12|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid12[]	findAll()
 * @method Grid12[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid12Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid12::class);
	}
}
