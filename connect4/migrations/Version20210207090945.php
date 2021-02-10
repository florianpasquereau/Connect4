<?php

declare(strict_types=1);

namespace DoctrineMigrations;

use Doctrine\DBAL\Schema\Schema;
use Doctrine\Migrations\AbstractMigration;

/**
 * Auto-generated Migration: Please modify to your needs!
 */
final class Version20210207090945 extends AbstractMigration
{
    public function getDescription() : string
    {
        return '';
    }

    public function up(Schema $schema) : void
    {
        // this up() migration is auto-generated, please modify it to your needs
        $this->addSql('CREATE TABLE grid0 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid1 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid10 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid11 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid12 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid13 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid14 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid15 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid16 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid17 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid18 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid19 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid2 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid20 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid21 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid22 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid23 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid24 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid25 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid26 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid27 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid28 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid29 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid3 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid30 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid31 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid32 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid33 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid34 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid35 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid36 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid37 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid38 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid39 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid4 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid40 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid41 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid5 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid6 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid7 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid8 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE grid9 (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(500) NOT NULL, column_ia_selected INT NOT NULL, score BIGINT NOT NULL, game_finish TINYINT(1) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
    }

    public function down(Schema $schema) : void
    {
        // this down() migration is auto-generated, please modify it to your needs
        $this->addSql('DROP TABLE grid0');
        $this->addSql('DROP TABLE grid1');
        $this->addSql('DROP TABLE grid10');
        $this->addSql('DROP TABLE grid11');
        $this->addSql('DROP TABLE grid12');
        $this->addSql('DROP TABLE grid13');
        $this->addSql('DROP TABLE grid14');
        $this->addSql('DROP TABLE grid15');
        $this->addSql('DROP TABLE grid16');
        $this->addSql('DROP TABLE grid17');
        $this->addSql('DROP TABLE grid18');
        $this->addSql('DROP TABLE grid19');
        $this->addSql('DROP TABLE grid2');
        $this->addSql('DROP TABLE grid20');
        $this->addSql('DROP TABLE grid21');
        $this->addSql('DROP TABLE grid22');
        $this->addSql('DROP TABLE grid23');
        $this->addSql('DROP TABLE grid24');
        $this->addSql('DROP TABLE grid25');
        $this->addSql('DROP TABLE grid26');
        $this->addSql('DROP TABLE grid27');
        $this->addSql('DROP TABLE grid28');
        $this->addSql('DROP TABLE grid29');
        $this->addSql('DROP TABLE grid3');
        $this->addSql('DROP TABLE grid30');
        $this->addSql('DROP TABLE grid31');
        $this->addSql('DROP TABLE grid32');
        $this->addSql('DROP TABLE grid33');
        $this->addSql('DROP TABLE grid34');
        $this->addSql('DROP TABLE grid35');
        $this->addSql('DROP TABLE grid36');
        $this->addSql('DROP TABLE grid37');
        $this->addSql('DROP TABLE grid38');
        $this->addSql('DROP TABLE grid39');
        $this->addSql('DROP TABLE grid4');
        $this->addSql('DROP TABLE grid40');
        $this->addSql('DROP TABLE grid41');
        $this->addSql('DROP TABLE grid5');
        $this->addSql('DROP TABLE grid6');
        $this->addSql('DROP TABLE grid7');
        $this->addSql('DROP TABLE grid8');
        $this->addSql('DROP TABLE grid9');
    }
}
