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
namespace virtdat{
class NewVirtTable {
	CommandAndControll* comAndcontrol;
	GtkWidget *new_window;
	static NewVirtTable* ints;
	void (*tableDone)();
public:
	 friend  void createTableButton(GtkWidget *widget, gpointer data) ;
	void createNewTable(CommandAndControll* comAndcontrol,void(*tableDone)());
	NewVirtTable();
	virtual ~NewVirtTable();
};
}
#endif /* GUIMODULE_NEWVIRTTABLE_H_ */
