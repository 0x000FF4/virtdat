/*
 * CommandAndControll.h
 *
 *  Created on: 28.02.2015 г.
 *      Author: x000ff4
 */

#ifndef COMMANDANDCONTROLLMODULE_COMMANDANDCONTROLL_H_
#define COMMANDANDCONTROLLMODULE_COMMANDANDCONTROLL_H_
#include "VirtTableHolder.h"
#include <vector>
class CommandAndControll {

public:
	void createTable(std::vector<std::VirtColum> columns ,std::string name = "",std::vector<std::string> tags = {});
	void serializeAllTables();
	int tableSize();
	CommandAndControll();
	virtual ~CommandAndControll();
};

#endif /* COMMANDANDCONTROLLMODULE_COMMANDANDCONTROLL_H_ */
