/*
 * Commands.h
 *
 *  Created on: 10.03.2015 г.
 *      Author: x000ff4
 */

#ifndef INTERNETMODULE_COMMANDS_H_
#define INTERNETMODULE_COMMANDS_H_

enum INTERNET_COMMANDS{
	CREATE_TABLE,
	DELETE_TABLE,
	CREATE_LINK,
	DELETE_LINK
};

class Commands {

public:
	Commands();
	virtual ~Commands();
};

#endif /* INTERNETMODULE_COMMANDS_H_ */
