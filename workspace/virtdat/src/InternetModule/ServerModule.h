/*
 * ServerModule.h
 *
 *  Created on: 27.02.2015 г.
 *      Author: x000ff4
 */

#ifndef INTERNETMODULE_SERVERMODULE_H_
#define INTERNETMODULE_SERVERMODULE_H_
#define BUFFER_LENGHT 4096

#include "openssl/bio.h"
#include "openssl/ssl.h"
#include "openssl/err.h"
#include <openssl/evp.h>
#include <sys/socket.h>
#include <iostream>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>
#include <sys/socket.h>
#include <resolv.h>
typedef int (*spc_x509verifycallback_t)(int, X509_STORE_CTX *);

typedef struct {
  char                      *cafile;
  char                      *capath;
  char                      *crlfile;
  spc_x509verifycallback_t  callback;
  STACK_OF(X509)            *certs;
  STACK_OF(X509_CRL)        *crls;
  char                      *use_certfile;
  STACK_OF(X509)            *use_certs;
  char                      *use_keyfile;
  EVP_PKEY                  *use_key;
  int                       flags;
} spc_x509store_t;


class ServerModule {
	BIO * bioServer;
	const SSL_METHOD *methodServer;
	SSL_CTX *serverContext;
	SSL* ssl;
	int errorVerifyCert;
	char  buffer[BUFFER_LENGHT];


public:
	ServerModule();
	 ~ServerModule();
	void start();
	void writeData();
};

#endif /* INTERNETMODULE_SERVERMODULE_H_ */
