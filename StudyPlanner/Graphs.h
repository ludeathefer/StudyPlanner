#pragma once
#include "RoundedRectangle.h"
#include "PieChart.h"

class Graphs : public wxPanel
{
private:
	struct Pie {
		RoundedRectangle* parent;
		std::vector <float> data;
		std::vector <wxString> dataLabel;
		wxString graphLabel;
	};
	std::vector<Pie> assignmentPies;
	std::vector<PieChart*> assignmentPieCharts;

	std::vector<Pie> syllabusPies;
	std::vector<PieChart*> syllabusPieCharts;
public:
	Graphs(wxWindow* parent);
	void Initialize();
	void LoadAssignmentsGraph();
	void LoadSyllabusGraph();
};

