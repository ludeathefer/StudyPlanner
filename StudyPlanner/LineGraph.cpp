#include "LineGraph.h"
#include "Assets.h"

LineGraph::LineGraph(RoundedRectangle* _parent, std::vector<int> _dataX, std::vector<double> _dataY, wxString _label, bool oddSem) :
	parent(_parent), dataX(_dataX), dataY(_dataY), label(_label)
{
	SetBackgroundStyle(wxBG_STYLE_PAINT);
	Create(parent, wxID_ANY, wxDefaultPosition, wxSize(parent->GetSize().GetWidth() - 2*parent->r, parent->GetSize().GetHeight() - 2*parent->r));
	AddLabel();
	month = oddSem ? new std::vector<wxString>{ "Bhadra", "Shrawan", "Asar", "Jestha", "Baisakh" } : new std::vector<wxString>{ "Chaitra", "Falgun", "Magh", "Poush", "Mangsir" };
	Bind(wxEVT_PAINT, &LineGraph::OnPaint, this);
};

void LineGraph::AddLabel() 
{
	wxFont* roundFont = new wxFont(16, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxStaticText* roundText = new wxStaticText(parent, wxID_STATIC, label);
	roundText->SetBackgroundColour(parent->color);
	roundText->SetForegroundColour(TEXT_THEME_COLOUR);
	roundText->SetFont(*roundFont);
	wxBoxSizer* roundSizer = new wxBoxSizer(wxVERTICAL);
	roundSizer->Add(roundText, 0, wxTOP | wxALIGN_CENTER_HORIZONTAL, GetSize().GetHeight() / 10.0);
	roundSizer->Add(this, 1, wxALIGN_CENTER_HORIZONTAL);
	parent->SetSizer(roundSizer);
};

void LineGraph::OnPaint(wxPaintEvent&)
{
	SetBackgroundColour(parent->color);
	wxAutoBufferedPaintDC dc(this);
	dc.Clear();
	wxGraphicsContext* gc = wxGraphicsContext::Create(dc);
	if (gc)
	{
		const double marginX = GetSize().GetWidth() / 15.0;
		const double marginY = GetSize().GetHeight() / 10.0;
		wxRect2DDouble graphArea(0, 0, wxDouble(GetRect().width), wxDouble(GetRect().height));
		graphArea.Inset(2.5*marginX, marginY, marginX, 1.5*marginY);

		double xLowValue = *std::min_element(dataX.begin(), dataX.end());
		double xHighValue = *std::max_element(dataX.begin(), dataX.end());
		double xValueSpan = xHighValue - xLowValue;
		double yLowValue = 0;
		double yHighValue = 5;
		double yValueSpan = yHighValue - yLowValue;

		wxAffineMatrix2D normalizedToYValue{};
		normalizedToYValue.Translate(0, yHighValue);
		normalizedToYValue.Scale(1, -1);
		normalizedToYValue.Scale((double)(dataY.size()-1), yValueSpan);

		wxAffineMatrix2D normalizedToGraphArea{};
		normalizedToGraphArea.Translate(graphArea.GetLeft(), graphArea.GetTop());
		normalizedToGraphArea.Scale(graphArea.m_width, graphArea.m_height);
		const int yLines = 11;

		gc->SetPen(wxPen(TEXT_THEME_COLOUR, 2));
		gc->SetFont(wxFont(wxFontInfo(8).Family(wxFONTFAMILY_TELETYPE)), TEXT_THEME_COLOUR);
		int monthCount = 0;
		for (int i = 0; i < yLines; i++) {
			double normalizedLineY = (double)i / (yLines - 1);
			wxPoint2DDouble startPoint = normalizedToGraphArea.TransformPoint({ 0, normalizedLineY });
			wxPoint2DDouble endPoint = normalizedToGraphArea.TransformPoint({ 1, normalizedLineY });
			wxPoint2DDouble linePoints[] = { startPoint, endPoint };
			gc->StrokeLines(2, linePoints);
			if (i % 2 == 0) {
				double tw, th;
				if (monthCount < (*month).size()) {
					gc->GetTextExtent((*month)[monthCount], &tw, &th);
					gc->DrawText((*month)[monthCount++], graphArea.GetLeft() - 5 - tw, startPoint.m_y - th / 2.0);
				}
				else {
					gc->GetTextExtent("CHAPTERS", &tw, &th);
					gc->DrawText("CHAPTERS", graphArea.GetLeft() - 5 - tw, startPoint.m_y - th / 2.0 + 10);
				};
			};
		};

		for (int i = 1; i < dataX.size(); i++) {
			double normalizedLineX = (double)i / (dataX.size() - 1);
			wxPoint2DDouble startPoint = normalizedToGraphArea.TransformPoint({ normalizedLineX, 0 });
			wxPoint2DDouble endPoint = normalizedToGraphArea.TransformPoint({ normalizedLineX, 1 });
			double tw, th;
			wxString text = wxString::Format("%d", dataX[i]);
			gc->GetTextExtent(text, &tw, &th);
			gc->DrawText(text, startPoint.m_x - tw / 2.0, graphArea.GetBottom() + th - 5);
		};

		wxPoint2DDouble leftHLinePoints[] = {
			normalizedToGraphArea.TransformPoint({ 0, 0 }),
			normalizedToGraphArea.TransformPoint({ 0, 1 })
		};

		wxPoint2DDouble rightHLinePoints[] = {
			normalizedToGraphArea.TransformPoint({ 1, 0 }),
			normalizedToGraphArea.TransformPoint({ 1, 1 })
		};

		gc->StrokeLines(2, leftHLinePoints);
		gc->StrokeLines(2, rightHLinePoints);

		std::vector<wxPoint2DDouble> pointVector(dataY.size());
		wxAffineMatrix2D valueToNormalized = normalizedToYValue;
		valueToNormalized.Invert();
		wxAffineMatrix2D valueToChartArea = normalizedToGraphArea;
		valueToChartArea.Concat(valueToNormalized);

		for (int i = 0; i < dataY.size(); i++) pointVector[i] = valueToChartArea.TransformPoint({ (double) i, dataY[i] });

		wxPoint2DDouble* pointArray = &pointVector[0];
		gc->SetPen(wxPen(*wxCYAN, 2));
		gc->StrokeLines(dataY.size(), pointArray);
	};
};
