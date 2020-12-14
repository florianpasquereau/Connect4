#ifndef SSL_H
# define SSL_H

#include <openssl/bio.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

void                    initializeSSL();
void                    destroySSL();
void                    shutdownSSL(SSL *cSSL);

#endif