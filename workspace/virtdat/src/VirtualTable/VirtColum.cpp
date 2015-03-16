/*
 * VirtColum.cpp
 *
 *  Created on: 20.02.2015 г.
 *      Author: x000ff4
 */

#include "VirtColum.h"

namespace std {
void VirtColum::setTable(void* table){
	this->table = (VirtualTable*)table;
}
VirtualTable* VirtColum::getTable(){
	return this->table;
}
bool VirtColum::isNull(){
	return this->null;
}

bool VirtColum::isAutoIncrement(){
	return this->autoIncrement;
}

TYPE VirtColum::getType(){
	return this->type;
}
string VirtColum::getName(){
	return this->name;
}
VirtColum::VirtColum(string name ,TYPE type,VirtualTable *table,bool null = true, bool autoIncrement =  false) {
	this->type = type;
	this->name = name;
	this->null = null;
	this->table = table;
	this->autoIncrement = autoIncrement;
}

VirtColum::~VirtColum() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
