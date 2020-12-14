<?php

namespace App\Service;

use App\Exception\Connect4Exception;
use Stringable;

final class Connect4 {
    private string $address;
    /**
     * @var resource
    */
    private $streamContext;
    private int $errorCode = 0;
    private string $errorMessage = "";
    private ?float $timeout = null;
    private int $flag = STREAM_CLIENT_CONNECT;

    /**
     * @param string $hostname
     * @param string $port
     * @param string $certificate
     * @throws Connect4Exception
     */
    public function __construct(string $hostname, string $port, string $certificate) {
        if (!is_numeric($port) || ($port = (int)$port) <= 0) {
            throw new Connect4Exception(sprintf("'%s' is not a valid port. Must be a digit higher than 0", $port));
        } else if (!file_exists($certificate) || !preg_match("/\.pem$/", $certificate)) {
            throw new Connect4Exception(sprintf("'%s' is not a valid certificate.pem file.", $certificate));
        }
        $this->address = sprintf('tls://%s:%s', $hostname, $port);
        $this->streamContext = stream_context_create(
            [
                'ssl' => [
                    'local_cert' => $certificate,
                    'allow_self_signed' => true
                ]
            ]
        );
    }

    /**
     * @param String|Stringable $data
     * @throws Connect4Exception
     */
    public function send($data) {
        $fd = stream_socket_client($this->address,
            $this->errorCode, $this->errorMessage, $this->timeout, $this->flag, $this->streamContext);
        if (!$fd) {
            throw new Connect4Exception(sprintf("'%s' is not accessible code : %s -> %s", $this->address, $this->errorCode, $this->errorMessage));
        }
        if (is_object($data)) {
            fwrite($fd, $data->__toString());
        } else {
            fwrite($fd, $data);
        }
        sleep(1);
        fclose($fd);
    }
}
