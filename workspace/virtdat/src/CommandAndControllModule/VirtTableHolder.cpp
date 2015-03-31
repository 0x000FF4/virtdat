/*
 * VirtTableHolder.cpp
 *
 *  Created on: 28.02.2015 г.
 *      Author: x000ff4
 */

#include "VirtTableHolder.h"


std::vector<virtdat::VirtualTable*>* virtdat::VirtTableHolder::getTables(){
	return &(this->tables);
}
void virtdat::VirtTableHolder::addTable(virtdat::VirtualTable *table){
	this->tables.push_back(table);
}
virtdat::VirtTableHolder& virtdat::VirtTableHolder::getInstance(){
	static virtdat::VirtTableHolder instance;
	return instance;
}
virtdat::VirtTableHolder::VirtTableHolder() {

}

virtdat::VirtTableHolder::~VirtTableHolder() {
	// TODO Auto-generated destructor stub
}

