#include "LineGraph.h"
#include "Assets.h"

LineGraph::LineGraph(RoundedRectangle* _parent, std::vector<float> _dataX, std::vector<float> _dataY, wxString _label) :
	parent(_parent), dataX(_dataX), dataY(_dataY), label(_label)
{
	SetBackgroundStyle(wxBG_STYLE_PAINT);
	Create(parent, wxID_ANY, wxDefaultPosition, wxSize(parent->GetSize().GetWidth() - 2*parent->r, parent->GetSize().GetHeight() - 2*parent->r));
	AddLabel();
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
	roundSizer->Add(roundText, 0, wxTOP | wxALIGN_CENTER_HORIZONTAL, 20);
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
		const double marginX = GetSize().GetWidth() / 20.0;
		const double marginY = GetSize().GetHeight() / 10.0;
		wxRect2DDouble graphArea(0, 0, wxDouble(GetRect().width), wxDouble(GetRect().height));
		graphArea.Inset(2*marginX, marginY, marginX, marginY);

		double xLowValue = *std::min_element(dataX.begin(), dataX.end());
		double xHighValue = *std::max_element(dataX.begin(), dataX.end());
		double xValueSpan = xHighValue - xLowValue;
		double yLowValue = *std::min_element(dataY.begin(), dataY.end());
		double yHighValue = *std::max_element(dataY.begin(), dataY.end());
		double yValueSpan = yHighValue - yLowValue;

		wxAffineMatrix2D normalizedToYValue{};
		normalizedToYValue.Translate(0, yHighValue);
		normalizedToYValue.Scale(1, -1);
		normalizedToYValue.Scale((double)(dataY.size()-1), yValueSpan);

		wxAffineMatrix2D normalizedToGraphArea{};
		normalizedToGraphArea.Translate(graphArea.GetLeft(), graphArea.GetTop());
		normalizedToGraphArea.Scale(graphArea.m_width, graphArea.m_height);
		const int yLines = 9;

		gc->SetPen(wxPen(TEXT_THEME_COLOUR, 2));
		gc->SetFont(wxFont(wxFontInfo(8).Family(wxFONTFAMILY_TELETYPE)), TEXT_THEME_COLOUR);
		for (int i = 0; i < yLines; i++) {
			double normalizedLineY = (double)i / (yLines - 1);
			wxPoint2DDouble startPoint = normalizedToGraphArea.TransformPoint({ 0, normalizedLineY });
			wxPoint2DDouble endPoint = normalizedToGraphArea.TransformPoint({ 1, normalizedLineY });
			wxPoint2DDouble linePoints[] = { startPoint, endPoint };
			gc->StrokeLines(2, linePoints);
			double valueAtY = normalizedToYValue.TransformPoint({ 0, normalizedLineY }).m_y;
			wxString text = wxString::Format("%.2f", valueAtY);
			text = wxControl::Ellipsize(text, dc, wxELLIPSIZE_MIDDLE, graphArea.GetLeft());
			double tw, th;
			gc->GetTextExtent(text, &tw, &th);
			gc->DrawText(text, graphArea.GetLeft() - 5 - tw, startPoint.m_y - th / 2.0);
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

		wxPoint2DDouble* pointArray = new wxPoint2DDouble[dataY.size()];
		wxAffineMatrix2D valueToNormalized = normalizedToYValue;
		valueToNormalized.Invert();
		wxAffineMatrix2D valueToChartArea = normalizedToGraphArea;
		valueToChartArea.Concat(valueToNormalized);

		for (int i = 0; i < dataY.size(); i++) pointArray[i] = valueToChartArea.TransformPoint({ (double) i, dataY[i] });

		gc->SetPen(wxPen(*wxCYAN, 2));
		gc->StrokeLines(dataY.size(), pointArray);
	};
};
