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

vector<vector<char*> > VirtualTable::getRow(map<string, string> criterion) {
	vector<vector<char*> > result;
	vector<VirtColum>::iterator itCol;
	for (map<string, string>::iterator it = criterion.begin();
			it != criterion.end(); ++it) {
		//because of broken std::find
		for (vector<VirtColum>::iterator itCol = colums.begin();
				itCol != colums.end(); itCol++) {
			if ((itCol)->getName().compare(it->first) == 0) {
				break; //the matrix
			}
			if (itCol == colums.end()) {
				return result;
			}
		}
		for (vector<char*> a : row) {
			char* value = a.at(colums.begin() - itCol);
			string valueCompared = it->second;
			if (valueCompared.compare(value)) {
				result.push_back(a);
			}
		}
	}
	return result;
}
void VirtualTable::addRow(vector<char*> newRow) {

	for (vector<char*>::iterator itRow = newRow.begin(); itRow != newRow.end();
			++itRow) {
		for (vector<VirtColum>::iterator it = colums.begin();
				it != colums.end(); ++it) {
			if (it->isNull() && (*itRow) == '\0') {
				throw invalid_argument("this column must be notNULL but it is null");
			}
			if (it->isAutoIncrement() && this->row.size() > 0) {
					char* block = newRow.back();
					*block += 1;
					newRow.at(newRow.begin() - itRow) = ++(block);
			}
		}
	}
	this->row.push_back(newRow);
}

VirtualTable::VirtualTable(vector<VirtColum> columns) {
	this->colums.insert(this->colums.end(), columns.begin(), columns.end());
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
