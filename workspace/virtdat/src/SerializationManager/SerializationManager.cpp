/*
 * SerializationManager.cpp
 *
 *  Created on: 27.02.2015 г.
 *      Author: x000ff4
 */

#include "SerializationManager.h"


void SerializationManager::Serialize(std::vector<std::VirtualTable> tables){
	for(std::vector<std::VirtualTable>::iterator  it = tables.begin(); it!= tables.end(); ++it){

	}
}
std::string SerializationManager::getTableTomb(){
	return this->tableTomb;
}
void SerializationManager::setTableTomb(std::string tableTomb){
	this->tableTomb = tableTomb;
}
SerializationManager::SerializationManager() {
	this->ofs.open(this->tableTomb.c_str());
}

SerializationManager::~SerializationManager() {
	// TODO Auto-generated destructor stub
}

