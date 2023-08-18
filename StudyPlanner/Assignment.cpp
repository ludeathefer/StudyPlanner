#include "Assignment.h"
#include <wx/wx.h>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <algorithm>
#include "RoundedRectangle.h"
#include<wx/gbsizer.h>

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
	wxPanel* panel = new wxPanel(this, wxID_ANY,wxDefaultPosition, wxSize(800,800));// , wxDefaultPosition, wxDefaultSize, wxEXPAND | wxALL);
	panel->SetBackgroundColour(wxColor(84, 78, 111));
	this->SetBackgroundColour(panel->GetBackgroundColour());
	auto sizer = new wxGridBagSizer(margin, margin);

	auto MainTitle = new wxStaticText(panel, wxID_ANY, "ASSIGNMENTS");
	/*auto DLText = new RoundedRectangle(panel, wxSize(400,220), wxColor(84, 78, 50), wxColor(84, 78, 111), 30);
	auto OOPText = new RoundedRectangle(panel, wxSize(400,220), wxColor(84, 78, 50), wxColor(84, 78, 111), 30);
	auto EMText = new RoundedRectangle(panel, wxSize(400,220), wxColor(84, 78, 50), wxColor(84, 78, 111), 30);
	auto TOCText = new RoundedRectangle(panel, wxSize(400,220), wxColor(84, 78, 50), wxColor(84, 78, 111), 30);
	auto MathText = new RoundedRectangle(panel, wxSize(400,220), wxColor(84, 78, 50), wxColor(84, 78, 111), 30);
	auto ECTText = new RoundedRectangle(panel, wxSize(400,220), wxColor(84, 78, 50), wxColor(84, 78, 111), 30);
	auto EDCText = new RoundedRectangle(panel, wxSize(400,220), wxColor(84, 78, 50), wxColor(84, 78, 111), 30);*/
	//auto BoxArray[7];
	int count = 0;
	sizer->Add(MainTitle, { 0,0 }, { 1,3 });
//	std::string  DisplayTitle;// = new std::string;
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
			{
			if (count < 7)
			{
				auto BoxArray = new RoundedRectangle(panel, wxSize(400, 220), wxColor(84, 78, 50), wxColor(84, 78, 111), 30);
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

						BindEventHandlers(count);

						count++;

					}
			}
	}

	MainTitle->SetBackgroundColour(wxColor(84, 78, 0));
	MainTitle->SetForegroundColour(wxColor(10, 100, 200));
	MainTitle->SetFont(headLineFont);

	AddSavedTasks();


	/*sizer->Add(DLText, { 1,0 }, { 1,1 });
	sizer->Add(OOPText, { 1,1 }, { 1,1 });
	sizer->Add(EMText, { 1,2 }, { 1,1 });
	sizer->Add(TOCText, { 2,0 }, { 1,1 });
	sizer->Add(MathText, { 2,1 }, { 1,1 });
	sizer->Add(ECTText, { 2,2 }, { 1,1 });
	sizer->Add(EDCText, { 3,0 }, { 1,1 });*/


/*
	std::vector<std::pair<wxGBPosition, wxGBSpan>> GridItem = {
		//{{0,0},{1,3}},
		{{1,0},{1,1}},
		{{1,1},{1,1}},
		{{1,2},{1,1}},
		{{2,0},{1,1}},
		{{2,1},{1,1}},
		{{2,2},{1,1}},
		{{3,0},{1,1}}
	};
	auto q = new wxPanel(panel, wxID_ANY, wxDefaultPosition, wxSize(200, 60));
	q->SetBackgroundColour(wxColor(84, 78, 0));
	sizer->Add(q,1,wxEXPAND);
	for (auto& item : GridItem) {

		auto p = new wxPanel(panel, wxID_ANY, wxDefaultPosition,  wxSize(400, 220));// , sizer->GetEmptyCellSize());
		p->SetBackgroundColour(wxColor(84, 78, 50));
		sizer->Add(p, item.first, item.second, wxEXPAND);
	}
*/	

	
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
		/*
		void Assignment::display_dl() {
			int i = 0;
			//wxPanel* Panel_dl = new wxPanel(this);
			//Panel_dl->SetDoubleBuffered(true);
			//Panel_dl->SetBackgroundColour(*wxBLUE);
			wxBoxSizer* dl_box = new wxBoxSizer(wxVERTICAL);
			wxBoxSizer* dl_text_button = new wxBoxSizer(wxVERTICAL);
			wxBoxSizer* dl_text = new wxBoxSizer(wxHORIZONTAL);
			wxBoxSizer* dl_button = new wxBoxSizer(wxHORIZONTAL);
			wxBoxSizer* dl_checklistbox = new wxBoxSizer(wxHORIZONTAL);
			//RoundedRectangle* container1 = new RoundedRectangle(Panel_dl, wxSize(600, 200), wxColor(84, 78, 10), wxColor(84, 78, 111), 30);

			wxFont headLineFont(wxFontInfo(wxSize(0, 20)).Bold());
			TitleText_[i] = new wxStaticText(this, wxID_ANY, "Digital Logic", wxPoint(40, 100), wxSize(430, 10));
			TitleText_[i]->SetForegroundColour(*wxGREEN);
			TitleText_[i]->SetFont(headLineFont);
			AddButton[i] = new wxButton(this, wxID_ANY, "+", wxPoint(345, 140), wxSize(35, 35));
			CheckListBox[i]= new wxCheckListBox(this, wxID_ANY, wxPoint(40, 185), wxSize(405, 150));
			//CheckListBox_ = wxCheckListBox(this, wxID_ANY, wxPoint(40, 185), wxSize(405, 150));

			ClearButton[i] = new wxButton(this, wxID_ANY, "CLEAR", wxPoint(40, 345), wxSize(100, 35));
			//Panel_dl->Add;
			//dl_box->Add(Panel_dl);
			dl_text->Add(TitleText_[i]);
			dl_button->Add(AddButton[i]);
			dl_text_button->Add(dl_text);
			dl_text_button->Add(dl_button);
			dl_checklistbox->Add(CheckListBox[i]);
			dl_box->Add(dl_text_button);
			dl_box->Add(dl_checklistbox);
			//SetSizerAndFit(dl_box);
			//dl_box->
			BindEventHandlers(i);
		}
		*/
		/*

			void Assignment::display_oop()
			{
				int i = 1;
				wxFont headLineFont(wxFontInfo(wxSize(0, 20)).Bold());
				TitleText_[i] = new wxStaticText(this, wxID_ANY, "Object Oriented Programming", wxPoint(630, 100), wxSize(430, 10));
				TitleText_[i]->SetForegroundColour(*wxWHITE);
				TitleText_[i]->SetFont(headLineFont);
				AddButton[i] = new wxButton(this, wxID_ANY, "+", wxPoint(935, 140), wxSize(35, 35));
				CheckListBox[i] = new wxCheckListBox(this, wxID_ANY, wxPoint(630, 185), wxSize(405, 150));
				ClearButton[i] = new wxButton(this, wxID_ANY, "CLEAR", wxPoint(630, 345), wxSize(100, 35));
				BindEventHandlers(i);
			}

			void Assignment::display_math()
			{
				int i = 2;
				wxFont headLineFont(wxFontInfo(wxSize(0, 20)).Bold());
				TitleText_[i] = new wxStaticText(this, wxID_ANY, "Mathematics III", wxPoint(40, 445), wxSize(430, 10));
				TitleText_[i]->SetForegroundColour(*wxWHITE);
				TitleText_[i]->SetFont(headLineFont);
				AddButton[i] = new wxButton(this, wxID_ANY, "+", wxPoint(345, 485), wxSize(35, 35));
				CheckListBox[i] = new wxCheckListBox(this, wxID_ANY, wxPoint(40, 525), wxSize(405, 150));
				ClearButton[i] = new wxButton(this, wxID_ANY, "CLEAR", wxPoint(40, 685), wxSize(100, 35));
				BindEventHandlers(i);
			}

			void Assignment::display_em()
			{
				int i = 3;
				wxFont headLineFont(wxFontInfo(wxSize(0, 20)).Bold());
				TitleText_[i] = new wxStaticText(this, wxID_ANY, "Electromagnetics", wxPoint(630, 445), wxSize(430, 10));
				TitleText_[i]->SetForegroundColour(*wxWHITE);
				TitleText_[i]->SetFont(headLineFont);
				AddButton[i] = new wxButton(this, wxID_ANY, "+", wxPoint(935, 485), wxSize(35, 35));
				CheckListBox[i] = new wxCheckListBox(this, wxID_ANY, wxPoint(630, 525), wxSize(405, 150));
				ClearButton[i] = new wxButton(this, wxID_ANY, "CLEAR", wxPoint(630, 685), wxSize(100, 35));
				BindEventHandlers(i);
			}

			void Assignment::display_ect()
			{
				int i = 4;
				wxFont headLineFont(wxFontInfo(wxSize(0, 20)).Bold());
				TitleText_[i] = new wxStaticText(this, wxID_ANY, "Electrical Circuits Theory", wxPoint(40, 785), wxSize(430, 10));
				TitleText_[i]->SetForegroundColour(*wxWHITE);
				TitleText_[i]->SetFont(headLineFont);
				AddButton[i] = new wxButton(this, wxID_ANY, "+", wxPoint(345, 825), wxSize(35, 35));
				CheckListBox[i] = new wxCheckListBox(this, wxID_ANY, wxPoint(40, 865), wxSize(405, 150));
				ClearButton[i] = new wxButton(this, wxID_ANY, "CLEAR", wxPoint(40, 1120), wxSize(100, 35));
				BindEventHandlers(i);
			}

			void Assignment::display_edc()
			{
				int i = 5;
				wxFont headLineFont(wxFontInfo(wxSize(0, 20)).Bold());
				TitleText_[i] = new wxStaticText(this, wxID_ANY, "Electronic Devices and Circuits", wxPoint(630, 785), wxSize(430, 10));
				TitleText_[i]->SetForegroundColour(*wxWHITE);
				TitleText_[i]->SetFont(headLineFont);
				AddButton[i] = new wxButton(this, wxID_ANY, "+", wxPoint(935, 825), wxSize(35, 35));
				CheckListBox[i] = new wxCheckListBox(this, wxID_ANY, wxPoint(630, 865), wxSize(405, 150));
				ClearButton[i] = new wxButton(this, wxID_ANY, "CLEAR", wxPoint(630, 1120), wxSize(100, 35));
				BindEventHandlers(i);
			}

			void Assignment::display_toc()
			{
				int i = 6;
				wxFont headLineFont(wxFontInfo(wxSize(0, 20)).Bold());
				TitleText_[i] = new wxStaticText(this, wxID_ANY, "Theory of Computation", wxPoint(40, 1220), wxSize(430, 10));
				TitleText_[i]->SetForegroundColour(*wxWHITE);
				TitleText_[i]->SetFont(headLineFont);
				AddButton[i] = new wxButton(this, wxID_ANY, "+", wxPoint(345, 1260), wxSize(35, 35));
				CheckListBox[i] = new wxCheckListBox(this, wxID_ANY, wxPoint(40, 1300), wxSize(405, 150));
				ClearButton[i] = new wxButton(this, wxID_ANY, "CLEAR", wxPoint(40, 1460), wxSize(100, 35));
				BindEventHandlers(i);
			}

			void Assignment::CreateControls()
			{
				display_edc();
				display_ect();
				display_toc();
				display_oop();
				display_math();
				display_em();
				display_dl();

			}*/



void Assignment::BindEventHandlers(int a)
{
	int j = a;
	int pra = j;
	AddButton[j]->Bind(wxEVT_BUTTON, [this, pra](wxCommandEvent& evt) {
		OnAddButtonClicked(evt, pra);
		});
	CheckListBox[j]->Bind(wxEVT_KEY_DOWN, [this, j](wxKeyEvent& evt) {OnListKeyDown(evt,j); });
	RemoveInputFields();
}

void Assignment::OnAddButtonClicked(wxCommandEvent& evt, int pra)
{
	//ElementsVisible = !ElementsVisible;
	//TitleText->Show(ElementsVisible);
	////for (int i = 0; i < 7; i++) {
	//	CheckListBox[0]->Show(ElementsVisible);
	//	AddButton[0]->Show(ElementsVisible);
	//	ClearButton[0]->Show(ElementsVisible);
	//	
	////}
	//InputFields->Show(!ElementsVisible);
	//GetSizer()->Layout();
	/*for (int i = 0; i < 4; i++) {
		CheckListBox[i]->Hide();
		AddButton[i]->Hide();
		ClearButton[i]->Hide();
		TitleText_[i]->Hide();
	}*/
	//RemoveInputFields();
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
	AddItemFromInput(f, Input);

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

void Assignment::AddSavedTasks()
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

void Assignment::OnWindowClosed_a(wxCloseEvent& evt)// , int i)
{
	std::vector<Assignment_a> assignments;
	//for (int i = 0; i < 7; i++) {
	int k = 3;// CheckListBox[0]->GetCount();
	for (int j = 0; j < k; j++)
	{
		//CheckListBox[i]->GetCount();
		Assignment_a assignment;
		assignment.item = "Ram hari";//CheckListBox[0]->GetString(j);
		assignment.done = true;//CheckListBox[0]->IsChecked(j);

		assignments.push_back(Assignment_a { assignment.item , assignment.done });
	}

	/*switch (i)
	{ 
	case 0:*/
		SaveItem(assignments, "Assignment_DL.txt");
		/*break;
	case 1:
		SaveItem(assignments, "Assignment_OOP.txt");
		break;
	case 2:
		SaveItem(assignments, "Assignment_Math.txt");
		break;
	case 3:
		SaveItem(assignments, "Assignment_EM.txt");
		break;
	case 4:
		SaveItem(assignments, "Assignment_ECT.txt");
		break;
	case 5:
		SaveItem(assignments, "Assignment_EDC.txt");
		break;
	case 6:
		SaveItem(assignments, "Assignment_TOC.txt");
		break;
	}*/
	evt.Skip();

	}

	//SaveItem(assignments, )
//}
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

std::vector<Assignment_a> LoadItem(const std::string& filename)
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


