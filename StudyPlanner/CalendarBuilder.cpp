#include "CalendarBuilder.h"
#include <map>
#include <vector>
#include <wx/datetime.h>
#include <string>


std::map<int, std::vector<int>> nepaliMap;


std::vector<std::string> CalendarBuilder::getDays()
{
    days.push_back("SUN");
    days.push_back("MON");
    days.push_back("TUE");
    days.push_back("WED");
    days.push_back("THU");
    days.push_back("FRI");
    days.push_back("SAT");
    return days;
}

std::vector<std::string> CalendarBuilder::getDates()
{
    dates.push_back("");
    dates.push_back("");
    for (int i = 1; i < 32; i++) {
        if (i < 10) {
            std::string x = "0" + std::to_string(i);
            dates.push_back(x);
        }
        else {
            std::string x = std::to_string(i);
            dates.push_back(x);
        }
    }
    dates.push_back("");
    dates.push_back("");

    return dates;
}

std::string CalendarBuilder::getEqvNepaliDate()
{

    nepaliMap[2000] = { 0, 30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31 };
    nepaliMap[2001] = { 0, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2002] = { 0, 31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2003] = { 0, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31 };
    nepaliMap[2004] = { 0, 30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31 };
    nepaliMap[2005] = { 0, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2006] = { 0, 31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2007] = { 0, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31 };
    nepaliMap[2008] = { 0, 31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 29, 31 };
    nepaliMap[2009] = { 0, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2010] = { 0, 31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2011] = { 0, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31 };
    nepaliMap[2012] = { 0, 31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 30, 30 };
    nepaliMap[2013] = { 0, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2014] = { 0, 31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2015] = { 0, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31 };
    nepaliMap[2016] = { 0, 31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 30, 30 };
    nepaliMap[2017] = { 0, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2018] = { 0, 31, 32, 31, 32, 31, 30, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2019] = { 0, 31, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31 };
    nepaliMap[2020] = { 0, 31, 31, 31, 32, 31, 31, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2021] = { 0, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2022] = { 0, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 30 };
    nepaliMap[2023] = { 0, 31, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31 };
    nepaliMap[2024] = { 0, 31, 31, 31, 32, 31, 31, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2025] = { 0, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2026] = { 0, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31 };
    nepaliMap[2027] = { 0, 30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31 };
    nepaliMap[2028] = { 0, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2029] = { 0, 31, 31, 32, 31, 32, 30, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2030] = { 0, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31 };
    nepaliMap[2031] = { 0, 30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31 };
    nepaliMap[2032] = { 0, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2033] = { 0, 31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2034] = { 0, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31 };
    nepaliMap[2035] = { 0, 30, 32, 31, 32, 31, 31, 29, 30, 30, 29, 29, 31 };
    nepaliMap[2036] = { 0, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2037] = { 0, 31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2038] = { 0, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31 };
    nepaliMap[2039] = { 0, 31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 30, 30 };
    nepaliMap[2040] = { 0, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2041] = { 0, 31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2042] = { 0, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31 };
    nepaliMap[2043] = { 0, 31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 30, 30 };
    nepaliMap[2044] = { 0, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2045] = { 0, 31, 32, 31, 32, 31, 30, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2046] = { 0, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31 };
    nepaliMap[2047] = { 0, 31, 31, 31, 32, 31, 31, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2048] = { 0, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2049] = { 0, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 30 };
    nepaliMap[2050] = { 0, 31, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31 };
    nepaliMap[2051] = { 0, 31, 31, 31, 32, 31, 31, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2052] = { 0, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2053] = { 0, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 30 };
    nepaliMap[2054] = { 0, 31, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31 };
    nepaliMap[2055] = { 0, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2056] = { 0, 31, 31, 32, 31, 32, 30, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2057] = { 0, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31 };
    nepaliMap[2058] = { 0, 30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31 };
    nepaliMap[2059] = { 0, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2060] = { 0, 31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2061] = { 0, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31 };
    nepaliMap[2062] = { 0, 30, 32, 31, 32, 31, 31, 29, 30, 29, 30, 29, 31 };
    nepaliMap[2063] = { 0, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2064] = { 0, 31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2065] = { 0, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31 };
    nepaliMap[2066] = { 0, 31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 29, 31 };
    nepaliMap[2067] = { 0, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2068] = { 0, 31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2069] = { 0, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31 };
    nepaliMap[2070] = { 0, 31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 30, 30 };
    nepaliMap[2071] = { 0, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2072] = { 0, 31, 32, 31, 32, 31, 30, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2073] = { 0, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31 };
    nepaliMap[2074] = { 0, 31, 31, 31, 32, 31, 31, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2075] = { 0, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2076] = { 0, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 30 };
    nepaliMap[2077] = { 0, 31, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31 };
    nepaliMap[2078] = { 0, 31, 31, 31, 32, 31, 31, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2079] = { 0, 31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30 };
    nepaliMap[2080] = { 0, 31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 30 };
    nepaliMap[2081] = { 0, 31, 31, 32, 32, 31, 30, 30, 30, 29, 30, 30, 30 };
    nepaliMap[2082] = { 0, 30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 30, 30 };
    nepaliMap[2083] = { 0, 31, 31, 32, 31, 31, 30, 30, 30, 29, 30, 30, 30 };
    nepaliMap[2084] = { 0, 31, 31, 32, 31, 31, 30, 30, 30, 29, 30, 30, 30 };
    nepaliMap[2085] = { 0, 31, 32, 31, 32, 30, 31, 30, 30, 29, 30, 30, 30 };
    nepaliMap[2086] = { 0, 30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 30, 30 };
    nepaliMap[2087] = { 0, 31, 31, 32, 31, 31, 31, 30, 30, 29, 30, 30, 30 };
    nepaliMap[2088] = { 0, 30, 31, 32, 32, 30, 31, 30, 30, 29, 30, 30, 30 };
    nepaliMap[2089] = { 0, 30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 30, 30 };
    nepaliMap[2090] = { 0, 30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 30, 30 };

    int startingEngYear = 1944;
    int startingEngMonth = 1;
    int startingEngDay = 1;
    int dayOfWeek = 7; // 1944/1/1 is Saturday
    int startingNepYear = 2000;
    int startingNepMonth = 9;
    int startingNepDay = 17;
    wxDateTime dt1, dt2;
    dt2 = wxDateTime::Now();
    dt1.ParseFormat("01.01.1944", "%d.%m.%Y");
    dt2.ParseFormat(dt2.Format(wxT("%d.%m.%Y")), "%d.%m.%Y");
    wxTimeSpan ts = dt2.Subtract(dt1); // get the exact difference as a time span
    int days = ts.GetDays(); // get the number of days in the time span

    int totalEngDaysCount = days;
    int nepYear = startingNepYear;
    int nepMonth = startingNepMonth;
    int nepDay = startingNepDay;

    while (totalEngDaysCount != 0) {

        int daysInIthMonth = nepaliMap.at(nepYear)[nepMonth];

        nepDay++; // incrementing nepali day

        if (nepDay > daysInIthMonth) {
            nepMonth++;
            nepDay = 1;
        }
        if (nepMonth > 12) {
            nepYear++;
            nepMonth = 1;
        }

        dayOfWeek++; // count the days in terms of 7 days
        if (dayOfWeek > 7) {
            dayOfWeek = 1;
        }

        totalEngDaysCount--;
    }

    std::string nepaliDate = std::to_string(nepDay) + ' ' + getMonthName(nepMonth) + ' ' + std::to_string(nepYear);
    // std::string nepaliDate = std::to_string(days);


    return (nepaliDate);
}

std::string CalendarBuilder::getMonthName(int num)
{
    switch (num) {
    case 1:
        return "Baisakh";
    case 2:
        return "Jestha";
    case 3:
        return "Asadh";
    case 4:
        return "Shrawan";
    case 5:
        return "Bhadra";
    case 6:
        return "Ashwin";
    case 7:
        return "Karthik";
    case 8:
        return "Mangsir";
    case 9:
        return "Poush";
    case 10:
        return "Magh";
    case 11:
        return "Falgun";
    case 12:
        return "Chaitra";
    }
}