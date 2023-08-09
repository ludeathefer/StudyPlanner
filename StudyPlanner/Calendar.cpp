#include "Calendar.h"
#include "Assets.h"
#include "AssignmentData.h"
#include <vector>
#include <cstring>
#include <string>
#include <iostream>
#include "CalendarBuilder.h"
#include <wx/wx.h>
#include <wx/datetime.h>
#include "Task.h"
#include "RoundedRectangle.h"
#include "PieChart.h"


AssignmentData a;
CalendarBuilder cr;


wxString engdate;
wxDateTime dt;
std::vector<std::string> dates;


Calendar::Calendar(wxWindow* parent) : wxPanel(parent)
{
	/*PANELS INITIALIZATIONS START*/
	wxPanel* panel = new wxPanel(this);
	panel->SetBackgroundColour(wxColor(84, 78, 111));
	panel->SetDoubleBuffered(true);
	
	RoundedRectangle* dayinfo = new RoundedRectangle(panel, wxSize(313, 120), wxColor(44, 41, 59), wxColor(84, 78, 111), 30);

	RoundedRectangle* todopend = new RoundedRectangle(panel, wxSize(140, 140), wxColor(44, 41, 59), wxColor(84, 78, 111), 30);

	RoundedRectangle* assignpend = new RoundedRectangle(panel, wxSize(140, 140), wxColor(44, 41, 59), wxColor(84, 78, 111), 30);

	RoundedRectangle* todolist = new RoundedRectangle(panel, wxSize(271, 266), wxColor(44, 41, 59), wxColor(84, 78, 111), 30);

	RoundedRectangle* noteslist = new RoundedRectangle(panel, wxSize(271, 266), wxColor(44, 41, 59), wxColor(84, 78, 111), 30);


	//wxPanel* assignpend = new wxPanel(panel, wxID_ANY, wxDefaultPosition, wxSize(130, 130));
	//assignpend->SetBackgroundColour(wxColor(44, 41, 59));
	
	wxPanel* calendar = new wxPanel(panel, wxID_ANY, wxDefaultPosition, wxSize(650, 530));


	wxPanel* titlecontainer = new wxPanel(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize);
	titlecontainer->SetBackgroundColour(wxColor(84, 78, 111));
	/*PANEL INITIALIZATION END*/


	/*FONT INITIALIZATION START*/
	wxFont* titleFont = new wxFont(32, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxFont* nepdateFont = new wxFont(24, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	wxFont* engdateFont = new wxFont(20, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_LIGHT);
	wxFont* boxheadingFont = new wxFont(14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	wxFont* boxsubheadingFont = new wxFont(14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	wxFont* boxnumberFont = new wxFont(48, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxFont* calendarnumberFont = new wxFont(38, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_THIN);
	/*FONT INITIALIZATION END*/


	/*STATIC TEXT INITIALIZATION START*/

	wxStaticText* titleText = new wxStaticText(titlecontainer, wxID_STATIC, "Calendar", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
	titleText->SetFont(*titleFont);
	titleText->SetForegroundColour(wxColour(233, 233, 233));

	/*DAY INFO TEXTS*/
	wxStaticText* nepdateInfo = new wxStaticText(dayinfo, wxID_ANY, cr.getEqvNepaliDate(2023, 8, 8), wxPoint(10, 10), wxDefaultSize);
	nepdateInfo->SetFont(*nepdateFont);
	nepdateInfo->SetBackgroundColour(wxColor(44, 41, 59));
	nepdateInfo->SetForegroundColour(wxColour(233, 233, 233));

	wxString* engdate = new wxString();
	dt = wxDateTime::Now();
	*engdate = dt.Format(wxT("%B %d %Y"));


	wxStaticText* engdateInfo = new wxStaticText(dayinfo, wxID_ANY, *engdate, wxPoint(10, 10), wxDefaultSize);
	engdateInfo->SetFont(*engdateFont);
	engdateInfo->SetBackgroundColour(wxColor(44, 41, 59));
	engdateInfo->SetForegroundColour(wxColour(233, 233, 233));


	/*PENDING ASSIGNMENTS TEXTS*/
	wxStaticText* assignHead = new wxStaticText(assignpend, wxID_ANY, "Assignment");
	assignHead->SetFont(*boxheadingFont);
	assignHead->SetBackgroundColour(wxColor(44, 41, 59));
	assignHead->SetForegroundColour(wxColour(255, 255, 255));

	wxStaticText* assignSubhead = new wxStaticText(assignpend, wxID_ANY, "Pending");
	assignSubhead->SetFont(*boxsubheadingFont);
	assignSubhead->SetBackgroundColour(wxColor(44, 41, 59));
	assignSubhead->SetForegroundColour(wxColour(255, 94, 3));

	wxStaticText* assignNumber = new wxStaticText(assignpend, wxID_ANY, "4");
	assignNumber->SetFont(*boxnumberFont);
	assignNumber->SetBackgroundColour(wxColor(44, 41, 59));
	assignNumber->SetForegroundColour(wxColour(255, 94, 3));


	/*PENDING TODOLISTS TEXTS*/
	wxStaticText* todoHead = new wxStaticText(todopend, wxID_ANY, "To Do List");
	todoHead->SetFont(*boxheadingFont);
	todoHead->SetBackgroundColour(wxColor(44, 41, 59));
	todoHead->SetForegroundColour(wxColour(255, 255, 255));

	wxStaticText* todoSubhead = new wxStaticText(todopend, wxID_ANY, "Incomplete");
	todoSubhead->SetFont(*boxsubheadingFont);
	todoSubhead->SetBackgroundColour(wxColor(44, 41, 59));
	todoSubhead->SetForegroundColour(wxColour(255, 94, 3));

	wxStaticText* todoNumber = new wxStaticText(todopend, wxID_ANY, "1");
	todoNumber->SetFont(*boxnumberFont);
	todoNumber->SetBackgroundColour(wxColor(44, 41, 59));
	todoNumber->SetForegroundColour(wxColour(255, 94, 3));


	wxStaticText* todolistHead = new wxStaticText(todolist, wxID_ANY, "To Do List");
	todolistHead->SetFont(*boxheadingFont);
	todolistHead->SetBackgroundColour(wxColor(44, 41, 59));
	todolistHead->SetForegroundColour(wxColour(255, 255, 255));

	/*STATIC TEXT INITIALIZATION END*/


	todocheckListBox = new wxCheckListBox(todolist, wxID_ANY, wxDefaultPosition, wxSize(330, 400), 0, NULL, wxNO_BORDER);
	todocheckListBox->UseForegroundColour();
	todocheckListBox->SetBackgroundColour(wxColor(44, 41, 59));



	/*SIZERS INITIALIZATION START*/
	wxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	mainSizer->Add(panel, 2, wxEXPAND | wxALL, 2);

	wxSizer* panelSizer = new wxBoxSizer(wxHORIZONTAL);
	wxSizer* taskSizer = new wxBoxSizer(wxVERTICAL);
	wxSizer* calenSizer = new wxBoxSizer(wxVERTICAL);
	wxSizer* dateSizer = new wxBoxSizer(wxHORIZONTAL);
	wxSizer* demoSizer = new wxBoxSizer(wxHORIZONTAL);
	wxSizer* dateinfoSizer = new wxBoxSizer(wxVERTICAL);
	wxSizer* assignpendSizer = new wxBoxSizer(wxVERTICAL);
	wxSizer* todopendSizer = new wxBoxSizer(wxVERTICAL);
	wxSizer* calendarcontentSizer = new wxGridSizer(6, 7, 0, 0);
	wxSizer* todolistSizer = new wxBoxSizer(wxVERTICAL);
	/*SIZERS INITIALIZATION END*/


	panelSizer->AddSpacer(50);
	panelSizer->Add(calenSizer, 3, wxEXPAND | wxTOP, 40);
	panelSizer->AddSpacer(50);
	panelSizer->Add(taskSizer, 1, wxEXPAND | wxTOP, 40);

	calenSizer->Add(dateSizer, 1, wxEXPAND | wxALL, 5);
	calenSizer->Add(demoSizer, 4.5, wxEXPAND | wxALL, 5);
	demoSizer->AddSpacer(5);
	demoSizer->Add(calendar, 4.5, wxEXPAND | wxALL, 5);


	taskSizer->Add(todolist, 1, wxEXPAND | wxALL, 40);
	taskSizer->Add(noteslist, 1, wxEXPAND | wxALL, 40);

	dateSizer->AddSpacer(30);
	dateSizer->Add(titlecontainer, wxSizerFlags().Bottom());
	dateSizer->AddSpacer(50);
	dateSizer->Add(dayinfo, 1, wxALL, 5);
	dateSizer->Add(todopend, 0, wxALL, 5);
	dateSizer->Add(assignpend, 0, wxALL, 5);

	dateinfoSizer->Add(nepdateInfo, 1, wxCenter | wxLEFT | wxTOP, 18);
	dateinfoSizer->AddSpacer(10);
	dateinfoSizer->Add(engdateInfo, 1, wxCenter | wxLEFT | wxBOTTOM, 18);

	todolistSizer->Add(todolistHead, 1, wxEXPAND | wxLEFT | wxTOP, 18);
	todolistSizer->Add(todocheckListBox, 4, wxEXPAND | wxALL, 20);


	assignpendSizer->Add(assignHead, 0, wxCENTER | wxTOP, 15);
	assignpendSizer->Add(assignSubhead, 0, wxCENTER | wxALL, 2);
	assignpendSizer->Add(assignNumber, 0, wxCENTER | wxBOTTOM, 15);

	todopendSizer->Add(todoHead, 0, wxCENTER | wxTOP, 15);
	todopendSizer->Add(todoSubhead, 0, wxCENTER | wxALL, 2);

	todopendSizer->Add(todoNumber, 0, wxCENTER | wxBOTTOM, 15);
	int color = 10;
	int size = 60;

	for (unsigned i = 0; i < 7; i++) {
		wxStaticText* calendardayText = new wxStaticText(calendar, wxID_ANY, cr.getDays()[i], wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
		calendardayText->SetFont(*nepdateFont);
		calendardayText->SetForegroundColour(*wxWHITE);
		calendarcontentSizer->Add(calendardayText, 1, wxEXPAND | wxALIGN_BOTTOM);
		color = color += 40;
	}

	size = 102;
	int count = 0;
	for (unsigned i = 0; i < 5; i++) {
		for (unsigned j = 0; j < 7; j++) {


			calendardateText[count] = new wxButton(calendar, count + 2, cr.getDates()[count],
				wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT | wxTop);
			calendardateText[count]->SetFont(*calendarnumberFont);
			(j == 6) ? calendardateText[count]->SetForegroundColour(wxColor("#dd403a")) : calendardateText[count]->SetForegroundColour(*wxWHITE);

			(strcmp(dt.Format(std::string("%d")).c_str(), cr.getDates()[count].c_str()) == 0)
				? calendardateText[count]->SetBackgroundColour(wxColor(178, 80, 34))
				: calendardateText[count]->SetBackgroundColour(wxColor(84, 78, 111));

			calendardateText[count]->Bind(wxEVT_LEFT_DOWN, [this, count](wxMouseEvent& evt) {
				onCalendarText(evt, count);
				});
			calendarcontentSizer->Add(calendardateText[count], 0, wxEXPAND | wxALL, 10);

			count++;

		}
	}


	taskSizer->Layout();
	calenSizer->Layout();
	dateSizer->Layout();
	panelSizer->Layout();
	this->SetSizerAndFit(mainSizer);
	panel->SetSizer(panelSizer);
	dayinfo->SetSizerAndFit(dateinfoSizer);
	todopend->SetSizer(todopendSizer);
	assignpend->SetSizer(assignpendSizer);
	calendar->SetSizer(calendarcontentSizer);
	todolist->SetSizer(todolistSizer);


	//	this->Bind(wxEVT_CLOSE_WINDOW, &Calendar::onWindowClosed, this);

	AddSavedTasks();
	assignNumber->SetLabel(std::to_string((a.pendingassignmentsCount("assignments.txt").at(1))));
	todoNumber->SetLabel(std::to_string((pendingtaskCount("tasks.txt").at(1))));

}

Calendar::~Calendar()
{
	for (int i = 0; i < 35; i++) {
		delete[] calendardateText[i];
	}
}

void Calendar::Initialize()
{
/*	SetBackgroundColour(THEME_COLOUR);
	wxBoxSizer* calendarSizer = new wxBoxSizer(wxVERTICAL);
	wxStaticText* calendarText = new wxStaticText(this, wxID_STATIC, wxT("Calendar"));
	wxFont* calendarFont = new wxFont(72, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_SEMIBOLD);
	calendarText->SetFont(*calendarFont);
	calendarText->SetForegroundColour(TEXT_THEME_COLOUR);
	wxBoxSizer* tempSizer = new wxBoxSizer(wxHORIZONTAL);
	tempSizer->Add(calendarText, 0, wxALIGN_CENTER);
	calendarSizer->Add(tempSizer, 1, wxALIGN_CENTER);
	SetSizer(calendarSizer);
	*/
	Hide();
}


void Calendar::AddSavedTasks()
{
	Task t;
	std::vector<Task> tasks = loadTasksFromFile("tasks.txt", dt.Format(wxT("%d/%m/%y")).ToStdString());

	for (const Task& task : tasks) {
		int index = todocheckListBox->GetCount();

		engdate = task.date;
		wxFont* boxtextFont = new wxFont(11, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
		dates.push_back(engdate.ToStdString());
		todocheckListBox->Insert(task.description, index);
		todocheckListBox->Check(index, task.done);
		todocheckListBox->GetItem(index)->SetTextColour(wxColor(255, 255, 255));
		todocheckListBox->GetItem(index)->SetFont(*boxtextFont);
		index = index + 1;
		todocheckListBox->Layout();

	}


}

void Calendar::AddSavedTasks(int pra)
{

	std::vector<Task> tasks = loadTasksFromFile("tasks.txt", (calendardateText[pra]->GetLabelText().ToStdString() + dt.Format(wxT("/%m/%y")).ToStdString()));

	//int index = todocheckListBox->GetCount();
	todocheckListBox->Clear();
	int index = 0;
	for (const Task& task : tasks) {

		//int index = todocheckListBox->GetCount();

		engdate = task.date;
		wxFont* boxtextFont = new wxFont(11, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
		todocheckListBox->Insert(task.description, index);
		todocheckListBox->Check(index, task.done);
		todocheckListBox->GetItem(index)->SetTextColour(wxColor(255, 255, 255));
		todocheckListBox->GetItem(index)->SetFont(*boxtextFont);
		index = index + 1;
		todocheckListBox->Layout();

	}


}




void Calendar::onCalendarText(wxMouseEvent& evt, int pra) {


	for (int i = 0; i < 35; i++) {
		calendardateText[i]->SetBackgroundColour(wxColor(84, 78, 111));
		calendardateText[i]->SetForegroundColour(*wxWHITE);
		(strcmp(dt.Format(std::string("%d")).c_str(), cr.getDates()[i].c_str()) == 0) ? calendardateText[i]->SetBackgroundColour(wxColor(178, 80, 34)) : calendardateText[i]->SetBackgroundColour(wxColor(84, 78, 111));
		(!((i + 1) % 7)) ? calendardateText[i]->SetForegroundColour(wxColor("#dd403a")) : calendardateText[i]->SetForegroundColour(*wxWHITE);

	}
	((pra + 1) % 7) ? calendardateText[pra]->SetForegroundColour(*wxWHITE) : calendardateText[pra]->SetForegroundColour(*wxWHITE);
	calendardateText[pra]->SetBackgroundColour(wxColor("#a4303f"));
	todocheckListBox->Clear();
	AddSavedTasks(pra);

}

