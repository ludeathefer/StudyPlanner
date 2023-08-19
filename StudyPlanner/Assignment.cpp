#include "Assignment.h"
#include <wx/wx.h>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <algorithm>
#include "RoundedRectangle.h"
#include<wx/gbsizer.h>
#include<wx/datectrl.h>


/*
OnClose event halera garna baaki xa. User le tick gareko save hudaina aile
*/

Assignment_b::Assignment_b()
{

}

Assignment_b::Assignment_b(wxWindow* parent):wxPanel(parent)
{
}
void Assignment_b::Initialize()
{
	wxPanel* panel_main = new wxPanel();
	wxBoxSizer* mainBox;
	wxBoxSizer* mainBox2;
	Assignment_b dummy;
	mainBox2 = new wxBoxSizer(wxHORIZONTAL);
	Assignment* assignment_a_a;
	mainBox = new wxBoxSizer(wxVERTICAL);
	SetBackgroundColour(wxColour(84, 78, 111));
	assignment_a_a = new Assignment(this);
	//panel_main
	//mainBox2->Add(assignment_a_a);
	mainBox2->Add(assignment_a_a,1,wxEXPAND);
	mainBox->Add(mainBox2,1,wxEXPAND);
	//assignment_a_a->Initialize();
	this->SetSizerAndFit(mainBox);
	Hide();

}

Assignment::Assignment(wxWindow* parent) : wxPanel(parent)
{
	const auto margin = FromDIP(10);
	auto mainsizer = new wxBoxSizer(wxVERTICAL);
	wxFont headLineFont(wxFontInfo(wxSize(0, 40)).Bold());
	auto* panel = new wxScrolled<wxPanel>(this, wxID_ANY,wxDefaultPosition, wxSize(800,800));// , wxDefaultPosition, wxDefaultSize, wxEXPAND | wxALL);
	panel->SetBackgroundColour(wxColor(84, 78, 111));
	panel->SetScrollRate(0, FromDIP(10));
	this->SetBackgroundColour(panel->GetBackgroundColour());
	auto sizer = new wxGridBagSizer(margin, margin);

	auto MainTitle = new wxStaticText(panel, wxID_ANY, "ASSIGNMENTS");
	
	int count = 0;
	sizer->Add(MainTitle, { 0,0 }, { 1,3 });
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 2; j++) 
			{
			if (count < 7)
			{
				auto BoxArray = new RoundedRectangle(panel, wxSize(400, 220), wxColor(44,41,59), wxColor(84, 78, 111), 30);
				//auto DialogPanel = new wxPanel(BoxArray);
				sizer->Add(BoxArray, { i + 1,j }, { 1,1 });

				auto MainSizer = new wxBoxSizer(wxVERTICAL);
				auto TitleAndButton = new wxBoxSizer(wxVERTICAL);
				auto Title = new wxBoxSizer(wxHORIZONTAL);
				auto Button = new wxBoxSizer(wxHORIZONTAL);
				auto CheckBox = new wxBoxSizer(wxHORIZONTAL);

				switch (count)
				{
				case 0:
					DisplayTitle = "Digital Logic";
					break;
				case 1:
					DisplayTitle = "Object Oriented Programming";
					break;
				case 2:
					DisplayTitle = "Electronics Devices and Circuits";
					break;
				case 3:
					DisplayTitle = "Electrical Circuits Theory";
					break;
				case 4:
					DisplayTitle = "Theory of Computation";
					break;
				case 5:
					DisplayTitle = "Mathematics III";
					break;
				case 6:
					DisplayTitle = "Electromagnetics";
					break;
				}

				wxFont TitleFont(wxFontInfo(wxSize(0, 20)).Bold());
				auto TitleDisplay = new wxStaticText(BoxArray, wxID_ANY, DisplayTitle, wxPoint(20, 10), wxSize(200, 30));
				TitleDisplay->SetFont(TitleFont);
				Title->Add(TitleDisplay);

				AddButton[count] = new wxButton(BoxArray, wxID_ANY, "+", wxPoint(355, 10), wxSize(25, 25));
				AddButton[count]->SetBackgroundColour(wxColor(84, 78, 111));
				Button->Add(AddButton[count]);

				CheckListBox[count] = new wxCheckListBox(BoxArray, wxID_ANY, wxPoint(20,50), wxSize(360,150));//, wxALIGN_BOTTOM);// | wxALIGN_CENTER);

						TitleAndButton->Add(Title);
						TitleAndButton->Add(Button);

						CheckBox->Add(CheckListBox[count]);

						MainSizer->Add(TitleAndButton);
						MainSizer->Add(CheckBox);

						//BoxArray->SetSizer(MainSizer);

						BindEventHandlers(count);

						count++;

					}
			}
	}

	MainTitle->SetBackgroundColour(wxColor(84, 78, 0));
	MainTitle->SetForegroundColour(wxColor(10, 100, 200));
	MainTitle->SetFont(headLineFont);

	AddSavedTasks();


	

	
	panel->SetSizer(sizer);
	mainsizer->Add(panel,0, wxEXPAND | wxALL, margin);
	this->SetSizerAndFit(mainsizer);
	Hide();
}


//		void Assignment::Initialize()
//		{
//			Hide();
	



			/* 
			ElementsVisible = true;
			SetBackgroundColour(wxColour(84,78,111));	
			wxFont headLineFont(wxFontInfo(wxSize(0, 40)).Bold());
	

			auto panel = new wxScrolled<wxPanel>(this, wxID_ANY,wxDefaultPosition,wxSize(400,100));
			panel->SetScrollRate(0, FromDIP(10));
			auto sizer = new wxBoxSizer(wxVERTICAL);
			panel->SetSizer(sizer);
			//wxSizer* Cotainer = new wxGridSizer(4, 2, 0, 0);


			//SetScrollbar(wxVERTICAL, 0, 16, 100);

	
			//wxPanel* panel1 = new wxPanel(this,wxEXPAND);
		//	RoundedRectangle* boxx = new RoundedRectangle(panel1, wxSize(200, 200), *wxRED, *wxBLUE, 30);
			TitleText = new wxStaticText(panel, wxID_ANY, "Assignments",
				wxPoint(40, 30), wxSize(800, 50));// , wxALIGN_LEFT);
	
			TitleText->SetFont(headLineFont);
			TitleText->SetForegroundColour(*wxBLUE);

		//	wxBoxSizer* box = new wxBoxSizer(wxHORIZONTAL);
			//wxBoxSizer* box2 = new wxBoxSizer(wxVERTICAL);
			//box2->Add(this, 1, wxEXPAND);
			//box->Add(box2, 0, wxEXPAND);
			//boxx-> SetSizerAndFit(box);

			CreateControls();
			AddSavedTasks();
			Hide();
			//panel1->SetSizer(box);
			//panel1->SetSizer(box);

			//wxPanel* contents = new wxPanel(this, wxID_ANY);

			*/
//		}
		
		



void Assignment::BindEventHandlers(int a)
{
	int j = a;
	int pra = j;
	//AddAssignmentDialog AddDialog(parent);

	AddButton[j]->Bind(wxEVT_BUTTON, [this, pra](wxCommandEvent& evt) {
		OnAddButtonClicked(evt, pra);
		});
	//AddAssignmentDialog AddDialog;
	/*
	AddButton[j]->Bind(wxEVT_BUTTON, [this,pra](wxCommandEvent& evt) {_OnAddButtonClicked(evt, pra); });//, AddButton[j]->GetId());
	*/
	CheckListBox[j]->Bind(wxEVT_KEY_DOWN, [this, j](wxKeyEvent& evt) {OnListKeyDown(evt,j); });
	RemoveInputFields();
}


void Assignment::OnAddButtonClicked(wxCommandEvent& evt, int pra)
{
	CallInputFields(pra);
}


void Assignment::OnListKeyDown(wxKeyEvent& evt, int j)
{
	switch (evt.GetKeyCode()) {
	case WXK_DELETE:
		DeleteSelectedTask(j);
		break;
	case WXK_UP:
		MoveSelectedTasks(j, -1);
		break;
	case WXK_DOWN:
		MoveSelectedTasks(j, 1);
		break;
	}
}

void Assignment::DeleteSelectedTask(int m)
{
	int selectedIndex = CheckListBox[m]->GetSelection();
	if (selectedIndex == wxNOT_FOUND) {
		return;
	}
	CheckListBox[m]->Delete(selectedIndex);
}

void Assignment::AddItemFromInput(int p, wxString Input)
{
	//Assignment_b dummy;


	wxString item = Input;// InputFields->GetValue();
	
	if (!item.IsEmpty()) {
		CheckListBox[p]->Insert(item, CheckListBox[p]->GetCount());
//		InputFields->Clear();
		//RemoveInputFields();
	}
	if (item.IsEmpty() ){
		//RemoveInputFields();
	}
} 

void Assignment::CallInputFields(int f)
{
	//wxBoxSizer* inputField = new wxBoxSizer(wxVERTICAL);
	//wxBoxSizer* inputField_contain = new wxBoxSizer(wxHORIZONTAL);
	////Assignment_b dummy;

	////this->Hide();
	////wxPanel* panel_input = new wxPanel();
	//InputFields = new wxTextCtrl(this/* panel_input*/, wxID_ANY, "", wxPoint(400, 400), wxSize(300, 35), wxTE_PROCESS_ENTER);//wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );// wxPoint(40, 140), wxSize(300, 35), wxTE_PROCESS_ENTER);
	//InputFields->Bind(wxEVT_COMMAND_TEXT_ENTER, [this, f](wxCommandEvent&) {AddItemFromInput(f); });
	// InputFields->SetFocus();
	// InputFields->Show();
	// InputFields->SetBackgroundColour(*wxBLUE);
	//inputField_contain->Add( InputFields,0, wxALIGN_CENTER);
	//inputField->Add(inputField_contain,1, wxALIGN_CENTER);
	////InputFields->Show();
	////inputField->Show();
	//InputValue=Input;
	//Input->Bind()
	//TextView->SetLabel(result);
	
	
	/*Input = wxGetTextFromUser(" ", "Input Assignment", "");
	SetBackgroundColour(wxColor(84, 78, 111));
	AddItemFromInput(f,Input);*/

	wxTextEntryDialog* InputBoxNew = new wxTextEntryDialog(this, "Haiyaa","Fuiyooh");
	InputBoxNew->SetBackgroundColour(wxColor(84, 78, 111));
	
	if (InputBoxNew->ShowModal() == wxID_OK) {
		Input = InputBoxNew->GetValue();
	}
	
	//DatePicker(f);

	AddItemFromInput(f, Input);

}

void Assignment::DatePicker(int f)
{
	wxDatePickerCtrl* DatePick = new wxDatePickerCtrl(this, wxID_ANY, wxDefaultDateTime, wxPoint(800,300), wxDefaultSize, wxDP_DEFAULT);
}

void Assignment::RemoveInputFields()
{
	//Assignment_b dummy;

	if ( InputFields!=nullptr &&  InputFields->IsShown()) {
		 InputFields->Hide();
		 for (int i = 0; i < 4; i++) {
			 CheckListBox[i]->Show();
			 AddButton[i]->Show();
			 ClearButton[i]->Show();
			 TitleText_[i]->Show();
		 }
	}
	//this->Show();
}

void Assignment::MoveSelectedTasks(int f, int offset)
{
	int selectedIndex = CheckListBox[f]->GetSelection() ;
	if (selectedIndex == wxNOT_FOUND) {
		return;
	}

	int newIndex = selectedIndex + offset;
	if (newIndex >= 0 && newIndex <= CheckListBox[f]->GetCount()) {
		SwapTasks(f, selectedIndex, newIndex);
		CheckListBox[f]->SetSelection(newIndex, true);

	}
}

void Assignment::SwapTasks(int i, int j, int k)
{
	Assignment_a TaskJ{ CheckListBox[i]->GetString(j).ToStdString(),CheckListBox[i]->IsChecked(j) };
	Assignment_a TaskK{ CheckListBox[i]->GetString(k).ToStdString(),CheckListBox[i]->IsChecked(k) };

	CheckListBox[i]->SetString(j, TaskK.item);
	CheckListBox[i]->Check(j, TaskK.done);

	CheckListBox[i]->SetString(k, TaskJ.item);
	CheckListBox[i]->Check(k, TaskJ.done);
}

void Assignment::AddSavedTasks()//This function Adds the saved tasks to the vector to display in the CheckListBox when the user opens the app
{
	int count = 0;
	while (count < 7) {
		switch (count)
		{
		case 0:
			FileName = "Assignment_DL.txt";
			break;
		case 1:
			FileName = "Assignment_OOP.txt";
			break;
		case 2:
			FileName = "Assignment_EDC.txt";
			break;
		case 3:
			FileName = "Assignment_ECT.txt";
			break;
		case 4:
			FileName = "Assignment_TOC.txt";
			break;
		case 5:
			FileName = "Assignment_Math.txt";
			break;
		case 6:
			FileName = "Assignment_EM.txt";
			break;
		}
		std::vector<Assignment_a> assignments = LoadItem(FileName);
		for (const Assignment_a& assignment : assignments) {
			int index = CheckListBox[count]->GetCount();
			CheckListBox[count]->Insert(assignment.item, index);
			CheckListBox[count]->Check(index,assignment.done);
		}
		count++;
	}
}

void Assignment::OnWindowClosedAssignment(wxCloseEvent& evt)// , int i)
{
	for (int i = 0; i < 7; i++) {
		std::vector<Assignment_a> assignments;

			int k = CheckListBox[i]->GetCount();
			for (int j = 0; j < k; j++)
			{
				//CheckListBox[i]->GetCount();
				Assignment_a assignment;
				assignment.item = CheckListBox[i]->GetString(j);
				assignment.done = CheckListBox[i]->IsChecked(j);

				assignments.push_back(Assignment_a{ assignment.item , assignment.done });
			}

			switch (i)
			{
			case 0:
				SaveItem(assignments, "Assignment_DL.txt");
				break;
			case 1:
				SaveItem(assignments, "Assignment_OOP.txt");
				break;
			case 2:
				SaveItem(assignments, "Assignment_EDC.txt");
				break;
			case 3:
				SaveItem(assignments, "Assignment_ECT.txt");
				break;
			case 4:
				SaveItem(assignments, "Assignment_TOC.txt");
				break;
			case 5:
				SaveItem(assignments, "Assignment_Math.txt");
				break;
			case 6:
				SaveItem(assignments, "Assignment_EM.txt");
				break;
			}
			evt.Skip();

	}

	//SaveItem(assignments, )
}
void SaveItem(const std::vector<Assignment_a>& Assignments,const std::string& filename)
{
	std::ofstream ostream(filename);
	ostream << Assignments.size();
	for (const Assignment_a& _assignment : Assignments) {
		wxString item = _assignment.item;
		std::replace(item.begin(), item.end(), ' ', '_');
		ostream << '\n' << item << ' ' << _assignment.done;
	}
}

std::vector<Assignment_a> LoadItem(const std::string& filename)//Loads the items in the vector and returns the vector
{
	if (!std::filesystem::exists(filename))
	{
		return std::vector<Assignment_a>();
	}

	std::vector<Assignment_a> Assignments;
	std::ifstream istream(filename);
	int n;
	istream >> n;
	for(int i = 0; i < n; i++){
		//wxString item;
		std::string item;
		//std::string s1 = (std::string)item;
		bool done;
		istream >> item >> done;
		std::replace(item.begin(), item.end(), '_', ' ');
		Assignments.push_back(Assignment_a{ item, done });
	}
	return Assignments;
}

void Assignment::DialogBoxDisplay(wxWindow* parent) {
	wxDialog dialog(parent, wxID_ANY, "ASSIGNMENT INPUT",  wxPoint(400,400),  wxSize(800,800));
	wxBoxSizer* DialogSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

	//auto* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(400, 400));
	//panel->SetBackgroundColour(*wxBLUE);

	for (int i = 0; i < 5; i++) {
		auto button = new wxButton(&dialog, wxID_ANY);
		
		sizer->Add(button);
	}

	SetSizerAndFit(sizer);
}

//void Assignment::OnAddButtonClicked(wxCommandEvent* evt, int f)//, wxWindow* parent)
//{
	//AddAssignmentDialog Dialog;// = new AddAssignmentDialog(m_parent);//Note add parameters
//			DialogBoxDisplay(this);
	/*if (DialogBoxDisplay->ShowModal() == wxID_OK) {

	}*/
//}
void Assignment::_OnAddButtonClicked(wxCommandEvent& evt, int f)//, wxWindow* parent)
{
//	OnAddButtonClicked(&evt, f);//, parent);
}
