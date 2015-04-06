/*
 * VirtualTableMetadata.cpp
 *
 *  Created on: 27.02.2015 г.
 *      Author: x000ff4
 */

#include "VirtualTableMetadata.h"
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
using  namespace virtdat;
VirtualTableMetadata::VirtualTableMetadata(std::string name,void(*updateFunc)(std::vector<void*> args),std::vector<VirtColum> columns,std::vector<std::string> tags) :
VirtualTable( columns ,updateFunc,name, tags) {
	// TODO Auto-generated constructor stub

}

VirtualTableMetadata::~VirtualTableMetadata() {
	// TODO Auto-generated destructor stub
}

