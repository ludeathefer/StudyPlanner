#include "PieChart.h"
#include "Assets.h"

PieChart::PieChart(RoundedRectangle* _parent, int _r, wxColour _bg, std::vector<float> _data, std::vector<wxString> _dataLabel, wxString _label) : 
	wxPanel(), parent(_parent), r(_r), bg(_bg), data(_data), dataLabel(_dataLabel), label(_label)
{
	SetBackgroundStyle(wxBG_STYLE_PAINT);
	Create(_parent, wxID_ANY,wxDefaultPosition, wxSize(2*r+1, 2*r+1));
	AddLabel();
	Bind(wxEVT_PAINT, &PieChart::OnPaint, this);
};

void PieChart::AddLabel() {
	for (double value : data) colors.push_back(wxColour(rand() % 256 - 100, rand() % 256 - 100, rand() % 256 - 100));
	wxPanel* labelPanel = new wxPanel(parent);
	labelPanel->SetBackgroundColour(parent->color);
	wxGridSizer* labelSizer = new wxGridSizer(2, 0, 5, 90);

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
	wxStaticText* roundText = new wxStaticText(parent, wxID_STATIC, wxT("CHART: " + label));
	roundText->SetBackgroundColour(parent->color);
	roundText->SetForegroundColour(TEXT_THEME_COLOUR);
	roundText->SetFont(*roundFont);
	wxBoxSizer* roundSizer = new wxBoxSizer(wxVERTICAL);
	roundSizer->Add(roundText, 0, wxTOP | wxALIGN_CENTER_HORIZONTAL, 20);
	roundSizer->Add(this, 0, wxTOP | wxALIGN_CENTER_HORIZONTAL, 20);
	roundSizer->AddStretchSpacer();
	roundSizer->Add(labelPanel, 0, wxBOTTOM | wxALIGN_CENTER_HORIZONTAL, 20);
	parent->SetSizer(roundSizer);
}

void PieChart::OnPaint(wxPaintEvent&)
{
	SetBackgroundColour(bg);
	wxAutoBufferedPaintDC dc(this);
	dc.Clear();
	wxGraphicsContext* gc = wxGraphicsContext::Create(dc);
	float total = 0;
	for (float value : data) total += value;
	double startAngle = 0;
	wxPoint2DDouble centrePoint = wxPoint2DDouble(r, r);
	wxPoint2DDouble circumPoint = wxPoint2DDouble(2*r, r);
	if (gc) {
		for (int i = 0; i < data.size(); i++)
		{
			double sweepAngle = data[i] / total * 2 * M_PI;
			gc->SetPen(colors[i]);
			gc->SetBrush(wxBrush(colors[i]));
			wxGraphicsPath path = gc->CreatePath();
			path.MoveToPoint(centrePoint);
			path.AddLineToPoint(circumPoint);
			path.AddArc(centrePoint, r, startAngle, startAngle+sweepAngle, true);
			circumPoint = path.GetCurrentPoint();
			path.MoveToPoint(centrePoint);
			startAngle += sweepAngle;
			gc->StrokePath(path);
			gc->FillPath(path);
		};
	};
};
