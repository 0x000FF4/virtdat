/*
 * MVObject.h
 *
 *  Created on: 5.03.2015 г.
 *      Author: x000ff4
 */

#ifndef GUIMODULE_MVOBJECT_H_
#define GUIMODULE_MVOBJECT_H_

class MVObject : public GtkDrawingArea{
public:
	void Redraw();
	MVObject();
	virtual ~MVObject();
};

#endif /* GUIMODULE_MVOBJECT_H_ */
