/*
 * NamePipeCommand.h
 *
 *  Created on: 25.02.2015 г.
 *      Author: x000ff4
 */

#ifndef NAMEDPIPEMODULE_NAMEPIPECOMMAND_H_
#define NAMEDPIPEMODULE_NAMEPIPECOMMAND_H_
#include <thread>
#include <string>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
class NamePipeCommand {
	static char* readBuffer;
	static char* writeBuffer;
	static FILE *readP;
	static FILE *writeP;
	static std::string fifo;
public:
	static void *readPipe(void *threadid);
	static void *writePipe(void *threadid);
	NamePipeCommand();
	virtual ~NamePipeCommand();
};

#endif /* NAMEDPIPEMODULE_NAMEPIPECOMMAND_H_ */
