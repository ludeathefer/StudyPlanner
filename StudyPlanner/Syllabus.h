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
	void BindEventHandlers(int f);

	wxCheckListBox* CheckListBox[7];

};

struct Syllabus_a {
	std::string item;
	bool done;
};

std::vector<Syllabus_a> LoadSyllabus(const std::string& filename);