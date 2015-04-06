/*
 * SerializationManager.cpp
 *
 *  Created on: 27.02.2015 г.
 *      Author: x000ff4
 */

#include "SerializationManager.h"
virtdat::SerializationManager& virtdat::SerializationManager::getInstance(){
	static SerializationManager instance;
	return instance;
}
void virtdat::SerializationManager::Serialize(std::vector<virtdat::VirtualTable*> *tables) {
	std::list<virtdat::VirtualTableMetadata*> metadata;
	for (std::vector<virtdat::VirtualTable*>::iterator it = tables->begin();
			it !=  tables->end(); ++it) {
		metadata.push_back((*it)->getMetadata());
	}
	for (std::list<virtdat::VirtualTableMetadata*>::iterator itMeta =
			metadata.begin(); itMeta != metadata.end();++itMeta) {
		virtdat::VirtualTableMetadata* metaPointer = *itMeta;
		(*this->archive)<< (metaPointer);

	}
}
std::string virtdat::SerializationManager::getTableTomb() {
	return this->tableTomb;
}
void virtdat::SerializationManager::setTableTomb(std::string tableTomb) {
	this->tableTomb = tableTomb;
}
 virtdat::SerializationManager::SerializationManager() {
	this->ofs.open(this->tableTomb.c_str());
	this->archive = new boost::archive::text_oarchive(this->ofs);
}

 virtdat::SerializationManager::~SerializationManager() {
	// TODO Auto-generated destructor stub
}

