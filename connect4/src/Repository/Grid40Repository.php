<?php

namespace App\Repository;

use App\Entity\Grid40;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @method Grid40|null find($id, $lockMode = null, $lockVersion = null)
 * @method Grid40|null findOneBy(array $criteria, array $orderBy = null)
 * @method Grid40[]	findAll()
 * @method Grid40[]	findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class Grid40Repository extends AbstractGridRepository
{
	public function __construct(ManagerRegistry $registry)
	{
		parent::__construct($registry, Grid40::class);
	}
}
