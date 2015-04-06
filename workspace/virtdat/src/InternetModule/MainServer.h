/*
 * MainServer.h
 *
 *  Created on: 24.02.2015 г.
 *      Author: x000ff4
 */

#ifndef INTERNETMODULE_MAINSERVER_H_
#define INTERNETMODULE_MAINSERVER_H_
#define NUM_THREADS 1
#include "ServerModule.h"
#include "ClientModule.h"

#include <thread>

class MainServer {
//	 ServerModule serverModule;
static	 ClientModule clientModule;
//	std::thread* threadsServerRead;
//	std::thread* threadsServerWrite;
	std::thread* threadsClientRead;
	std::thread* threadsClientWrite;
	std::thread* threadsServerRead;
	std::thread* threadsServerWrite;
public:
	MainServer();
	virtual ~MainServer();
};


#endif /* INTERNETMODULE_MAINSERVER_H_ */
