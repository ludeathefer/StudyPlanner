#include "PieChart.h"
#include "Assets.h"

PieChart::PieChart(RoundedRectangle* _parent, std::vector<float> _data, std::vector<wxString> _dataLabel, wxString _label) : 
	wxPanel(), parent(_parent), r(0.27*_parent->GetSize().GetWidth()), data(_data), dataLabel(_dataLabel), label(_label)
{
	SetBackgroundStyle(wxBG_STYLE_PAINT);
	Create(_parent, wxID_ANY,wxDefaultPosition, wxSize(2*(r+5), 2*(r+5)));
	AddLabel();
	Bind(wxEVT_PAINT, &PieChart::OnPaint, this);
};

void PieChart::AddLabel() {
	srand(time(0));
	for (double value : data) colors.push_back(wxColour(rand() % 200 - 100, rand() % 200 - 100, rand() % 200 - 130));
	std::sort(colors.begin(), colors.end(), [](const wxColour& a, const wxColour& b) {
		return a.GetRed() + a.GetGreen() + a.GetBlue() < b.GetRed() + b.GetGreen() + b.GetBlue();
	});
	wxPanel* labelPanel = new wxPanel(parent);
	labelPanel->SetBackgroundColour(parent->color);
	wxGridSizer* labelSizer = new wxGridSizer(2, 5, 90);

	std::vector<wxPanel*> labelPanels;
	std::vector<wxBoxSizer*> labelSizers;
	std::vector<RoundedRectangle*> labelIndex;
	std::vector<wxStaticText*> labelText;

	for (int i = 0; i < colors.size(); i++) {
		labelPanels.push_back(new wxPanel(labelPanel));
		labelPanels[i]->SetBackgroundColour(parent->color);
		labelSizers.push_back(new wxBoxSizer(wxHORIZONTAL));
		labelIndex.push_back(new RoundedRectangle(labelPanels[i], wxSize(15, 15), colors[i], parent->color, 4));
		labelText.push_back(new wxStaticText(labelPanels[i], wxID_STATIC, dataLabel[i]));
		labelText[i]->SetFont(wxFont(wxFontInfo(10).Family(wxFONTFAMILY_TELETYPE)));
		labelText[i]->SetForegroundColour(TEXT_THEME_COLOUR);
		labelSizers[i]->Add(labelIndex[i], 0, wxALIGN_CENTER_VERTICAL);
		labelSizers[i]->Add(labelText[i], 1, wxLEFT | wxALIGN_CENTER_VERTICAL, 5);
		labelPanels[i]->SetSizerAndFit(labelSizers[i]);
		labelSizer->Add(labelPanels[i]);
	};
	labelPanel->SetSizerAndFit(labelSizer);

	wxFont* roundFont = new wxFont(16, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxStaticText* roundText = new wxStaticText(parent, wxID_STATIC, label);
	roundText->SetBackgroundColour(parent->color);
	roundText->SetForegroundColour(TEXT_THEME_COLOUR);
	roundText->SetFont(*roundFont);
	wxBoxSizer* roundSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* pieSizer = new wxBoxSizer(wxHORIZONTAL);
	roundSizer->Add(roundText, 0, wxTOP | wxALIGN_CENTER_HORIZONTAL, parent->GetSize().GetHeight() / 10.0);
	pieSizer->Add(this, 0, wxALIGN_CENTER);
	roundSizer->Add(pieSizer, 1, wxALIGN_CENTER);
	roundSizer->Add(labelPanel, 0, wxBOTTOM | wxALIGN_CENTER_HORIZONTAL, parent->GetSize().GetHeight() / 20.0);
	parent->SetSizer(roundSizer);
}

void PieChart::OnPaint(wxPaintEvent&)
{
	SetBackgroundColour(parent->color);
	wxAutoBufferedPaintDC dc(this);
	dc.Clear();
	wxGraphicsContext* gc = wxGraphicsContext::Create(dc);
	float total = 0;
	for (float value : data) total += value;
	double startAngle = 0;
	wxPoint2DDouble centrePoint = wxPoint2DDouble(r+4, r+4);
	wxPoint2DDouble circumPoint = wxPoint2DDouble(2*r+4, r+4);
	if (gc) {
		for (int i = 0; i < data.size(); i++)
		{
			double sweepAngle = data[i] / total * 2 * M_PI;
			gc->SetPen(wxPen(SIDEBAR_SELECTED_COLOUR, 2));
			gc->SetBrush(wxBrush(colors[i]));
			wxGraphicsPath path = gc->CreatePath();
			path.MoveToPoint(centrePoint);
			path.AddLineToPoint(circumPoint);
			path.AddArc(centrePoint, r, startAngle, startAngle+sweepAngle, true);
			circumPoint = path.GetCurrentPoint();
			path.MoveToPoint(centrePoint);
			startAngle += sweepAngle;
			if (i == data.size()-1) { path.AddLineToPoint(circumPoint); path.MoveToPoint(centrePoint); }
			gc->FillPath(path);
			gc->StrokePath(path);
		};
		gc->SetPen(SIDEBAR_SELECTED_COLOUR);
		gc->SetBrush(wxBrush(SIDEBAR_SELECTED_COLOUR));
		gc->DrawEllipse(r, r, 6, 6);
	};
};
