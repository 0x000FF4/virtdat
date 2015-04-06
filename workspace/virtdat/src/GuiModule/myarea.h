/*
 * myarea.h
 *
 *  Created on: 7.03.2015 г.
 *      Author: x000ff4
 */

#ifndef GUIMODULE_MYAREA_H_
#define GUIMODULE_MYAREA_H_
#include <gtk/gtk.h>
#include <gtkmm/drawingarea.h>

class MyArea : public Gtk::DrawingArea
{
public:
  MyArea();
  virtual ~MyArea();

protected:
  //Override default signal handler:
  virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
};



#endif /* GUIMODULE_MYAREA_H_ */
