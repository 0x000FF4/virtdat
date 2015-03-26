/*
 * SerializationManager.cpp
 *
 *  Created on: 27.02.2015 г.
 *      Author: x000ff4
 */

#include "SerializationManager.h"
using namespace virtdat;
SerializationManager& SerializationManager::getInstance(){
	static SerializationManager instance;
	return instance;
}
void SerializationManager::Serialize(std::vector<VirtualTable*> *tables) {
	std::list<VirtualTableMetadata*> metadata;
	for (std::vector<VirtualTable*>::iterator it = tables->begin();
			it !=  tables->end(); ++it) {
		metadata.push_back((*it)->getMetadata());
	}
	for (std::list<VirtualTableMetadata*>::iterator itMeta =
			metadata.begin(); itMeta != metadata.end();++itMeta) {
		VirtualTableMetadata* metaPointer = *itMeta;
		(*this->archive)<< (metaPointer);

	}
}
std::string SerializationManager::getTableTomb() {
	return this->tableTomb;
}
void SerializationManager::setTableTomb(std::string tableTomb) {
	this->tableTomb = tableTomb;
}
SerializationManager::SerializationManager() {
	this->ofs.open(this->tableTomb.c_str());
	this->archive = new boost::archive::text_oarchive(this->ofs);
}

SerializationManager::~SerializationManager() {
	// TODO Auto-generated destructor stub
}

