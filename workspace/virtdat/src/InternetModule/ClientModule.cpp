/*
 * ClientModule.cpp
 *
 *  Created on: 27.02.2015 г.
 *      Author: x000ff4
 */

#include "ClientModule.h"
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
ClientModule::ClientModule() {
	SSL_load_error_strings();
	ERR_load_BIO_strings();
	OpenSSL_add_all_algorithms();
	this->ssl = NULL;
	this->methodClient = SSLv23_client_method();
	this->clientContext = SSL_CTX_new(this->methodClient);
	this->errorVerifyCert = SSL_CTX_load_verify_locations(this->clientContext,
			"/tmp/virtdata", "cert");
	if (this->errorVerifyCert == 0) {
		ERR_print_errors_fp(stderr);
		//std::cout << 'Error:' << stderr;
		abort();
	}
	this->bioClient = BIO_new_ssl_connect(this->clientContext);
	BIO_get_ssl(this->bioClient, this->ssl);
	if ((this->ssl) == 0) {
		ERR_print_errors_fp(stderr);
		//std::cout << 'Error:' << stderr;
		abort();
	}
	SSL_set_mode(this->ssl, SSL_MODE_AUTO_RETRY);
	BIO_set_conn_hostname(this->bioClient, "127.0.0.1:8888");

	if (BIO_do_connect(this->bioClient) < 1) {

		//std::cerr << "cannot to connect to the server";
	}

	if (SSL_get_verify_result(this->ssl) != X509_V_OK) {
		//std::cerr << "cannot verify connection";
	}
}

ClientModule::~ClientModule() {
	ERR_free_strings ();

	EVP_cleanup ();
	// this seems to cause double-frees for me: ENGINE_cleanup ();

	ERR_remove_state (0);
}

