<?php

namespace App\Service;

interface Stringable {
    /**
     * Convert the object into a string
     * @return string
    */
    public function __toString() : string;

    /**
     * Convert the object into a socket
     * @return array
     */
    public function __toSocket() : array;
}
