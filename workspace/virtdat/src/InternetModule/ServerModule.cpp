/*
 * ServerModule.cpp
 *
 *  Created on: 27.02.2015 г.
 *      Author: x000ff4
 */

#include "ServerModule.h"

ServerModule::ServerModule() {
	SSL_library_init();// nobodys is perfect
	SSL_load_error_strings();
	ERR_load_BIO_strings();

	OpenSSL_add_all_algorithms();
	SSLeay_add_ssl_algorithms();
	this->ssl = NULL;


	this->methodServer = SSLv23_method();

	this->serverContext = SSL_CTX_new(this->methodServer);

	this->errorVerifyCert = SSL_CTX_load_verify_locations(this->serverContext,
			"/home/x000ff4/workspace/virtdat/src/cert.pem",NULL);
	if (this->errorVerifyCert == 0) {
		 SSL_load_error_strings();
		ERR_print_errors_fp(stderr);
		std::cout << "\n";
		std::flush(std::cout);
		std::cout << "\n";
		std::flush(std::cerr);
		std::cout << "\n";
	std::cout << 'Error:' << stderr;
		abort();
	}
	this->bioServer = BIO_new_ssl_connect(this->serverContext);
	BIO_get_ssl(this->bioServer, &this->ssl);
	if ((this->ssl) == 0) {
		ERR_print_errors_fp(stderr);
		std::cout << this->bioServer<<" \n";
		std::flush(std::cout);
		std::cout << "\n";
		std::flush(std::cerr);
		//std::cout << 'Error:' << stderr;
		abort();
	}
	SSL_set_mode(this->ssl, SSL_MODE_AUTO_RETRY);

	int val = BIO_set_conn_hostname(this->bioServer, "127.0.0.1:https");

	if (BIO_do_connect(this->bioServer) < 1) {
		char* valS = BIO_get_conn_hostname(this->bioServer);
		int port = BIO_get_conn_int_port(this->bioServer);
		std::cout << "\n cannot to connect to the server "<<BIO_do_connect(this->bioServer) <<" val:" << port ;
	}

	if (SSL_get_verify_result(this->ssl) != X509_V_OK) {
		std::cout << "\n cannot verify connection";
	}
	std::flush(std::cout);

}

ServerModule::~ServerModule() {
	// TODO Auto-generated destructor stub
}

