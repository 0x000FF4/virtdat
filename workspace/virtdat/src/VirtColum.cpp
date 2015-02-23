/*
 * VirtColum.cpp
 *
 *  Created on: 20.02.2015 г.
 *      Author: x000ff4
 */

#include "VirtColum.h"

namespace std {

TYPE VirtColum::getType(){
	return this->type;
}
string VirtColum::getName(){
	return this->name;
}
VirtColum::VirtColum(string newName ,TYPE newType) {
	this->type = newType;
	this->name = newName;
}

VirtColum::~VirtColum() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
