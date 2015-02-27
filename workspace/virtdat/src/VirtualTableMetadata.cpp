/*
 * VirtualTableMetadata.cpp
 *
 *  Created on: 27.02.2015 г.
 *      Author: x000ff4
 */

#include "VirtualTableMetadata.h"
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

VirtualTableMetadata::VirtualTableMetadata(std::string name,std::vector<std::VirtColum> columns,std::vector<std::string> tags) :
std::VirtualTable( name, columns, tags) {
	// TODO Auto-generated constructor stub

}

VirtualTableMetadata::~VirtualTableMetadata() {
	// TODO Auto-generated destructor stub
}

