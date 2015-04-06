/*
 * ClientModule.cpp
 *
 *  Created on: 27.02.2015 г.
 *      Author: x000ff4
 */

#include "ClientModule.h"
void LoadCertificatesClient(SSL_CTX* ctx, char* CertFile, char* KeyFile)
{
 /* set the local certificate from CertFile */
    if ( SSL_CTX_use_certificate_file(ctx, CertFile, SSL_FILETYPE_PEM) <= 0 )
    {
        ERR_print_errors_fp(stderr);
        abort();
    }
    /* set the private key from KeyFile (may be the same as CertFile) */
    if ( SSL_CTX_use_PrivateKey_file(ctx, KeyFile, SSL_FILETYPE_PEM) <= 0 )
    {
        ERR_print_errors_fp(stderr);
        abort();
    }
    /* verify private key */
    if ( !SSL_CTX_check_private_key(ctx) )
    {
        fprintf(stderr, "Private key does not match the public certificate\n");
        abort();
    }
}

int OpenConnection(const char *hostname, int port)
{   int sd;
    struct hostent *host;
    struct sockaddr_in addr;

    if ( (host = gethostbyname(hostname)) == NULL )
    {
        perror(hostname);
        abort();
    }
    sd = socket(PF_INET, SOCK_STREAM, 0);
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = *(long*)(host->h_addr_list[0]);
    if ( connect(sd, (struct sockaddr*)&addr, sizeof(addr)) != 0 )
    {
        close(sd);
        perror(hostname);
        abort();
    }
    return sd;
}

SSL_CTX* InitCTX(void)
{   const SSL_METHOD *method;
    SSL_CTX *ctx;

    OpenSSL_add_all_algorithms();  /* Load cryptos, et.al. */
    SSL_load_error_strings();   /* Bring in and register error messages */
    method = SSLv3_client_method();  /* Create new client-method instance */
    ctx = SSL_CTX_new(method);   /* Create new context */
    if ( ctx == NULL )
    {
        ERR_print_errors_fp(stderr);
        abort();
    }
    return ctx;
}

void ShowCertsClient(SSL* ssl)
{   X509 *cert;
    char *line;

    cert = SSL_get_peer_certificate(ssl); /* get the server's certificate */
    if ( cert != NULL )
    {
        printf("Server certificates:\n");
        line = X509_NAME_oneline(X509_get_subject_name(cert), 0, 0);
        printf("Subject: %s\n", line);
        free(line);       /* free the malloc'ed string */
        line = X509_NAME_oneline(X509_get_issuer_name(cert), 0, 0);
        printf("Issuer: %s\n", line);
        free(line);       /* free the malloc'ed string */
        X509_free(cert);     /* free the malloc'ed certificate copy */
    }
    else
        printf("No certificates.\n");
}
void ClientModule::readData() {
	while (true) {
		ssize_t isReaded = -1;
		while (isReaded < 0) {
			isReaded = BIO_read(this->bioClient, readBuffer, BUFFER_LENGHT);
			if (isReaded == 0) {
				continue;
			} else {
				if (!BIO_should_retry(this->bioClient)) {
					//std::cerr << "error while reading internet client module";
					continue;
				}
			}
		}

	}

}
std::ofstream&  ClientModule::getOutputStream(){
	return this->writeBuffer;
}
std::ifstream&  ClientModule::getInputStream(){
	return this->readBuffer;
}
void ClientModule::writeData() {
	while (true) {
		ssize_t isReaded = -1;
		while (isReaded < 0) {
			isReaded = BIO_write(this->bioClient, writeBuffer, BUFFER_LENGHT);

			if (!BIO_should_retry(this->bioClient)) {
				//std::cerr << "error while reading internet client module";
				continue;
			}
		}

	}

}
void ClientModule::start(){
	 SSL_CTX *ctx;
	    int server;
	    SSL *ssl;
	    char buf[1024];
	    int bytes;
	    char hostname[]="127.0.0.1";
	    char portnum[]="5000";

        char CertFile[] = "/home/x000ff4/workspace/virtdat/src/cert.pem";
        char KeyFile[] = "/home/x000ff4/workspace/virtdat/src/key.pem";
	    SSL_library_init();

	    ctx = InitCTX();
	    LoadCertificatesClient(ctx, CertFile, KeyFile);
	    server = OpenConnection(hostname, atoi(portnum));
	    ssl = SSL_new(ctx);      /* create new SSL connection state */
	    SSL_set_fd(ssl, server);    /* attach the socket descriptor */
	    if ( SSL_connect(ssl) == -1 )   /* perform the connection */
	        ERR_print_errors_fp(stderr);
	    else
	    {   char *msg = "Hello???";

	        printf("Connected with %s encryption\n", SSL_get_cipher(ssl));
	        ShowCertsClient(ssl);        /* get any certs */
	        SSL_write(ssl, msg, strlen(msg));   /* encrypt & send message */
	        bytes = SSL_read(ssl, buf, sizeof(buf)); /* get reply & decrypt */
	        buf[bytes] = 0;
	        printf("Received: \"%s\"\n", buf);
	        SSL_free(ssl);        /* release connection state */
	    }
	    close(server);         /* close socket */
	    SSL_CTX_free(ctx);        /* release context */

}
ClientModule::ClientModule() {
}

ClientModule::~ClientModule() {
}

