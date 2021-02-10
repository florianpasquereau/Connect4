<?php

namespace App\Repository;

use App\Entity\Grid34;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid34|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid34|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid34[]	findAll()
 * @method Grid34[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid34Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid34::class);
	}
}
