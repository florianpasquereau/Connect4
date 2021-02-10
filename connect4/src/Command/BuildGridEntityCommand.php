<?php

namespace App\Command;

class BuildGridEntityCommand extends AbstractBuildCommand
{
    protected static $defaultName = 'app:build-grid-entity';

    protected function buildFileName(int $index) : string {
        return sprintf("./src/Entity/Grid%d.php", $index);
    }

    protected function buildFileContent(int $index) : string {
        $content = "<?php\n";
        $content .= "\n";
        $content .= "namespace App\\Entity;\n";
        $content .= "\n";
        $content .= sprintf("use App\\Repository\\Grid%dRepository;\n", $index);
        $content .= "use Doctrine\\ORM\\Mapping as ORM;\n";
        $content .= "\n";
        $content .= "/**\n";
        $content .= sprintf(" * @ORM\\Entity(repositoryClass=Grid%dRepository::class)\n", $index);
        $content .= " */\n";
        $content .= sprintf("class Grid%d extends AbstractGrid\n", $index);
        $content .= "{\n";
        $content .= "\t/**\n";
        $content .= "\t * @ORM\\Id\n";
        $content .= "\t * @ORM\\GeneratedValue\n";
        $content .= "\t * @ORM\\Column(type=\"integer\")'\n";
        $content .= "\t */\n";
        $content .= "\tprivate ?int \$id;\n";
        $content .= "\n";
        $content .= "\tpublic function getId(): ?int\n";
        $content .= "\t{\n";
        $content .= "\t\treturn \$this->id;\n";
        $content .= "\t}\n";
        $content .= "}\n";
        return $content;
    }
}
