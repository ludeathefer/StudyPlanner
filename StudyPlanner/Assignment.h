#pragma once
#include <wx/wx.h>
#include <string>
#include <vector>
#include <wx/srchctrl.h>
#include<wx/datectrl.h>

class AddAssignmentDialog;
	
class Assignment : public wxPanel//, public Assignment_b/* public Assignment_b*/
{
public:
	Assignment();
	Assignment(wxWindow* parent);

	void Initialize();
	
	//void display_dl();
	//void display_oop();
	//void display_math();
	//void display_em();
	//void display_ect();
	//void display_edc();
	//void display_toc();

	//void CreateControls();

	wxPanel* Panel;
	wxStaticText* TitleText;
	wxStaticText* TitleText_[7];
	wxStaticText* TextView;
	wxButton* AddButton[7];
	wxCheckListBox* CheckListBox[7];
	wxTextCtrl* InputFields;
	wxString Input;	
	wxString* InputValue;
	std::string DisplayTitle;
	std::string FileName;
	//wxGetTextFromUser* Input;
	//wxCheckListBox CheckListBox_;

	wxButton* ClearButton[7];
	wxFont* CheckListBox_Font;

	void BindEventHandlers(int a);
	void OnAddButtonClicked(wxCommandEvent& evt, int pra);
	void OnListKeyDown(wxKeyEvent& evt, int j);
	void DeleteSelectedTask(int m);
	void AddItemFromInput( int f, wxString Val);
	void CallInputFields(int f);
	void RemoveInputFields();
	void MoveSelectedTasks(int f, int offset);
	void SwapTasks(int i, int j, int k);
	void OnWindowClosedAssignment(wxCloseEvent& evt);// , int i);
	void AddSavedTasks();
	bool ElementsVisible;
	void DatePicker(int f);

	void DialogBoxDisplay(wxWindow* parent);
	//void OnAddButtonClicked(wxCommandEvent* evt, int f);
	void _OnAddButtonClicked(wxCommandEvent& evt, int f);

	//AddAssignmentDialog AddDialog(wxWindow* parent);

	//std::string item;
	//bool done;
};	


struct Assignment_a {
	std::string item;
	bool done;
};

void SaveItem(const std::vector<Assignment_a>& Assignment,const std::string& filename);
std::vector<Assignment_a> LoadItem(const std::string& filename);


class AddAssignmentDialog : public wxDialog
{
public:
	

};