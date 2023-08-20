#include "Revision.h"
#include <wx/wx.h>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <algorithm>
#include "RoundedRectangle.h"
#include<wx/gbsizer.h>

Revision::Revision(wxWindow* parent) : wxPanel(parent)
{


	const auto margin = FromDIP(10);
	auto mainsizer = new wxBoxSizer(wxVERTICAL);
	wxFont headLineFont(wxFontInfo(wxSize(0, 40)).Bold());
	auto* panel = new wxScrolled<wxPanel>(this, wxID_ANY, wxDefaultPosition, wxSize(800, 800));// , wxDefaultPosition, wxDefaultSize, wxEXPAND | wxALL);
	panel->SetBackgroundColour(wxColor(84, 78, 111));
	panel->SetScrollRate(0, FromDIP(10));
	this->SetBackgroundColour(panel->GetBackgroundColour());
	auto sizer = new wxGridBagSizer(margin, margin);

	auto MainTitle = new wxStaticText(panel, wxID_ANY, "REVISION");
	int count = 0;
	sizer->Add(MainTitle, { 0,0 }, { 1,3 });

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (count < 7)
			{
				auto BoxArray = new RoundedRectangle(panel, wxSize(400, 220), wxColor(84, 78, 50), wxColor(84, 78, 111), 30);
				sizer->Add(BoxArray, { i + 1,j }, { 1,1 });

				auto MainSizer = new wxBoxSizer(wxVERTICAL);
				//auto TitleAndButton = new wxBoxSizer(wxVERTICAL);
				auto Title = new wxBoxSizer(wxHORIZONTAL);
				//	auto Button = new wxBoxSizer(wxHORIZONTAL);
				auto CheckBox = new wxBoxSizer(wxHORIZONTAL);

				switch (count)
				{
				case 0:
					DisplaySubject = "Digital Logic";
					break;
				case 1:
					DisplaySubject = "Object Oriented Programming";
					break;
				case 2:
					DisplaySubject = "Electronics Devices and Circuits";
					break;
				case 3:
					DisplaySubject = "Electrical Circuits Theory";
					break;
				case 4:
					DisplaySubject = "Theory of Computation";
					break;
				case 5:
					DisplaySubject = "Mathematics III";
					break;
				case 6:
					DisplaySubject = "Electromagnetics";
					break;
				}

				wxFont TitleFont(wxFontInfo(wxSize(0, 20)).Bold());
				auto TitleDisplay = new wxStaticText(BoxArray, wxID_ANY, DisplaySubject, wxPoint(20, 10), wxSize(200, 30));
				TitleDisplay->SetFont(TitleFont);
				Title->Add(TitleDisplay);

				/*AddButton[count] = new wxButton(BoxArray, wxID_ANY, "+", wxPoint(355, 10), wxSize(25, 25));
				AddButton[count]->SetBackgroundColour(wxColor(84, 78, 111));
				Button->Add(AddButton[count]);*/

				CheckListBox[count] = new wxCheckListBox(BoxArray, wxID_ANY, wxPoint(20, 50), wxSize(360, 150));//, wxALIGN_BOTTOM);// | wxALIGN_CENTER);

				//TitleAndButton->Add(Title);
				//TitleAndButton->Add(Button);

				CheckBox->Add(CheckListBox[count]);

				//MainSizer->Add(TitleAndButton);
				MainSizer->Add(CheckBox);

				//BindEventHandlers(count);

				count++;

			}
		}
	}

	MainTitle->SetBackgroundColour(wxColor(84, 78, 0));
	MainTitle->SetForegroundColour(wxColor(10, 100, 200));
	MainTitle->SetFont(headLineFont);

	DisplayRevision();




	panel->SetSizer(sizer);
	mainsizer->Add(panel, 0, wxEXPAND | wxALL, margin);
	this->SetSizerAndFit(mainsizer);
	Hide();

}

void Revision::Initialize()
{
	//SetBackgroundColour(wxColour(84, 78, 111));
	//wxBoxSizer* revisionSizer = new wxBoxSizer(wxVERTICAL);
	//wxStaticText* revisionText = new wxStaticText(this, wxID_STATIC, wxT("Revision"));
	//wxFont* revisionFont = new wxFont(72, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_SEMIBOLD);
	//revisionText->SetFont(*revisionFont);
	//revisionText->SetForegroundColour(wxColour(200, 200, 200));
	//wxBoxSizer* tempSizer = new wxBoxSizer(wxHORIZONTAL);
	//tempSizer->Add(revisionText, 0, wxALIGN_CENTER);
	//revisionSizer->Add(tempSizer, 1, wxALIGN_CENTER);
	//SetSizer(revisionSizer);
	Hide();
}

void Revision::DisplayRevision()//displays revision
{
	int count = 0;
	while (count < 7) {
		switch (count)
		{
		case 0:
			FileName = "Revision_DL.txt";
			break;
		case 1:
			FileName = "Revision_OOP.txt";
			break;
		case 2:
			FileName = "Revision_EDC.txt";
			break;
		case 3:
			FileName = "Revision_ECT.txt";
			break;
		case 4:
			FileName = "Revision_TOC.txt";
			break;
		case 5:
			FileName = "Revision_Math.txt";
			break;
		case 6:
			FileName = "Revision_EM.txt";
			break;
		}
		std::vector<Revision_a> assignments = LoadRevision(FileName);
		for (const Revision_a& assignment : assignments) {
			int index = CheckListBox[count]->GetCount();
			CheckListBox[count]->Insert(assignment.item, index);
			CheckListBox[count]->Check(index, assignment.done);
		}
		count++;
	}
}

void Revision::UpdateCurrentRevision(wxCloseEvent& evt)//updates changes on revision
{


	for (int i = 0; i < 7; i++) {
		std::vector<Revision_a> _Revision;
		int k = CheckListBox[i]->GetCount();
		for (int j = 0; j < k; j++)
		{
			//CheckListBox[i]->GetCount();
			Revision_a revision;
			revision.item = CheckListBox[i]->GetString(j);
			revision.done = CheckListBox[i]->IsChecked(j);

			_Revision.push_back(Revision_a{ revision.item , revision.done });
		}

		switch (i)
		{
		case 0:
			UpdateRevision(_Revision, "Revision_DL.txt");
			break;
		case 1:
			UpdateRevision(_Revision, "Revision_OOP.txt");
			break;
		case 2:
			UpdateRevision(_Revision, "Revision_EDC.txt");
			break;
		case 3:
			UpdateRevision(_Revision, "Revision_ECT.txt");
			break;
		case 4:
			UpdateRevision(_Revision, "Revision_TOC.txt");
			break;
		case 5:
			UpdateRevision(_Revision, "Revision_Math.txt");
			break;
		case 6:
			UpdateRevision(_Revision, "Revision_EM.txt");
			break;
		}
		evt.Skip();

	}

}



std::vector<Revision_a> LoadRevision(const std::string& filename)//loads revision in vector
{
	if (!std::filesystem::exists(filename))
	{
		return std::vector<Revision_a>();
	}

	std::vector<Revision_a> _Revision;
	std::ifstream istream(filename);
	int n;
	istream >> n;
	for (int i = 0; i < n; i++) {
		//wxString item;
		std::string item;
		//std::string s1 = (std::string)item;
		bool done;
		istream >> item >> done;
		std::replace(item.begin(), item.end(), '_', ' ');
		_Revision.push_back(Revision_a{ item, done });
	}
	return _Revision;
}

void UpdateRevision(const std::vector<Revision_a>& Revision, const std::string& filename)//Saves revision in file(updates it)
{
	std::ofstream ostream(filename);
	ostream << Revision.size();
	for (const Revision_a& _revision : Revision) {
		wxString item = _revision.item;
		std::replace(item.begin(), item.end(), ' ', '_');
		ostream << '\n' << item << ' ' << _revision.done;
	}
}
