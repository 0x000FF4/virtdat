/*
 * CommandAndControll.h
 *
 *  Created on: 28.02.2015 г.
 *      Author: x000ff4
 */

#ifndef COMMANDANDCONTROLLMODULE_COMMANDANDCONTROLL_H_
#define COMMANDANDCONTROLLMODULE_COMMANDANDCONTROLL_H_
#include "VirtTableHolder.h"
#include "../InternetModule/ServerModule.h"
#include "../InternetModule/session.h"
#include "../InternetModule/server.h"
#include <vector>
#include <string>
namespace virtdat{
class CommandAndControll {
	
public:
	void startServer(int port);
	void linkTwoColumns(virtdat::VirtColum *firts,virtdat::VirtColum *second);
	void createTable(std::vector<virtdat::VirtColum> columns ,std::string name = "",std::vector<std::string> tags = {});
	void serializeAllTables();
	int tableSize();
	CommandAndControll();
	virtual ~CommandAndControll();
};
}
#endif /* COMMANDANDCONTROLLMODULE_COMMANDANDCONTROLL_H_ */
