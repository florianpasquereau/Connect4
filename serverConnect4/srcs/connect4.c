#include "../incs/connect4.h"

void                    initConnect4(t_connect4 *ret, uint32_t portReader) {
    struct sockaddr_in  sin;
    ret->error = true;
    memset(ret, 0, sizeof(t_connect4));
    if ((ret->socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        snprintf(ret->errorMsg, BUFFER_ERROR_SIZE, "Not possible to initialise socket %s %d\n", __FILE__, __LINE__);
        return ;
    }
    sin.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(portReader);
    if (bind(ret->socket, (struct sockaddr *)&sin,sizeof(sin)) != 0) {
        snprintf(ret->errorMsg, BUFFER_ERROR_SIZE, "Not possible bind the port(%u)\n", portReader);
        return ;
    } else if (listen(ret->socket, BACKLOG) != 0) {
        snprintf(ret->errorMsg, BUFFER_ERROR_SIZE, "Not possible listen the socket\n");
        return ;
    }
    ret->error = false;
    ret->sizeCSin = sizeof(struct sockaddr_in);
    printf("Socket open on the port [%u]\n", portReader);
}

bool                    isValidConnect4(const t_connect4 *connect4) {
    return (connect4 == NULL) ? false : !connect4->error;
}

char*                   getErrorMsgConnect4(t_connect4 *connect4) {
    if (connect4 == NULL) {
        return "Memory full";
    }
    return connect4->errorMsg;
}

void                    waitingForCliencConnect4(t_connect4 *connect4) {
    int                 fd;
    
    printf("Wainting for client\n");
    fd = accept(connect4->socket, (struct sockaddr*)&connect4->cSin, &connect4->sizeCSin);
    if (fd <= 0) {
        printf("\033[31mClient connection failled\n\033[0m");
        return ;
    }
    printf("\033[32mClient connected on the fd[%d]\n\033[0m", fd);
    close (fd);
}

void                    closeConnect4(t_connect4 *connect4) {
    if (connect4 != NULL) {
        if (connect4->socket > 0) {
            close(connect4->socket);
            printf("Socket closed\n");
        }
    }
}