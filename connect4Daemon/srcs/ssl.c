#include "../incs/ssl.h"

void                    initializeSSL(){
    SSL_load_error_strings();
    SSL_library_init();
    OpenSSL_add_all_algorithms();
}

void                    destroySSL(){
    ERR_free_strings();
    EVP_cleanup();
}

void                    shutdownSSL(SSL *cSSL) {
    SSL_shutdown(cSSL);
    SSL_free(cSSL);
}