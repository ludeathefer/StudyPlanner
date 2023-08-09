#include "Dashboard.h"
#include "Assets.h"
#include "RoundedRectangle.h"
#include "PieChart.h"
#include <wx/wx.h>
#include <wx/datetime.h>
#include <vector>
#include <cstring>
#include "AssignmentData.h"
#include "Task.h"
#include "Dummies.h"

Dashboard::Dashboard(wxWindow* parent) : wxPanel(parent) 
{

	AssignmentData a;
	SyllabusData s;
	RevisionData r;
	ClassRoutine c;

	/*PANELS INITIALIZATIONS START*/
	wxPanel* panel = new wxPanel(this);
	panel->SetBackgroundColour(wxColor(84, 78, 111));
	wxPanel* assigninfo = new wxPanel(panel, wxID_ANY, wxDefaultPosition, wxSize(220, 148));
	assigninfo->SetBackgroundColour(wxColor(44, 41, 59));
	wxPanel* todoinfo = new wxPanel(panel, wxID_ANY, wxDefaultPosition, wxSize(220, 148));
	todoinfo->SetBackgroundColour(wxColor(44, 41, 59));
	auto classroutine = new wxScrolled<wxPanel>(panel, wxID_ANY, wxDefaultPosition, wxSize(600, 325));
	classroutine->SetBackgroundColour(wxColor(44, 41, 59));
	auto revisionprog = new wxScrolled<wxPanel>(panel, wxID_ANY, wxDefaultPosition, wxSize(420, 250));
	revisionprog->SetBackgroundColour(wxColor(44, 41, 59));
	auto syllabusprog = new wxScrolled<wxPanel>(panel, wxID_ANY, wxDefaultPosition, wxSize(420, 250));
	syllabusprog->SetBackgroundColour(wxColor(44, 41, 59));

	classroutine->SetScrollRate(0, FromDIP(10));
	revisionprog->SetScrollRate(0, FromDIP(10));
	revisionprog->ShowScrollbars(wxSHOW_SB_NEVER, wxSHOW_SB_NEVER);
	syllabusprog->SetScrollRate(0, 10);
	classroutine->ShowScrollbars(wxSHOW_SB_NEVER, wxSHOW_SB_NEVER);

	/*PANEL INITIALIZATION END*/



	/*FONT INITIALIZATION START*/
	wxFont* titleFont = new wxFont(32, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxFont* boxheadingFont = new wxFont(15, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	wxFont* boxsubheadingFont = new wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	wxFont* boxtextFont = new wxFont(13, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	wxFont* boxnumberFont = new wxFont(15, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	wxFont* completednumFont = new wxFont(24, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxFont* pendingnumFont = new wxFont(24, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

	/*FONT INITIALIZATION END*/

	/*STATIC TEXT INITIALIZATION START*/

	wxStaticText* titleText = new wxStaticText(panel, wxID_STATIC, "Main Page", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
	titleText->SetFont(*titleFont);
	titleText->SetForegroundColour(wxColour(233, 233, 233));

	wxStaticText* syllabusTitle = new wxStaticText(syllabusprog, wxID_STATIC, "Syllabus Progress", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
	syllabusTitle->SetFont(*boxheadingFont);
	syllabusTitle->SetForegroundColour(wxColour(233, 233, 233));

	wxStaticText* routineTitle = new wxStaticText(classroutine, wxID_STATIC, "Class Routine", wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
	routineTitle->SetFont(*boxheadingFont);
	routineTitle->SetForegroundColour(wxColour(233, 233, 233));
	wxStaticText* routineBlank = new wxStaticText(classroutine, wxID_STATIC, "", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);

	wxStaticText* revisionTitle = new wxStaticText(revisionprog, wxID_STATIC, "Revision Progress", wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
	revisionTitle->SetFont(*boxheadingFont);
	revisionTitle->SetForegroundColour(wxColour(233, 233, 233));
	wxStaticText* revisionBlank = new wxStaticText(revisionprog, wxID_STATIC, "", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);




	wxStaticText* todoTitle = new wxStaticText(todoinfo, wxID_STATIC, "", wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
	todoTitle->SetFont(*boxheadingFont);
	todoTitle->SetForegroundColour(wxColour(233, 233, 233));

	wxStaticText* todoSubhead = new wxStaticText(todoinfo, wxID_STATIC, "", wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
	todoSubhead->SetFont(*boxsubheadingFont);
	todoSubhead->SetForegroundColour(wxColour(233, 233, 233));

	wxStaticText* todoCompleted = new wxStaticText(todoinfo, wxID_STATIC, "", wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
	todoCompleted->SetFont(*boxsubheadingFont);
	todoCompleted->SetForegroundColour(wxColour(233, 233, 233));

	wxStaticText* todoPending = new wxStaticText(todoinfo, wxID_STATIC, "", wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
	todoPending->SetFont(*boxsubheadingFont);
	todoPending->SetForegroundColour(wxColour(233, 233, 233));

	wxStaticText* todocompNum = new wxStaticText(todoinfo, wxID_STATIC, "", wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
	todocompNum->SetFont(*completednumFont);
	todocompNum->SetForegroundColour(wxColour(233, 233, 233));

	wxStaticText* todopendNum = new wxStaticText(todoinfo, wxID_STATIC, "", wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
	todopendNum->SetFont(*pendingnumFont);
	todopendNum->SetForegroundColour(wxColour(255, 94, 3));
	wxStaticText* todoBlank = new wxStaticText(todoinfo, wxID_STATIC, "", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
	wxStaticText* todoBlank1 = new wxStaticText(todoinfo, wxID_STATIC, "", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
	wxStaticText* todoBlank2 = new wxStaticText(todoinfo, wxID_STATIC, "", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
	wxStaticText* todoBlank3 = new wxStaticText(todoinfo, wxID_STATIC, "", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);




	wxStaticText* assignmentTitle = new wxStaticText(assigninfo, wxID_STATIC, "", wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
	assignmentTitle->SetFont(*boxheadingFont);
	assignmentTitle->SetForegroundColour(wxColour(233, 233, 233));

	wxStaticText* assignmentSubhead = new wxStaticText(assigninfo, wxID_STATIC, "", wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
	assignmentSubhead->SetFont(*boxsubheadingFont);
	assignmentSubhead->SetForegroundColour(wxColour(233, 233, 233));

	wxStaticText* assignmentCompleted = new wxStaticText(assigninfo, wxID_STATIC, "", wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
	assignmentCompleted->SetFont(*boxsubheadingFont);
	assignmentCompleted->SetForegroundColour(wxColour(233, 233, 233));

	wxStaticText* assignmentPending = new wxStaticText(assigninfo, wxID_STATIC, "", wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
	assignmentPending->SetFont(*boxsubheadingFont);
	assignmentPending->SetForegroundColour(wxColour(233, 233, 233));

	wxStaticText* assigncompNum = new wxStaticText(assigninfo, wxID_STATIC, "", wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
	assigncompNum->SetFont(*completednumFont);
	assigncompNum->SetForegroundColour(wxColour(233, 233, 233));

	wxStaticText* assignpendNum = new wxStaticText(assigninfo, wxID_STATIC, "", wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
	assignpendNum->SetFont(*pendingnumFont);
	assignpendNum->SetForegroundColour(wxColour(255, 94, 3));
	wxStaticText* assignBlank = new wxStaticText(assigninfo, wxID_STATIC, "", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
	wxStaticText* assignBlank1 = new wxStaticText(assigninfo, wxID_STATIC, "", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
	wxStaticText* assignBlank2 = new wxStaticText(assigninfo, wxID_STATIC, "", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
	wxStaticText* assignBlank3 = new wxStaticText(assigninfo, wxID_STATIC, "", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);

	/*STATIC TEXT INITIALIZATION END*/


	/*SIZERS INITIALIZATION START*/
	wxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	mainSizer->Add(panel, 2, wxEXPAND);

	wxSizer* panelSizer = new wxBoxSizer(wxVERTICAL);
	wxSizer* infoSizer = new wxBoxSizer(wxHORIZONTAL);
	wxSizer* progSizer = new wxBoxSizer(wxHORIZONTAL);
	wxSizer* pendSizer = new wxBoxSizer(wxVERTICAL);
	wxSizer* syllabusSizer = new wxGridSizer(16, 1, 10, 10);

	const int cols = 2;
	const int routineRows = 9;
	const int revisionRows = 8;
	const int smallboxRows = 5;

	auto assigninfoSizer = new wxGridSizer(smallboxRows, cols, FromDIP(2), FromDIP(2));
	auto todoinfoSizer = new wxGridSizer(smallboxRows, cols, FromDIP(2), FromDIP(2));
	auto routineSizer = new wxGridSizer(routineRows, cols, 10, 5);
	auto revisionSizer = new wxGridSizer(revisionRows	, cols, 5, 5);
	/*SIZERS INITIALIZATION END*/


	panelSizer->AddSpacer((0, 30));
	panelSizer->Add(titleText, 1, wxLeft | wxLEFT, 50);
	panelSizer->Add(infoSizer, 5, wxALL, 10);
	panelSizer->Add(progSizer, 5, wxALL, 10);

	infoSizer->Add(pendSizer, 1, wxALL, 15);
	infoSizer->AddSpacer((20, 0));
	infoSizer->Add(classroutine, 2.5, wxTOP, 30);

	pendSizer->Add(assigninfo, 1, wxALL, 15);
	pendSizer->Add(todoinfo, 1, wxALL, 15);

	progSizer->AddSpacer(16);
	progSizer->Add(revisionprog, 1, wxALL, 15);
	progSizer->Add(syllabusprog, 1, wxALL, 15);

	syllabusSizer->Add(syllabusTitle, 1, wxALL | wxLeft, FromDIP(8));

	int count = 0;
	for (int i = 5; i < 12; i++) {
		wxStaticText* bodytext = new wxStaticText(syllabusprog, i, s.subjects[count]);
		bodytext->SetFont(*boxtextFont);
		bodytext->SetForegroundColour(wxColor(255, 255, 255));
		wxGauge* proggauge = new wxGauge(syllabusprog, i, 100);
		proggauge->SetValue(s.completion[count]);
		syllabusSizer->Add(bodytext, 1, wxLEFT | wxLeft, 10);
		syllabusSizer->Add(proggauge, 1, wxEXPAND | wxLEFT | wxLeft, 10);
		if (count == 6) count = 0;
		count++;

	}


	wxDateTime* dt = new wxDateTime();
	*dt = wxDateTime::Now();
	int dayin = 0;

	routineSizer->Add(routineTitle, 0, wxEXPAND | wxLEFT | wxTOP | wxLEFT, 5);
	routineSizer->Add(routineBlank, 0, wxEXPAND | wxLEFT | wxTOP | wxLeft, 10);
	count = 0;
	for (int i = 2; i < routineRows + 1; i++) {
		for (int j = 2; j < cols + 2; j++) {
			auto classtimeText = new wxStaticText(classroutine, wxID_STATIC, "", wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
			auto routinesubjectText = new wxStaticText(classroutine, wxID_STATIC, "", wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
			strcmp(dt->Format(wxT("%a")).c_str(), "Sun") == 0 ? dayin = 0 : dayin = 0;
			strcmp(dt->Format(wxT("%a")).c_str(), "Mon") == 1 ? dayin = 1 : dayin = 0;
			strcmp(dt->Format(wxT("%a")).c_str(), "Tue") == 2 ? dayin = 2 : dayin = 0;
			strcmp(dt->Format(wxT("%a")).c_str(), "Wed") == 3 ? dayin = 3 : dayin = 0;
			strcmp(dt->Format(wxT("%a")).c_str(), "Thu") == 4 ? dayin = 4 : dayin = 0;
			strcmp(dt->Format(wxT("%a")).c_str(), "Fri") == 5 ? dayin = 5 : dayin = 0;
			strcmp(dt->Format(wxT("%a")).c_str(), "Sat") == 6 ? dayin = 6 : dayin = 0;

			switch (j) {
			case 2:
				classtimeText->SetFont(*boxtextFont);
				classtimeText->SetForegroundColour(wxColour(215, 191, 177));
				classtimeText->SetLabel(c.Routine[dayin][count][0]);
				routineSizer->Add(classtimeText, 0, wxEXPAND | wxLEFT | wxTOP | wxLeft, 10);
				break;
			case 3:
				routinesubjectText->SetFont(*boxtextFont);
				routinesubjectText->SetForegroundColour(wxColour(255, 255, 255));
				routinesubjectText->SetLabel(c.Routine[dayin][count][1]);
				routineSizer->Add(routinesubjectText, 0, wxEXPAND | wxRIGHT | wxTOP | wxRight, 10);
				break;
			}
		}
		count++;
		if (count == 5) count = 0;
	}

	revisionSizer->Add(revisionTitle, 0, wxEXPAND | wxLEFT | wxTOP | wxLEFT, 5);
	revisionSizer->Add(revisionBlank, 0, wxEXPAND | wxLEFT | wxTOP | wxLeft, 5);

	count = 0;
	for (int i = 2; i < revisionRows + 1; i++) {
		for (int j = 2; j < cols + 2; j++) {
			auto revisionSubject = new wxStaticText(revisionprog, wxID_STATIC, "", wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
			auto revCompletion = new wxStaticText(revisionprog, wxID_STATIC, "", wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);

			switch (j) {
			case 2:
				revisionSubject->SetFont(*boxtextFont);
				revisionSubject->SetForegroundColour(wxColour(255, 255, 255));
				revisionSubject->SetLabel(r.subjects[count]);
				revisionSizer->Add(revisionSubject, 0, wxEXPAND | wxLEFT | wxTOP | wxLeft, 5);
				break;
			case 3:
				revCompletion->SetFont(*boxtextFont);
				revCompletion->SetForegroundColour(wxColour(255, 94, 3));
				revCompletion->SetLabel((r.completion[count]));
				revisionSizer->Add(revCompletion, 0, wxEXPAND | wxRIGHT | wxTOP | wxRight, 5);
				break;
			}
			if (count == 6) { count = 0; }
			else { count++; }
		}
	}

	assignmentTitle->SetLabel("Assignments");
	assigninfoSizer->Add(assignmentTitle, 0, wxEXPAND | wxLeft | wxLEFT, 5);
	assigninfoSizer->Add(assignBlank, 0, wxEXPAND | wxRight | wxRIGHT, 0);
	assignmentSubhead->SetLabel("This week");
	assigninfoSizer->Add(assignmentSubhead, 0, wxEXPAND | wxLeft | wxLEFT, 5);
	assigninfoSizer->Add(assignBlank1, 0, wxEXPAND | wxRight | wxRIGHT, 5);
	assigninfoSizer->Add(assignBlank2, 0, wxEXPAND | wxRight | wxRIGHT, 5);
	assigninfoSizer->Add(assignBlank3, 0, wxEXPAND | wxRight | wxRIGHT, 5);
	assigncompNum->SetLabel("13");
	assigninfoSizer->Add(assigncompNum, 0, wxEXPAND | wxLEFT | wxLeft | wxTop, 5);
	assignpendNum->SetLabel("5");
	assigninfoSizer->Add(assignpendNum, 0, wxEXPAND | wxRIGHT | wxRight | wxTop, 5);
	assignmentCompleted->SetLabel("Completed");
	assigninfoSizer->Add(assignmentCompleted, 0, wxEXPAND | wxRIGHT | wxRight | wxBottom, 5);
	assignmentPending->SetLabel("Pending");
	assigninfoSizer->Add(assignmentPending, 0, wxEXPAND | wxLEFT | wxLeft | wxBottom, 5);



	todoTitle->SetLabel("To Dos");
	todoinfoSizer->Add(todoTitle, 0, wxEXPAND | wxLeft | wxLEFT, 5);
	todoinfoSizer->Add(todoBlank, 0, wxEXPAND | wxRight | wxRIGHT, 0);
	todoSubhead->SetLabel("This week");
	todoinfoSizer->Add(todoSubhead, 0, wxEXPAND | wxLeft | wxLEFT, 5);
	todoinfoSizer->Add(todoBlank1, 0, wxEXPAND | wxRight | wxRIGHT, 5);
	todoinfoSizer->Add(todoBlank2, 0, wxEXPAND | wxRight | wxRIGHT, 5);
	todoinfoSizer->Add(todoBlank3, 0, wxEXPAND | wxRight | wxRIGHT, 5);
	todocompNum->SetLabel("7");
	todoinfoSizer->Add(todocompNum, 0, wxEXPAND | wxLEFT | wxLeft | wxTop, 5);
	todopendNum->SetLabel("10");
	todoinfoSizer->Add(todopendNum, 0, wxEXPAND | wxRIGHT | wxRight | wxTop, 5);
	todoCompleted->SetLabel("Completed");
	todoinfoSizer->Add(todoCompleted, 0, wxEXPAND | wxRIGHT | wxRight | wxBottom, 5);
	todoPending->SetLabel("Pending");
	todoinfoSizer->Add(todoPending, 0, wxEXPAND | wxLEFT | wxLeft | wxBottom, 5);



	this->SetSizer(mainSizer);
	panel->SetSizerAndFit(panelSizer);
	syllabusprog->SetSizer(syllabusSizer);
	classroutine->SetSizer(routineSizer);
	revisionprog->SetSizer(revisionSizer);
	assigninfo->SetSizer(assigninfoSizer);
	todoinfo->SetSizer(todoinfoSizer);


	assigncompNum->SetLabel(std::to_string((a.pendingassignmentsCount("assignments.txt").at(0)) - a.pendingassignmentsCount("assignments.txt").at(1)));
	assignpendNum->SetLabel(std::to_string((a.pendingassignmentsCount("assignments.txt").at(1))));

	todocompNum->SetLabel(std::to_string((pendingtaskCount("tasks.txt").at(0)) - pendingtaskCount("tasks.txt").at(1)));
	todopendNum->SetLabel(std::to_string((pendingtaskCount("tasks.txt").at(1))));


	Hide();


}

void Dashboard::Initialize()
{
	//Pie Chart Demonstration
	//std::vector <float> data = { 20, 10, 5, 25, 10, 20, 7, 3 };
	//PieChart* round = new PieChart(this, 100, THEME_COLOUR, data);
	 
	/*
	//Rounded Rectangle Demonstration
	RoundedRectangle* round = new RoundedRectangle(this, wxSize(300, 300), SIDEBAR_COLOUR, THEME_COLOUR, 10);
	wxFont* round1Font = new wxFont(24, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxFont* round2Font = new wxFont(18, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	wxStaticText* roundText1 = new wxStaticText(round, wxID_STATIC, wxT("Assignments"));
	roundText1->SetBackgroundColour(SIDEBAR_COLOUR);
	roundText1->SetForegroundColour(TEXT_THEME_COLOUR);
	roundText1->SetFont(*round1Font);
	wxStaticText* roundText2 = new wxStaticText(round, wxID_STATIC, wxT("This Week"));
	roundText2->SetBackgroundColour(SIDEBAR_COLOUR);
	roundText2->SetForegroundColour(TEXT_THEME_COLOUR);
	roundText2->SetFont(*round2Font);
	wxBoxSizer* roundSizer = new wxBoxSizer(wxVERTICAL);
	roundSizer->Add(roundText1, 0, wxTOP | wxLEFT, 10);
	roundSizer->Add(roundText2, 0, wxLEFT, 10);
	round->SetSizer(roundSizer);

	SetBackgroundColour(THEME_COLOUR);
	wxBoxSizer* dashboardSizer = new wxBoxSizer(wxVERTICAL);
	wxStaticText* dashboardText = new wxStaticText(this, wxID_STATIC, wxT("Dashboard"));
	wxFont* dashboardFont = new wxFont(72, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_SEMIBOLD);
	dashboardText->SetFont(*dashboardFont);
	dashboardText->SetForegroundColour(TEXT_THEME_COLOUR);
	wxBoxSizer* tempSizer = new wxBoxSizer(wxHORIZONTAL);
	tempSizer->Add(dashboardText, 0, wxALIGN_CENTER);
	tempSizer->Add(round, 0, wxLEFT | wxALIGN_CENTER, 40);
	dashboardSizer->Add(tempSizer, 1, wxALIGN_CENTER);
	SetSizer(dashboardSizer);
	Hide();
	*/





}