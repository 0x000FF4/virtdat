/*
 * VirtualTable.cpp
 *
 *  Created on: 20.02.2015 г.
 *      Author: x000ff4
 */

#include "VirtualTable.h"
#include "VirtualTableMetadata.h"
namespace std {

void VirtualTable::setUpdateFunc(
		void (*updateFunc)(vector<void*> callbackArgs)) {
	this->updateFunc = updateFunc;
}
long long int VirtualTable::getRowCount() {
	return this->row.size();
}
vector<VirtColum> VirtualTable::getColumns() {
	return this->colums;
}
VirtualTableMetadata* VirtualTable::getMetadata() {

	VirtualTableMetadata* metadata = new VirtualTableMetadata(this->name,
			this->updateFunc, this->colums, this->tags);
	return metadata;
}
void VirtualTable::updateCell(int row, int column, char *newVal) {
	this->row.at(column).at(row) = newVal;
}
short VirtualTable::getColumCount() {
	return this->colums.size();
}
void VirtualTable::addCell(int column, char* val) {
	this->row.at(column).push_back(val);
}
void VirtualTable::setName(string name) {
	this->name = name;
}
char* VirtualTable::getCell(int row, int column) {
	return this->row.at(column).at(row);
}

string VirtualTable::getName() {
	return this->name;
}
vector<char*> VirtualTable::getRow(int position) {
	return this->row.at(position);
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
				throw invalid_argument(
						"this column must be notNULL but it is null");
			}
			if (it->isAutoIncrement() && this->row.size() > 0) {
				char* block = newRow.back();
				*block += 1;
				newRow.at(newRow.begin() - itRow) = ++(block);
			}
		}
	}
	this->row.push_back(newRow);
	updateFunc(callbackArgs);
}
void VirtualTable::addTag(string tag) {
	this->tags.push_back(tag);
}
vector<string> VirtualTable::getTags() {
	return this->tags;
}

VirtualTable::VirtualTable(vector<VirtColum> columns,
		void (*updateFunc)(vector<void*> callbackArgs), string name,
		vector<string> tags) {
	this->colums.insert(this->colums.end(), columns.begin(), columns.end());
	this->tags.insert(this->tags.end(), tags.begin(), tags.end());
	this->name = name;
	this->updateFunc = updateFunc;
}
VirtualTable::~VirtualTable() {
}

} /* namespace std */

namespace boost {
namespace serialization {
class access;
}
}
