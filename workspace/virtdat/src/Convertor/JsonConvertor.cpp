/*
 * JsonConvertor.cpp
 *
 *  Created on: 17.03.2015 г.
 *      Author: x000ff4
 */

#include "JsonConvertor.h"

#include <string>
#include <iostream>
#include "../VirtualTable/VirtColum.h"
std::string virtdat::JsonConvertor::generateJson(std::vector<virtdat::VirtColum*> columns,std::vector<std::vector<std::string>> rows){
	rapidjson::Document d;
	rapidjson::Document::AllocatorType& a = d.GetAllocator();
	std::vector<rapidjson::Value*> columnsJson;// make a copy

	for(int i = 0 ; i< columns.size();i++){
		rapidjson::Value clomun;
		clomun.SetArray();
		columnsJson.push_back(&clomun);
			for(int j = 0 ; j<rows.at(i).size();j++){
				//string s = rows.at(i).at(j);
				rapidjson::Value cell(columns.at(i)->getName().c_str(),1);
				clomun.PushBack(cell, a);
			}
	}

	d.SetObject();
	for(int i = 0;  i < columns.size();i++){
		rapidjson::Value name(columns.at(i)->getName().c_str(),1);
		d.AddMember(name,*columnsJson.at(i),a);
	}

    rapidjson::StringBuffer buffer;


    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);

    d.Accept(writer);
    std::cout<<"JSON:" <<buffer.GetString()<<std::endl;
    return buffer.GetString();
}

virtdat::JsonConvertor::JsonConvertor() {
	// TODO Auto-generated constructor stub

}

virtdat::JsonConvertor::~JsonConvertor() {
	// TODO Auto-generated destructor stub
}

