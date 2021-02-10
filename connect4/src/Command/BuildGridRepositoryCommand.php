<?php

namespace App\Command;

class BuildGridRepositoryCommand extends AbstractBuildCommand
{
    protected static $defaultName = 'app:build-grid-repository';

    protected function buildFileName(int $index) : string {
        return sprintf("./src/Repository/Grid%dRepository.php", $index);
    }

    protected function buildFileContent(int $index) : string {
        $content = "<?php\n";
        $content .= "\n";
        $content .= "namespace App\\Repository;\n";
        $content .= "\n";
        $content .= sprintf("use App\\Entity\\Grid%d;\n", $index);
        $content .= "use Doctrine\Persistence\ManagerRegistry;\n";
        $content .= "\n";
        $content .= "/**\n";
        $content .= sprintf(" * @method Grid%d|null find(\$id, \$lockMode = null, \$lockVersion = null)\n", $index);
        $content .= sprintf(" * @method Grid%d|null findOneBy(array \$criteria, array \$orderBy = null)\n", $index);
        $content .= sprintf(" * @method Grid%d[]\tfindAll()\n", $index);
        $content .= sprintf(" * @method Grid%d[]\tfindBy(array \$criteria, array \$orderBy = null, \$limit = null, \$offset = null)\n", $index);
        $content .= " */\n";
        $content .= sprintf("class Grid%dRepository extends AbstractGridRepository\n", $index);
        $content .= "{\n";
        $content .= "\tpublic function __construct(ManagerRegistry \$registry)\n";
        $content .= "\t{\n";
        $content .= sprintf("\t\tparent::__construct(\$registry, Grid%d::class);\n", $index);
        $content .= "\t}\n";
        $content .= "}\n";
        return $content;
    }
}
