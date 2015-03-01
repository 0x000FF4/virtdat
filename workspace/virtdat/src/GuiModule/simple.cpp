/*
 * simple.cpp
 *
 *  Created on: 1.03.2015 г.
 *      Author: x000ff4
 */

#include "simple.h"

Simple::Simple(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 150))
{
  Centre();
}
