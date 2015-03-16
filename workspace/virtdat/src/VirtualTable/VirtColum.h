/*
 * VirtColum.h
 *
 *  Created on: 20.02.2015 г.
 *      Author: x000ff4
 */

#ifndef VIRTCOLUM_H_
#define VIRTCOLUM_H_
#include <string>
//#include "../VirtualTable/VirtualTable.h"
struct VirtualTable;
namespace std {
enum TYPE{
	TEXT = 1,
	BOOLEAN = 2,
	INTEGER = 3,
	BLOB = 4,
	REAL = 5
};
class VirtColum {
	TYPE type;
	string name;
	bool null;
	VirtualTable *table;
	bool autoIncrement;
public:
	template<typename Archive>
	void serialize(Archive& ar, const unsigned version) {
		ar & name & null & autoIncrement & type;
	};
	void setTable(void* table);
	VirtualTable* getTable();
	string getName();
	bool isNull();
	bool isAutoIncrement();
	TYPE getType();
	// The constructor for the column
	 /*!
	  *\param name - the name of the column.It can`t be changed after
	  *\the construction of the object because to keep integrity.
	  *\
	  *\param type - the type of the column(text,boolean,integer,blob or real).
	  *\It can`t be changed after the construction of the object because to keep integrity.
	  *\
	  *\param null - set the permission of the block in this column to be null.
	  *\It can`t be changed after the construction of the object because to keep integrity.
	  *\
	  *\param autoIncrement - set the autoIncrement option for this column.
	  *\It can`t be changed after the construction of the object because to keep integrity.
	  */
	VirtColum(string name ,TYPE type,VirtualTable* table,bool null, bool autoIncremen);
	virtual ~VirtColum();
};

} /* namespace std */

#endif /* VIRTCOLUM_H_ */
