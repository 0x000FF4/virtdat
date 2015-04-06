/*
 * LineParams.h
 *
 *  Created on: 7.03.2015 г.
 *      Author: x000ff4
 */

#ifndef GUIMODULE_LINEPARAMS_H_
#define GUIMODULE_LINEPARAMS_H_
#include <gtk/gtk.h>

class LineParams {

	GtkImage* beginImage;
	GtkImage* endImage;
public:
	void setBeginImage(GtkImage* beginImage);
	void setEndImage(GtkImage* endImage);
	GtkImage* getEndImage();
	GtkImage* getBeginImage();

	LineParams(GtkImage* beginImage,GtkImage* endImage);
	virtual ~LineParams();
};

#endif /* GUIMODULE_LINEPARAMS_H_ */
