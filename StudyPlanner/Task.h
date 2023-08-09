#pragma once
#include <string>
#include <vector>

struct Task
{
	std::string date;
	std::string description;
	bool done;

};


void saveTasksToFile(const std::vector<Task>& tasks, const std::string& fileName);
std::vector<Task> loadTasksFromFile(const std::string fileName, const std::string date);
std::vector<int> pendingtaskCount(const std::string fileName);