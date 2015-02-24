/*
 * VirtColum.h
 *
 *  Created on: 20.02.2015 г.
 *      Author: x000ff4
 */

#ifndef VIRTCOLUM_H_
#define VIRTCOLUM_H_
#include <string>
namespace std {
enum TYPE{
	TEXT,
	BOOLEAN,
	INTEGER,
	BLOB,
	REAL
};
class VirtColum {
	TYPE type;
	string name;
	bool null;

	bool autoIncrement;
public:

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
	VirtColum(string name ,TYPE type,bool null, bool autoIncremen);
	virtual ~VirtColum();
};

} /* namespace std */

#endif /* VIRTCOLUM_H_ */
