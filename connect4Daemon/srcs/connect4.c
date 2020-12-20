#include "../incs/connect4.h"

static bool                    sendIAGame(t_connect4 *connect4) {
    time_t              start_t, end_t;
    double              timeSpend;
    t_answerGrid        answerGrid;
    char                *answer, message[BUFFER_SIZE_MESSAGE] = "???????";
    unsigned char       columnIaSelected;
    bool                success;

    if (connect4 == NULL) {
        return false;
    }
    time(&start_t);
    sleep(1);
    success = findColumnIaSelected(&connect4->grid, &columnIaSelected, message);
    time(&end_t);
    timeSpend = difftime(end_t, start_t);
    initAnswerGrid(&answerGrid, 
        columnIaSelected, 
        timeSpend, 
        (*gridGetGameFinish(&connect4->grid)),
        success,
        message
    );
    if ((answer = answerGridToJson(&answerGrid)) == NULL) {
        return false;
    }
    SSL_write(connect4->cSSL, answer, strlen(answer));
    printGrid(&connect4->grid);
    printf("LastColumnPlayerCoin = %d\n", connect4->grid.lastColumnPlayerCoin);
    return true;            
}


static bool             readCurrentGrid(t_connect4 *connect4) {
    int                 read;
    char                requestGrid[BUFFER_SIZE + 1];

    if (connect4 == NULL) {
        return false; 
    }
    while ((read = SSL_read(connect4->cSSL, requestGrid, BUFFER_SIZE)) == BUFFER_SIZE) {
        requestGrid[read] = '\0';
    }
    requestGrid[read] = '\0';
    return initGrid(&connect4->grid, requestGrid);
}

static bool             manageData(t_connect4 *connect4) {
    
    if (connect4 == NULL) {
        return false;
    }
    printf("\033[32mClient connected on the fd[%d]\n\033[0m", connect4->fd);
    if (readCurrentGrid(connect4)) {
        return sendIAGame(connect4);
    }
    return false;
}

void                    initConnect4(t_connect4 *connect4, uint32_t portReader, char *pathFileCertificat) {
    if (connect4 == NULL) {
        return ;
    }
    struct sockaddr_in  sin;
    memset(connect4, 0, sizeof(t_connect4));
    connect4->error = true;
    connect4->pathFileCertificat = pathFileCertificat;
    if (access(connect4->pathFileCertificat, F_OK) != 0) {
        snprintf(connect4->errorMsg, BUFFER_ERROR_SIZE, "Certificate '%s' is a directory or do not exist\n", connect4->pathFileCertificat);
        return ;
    }
    initializeSSL();
    if ((connect4->socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        snprintf(connect4->errorMsg, BUFFER_ERROR_SIZE, "Not possible to initialise socket %s %d\n", __FILE__, __LINE__);
        return ;
    }
    fcntl(connect4->socket, F_SETFL, O_NONBLOCK);
    sin.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(portReader);
    if (bind(connect4->socket, (struct sockaddr *)&sin,sizeof(sin)) != 0) {
        snprintf(connect4->errorMsg, BUFFER_ERROR_SIZE, "Not possible bind the port(%u)\n", portReader);
    } else if (listen(connect4->socket, BACKLOG) != 0) {
        snprintf(connect4->errorMsg, BUFFER_ERROR_SIZE, "Not possible listen the socket\n");
    } else {
        connect4->error = false;
        connect4->sizeCSin = sizeof(struct sockaddr_in);
        printf("Socket open on the port [%u]\n", portReader);
    }
}

bool                    isValidConnect4(const t_connect4 *connect4) {
    return (connect4 == NULL) ? false : !connect4->error;
}

char*                   getErrorMsgConnect4(t_connect4 *connect4) {
    return (connect4 == NULL) ? "Memory full" : connect4->errorMsg;
}

void                    waitingForCliencConnect4(t_connect4 *connect4) {
    if (connect4 == NULL) {
        return ;
    }
    if ((connect4->fd = accept(connect4->socket, (struct sockaddr*)&connect4->cSin, &connect4->sizeCSin)) > 0) {
        connect4->sslctx = SSL_CTX_new(TLS_method());
        SSL_CTX_set_options(connect4->sslctx, SSL_OP_SINGLE_DH_USE);
        if (SSL_CTX_use_certificate_file(connect4->sslctx, connect4->pathFileCertificat , SSL_FILETYPE_PEM) == 1) {
            if (SSL_CTX_use_PrivateKey_file(connect4->sslctx, connect4->pathFileCertificat, SSL_FILETYPE_PEM) == 1) {
                connect4->cSSL = SSL_new(connect4->sslctx);
                SSL_set_fd(connect4->cSSL, connect4->fd);
                if(SSL_accept(connect4->cSSL) > 0){
                    manageData(connect4);
                }  else {
                    printf("\033[31mError sslError %s %d\n\033[0m", __FILE__, __LINE__);
                }
                shutdownSSL(connect4->cSSL);
            } else {
                printf("\033[31mError userPrv %s %d\n\033[0m", __FILE__, __LINE__);
            }
        } else {
            printf("\033[31mError useCert %s %d\n\033[0m", __FILE__, __LINE__);
        }
        close (connect4->fd);
    }
}

void                    closeConnect4(t_connect4 *connect4) {
    if (connect4 != NULL) {
        if (connect4->socket > 0) {
            close(connect4->socket);
            printf("Socket closed\n");
        }
    }
}         