#pragma once
#include<string>
#include<vector>
class CalendarBuilder {
	std::vector<std::string> days;
	std::vector<std::string> dates;
public:
	std::vector<std::string> getDays();
	std::vector<std::string> getDates();
	std::string getMonthName(int num);
	std::string getEqvNepaliDate(int day, int month, int year);


};
