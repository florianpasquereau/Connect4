#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>

#include "../incs/connect4.h"

static volatile bool keepRunning = true;

void                    leaveLoop(int handler) {
    keepRunning =  false;
    handler = (char)handler;
}

void                    initSignal() {
    signal(SIGINT, leaveLoop);
}

void                    helper(char **argv) {
    fprintf(stderr, "%s <port reader(between : %d <-> %d)> <certificate.pem>\n", argv[0], MIN_PORT, MAX_PORT);
    exit(EXIT_FAILURE);
}

int                     main(int argc, char **argv) {
    uint32_t            port;
    t_connect4          connect4;

    if (argc != 3) {
        helper(argv);
    }
    initSignal();
    if ((port = (uint32_t)atoi(argv[1])) <= 0 || port < MIN_PORT || port > MAX_PORT) {
        fprintf(stderr, "'%s' is not a valid <port reader> value\n", argv[1]);
        helper(argv);
    }
    initConnect4(&connect4, port, argv[2]);
    if (!isValidConnect4(&connect4)) {
        fprintf(stderr, "%s", getErrorMsgConnect4(&connect4));
        closeConnect4(&connect4);
        exit(EXIT_FAILURE);
    }
    while (keepRunning) {
        waitingForCliencConnect4(&connect4);
        sleep(1);
    }
    closeConnect4(&connect4);
    return EXIT_SUCCESS;
}