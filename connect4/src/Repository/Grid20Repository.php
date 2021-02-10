<?php

namespace App\Repository;

use App\Entity\Grid20;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid20|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid20|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid20[]	findAll()
 * @method Grid20[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid20Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid20::class);
	}
}
