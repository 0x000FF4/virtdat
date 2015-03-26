/*
 * VirtualTable.cpp
 *
 *  Created on: 20.02.2015 г.
 *      Author: x000ff4
 */

#include "VirtualTable.h"
#include "VirtualTableMetadata.h"
using namespace virtdat;

void VirtualTable::setUpdateFunc(
		void (*updateFunc)(std::vector<void*> callbackArgs)) {
	this->updateFunc = updateFunc;
}
long long int VirtualTable::getRowCount() {
	return this->row.size();
}
std::vector<VirtColum> VirtualTable::getColumns() {
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
void VirtualTable::setName(std::string name) {
	this->name = name;
}
char* VirtualTable::getCell(int row, int column) {
	return this->row.at(column).at(row);
}

std::string VirtualTable::getName() {
	return this->name;
}
std::vector<char*> VirtualTable::getRow(int position) {
	return this->row.at(position);
}
std::vector<std::vector<char*> > VirtualTable::getRow(std::map<std::string, std::string> criterion) {
	std::vector<std::vector<char*> > result;
	std::vector<VirtColum>::iterator itCol;
	for (std::map<std::string, std::string>::iterator it = criterion.begin();
			it != criterion.end(); ++it) {
		//because of broken std::find
		for (std::vector<VirtColum>::iterator itCol = colums.begin();
				itCol != colums.end(); itCol++) {
			if ((itCol)->getName().compare(it->first) == 0) {
				break; //the matrix
			}
			if (itCol == colums.end()) {
				return result;
			}
		}
		for (std::vector<char*> a : row) {
			char* value = a.at(colums.begin() - itCol);
			std::string valueCompared = it->second;
			if (valueCompared.compare(value)) {
				result.push_back(a);
			}
		}
	}
	return result;
}
void VirtualTable::addRow(std::vector<char*> newRow) {

	for (std::vector<char*>::iterator itRow = newRow.begin(); itRow != newRow.end();
			++itRow) {
		for (std::vector<VirtColum>::iterator it = colums.begin();
				it != colums.end(); ++it) {
			if (it->isNull() && (*itRow) == '\0') {
				throw -1;
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
void VirtualTable::addTag(std::string tag) {
	this->tags.push_back(tag);
}
std::vector<std::string> VirtualTable::getTags() {
	return this->tags;
}

VirtualTable::VirtualTable(std::vector<VirtColum> columns,
		void (*updateFunc)(std::vector<void*> callbackArgs), std::string name,
		std::vector<std::string> tags) {
	this->colums.insert(this->colums.end(), columns.begin(), columns.end());
	this->tags.insert(this->tags.end(), tags.begin(), tags.end());
	this->name = name;
	this->updateFunc = updateFunc;
}
VirtualTable::~VirtualTable() {
}

namespace boost {
namespace serialization {
class access;
}
}
