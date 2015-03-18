/*
 * JsonConvertor.cpp
 *
 *  Created on: 17.03.2015 г.
 *      Author: x000ff4
 */

#include "JsonConvertor.h"

#include <string>

#include "../VirtualTable/VirtColum.h"

namespace std {

string JsonConvertor::generateJson(vector<VirtColum*> cloumns,vector<vector<string>> rows){
	rapidjson::Document d;
	rapidjson::Value v;
	v.SetObject();
	rapidjson::Document::AllocatorType& allocator = d.GetAllocator();
	v.AddMember("playername","2", allocator);
	//d.AddMember("",rapidjson::Value(rows.at(0).at(0)));


    // 3. Stringify the DOM
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    d.Accept(writer);

    // Output {"project":"rapidjson","stars":11}
    return buffer.GetString();
}

JsonConvertor::JsonConvertor() {
	// TODO Auto-generated constructor stub

}

JsonConvertor::~JsonConvertor() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
