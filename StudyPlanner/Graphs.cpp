#include "Graphs.h"
#include "Assets.h"
#include "Assignment.h"
#include "Syllabus.h"

Graphs::Graphs(wxWindow* parent) : wxPanel(parent)
{

};

wxScrolled<wxPanel>* panel;

void Graphs::Initialize()
{
	SetBackgroundColour(THEME_COLOUR);
	panel = new wxScrolled<wxPanel>(this);
	panel->SetDoubleBuffered(true);
	panel->SetScrollRate(0, 50);
	panel->SetBackgroundColour(THEME_COLOUR);
	wxBoxSizer* graphsSizer = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText* graphsText = new wxStaticText(panel, wxID_STATIC, wxT("Progress"));
	wxFont* graphsFont = new wxFont(32, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	graphsText->SetFont(*graphsFont);
	graphsText->SetForegroundColour(TEXT_THEME_COLOUR);
	LoadAssignmentsGraph();
	LoadSyllabusGraph();
	wxGridSizer* assignmentGraphsSizer = new wxGridSizer(3, wxSize(50, 20));
	wxGridSizer* syllabusGraphsSizer = new wxGridSizer(3, wxSize(50, 20));

	wxStaticText* assignmentText = new wxStaticText(panel, wxID_STATIC, wxT("Assignment Progress"));
	assignmentText->SetFont(wxFont(wxFontInfo(24).Family(wxFONTFAMILY_SWISS).Weight(wxFONTWEIGHT_BOLD)));
	assignmentText->SetForegroundColour(TEXT_THEME_COLOUR);
	for (Pie pie : assignmentPies) {
		assignmentPieCharts.push_back(new PieChart(pie.parent, pie.data, pie.dataLabel, pie.graphLabel));
		assignmentGraphsSizer->Add(pie.parent);
	};
	wxStaticText* syllabusText = new wxStaticText(panel, wxID_STATIC, wxT("Syllabus Progress"));
	syllabusText->SetFont(wxFont(wxFontInfo(24).Family(wxFONTFAMILY_SWISS).Weight(wxFONTWEIGHT_BOLD)));
	syllabusText->SetForegroundColour(TEXT_THEME_COLOUR);
	for (Pie pie : syllabusPies) {
		syllabusPieCharts.push_back(new PieChart(pie.parent, pie.data, pie.dataLabel, pie.graphLabel));
		syllabusGraphsSizer->Add(pie.parent);
	};
	
	wxBoxSizer* tempSizer = new wxBoxSizer(wxVERTICAL);
	tempSizer->AddSpacer(20);
	tempSizer->Add(graphsText);
	tempSizer->AddSpacer(30);
	tempSizer->Add(assignmentText);
	tempSizer->AddSpacer(10);
	tempSizer->Add(assignmentGraphsSizer);
	tempSizer->AddSpacer(50);
	tempSizer->Add(syllabusText);
	tempSizer->AddSpacer(10);
	tempSizer->Add(syllabusGraphsSizer);
	panel->SetSizer(tempSizer);
	graphsSizer->Add(panel, 1, wxTOP | wxLEFT | wxEXPAND, 25);
	SetSizer(graphsSizer);
	Hide();
};

void Graphs::LoadAssignmentsGraph()
{
	std::string FileName;
	std::string ChartName;
	for (int count = 0; count < 7; count++) {
		switch (count)
		{
			case 0:
				ChartName = "DL Assignments";
				FileName = "Assignment_DL.txt";
				break;
			case 1:
				ChartName = "OOP Assignments";
				FileName = "Assignment_OOP.txt";
				break;
			case 2:
				ChartName = "EDC Assignments";
				FileName = "Assignment_EDC.txt";
				break;
			case 3:
				ChartName = "ECT Assignments";
				FileName = "Assignment_ECT.txt";
				break;
			case 4:
				ChartName = "TOC Assignments";
				FileName = "Assignment_TOC.txt";
				break;
			case 5:
				ChartName = "Math Assignments";
				FileName = "Assignment_Math.txt";
				break;
			case 6:
				ChartName = "EM Assignments";
				FileName = "Assignment_EM.txt";
				break;
			default:
				break;
		};

		std::vector<Assignment_a> assignments = LoadItem(FileName);
		Pie pie;
		float doneCount = 0;
		for (const Assignment_a& assignment : assignments) if (assignment.done) doneCount++;
		pie.parent = new RoundedRectangle(panel, wxSize(300, 300), SIDEBAR_COLOUR, THEME_COLOUR, 32);
		if (doneCount == 0) {
			pie.data = { (float)assignments.size() };
			pie.dataLabel = { "Not Done" };
		}
		else if (doneCount == (float)assignments.size()) {
			pie.data = { (float) assignments.size() };
			pie.dataLabel = { "Done" };
		}
		else {
			pie.data = { doneCount, assignments.size() - doneCount };
			pie.dataLabel = { "Done", "Not Done" };
		}
		pie.graphLabel = ChartName;
		assignmentPies.push_back(pie);
	};
};

void Graphs::LoadSyllabusGraph() 
{
	std::string FileName;
	std::string ChartName;
	for (int count = 0; count < 7; count++) {
		switch (count)
		{
		case 0:
			ChartName = "DL Syllabus";
			FileName = "Syllabus_DL.txt";
			break;
		case 1:
			ChartName = "OOP Syllabus";
			FileName = "Syllabus_OOP.txt";
			break;
		case 2:
			ChartName = "EDC Syllabus";
			FileName = "Syllabus_EDC.txt";
			break;
		case 3:
			ChartName = "ECT Syllabus";
			FileName = "Syllabus_ECT.txt";
			break;
		case 4:
			ChartName = "TOC Syllabus";
			FileName = "Syllabus_TOC.txt";
			break;
		case 5:
			ChartName = "Math Syllabus";
			FileName = "Syllabus_Math.txt";
			break;
		case 6:
			ChartName = "EM Syllabus";
			FileName = "Syllabus_EM.txt";
			break;
		default:
			break;
		};

		std::vector<Syllabus_a> syllabi = LoadSyllabus(FileName);
		Pie pie;
		float doneCount = 0;
		for (const Syllabus_a& syllabus : syllabi) if (syllabus.done) doneCount++;
		pie.parent = new RoundedRectangle(panel, wxSize(300, 300), SIDEBAR_COLOUR, THEME_COLOUR, 32);
		if (doneCount == 0) {
			pie.data = { (float)syllabi.size() };
			pie.dataLabel = { "Not Done" };
		}
		else if (doneCount == (float)syllabi.size()) {
			pie.data = { (float)syllabi.size() };
			pie.dataLabel = { "Done" };
		}
		else {
			pie.data = { doneCount, syllabi.size() - doneCount };
			pie.dataLabel = { "Done", "Not Done" };
		}
		pie.graphLabel = ChartName;
		syllabusPies.push_back(pie);
	};
}
