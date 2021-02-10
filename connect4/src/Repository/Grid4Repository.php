<?php

namespace App\Repository;

use App\Entity\Grid4;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid4|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid4|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid4[]	findAll()
 * @method Grid4[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid4Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid4::class);
	}
}
