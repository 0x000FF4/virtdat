/*
 * ServerModule.cpp
 *
 *  Created on: 27.02.2015 г.
 *      Author: x000ff4
 */

#include "ServerModule.h"

ServerModule::ServerModule() {
	SSL_load_error_strings();
	ERR_load_BIO_strings();
	OpenSSL_add_all_algorithms();
	this->ssl = NULL;
	this->methodServer = SSLv23_method();
	this->serverContext = SSL_CTX_new(this->methodServer);
	this->errorVerifyCert = SSL_CTX_load_verify_locations(this->serverContext,
			"/tmp/virtdata", "cert");
	if (this->errorVerifyCert == 0) {
		ERR_print_errors_fp(stderr);
		std::cout << 'Error:' << stderr;
		abort();
	}
	this->bioServer = BIO_new_ssl_connect(this->serverContext);
	BIO_get_ssl(this->bioServer, this->ssl);
	if ((this->ssl) == 0) {
		ERR_print_errors_fp(stderr);
		std::cout << 'Error:' << stderr;
		abort();
	}
	SSL_set_mode(this->ssl, SSL_MODE_AUTO_RETRY);
	BIO_set_conn_hostname(this->bioServer, "127.0.0.1:8888");

	if (BIO_do_connect(this->bioServer) < 1) {

		std::cerr << "cannot to connect to the server";
	}

	if (SSL_get_verify_result(this->ssl) != X509_V_OK) {
		std::cerr << "cannot verify connection";
	}

}

ServerModule::~ServerModule() {
	// TODO Auto-generated destructor stub
}

