/*
 * CommandAndControll.cpp
 *
 *  Created on: 28.02.2015 г.
 *      Author: x000ff4
 */

#include "CommandAndControll.h"
//#include "../Convertor/JsonConvertor.h"
//#include "../VirtualTable/VirtualTable.h"
//#include "../SerializationManager/SerializationManager.h"
/*
void updateLinkFunc(std::vector<void*> args) {

	virtdat::VirtualTable* table1 = (virtdat::VirtualTable*) args.at(0);
	virtdat::VirtualTable* table2 = (virtdat::VirtualTable*) args.at(1);
	int *pos1 = (int*) args.at(2);
	int *pos2 = (int*) args.at(3);
	int table1RowCount = table1->getRowCount();
	int table2RowCount = table2->getRowCount();
	for (int i = 0; i < table1RowCount; i++) {
		char* chr1 = table1->getCell(i, *pos1);
		try {
			char* chr2 = table2->getCell(i, *pos2);
			if (strcmp(chr1, chr2)) {
				table2->updateCell(i, *pos2, chr1);
}			
		} catch (const std::out_of_range& oor) {
			table2->addCell(*pos2, chr1);
		}

	}
}
void updateFuncNULL(std::vector<void*> args){

}
void CommandAndControll::linkTwoColumns(virtdat::VirtColum *first,
		virtdat::VirtColum *second) {
	VirtualTable *table1 = (VirtualTable*) first->getTable();
	VirtualTable *table2 = (VirtualTable*) second->getTable();
	table1->setUpdateFunc(updateLinkFunc);
}
int CommandAndControll::tableSize() {
	return VirtTableHolder::getInstance().getTables()->size();
}
void CommandAndControll::createTable(std::vector<VirtColum> columns,
		std::string name, std::vector<std::string> tags) {
	VirtualTable *newTable = new VirtualTable(columns, updateFuncNULL,
			name, tags);
	for (int i = 0; i < newTable->getColumCount(); i++) {
		newTable->getColumns().at(i).setTable(newTable);
	}
	VirtTableHolder::getInstance().addTable(newTable);
}
void CommandAndControll::serializeAllTables() {
	std::vector<VirtualTable*> *tables =
			VirtTableHolder::getInstance().getTables();
//	SerializationManager::getInstance().Serialize(tables);
}
*/
/*
CommandAndControll::CommandAndControll() {
}*/
/*
CommandAndControll::~CommandAndControll() {
	
}
*/
