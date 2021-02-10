<?php

namespace App\Repository;

use App\Entity\Grid16;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid16|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid16|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid16[]	findAll()
 * @method Grid16[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid16Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid16::class);
	}
}
