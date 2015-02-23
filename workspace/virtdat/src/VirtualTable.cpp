/*
 * VirtualTable.cpp
 *
 *  Created on: 20.02.2015 г.
 *      Author: x000ff4
 */

#include "VirtualTable.h"

namespace std {

long long int VirtualTable::getRowCount() {
	return this->row.size();
}

short VirtualTable::getColumCount() {
	return this->colums.size();
}

void VirtualTable::getRow(map<string, string> criterion) {
	for (map<char, char>::iterator it = criterion.begin();
			it != criterion.end(); ++it) {
		int index = find(colums.begin(), colums.end(), it->first)
				- colums.begin();

		for (vector<char*> a : row) {
			char* value = a.at(index);
			string valueCompared  = it->first;
			if(valueCompared.compare(value)){

			}
		}
	}
}
void VirtualTable::addRow(vector<char*> newRow) {
	this->row.insert(row.end(), newRow.begin(), newRow.end());
}

VirtualTable::VirtualTable() {
	// TODO Auto-generated constructor stub

}

VirtualTable::~VirtualTable() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
