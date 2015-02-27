/*
 * ClientModule.h
 *
 *  Created on: 27.02.2015 г.
 *      Author: x000ff4
 */

#ifndef INTERNETMODULE_CLIENTMODULE_H_
#define INTERNETMODULE_CLIENTMODULE_H_
#define BUFFER_LENGHT 4096
#include "openssl/bio.h"
#include "openssl/ssl.h"
#include "openssl/err.h"
#include <openssl/evp.h>
#include <iostream>

class ClientModule {
	BIO * bioClient;
	const SSL_METHOD *methodClient;
	SSL_CTX *clientContext;
	SSL* ssl;
	int errorVerifyCert;
	char  buffer[BUFFER_LENGHT];

public:
	ClientModule();
	virtual ~ClientModule();
	void readData();
	void writeData();
};

#endif /* INTERNETMODULE_CLIENTMODULE_H_ */
