/*
 * VirtTableHolder.h
 *
 *  Created on: 28.02.2015 г.
 *      Author: x000ff4
 */

#ifndef COMMANDANDCONTROLLMODULE_VIRTTABLEHOLDER_H_
#define COMMANDANDCONTROLLMODULE_VIRTTABLEHOLDER_H_

#include <vector>
#include "../VirtualTable/VirtualTable.h"
namespace virtdat{
class VirtTableHolder {
	std::vector<std::VirtualTable*> tables;
	VirtTableHolder(VirtTableHolder const&) = delete;
	VirtTableHolder& operator=(const VirtTableHolder&){};
 	VirtTableHolder();
 	virtual ~VirtTableHolder();
public:
	void addTable(std::VirtualTable *table);
	std::vector<std::VirtualTable*>* getTables();
	static VirtTableHolder& getInstance();

};
]

#endif /* COMMANDANDCONTROLLMODULE_VIRTTABLEHOLDER_H_ */
