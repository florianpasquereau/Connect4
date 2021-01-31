<?php

namespace App\Service\Selenium;

use App\Exception\Connect4Exception;
use App\Exception\Connect4SeleniumException;
use App\Service\ExchangeConnect4\RequestGrid;
use App\Service\ExchangeConnect4\ResponseGrid;
use App\Service\Grid\Cell\CellValue;
use App\Service\Grid\Grid;
use Facebook\WebDriver\Exception\NoSuchElementException;
use Facebook\WebDriver\Remote\DesiredCapabilities;
use Facebook\WebDriver\Remote\RemoteWebDriver;
use Facebook\WebDriver\Remote\RemoteWebElement;
use Facebook\WebDriver\WebDriverBy;

class Connect4Selenium {
    private RemoteWebDriver $driver;

    public function __construct(string $connect4SrcUrl = '127.0.0.1:4444') {
        $this->driver = RemoteWebDriver::create($connect4SrcUrl, DesiredCapabilities::firefox());
    }

    public function __destruct() {
        $this->driver->close();
    }

    public function startParty(string $urlGrid) {
        $this->driver->get($urlGrid);
        $this->newGame();
    }

    public function newGame() {
//        $elements = $this->driver
        $this->driver
            ->findElement(WebDriverBy::cssSelector('#chooseLevel'))
            ->click();
//            ->findElements(WebDriverBy::className('levelNameContainer'));
//        foreach($elements as $element) {
//            dump($element);
//        }
//        die();
        sleep(5);
    }

    /**
     * @param Grid|null $gridPrev
     * @return RequestGrid
     * @throws Connect4Exception
     */
    public function buildRequestGrid(?Grid $gridPrev) : ?RequestGrid {
        $grid = new Grid();
        //player_won
        try {
            $iaWon = $this->driver
                ->findElement(WebDriverBy::cssSelector('#player_won'));
        } catch (NoSuchElementException $e) {
            $iaWon = null;
        }
        if ($iaWon !== null) {
            return null;
        }
        $holes = $this->driver
            ->findElement(WebDriverBy::cssSelector('#gameBoard'))
            ->findElements(WebDriverBy::className('hole'));
        foreach ($holes as $hole) {
            try {
                $child = $hole->findElement(WebDriverBy::tagName('span'));
            } catch (NoSuchElementException $e) {
                $child = null;
            }
            $ids = explode('x', $hole->getAttribute("id"));
            $x = $ids[0];
            $y = $ids[1];
            $value = $this->getValueCell($child);
            $grid->setCell($y, $x, $value);
        }
        return new RequestGrid($grid, CellValue::RED, $this->getLastColumnPlayerCoin($grid, $gridPrev, CellValue::YELLOW));
    }

    /**
     * @param ResponseGrid $answerGrid
     * @throws Connect4SeleniumException
     */
    public function putCoin(ResponseGrid $answerGrid) {
        $column = $answerGrid->getColumnIaSelected();
        if ($column < 0 || $column >= Grid::WIDTH) {
            throw new Connect4SeleniumException(sprintf("The column '%d' is not valid", $column));
        }
        $this->driver
            ->findElement(WebDriverBy::cssSelector(sprintf('#col%d', $column)))
            ->click();
        sleep(5);
    }

    private function getValueCell(?RemoteWebElement $hole) : int {
        if ($hole === null) {
            return CellValue::EMPTY;
        }
        $player = explode(' ', $hole->getAttribute('class'));
        if (count($player) >= 2) {
            $player = $player[1];
            if (preg_match('/player[0-1]$/', $player) === 1) {
                $player = str_replace('player', '', $player);
            } else {
                return CellValue::EMPTY;
            }
        }
        return $player === '1' ? CellValue::YELLOW : CellValue::RED;
    }

    /**
     * @param Grid $grid
     * @param Grid|null $gridPrev
     * @param int $colorPlayer
     * @return int|null
     * @throws Connect4Exception
     */
    private function getLastColumnPlayerCoin(Grid $grid, ?Grid $gridPrev, int $colorPlayer) : ?int {
        if ($gridPrev !== null) {
            for($y = 0;$y < Grid::HEIGHT; $y++) {
                for($x = 0; $x < Grid::WIDTH; $x++) {
                    if ($grid->getCell($y, $x)->getValue() === $colorPlayer &&
                            $gridPrev->getCell($y, $x)->getValue() !== $grid->getCell($y, $x)->getValue()) {
                        return $x;
                    }
                }
            }
        }
        return null;
    }
}