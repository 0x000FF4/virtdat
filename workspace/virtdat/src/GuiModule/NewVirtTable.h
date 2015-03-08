/*
 * NewVirtTable.h
 *
 *  Created on: 8.03.2015 г.
 *      Author: x000ff4
 */

#ifndef GUIMODULE_NEWVIRTTABLE_H_
#define GUIMODULE_NEWVIRTTABLE_H_
#include <gtk/gtk.h>
#include <vector>
#include "../CommandAndControllModule/CommandAndControll.h"
class NewVirtTable {
	CommandAndControll* comAndcontrol;
public:
	void createNewTable();
	NewVirtTable(CommandAndControll* comAndcontrol);
	virtual ~NewVirtTable();
};

#endif /* GUIMODULE_NEWVIRTTABLE_H_ */
