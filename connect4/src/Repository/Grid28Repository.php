<?php

namespace App\Repository;

use App\Entity\Grid28;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid28|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid28|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid28[]	findAll()
 * @method Grid28[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid28Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid28::class);
	}
}
