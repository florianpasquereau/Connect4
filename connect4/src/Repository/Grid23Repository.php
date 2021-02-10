<?php

namespace App\Repository;

use App\Entity\Grid23;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid23|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid23|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid23[]	findAll()
 * @method Grid23[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid23Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid23::class);
	}
}
