/*
 * SerializationManager.h
 *
 *  Created on: 27.02.2015 г.
 *      Author: x000ff4
 */

#ifndef SERIALIZATIONMANAGER_SERIALIZATIONMANAGER_H_
#define SERIALIZATIONMANAGER_SERIALIZATIONMANAGER_H_
#include <vector>
#include <iostream>
#include <fstream>
#include "../VirtualTable.h"
#include "../VirtualTableMetadata.h"
class SerializationManager {
	std::string tableTomb;
	std::ofstream ofs;
	boost::archive::text_oarchive *archive;
public:
	void Serialize(std::vector<std::VirtualTable> tables);
	std::vector<std::VirtualTable>  Deserialize();
	std::string getTableTomb();
	void setTableTomb(std::string);
	SerializationManager();
	virtual ~SerializationManager();
};

#endif /* SERIALIZATIONMANAGER_SERIALIZATIONMANAGER_H_ */
