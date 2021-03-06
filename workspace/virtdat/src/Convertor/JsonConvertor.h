/*
 * JsonConvertor.h
 *
 *  Created on: 17.03.2015 г.
 *      Author: x000ff4
 */

#ifndef CONVERTOR_JSONCONVERTOR_H_
#define CONVERTOR_JSONCONVERTOR_H_
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include "../VirtualTable/VirtColum.h"
#include <vector>
#include <string>
namespace virtdat {

class JsonConvertor {
public:
	std::string generateJson(std::vector<VirtColum*> columns,std::vector<std::vector<std::string>> rows);
	JsonConvertor();
	virtual ~JsonConvertor();
};

} /* namespace std */

#endif /* CONVERTOR_JSONCONVERTOR_H_ */
