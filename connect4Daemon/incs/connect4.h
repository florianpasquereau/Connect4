#ifndef CONNECT4_H
# define CONNECT4_H

# define MIN_PORT 1u
# define MAX_PORT 0xffffu

# define BUFFER_ERROR_SIZE 150
# define BACKLOG 1

# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <fcntl.h>

# include "grid.h"
# include "ssl.h"
# include "responseGrid.h"

typedef struct          s_connect4 {
    int                 socket;
    int                 fd;
    bool                error;
    char                errorMsg[BUFFER_ERROR_SIZE];
    unsigned int        sizeCSin;
    struct sockaddr_in  cSin;
    SSL                 *cSSL;
    SSL_CTX             *sslctx;
    char                *pathFileCertificat;
    t_grid              grid;
}                       t_connect4;

void                    initConnect4(t_connect4 *ret, uint32_t portReader, char *pathFileCertificat);
bool                    isValidConnect4(const t_connect4 *connect4);
char*                   getErrorMsgConnect4(t_connect4 *connect4);
void                    waitingForCliencConnect4(t_connect4 *connect4);
void                    closeConnect4(t_connect4 *connect4);

void                    manageData(t_connect4 *connect4);
void                    readCurrentGrid(t_connect4 *connect4);
void                    sendIAGame(t_connect4 *connect4);

#endif