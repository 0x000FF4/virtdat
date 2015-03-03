/*
 * CommandClass.h
 *
 *  Created on: 26.02.2015 г.
 *      Author: x000ff4
 */

#ifndef PLUGINMODULE_COMMANDCLASS_H_
#define PLUGINMODULE_COMMANDCLASS_H_
#include "../VirtualTable/VirtColum.h"
#include <vector>

class CommandClass {
public:
	void CreateTable(std::vector<std::VirtColum> columns,std::string name,std::vector<std::string> tags);
	CommandClass();
	virtual ~CommandClass();
};

#endif /* PLUGINMODULE_COMMANDCLASS_H_ */
