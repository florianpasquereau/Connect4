<?php

namespace App\Repository;

use App\Entity\Grid38;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid38|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid38|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid38[]	findAll()
 * @method Grid38[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid38Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid38::class);
	}
}
