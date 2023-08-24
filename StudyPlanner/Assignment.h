#pragma once
#include <wx/wx.h>
#include <string>
#include <vector>
#include <wx/srchctrl.h>
#include<wx/datectrl.h>



class Assignment : public wxPanel
{
public:
	Assignment(wxWindow* parent);

	wxPanel* Panel;
	wxStaticText* TitleText;
	wxStaticText* TitleText_[7];
	wxStaticText* TextView;
	wxButton* AddButton[7];
	wxCheckListBox* CheckListBox[7];
	wxTextCtrl* InputFields;
	wxString Input;
	wxString InputTime;
	wxString* InputValue;
	std::string DisplayTitle;
	std::string FileName;
	

	wxButton* ClearButton[7];
	wxFont* CheckListBox_Font;

	void BindEventHandlers(int a);
	void OnAddButtonClicked(wxCommandEvent& evt, int pra);
	void OnListKeyDown(wxKeyEvent& evt, int j);
	void DeleteSelectedTask(int m);
	void AddItemFromInput(int f, wxString Val, wxString Time);
	void CallInputFields(int f);
	void RemoveInputFields();
	void MoveSelectedTasks(int f, int offset);
	void SwapTasks(int i, int j, int k);
	void OnWindowClosedAssignment(wxCloseEvent& evt);
	void AddSavedTasks();
	bool ElementsVisible;

	struct Assignment_a;
	
};


struct Assignment::Assignment_a {
	std::string item;
	bool done;
	std::string time;

};

void SaveItem(const std::vector<Assignment::Assignment_a>& Assignment, const std::string& filename);
std::vector<Assignment::Assignment_a> LoadItem(const std::string& filename);

