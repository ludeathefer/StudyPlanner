#pragma once
#include <string>
#include "cpr/cpr.h"
#include "libxml/HTMLparser.h"
#include "libxml/xpath.h"
#include <vector>


// define a struct where to store the scraped data
struct JobCard
{
    std::string name;
    std::string company;
    std::string location;
    std::string image;
    std::string job_url;
    std::string company_url;
    std::string deadline;
};

struct CompanyPageCard {
    std::string industry;
    std::string companysize;
    std::string location;
    std::vector<JobCard> companyjob_cards;
};

struct JobDetailCard {
    std::string jobcat;
    std::string joblevel;
    std::string emptype;
    std::string location;
    std::string salary;
    std::string deadline;
    std::string edulevel;
    std::string explevel;
    std::string jobDesc;
    std::vector<JobCard> similar_job_cards;

};

class MeroJob
{
 private: 
    std::string searchKey;
    std::vector<JobCard> job_cards;
    CompanyPageCard c1;
    JobDetailCard j1;
   
public:
    void RetrieveResults( std::string _searchKey);
    std::vector<JobCard> GetResults();
    CompanyPageCard GetCompanyDetails();
    JobDetailCard GetJobDetails();
    void ClearElements();
    void RetrieveCompanyDetails(std::string _key);  
    void RetrieveJobDetails(std::string _url);

};

