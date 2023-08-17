#pragma once
#include <string>
#include "cpr/cpr.h"
#include "libxml/HTMLparser.h"
#include "libxml/xpath.h"
#include <vector>


// define a struct where to store the scraped data
struct IndustryCard
{
    std::string name;
    std::string company;
    std::string location;
    std::string image;
    std::string job_url;
    std::string company_url;
    std::string deadline;
};

class MeroJob
{
 
private: 
    std::string searchKey;
    std::vector<IndustryCard> industry_cards;


public:
    void RetrieveResults( std::string _searchKey );
    std::vector<IndustryCard> GetResults();

};

