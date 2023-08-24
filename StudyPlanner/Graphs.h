#pragma once
#include "RoundedRectangle.h"
#include "PieChart.h"
#include "LineGraph.h"

class Graphs : public wxPanel
{
private:
	struct Pie {
		RoundedRectangle* parent;
		std::vector <float> data;
		std::vector <wxString> dataLabel;
		wxString graphLabel;
	};

	struct Line{
		RoundedRectangle* parent;
		std::vector <int> dataX;
		std::vector <double> dataY;
		wxString graphLabel;
	};

	std::vector<Pie> assignmentPies;
	std::vector<PieChart*> assignmentPieCharts;

	std::vector<Pie> syllabusPies;
	std::vector<PieChart*> syllabusPieCharts;

	std::vector<Line> revisionLines;
	std::vector<LineGraph*> revisionLineGraphs;

public:
	Graphs(wxWindow* parent);
	void Initialize();
	void LoadAssignmentsGraph();
	void LoadSyllabusGraph();
	void LoadRevisionGraph();
};

