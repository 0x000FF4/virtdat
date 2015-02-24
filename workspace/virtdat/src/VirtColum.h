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
	void addRow();
	bool isNull();
	bool isAutoIncrement();
	TYPE getType();
	VirtColum(string name ,TYPE type,bool null, bool autoIncremen);
	virtual ~VirtColum();
};

} /* namespace std */

#endif /* VIRTCOLUM_H_ */
