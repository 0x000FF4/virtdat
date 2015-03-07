/*
 * LineParams.cpp
 *
 *  Created on: 7.03.2015 г.
 *      Author: x000ff4
 */

#include "LineParams.h"

GtkImage*  LineParams::getBeginImage(){
	return this->beginImage;
}

GtkImage*  LineParams::getEndImage(){
	return this->endImage;
}

void LineParams::setBeginImage(GtkImage* beginImage){
		this->beginImage = beginImage;
}

void LineParams::setEndImage(GtkImage* endImage){
		this->endImage = endImage;
}

LineParams::LineParams(GtkImage* beginImage,GtkImage* endImage) {
	this->beginImage =  beginImage;
	this->endImage = endImage;
}

LineParams::~LineParams() {
}

