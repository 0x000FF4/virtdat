/*
 * VirtualTableMetadata.h
 *
 *  Created on: 27.02.2015 г.
 *      Author: x000ff4
 */

#ifndef VIRTUALTABLEMETADATA_H_
#define VIRTUALTABLEMETADATA_H_
#include "VirtualTable.h"
class VirtualTableMetadata : public std::VirtualTable {
	friend class boost::serialization::access;
	template<typename Archive>
	void serialize(Archive& ar, const unsigned version) {
		ar & std::VirtualTable::getColumns() & std::VirtualTable::getTags();
	};
public:
	VirtualTableMetadata(std::string name,std::vector<std::VirtColum> columns,std::vector<std::string> tags);
	virtual ~VirtualTableMetadata();
};

#endif /* VIRTUALTABLEMETADATA_H_ */
