#pragma once
 
#include<wx/wx.h>
#include<wx/datectrl.h>

//class AddAssignmentDialog : public wxDialog
//{
//public:
//	AddAssignmentDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = "Assignment Input",
//		const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE) :
//	wxDialog(parent, id, title, pos, size, style)
//	{
//		wxBoxSizer* DialogSizer = new wxBoxSizer(wxVERTICAL);
//
//        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
//
//        wxStaticText* label = new wxStaticText(this, wxID_ANY, "Enter something:");
//        sizer->Add(label, 0, wxALL | wxALIGN_CENTER, 10);
//
//        auto textEntry = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
//        sizer->Add(textEntry, 0, wxALL | wxEXPAND, 10);
//
//        wxStaticText* dateLabel = new wxStaticText(this, wxID_ANY, "Select a date:");
//        sizer->Add(dateLabel, 0, wxALL | wxALIGN_CENTER, 10);
//
//        auto datePicker = new wxDatePickerCtrl(this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT);
//        sizer->Add(datePicker, 0, wxALL | wxEXPAND, 10);
//
//        wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
//        auto okButton = new wxButton(this, wxID_OK, "OK");
//        buttonSizer->Add(okButton, 0, wxALL, 10);
//        auto cancelButton = new wxButton(this, wxID_CANCEL, "Cancel");
//        buttonSizer->Add(cancelButton, 0, wxALL, 10);
//
//        sizer->Add(buttonSizer, 0, wxALIGN_CENTER);
//
//        SetSizerAndFit(sizer);
//	}
//
//	//wxStaticText* label;
//    
//};

