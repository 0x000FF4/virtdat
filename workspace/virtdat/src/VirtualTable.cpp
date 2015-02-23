/*
 * VirtualTable.cpp
 *
 *  Created on: 20.02.2015 г.
 *      Author: x000ff4
 */

#include "VirtualTable.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

namespace std {

long long int VirtualTable::getRowCount() {
	return this->row.size();
}

short VirtualTable::getColumCount() {
	return this->colums.size();
}

vector< vector<char*> > VirtualTable::getRow(map<string, string> criterion) {
	vector< vector<char*> > result ;
	vector<VirtColum>::iterator itCol;
	for (map<string, string>::iterator it = criterion.begin();
			it != criterion.end(); ++it) {
		 //because of broken std::find
		 for(vector<VirtColum>::iterator itCol = colums.begin(); itCol != colums.end();itCol++){
			 if((itCol)->getName().compare(it->first) == 0){
				 break;//the matrix
			 }
			 if(itCol == colums.end()){
				 return result;
			 }
		 }
		for (vector<char*> a : row) {
			char* value = a.at(colums.begin() -  itCol);
			string valueCompared  = it->second;
			if(valueCompared.compare(value)){
				result.push_back(a);
		}
	}
	}
	return result;
}
void VirtualTable::addRow(vector<char*> newRow) {
	this->row.push_back( newRow);
}

VirtualTable::VirtualTable() {
	// TODO Auto-generated constructor stub

}

VirtualTable::~VirtualTable() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */

namespace boost {
namespace serialization {
class access;
}
}
