/*
 * VirtualTable.h
 *
 *  Created on: 20.02.2015 г.
 *      Author: x000ff4
 */

#ifndef VIRTUALTABLE_H_
#define VIRTUALTABLE_H_

#include <vector>
#include <map>
#include <algorithm>
#include "VirtColum.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

namespace virtdat {
class VirtualTableMetadata;
class VirtualTable {
protected:
	std::string name;
	std::vector<void*> callbackArgs;
	std::vector<VirtColum*> colums; //holding the meta data about the virtTable;
	std::vector<std::vector<char*> > row; //holding the rows;
	void (*updateFunc)(std::vector<void*> args);
	std::vector<std::string> tags;

public:
	void setName(std::string name);
	std::string getName();
	int getInt();
	void addTag(std::string tag);
	std::vector<std::string> getTags();
	char* getCell(int row, int column);
	std::vector<char*> getRow(int position);
	void addCell(int column, char* val);
	std::vector<virtdat::VirtColum*> getColumns();
	void updateCell(int row, int column, char *newVal);
	VirtualTableMetadata* getMetadata();
	void setUpdateFunc(void (*updateFunc)(std::vector<void*> args));
	long long int getRowCount();
	// Get row or rows by the given criterion.If no result was found will
	// return empty vector.
	/*!
	 *\param criterion - the criterion to which the rows will be compared.
	 *\The key in the map is the column to which will be compared the block
	 *\and the key of the map.
	 */
	std::vector<std::vector<char*> > getRow(
			std::map<std::string, std::string> criterion);
	short getColumCount();
	// Adding row to the table.
	/*!
	 *\param row -  the row to be added if there is at least one row in the table.
	 *\the block in the column with autoIncrement will be replaced with the previous
	 *\value incremented with one.If the block in the column which have isNull  is null('\0')
	 *\an exception will be thrown.
	 */
	void addRow(std::vector<char*> row);
	// Constructor for the virtTable
	/*!
	 * \param columns - the meta data of the current table.Can be with size zero but there is not
	 * \point in this.
	 */

	VirtualTable(std::vector<virtdat::VirtColum> columns,
			void (*updateFunc)(std::vector<void*> callbackArgs), std::string name =
					"", std::vector<std::string> tags = { });
	virtual ~VirtualTable();
};

} /* namespace std */

#endif /* VIRTUALTABLE_H_ */
