/*
 * Commands.h
 *
 *  Created on: 10.03.2015 г.
 *      Author: x000ff4
 */

#ifndef INTERNETMODULE_COMMANDS_H_
#define INTERNETMODULE_COMMANDS_H_

#include <vector>
#include <string>

enum INTERNET_COMMANDS{
	CREATE_TABLE,
	DELETE_TABLE,
	CREATE_LINK,
	DELETE_LINK
};

class Commands {
	INTERNET_COMMANDS command;
	 std::vector<std::string> args;
public:
	void setCommand(INTERNET_COMMANDS command);
	void addArg(std::string arg);
	std::vector<std::string> getArgs();
	Commands(INTERNET_COMMANDS command);
	virtual ~Commands();
};

#endif /* INTERNETMODULE_COMMANDS_H_ */
