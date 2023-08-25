#include "Syllabus.h"
#include <wx/wx.h>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <algorithm>
#include "RoundedRectangle.h"
#include <wx/gbsizer.h>
#include "Assets.h"
#include <windows.h>

Syllabus::Syllabus(wxWindow* parent) : wxPanel(parent)
{
	const auto margin = FromDIP(30);
	auto mainsizer = new wxBoxSizer(wxVERTICAL);
	mainsizer->AddSpacer(10);
	wxFont* headLineFont = new wxFont(32, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	auto* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(800, 800)); // , wxDefaultPosition, wxDefaultSize, wxEXPAND | wxALL);
	panel->SetBackgroundColour(wxColor(84, 78, 111));
	this->SetBackgroundColour(panel->GetBackgroundColour());
	auto sizer = new wxGridBagSizer(margin, margin);

	auto MainTitle = new wxStaticText(panel, wxID_ANY, "Syllabus");

	MainTitle->SetForegroundColour(TEXT_THEME_COLOUR);
	int count = 0;
	sizer->Add(MainTitle, { 0, 0 }, { 1, 3 });

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (count < 7)
			{
				auto BoxArray = new RoundedRectangle(panel, wxSize(400, 220), wxColor(44, 41, 59), wxColor(84, 78, 111), 30);
				sizer->Add(BoxArray, { i + 1, j }, { 1, 1 });

				auto MainSizer = new wxBoxSizer(wxVERTICAL);
				// auto TitleAndButton = new wxBoxSizer(wxVERTICAL);
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
				TitleDisplay->SetBackgroundColour(wxColor(44, 41, 59));
				TitleDisplay->SetForegroundColour(*wxWHITE);
				Title->Add(TitleDisplay);

				/*AddButton[count] = new wxButton(BoxArray, wxID_ANY, "+", wxPoint(355, 10), wxSize(25, 25));
				AddButton[count]->SetBackgroundColour(wxColor(84, 78, 111));
				Button->Add(AddButton[count]);*/

				CheckListBox[count] = new wxCheckListBox(BoxArray, wxID_ANY, wxPoint(20, 50), wxSize(360, 150), 0, NULL, wxNO_BORDER); //, wxALIGN_BOTTOM);// | wxALIGN_CENTER);
				CheckListBox[count]->SetBackgroundColour(SIDEBAR_COLOUR);
				CheckListBox[count]->SetForegroundColour(*wxWHITE);
				LONG style = GetWindowLong((HWND)CheckListBox[count]->GetHWND(), GWL_STYLE);
				style &= ~(WS_VSCROLL | WS_HSCROLL);
				SetWindowLong((HWND)CheckListBox[count]->GetHWND(), GWL_STYLE, style);
				CheckListBox[count]->Refresh();

				// TitleAndButton->Add(Title);
				// TitleAndButton->Add(Button);

				CheckBox->Add(CheckListBox[count], 0, wxSHRINK);

				// MainSizer->Add(TitleAndButton);
				MainSizer->Add(CheckBox, 0, wxSHRINK);

				// BindEventHandlers(count);

				count++;
			}
		}
	}

	MainTitle->SetFont(*headLineFont);
	DisplaySyllabus();
	panel->SetSizer(sizer);
	mainsizer->Add(panel, 0, wxEXPAND | wxALL, margin);
	this->SetSizerAndFit(mainsizer);
	Hide();
}

void Syllabus::Initialize()
{
	// SetBackgroundColour(wxColour(84, 78, 111));
	// wxBoxSizer* syllabusSizer = new wxBoxSizer(wxVERTICAL);
	// wxStaticText* syllabusText = new wxStaticText(this, wxID_STATIC, wxT("Syllabus"));
	// wxFont* syllabusFont = new wxFont(72, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_SEMIBOLD);
	// syllabusText->SetFont(*syllabusFont);
	// syllabusText->SetForegroundColour(wxColour(200, 200, 200));
	// wxBoxSizer* tempSizer = new wxBoxSizer(wxHORIZONTAL);
	// tempSizer->Add(syllabusText, 0, wxALIGN_CENTER);
	// syllabusSizer->Add(tempSizer, 1, wxALIGN_CENTER);
	// SetSizer(syllabusSizer);
	Hide();
}

void Syllabus::DisplaySyllabus() // Displays the syllabus
{
	int count = 0;
	while (count < 7)
	{
		switch (count)
		{
		case 0:
			FileName = "Syllabus_DL.txt";
			break;
		case 1:
			FileName = "Syllabus_OOP.txt";
			break;
		case 2:
			FileName = "Syllabus_EDC.txt";
			break;
		case 3:
			FileName = "Syllabus_ECT.txt";
			break;
		case 4:
			FileName = "Syllabus_TOC.txt";
			break;
		case 5:
			FileName = "Syllabus_Math.txt";
			break;
		case 6:
			FileName = "Syllabus_EM.txt";
			break;
		}
		std::vector<Syllabus_a> _Syllabus = LoadSyllabus(FileName);
		for (const Syllabus_a& syllabus : _Syllabus)
		{
			int index = CheckListBox[count]->GetCount();
			CheckListBox[count]->Insert(syllabus.item, index);
			CheckListBox[count]->Check(index, syllabus.done);
			CheckListBox[count]->GetItem(index)->SetTextColour(wxColor(255, 255, 255));
		}
		count++;
	}
}

void Syllabus::UpdateCurrentSyllabus(wxCloseEvent& evt) // Updated changes of checklistbox
{

	for (int i = 0; i < 7; i++)
	{
		std::vector<Syllabus_a> _Syllabus;
		int k = CheckListBox[i]->GetCount();
		for (int j = 0; j < k; j++)
		{
			// CheckListBox[i]->GetCount();
			Syllabus_a syllabus;
			syllabus.item = CheckListBox[i]->GetString(j);
			syllabus.done = CheckListBox[i]->IsChecked(j);

			_Syllabus.push_back(Syllabus_a{ syllabus.item, syllabus.done });
		}

		switch (i)
		{
		case 0:
			UpdateSyllabus(_Syllabus, "Syllabus_DL.txt");
			break;
		case 1:
			UpdateSyllabus(_Syllabus, "Syllabus_OOP.txt");
			break;
		case 2:
			UpdateSyllabus(_Syllabus, "Syllabus_EDC.txt");
			break;
		case 3:
			UpdateSyllabus(_Syllabus, "Syllabus_ECT.txt");
			break;
		case 4:
			UpdateSyllabus(_Syllabus, "Syllabus_TOC.txt");
			break;
		case 5:
			UpdateSyllabus(_Syllabus, "Syllabus_Math.txt");
			break;
		case 6:
			UpdateSyllabus(_Syllabus, "Syllabus_EM.txt");
			break;
		}
		evt.Skip();
	}

	// SaveItem(Syllabuss, )
}

std::vector<Syllabus::Syllabus_a> LoadSyllabus(const std::string& filename) // loads syllabus in vector
{
	if (!std::filesystem::exists(filename))
	{
		return std::vector<Syllabus::Syllabus_a>();
	}

	std::vector<Syllabus::Syllabus_a> _Syllabus;
	std::ifstream istream(filename);
	int n;
	istream >> n;
	for (int i = 0; i < n; i++)
	{
		// wxString item;
		std::string item;
		// std::string s1 = (std::string)item;
		bool done;
		istream >> item >> done;
		std::replace(item.begin(), item.end(), '_', ' ');
		_Syllabus.push_back(Syllabus::Syllabus_a{item, done});
	}
	return _Syllabus;
}

void UpdateSyllabus(const std::vector<Syllabus::Syllabus_a>& Syllabus, const std::string& filename) // saves syllabus in file(updates it)
{
	std::ofstream ostream(filename);
	ostream << Syllabus.size();
	for (const Syllabus::Syllabus_a& _syllabus : Syllabus)
	{
		wxString item = _syllabus.item;
		std::replace(item.begin(), item.end(), ' ', '_');
		ostream << '\n'
			<< item << ' ' << _syllabus.done;
	}
}

std::vector<Syllabus::Progress> Syllabus::GetSyllabusVector()
{
	std::vector<Syllabus::Progress> _Progress;
	for (int i = 0; i < 7; i++)
	{
		int l = 0;
		int k = CheckListBox[i]->GetCount();
		for (int j = 0; j < k; j++)
		{
			Syllabus_a syllabus;
			syllabus.done = CheckListBox[i]->IsChecked(j);
			if (syllabus.done)
			{
				l++;
			}
		}

		Progress _progress;
		_progress.percentage = (l / k) * 100;

		switch (i)
		{
		case 0:
			_progress.Name = "Digital Logic";
			break;
		case 1:
			_progress.Name = "Object Oriented Programming";
			break;
		case 2:
			_progress.Name = "Electronic Devices and Circuits";
			break;
		case 3:
			_progress.Name = "Electric Circuit Theory";
			break;
		case 4:
			_progress.Name = "Theory of Computation";
			break;
		case 5:
			_progress.Name = "Mathematics III";
			break;
		case 6:
			_progress.Name = "Electromagnetics";
			break;
		}
		_Progress.push_back(Progress{ _progress.percentage, _progress.Name });
	}

	return _Progress;
}