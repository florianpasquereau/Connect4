<?php

namespace App\Repository;

use App\Entity\AbstractGrid;
use Doctrine\Bundle\DoctrineBundle\Repository\ServiceEntityRepository;
use Doctrine\ORM\NonUniqueResultException;

Abstract class AbstractGridRepository extends ServiceEntityRepository
{
    /**
     * @param string $gridString
     * @return ?AbstractGrid
     * @throws NonUniqueResultException
     */
    public function findFromCurrentGridString(string $gridString) : ?AbstractGrid {
        return $this->createQueryBuilder('g')
            ->andWhere('g.name = :gridString')
            ->setParameter('gridString', $gridString)
            ->getQuery()
            ->getOneOrNullResult();
    }

    // /**
    //  * @return Grid1[] Returns an array of Grid1 objects
    //  */
    /*
    public function findByExampleField($value)
    {
        return $this->createQueryBuilder('g')
            ->andWhere('g.exampleField = :val')
            ->setParameter('val', $value)
            ->orderBy('g.id', 'ASC')
            ->setMaxResults(10)
            ->getQuery()
            ->getResult()
        ;
    }
    */



    /*
    public function findOneBySomeField($value): ?Grid1
    {
        return $this->createQueryBuilder('g')
            ->andWhere('g.exampleField = :val')
            ->setParameter('val', $value)
            ->getQuery()
            ->getOneOrNullResult()
        ;
    }
    */
}
