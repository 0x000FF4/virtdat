/*
 * MainServer.cpp
 *
 *  Created on: 24.02.2015 г.
 *      Author: x000ff4
 */

#include "MainServer.h"

#include <cstdio>
#include <cstdlib>
#include <thread>
void MainServer::lol(){

}
MainServer::MainServer() {
	this->threadsClientRead = new std::thread(&ClientModule::readData,&MainServer::clientModule);
	this->threadsClientWrite= new std::thread(&ClientModule::writeData,&MainServer::clientModule);
	this->threadsServerRead = new std::thread(&ServerModule::readData,&MainServer::serverModule);
	this->threadsServerWrite = new std::thread(&ServerModule::writeData,&MainServer::serverModule);
}

MainServer::~MainServer() {

}


