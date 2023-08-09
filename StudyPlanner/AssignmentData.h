#pragma once
#include <string>
#include <vector>

class AssignmentData
{
public:
	std::string date;
	std::string description;
	bool done;


	void saveAssignmentsToFile(const std::vector<AssignmentData>& assignments, const std::string& fileName);
	std::vector<AssignmentData> loadAssignmentsFromFile(const std::string fileName);
	std::vector<int> pendingassignmentsCount(const std::string fileName);

};