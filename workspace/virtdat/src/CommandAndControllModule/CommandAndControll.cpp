/*
 * CommandAndControll.cpp
 *
 *  Created on: 28.02.2015 г.
 *      Author: x000ff4
 */

#include "CommandAndControll.h"
#include "../VirtualTable/VirtualTable.h"
//#include "../SerializationManager/SerializationManager.h"
int CommandAndControll::tableSize(){
	return VirtTableHolder::getInstance().getTables()->size();
}
void CommandAndControll::createTable(std::vector<std::VirtColum> columns ,std::string name,std::vector<std::string> tags ){
	std::VirtualTable *newTable = new std::VirtualTable(columns,name,tags);
	VirtTableHolder::getInstance().addTable(newTable);
}
void CommandAndControll::serializeAllTables(){
	std::vector<std::VirtualTable*> *tables = VirtTableHolder::getInstance().getTables();
//	SerializationManager::getInstance().Serialize(tables);
}

CommandAndControll::CommandAndControll() {


}

CommandAndControll::~CommandAndControll() {
	// TODO Auto-generated destructor stub
}

