/*
 * VirtualTableMetadata.h
 *
 *  Created on: 27.02.2015 г.
 *      Author: x000ff4
 */

#ifndef VIRTUALTABLEMETADATA_H_
#define VIRTUALTABLEMETADATA_H_
#include "VirtualTable.h"
#include <boost/serialization/vector.hpp>
#include <boost/serialization/utility.hpp>

class VirtualTableMetadata : public std::VirtualTable {
	friend class boost::serialization::access;
	template<typename Archive>
	void serialize(Archive& ar, const unsigned version) {
		ar & name & colums & tags;
	};
public:
	VirtualTableMetadata(std::string name,void(*updateFunc)(std::vector<void*> args),std::vector<std::VirtColum> columns,std::vector<std::string> tags);
	virtual ~VirtualTableMetadata();
};

#endif /* VIRTUALTABLEMETADATA_H_ */
