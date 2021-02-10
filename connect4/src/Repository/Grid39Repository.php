<?php

namespace App\Repository;

use App\Entity\Grid39;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid39|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid39|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid39[]	findAll()
 * @method Grid39[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid39Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid39::class);
	}
}
