/*
 * NamePipeCommand.cpp
 *
 *  Created on: 25.02.2015 г.
 *      Author: x000ff4
 */

#include "NamePipeCommand.h"

#include <pthread.h>
#include <cstdio>

using namespace std;
void *NamePipeCommand::readPipe(void *threadid){

    while (true) {
    	std::fread(NamePipeCommand::readBuffer,200,1,readP);
    }
	return NULL;
}
void *NamePipeCommand::writePipe(void *threadid){

    while (true) {
    	std::fwrite(NamePipeCommand::writeBuffer,200,1,writeP);
    }
	return NULL;
}
NamePipeCommand::NamePipeCommand() {

	  fifo = "/tmp/virtdat";
	  readBuffer = (char*) malloc(sizeof(char)*128);
	  writeBuffer = (char*) malloc(sizeof(char)*128);
	  mkfifo(fifo.c_str(), 0666);
	  readP =  std::fopen(NamePipeCommand::fifo.c_str(),"rb");
	  writeP =  std::fopen(NamePipeCommand::fifo.c_str(),"wb");
	  pthread_t my_thread;
	  pthread_create(&my_thread, NULL, &NamePipeCommand::readPipe, NULL);

}

NamePipeCommand::~NamePipeCommand() {
	free(readBuffer);
	free(writeBuffer);
	unlink(fifo.c_str());
}

