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
#include <netdb.h>
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
#include <iostream>
#include <fstream>
class ClientModule {
	BIO * bioClient;
	const SSL_METHOD *methodClient;
	SSL_CTX *clientContext;
	SSL* ssl;
	int errorVerifyCert;
	std::ifstream readBuffer;
	std::ofstream writeBuffer;
public:
	void start();
	std::ifstream& getInputStream();
	std::ofstream& getOutputStream();
	ClientModule();
   ~ClientModule();
	void readData();
	void writeData();
};

#endif /* INTERNETMODULE_CLIENTMODULE_H_ */
