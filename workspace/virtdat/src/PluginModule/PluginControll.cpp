/*
 * PluginControll.cpp
 *
 *  Created on: 26.02.2015 г.
 *      Author: x000ff4
 */

#include "PluginControll.h"
#include "CommandClass.h"
#include "../VirtColum.h"
#include <boost/python.hpp>
#include <boost/python/module.hpp>
using namespace boost::python;
PluginControll::PluginControll() {
	// TODO Auto-generated constructor stub

}

PluginControll::~PluginControll() {
	// TODO Auto-generated destructor stub
}
struct World
{
    void set(std::string msg) { this->msg = msg; }
    std::string greet() { return msg; }
    std::string msg;
};
BOOST_PYTHON_MODULE(hello)
{class_<CommandClass>("World")
   .def("greet", &CommandClass::CreateTable) ;
}
