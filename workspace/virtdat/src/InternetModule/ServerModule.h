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
#include <iostream>
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
	void readData();
	void writeData();
};

#endif /* INTERNETMODULE_SERVERMODULE_H_ */
