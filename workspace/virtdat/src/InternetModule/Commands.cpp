/*
 * Commands.cpp
 *
 *  Created on: 10.03.2015 г.
 *      Author: x000ff4
 */

#include "Commands.h"


std::vector<std::string> Commands::getArgs(){
	return this->args;
}
void Commands::addArg(std::string arg){
	this->args.push_back(arg);
}
Commands::Commands(INTERNET_COMMANDS command) {
	this->command = command;

}

Commands::~Commands() {
	// TODO Auto-generated destructor stub
}

