Connect4 Client
==========
Establish the link between the browser and connect4_d. It sends current grid to **connect4_d** and put coin on the grid following the server return.

Details:
----------
Client developed in PHP 7.4 (Will be updated to support php 8). This client is composed of only one command, 
`php bin/console <hostname/ip> <port> <certificate.pem>`. 
To scrape and fill the grid from .... [selenium](https://www.selenium.dev/documentation/en/) is used with the [firefox webdriver](https://github.com/mozilla/geckodriver/releases).
