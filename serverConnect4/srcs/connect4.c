#include "../incs/connect4.h"

void                    initConnect4(t_connect4 *ret, uint32_t portReader, char *pathFileCertificat) {
    struct sockaddr_in  sin;
    memset(ret, 0, sizeof(t_connect4));
    ret->error = true;
    ret->pathFileCertificat = pathFileCertificat;
    if (access(ret->pathFileCertificat, F_OK) != 0) {
        snprintf(ret->errorMsg, BUFFER_ERROR_SIZE, "Certificate '%s' is a directory or do not exist\n", ret->pathFileCertificat);
        return ;
    }
    initializeSSL();
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
    int                 useCert;
    int                 usePrv;
    int                 sslErr;
    
    printf("Wainting for client\n");
    fd = accept(connect4->socket, (struct sockaddr*)&connect4->cSin, &connect4->sizeCSin);
    if (fd <= 0) {
        printf("\033[31mClient connection failled\n\033[0m");
        return ;
    }
    connect4->sslctx = SSL_CTX_new( SSLv23_server_method());
    SSL_CTX_set_options(connect4->sslctx, SSL_OP_SINGLE_DH_USE);
    if ((useCert = SSL_CTX_use_certificate_file(connect4->sslctx, connect4->pathFileCertificat , SSL_FILETYPE_PEM)) == 1) {
        if ((usePrv = SSL_CTX_use_PrivateKey_file(connect4->sslctx, connect4->pathFileCertificat, SSL_FILETYPE_PEM)) == 1) {
            connect4->cSSL = SSL_new(connect4->sslctx);
            SSL_set_fd(connect4->cSSL, fd);
            sslErr = SSL_accept(connect4->cSSL);
            if(sslErr > 0){
                printf("\033[32mClient connected on the fd[%d]\n\033[0m", fd);
            }  else {
                printf("\033[31mError sslError %s %d\n\033[0m", __FILE__, __LINE__);
            }
            shutdownSSL(connect4->cSSL);
            close (fd);
        } else {
            printf("\033[31mError userPrv %s %d\n\033[0m", __FILE__, __LINE__);
        }
    } else {
        printf("\033[31mError useCert %s %d\n\033[0m", __FILE__, __LINE__);
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