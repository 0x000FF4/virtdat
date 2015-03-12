/*
 * MainServer.cpp
 *
 *  Created on: 24.02.2015 г.
 *      Author: x000ff4
 */

#include "MainServer.h"

MainServer::MainServer() {
	ClientModule client;
	//ServerModule server;
	this->threadsClientRead = new std::thread(&ClientModule::readData,&client);
	this->threadsClientWrite= new std::thread(&ClientModule::writeData,&client);
	//this->threadsServerRead = new std::thread(&ServerModule::readData,&server);
	//this->threadsServerWrite= new std::thread(&ServerModule::writeData,&server);

}

MainServer::~MainServer() {

}


