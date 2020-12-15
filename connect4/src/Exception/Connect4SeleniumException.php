<?php

namespace App\Exception;

use Exception;

class Connect4SeleniumException extends Exception {
    public function __construct($message, $code = 0, Exception $previous = null) {
        parent::__construct($message, $code, $previous);
    }
}