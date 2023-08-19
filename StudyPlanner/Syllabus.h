#pragma once
#include <wx/wx.h>

class Syllabus : public wxPanel
{
public:
	Syllabus(wxWindow* parent);
	void Initialize();

	void DisplaySyllabus();
	std::string FileName;
	std::string DisplaySubject;
	//void BindEventHandlers(int f);
	void UpdateCurrentSyllabus(wxCloseEvent& evt);
	//void SaveSyllabusStatus();
	wxCheckListBox* CheckListBox[7];

};

struct Syllabus_a {
	std::string item;
	bool done;
};

std::vector<Syllabus_a> LoadSyllabus(const std::string& filename);
void UpdateSyllabus(const std::vector<Syllabus_a>& Syllabus, const std::string& filename);
