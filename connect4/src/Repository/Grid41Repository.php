<?php

namespace App\Repository;

use App\Entity\Grid41;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid41|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid41|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid41[]	findAll()
 * @method Grid41[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid41Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid41::class);
	}
}
