/*
 * VirtTableHolder.cpp
 *
 *  Created on: 28.02.2015 г.
 *      Author: x000ff4
 */

#include "VirtTableHolder.h"
using namespace virtdat;
std::vector<VirtualTable*>* VirtTableHolder::getTables(){
	return &(this->tables);
}
void VirtTableHolder::addTable(VirtualTable *table){
	this->tables.push_back(table);
}
VirtTableHolder& VirtTableHolder::getInstance(){
	static VirtTableHolder instance;
	return instance;
}
VirtTableHolder::VirtTableHolder() {

}

VirtTableHolder::~VirtTableHolder() {
	// TODO Auto-generated destructor stub
}

