/*
 * MainGui.h
 *
 *  Created on: 28.02.2015 г.
 *      Author: x000ff4
 */

#ifndef GUIMODULE_MAINGUI_H_
#define GUIMODULE_MAINGUI_H_
#include <wx/wxprec.h>
#include <wx/wx.h>
class MainGui: public wxFrame {
	void OnHello(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();

public:
	MainGui(const wxString& title, const wxPoint& pos, const wxSize& size);

MainGui();
virtual ~MainGui();
};

#endif /* GUIMODULE_MAINGUI_H_ */
