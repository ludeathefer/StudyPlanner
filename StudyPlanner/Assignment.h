#pragma once
#include <wx/wx.h>
#include <string>
#include <vector>
#include <wx/srchctrl.h>

class Assignment_b : public wxPanel
{
public:
	Assignment_b();
	Assignment_b(wxWindow* parent);
	void Initialize();

	//Assignment* assignment_a_a;

};
	
class Assignment : public wxPanel//, public Assignment_b/* public Assignment_b*/
{
public:
	Assignment();
	Assignment(wxWindow* parent);

	/*void Initialize();
	
	void display_dl();
	void display_oop();
	void display_math();
	void display_em();
	void display_ect();
	void display_edc();
	void display_toc();

	void CreateControls();*/

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
	void OnWindowClosed_a(wxCloseEvent& evt);// , int i);
	void AddSavedTasks();
	bool ElementsVisible;

	//std::string item;
	//bool done;
};	


struct Assignment_a {
	//wxString item;
	std::string item;
	bool done;
};

void SaveItem(const std::vector<Assignment_a>& Assignment,const std::string& filename);
std::vector<Assignment_a> LoadItem(const std::string& filename);