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
public:
	string getName();
	void addRow();
	TYPE getType();
	VirtColum(string newName ,TYPE newType);
	virtual ~VirtColum();
};

} /* namespace std */

#endif /* VIRTCOLUM_H_ */
