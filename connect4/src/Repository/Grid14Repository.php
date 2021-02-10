<?php

namespace App\Repository;

use App\Entity\Grid14;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid14|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid14|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid14[]	findAll()
 * @method Grid14[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid14Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid14::class);
	}
}
