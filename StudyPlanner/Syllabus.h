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
	void UpdateCurrentSyllabus(wxCloseEvent& evt);
	wxCheckListBox* CheckListBox[7];
	struct Syllabus_a;
	struct Progress;
	std::vector<Syllabus::Progress> GetSyllabusVector();
};
struct Syllabus::Progress
{
	float percentage;
	std::string Name;
};
struct Syllabus::Syllabus_a
{
	std::string item;
	bool done;
};

std::vector<Syllabus::Syllabus_a> LoadSyllabus(const std::string& filename);
void UpdateSyllabus(const std::vector<Syllabus::Syllabus_a>& Syllabus, const std::string& filename);