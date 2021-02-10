<?php

namespace App\Repository;

use App\Entity\Grid1;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid1|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid1|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid1[]	findAll()
 * @method Grid1[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid1Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid1::class);
	}
}
