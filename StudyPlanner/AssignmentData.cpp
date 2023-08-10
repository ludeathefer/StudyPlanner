#include "AssignmentData.h"
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <algorithm>


void AssignmentData::saveAssignmentsToFile(const std::vector<AssignmentData>& assignments, const std::string& fileName) {

	std::ofstream ostream(fileName);
	ostream << assignments.size();
	for (const AssignmentData& assignment : assignments) {
		std::string description = assignment.description;
		std::replace(description.begin(), description.end(), ' ', '_'); // to replace ever space in assignments with underscore
		ostream << '\n' << assignment.date << ' ' << description << ' ' << assignment.done;
	}
}


std::vector<AssignmentData> AssignmentData::loadAssignmentsFromFile(const std::string fileName) {

	if (!std::filesystem::exists(fileName)) {
		return std::vector<AssignmentData>();
	}
	std::ifstream istream(fileName);
	std::vector<AssignmentData> assignments;

	int num;
	istream >> num;

	for (int i = 0; i < num; i++) {

		std::string desc;
		std::string date;
		bool done;
		istream >> date >> desc >> done;
		if (strcmp(date.c_str(), "08/06/23") == 0) {
			std::replace(desc.begin(), desc.end(), '_', ' ');
			assignments.push_back(AssignmentData{ date, desc, done });
		}

	}

	return assignments;
}

std::vector<int> AssignmentData::pendingassignmentsCount(const std::string fileName)
{
	std::vector<int> count;
	if (!std::filesystem::exists(fileName)) {
		return std::vector<int>();
	}
	int c = 0, p = 0;
	std::ifstream istream(fileName);
	istream >> c;
	count.push_back(c);
	p = 0;
	for (int i = 0; i < c; i++) {

		std::string desc;
		std::string date;
		bool donee;
		istream >> date >> desc >> donee;
		if (!donee) p++;
	}
	count.push_back(p);
	return count;
}


