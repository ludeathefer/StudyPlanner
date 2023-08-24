#include "MeroJob.h"
#include <string>
#include "cpr/cpr.h"
#include "libxml/HTMLparser.h"
#include "libxml/xpath.h"
#include <vector>

void MeroJob::RetrieveResults(std::string _searchKey = "Software Engineer")
{
	std::replace(_searchKey.begin(), _searchKey.end(), ' ', '+'); // to replace every space in tasks with plus
	searchKey = _searchKey;

    // define the user agent for the GET request
    cpr::Header headers = { {"User-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/113.0.0.0 Safari/537.36"} };
    // make an HTTP GET request to retrieve the target page
    std::string url_str = "https://merojob.com/search/?q=" + _searchKey ;
    cpr::Url url(url_str);
    cpr::Response response = cpr::Get(url, headers);

    // parse the HTML document returned by the server
    htmlDocPtr doc = htmlReadMemory(response.text.c_str(), (int) response.text.length(), nullptr, nullptr, HTML_PARSE_NOWARNING | HTML_PARSE_NOERROR);

 
 
    // set the libxml2 context to the current document
    xmlXPathContextPtr context = xmlXPathNewContext(doc);
    // select all result card HTML elements
    // with an XPath selector
    xmlXPathObjectPtr job_card_html_elements = xmlXPathEvalExpression((xmlChar*)"//div[contains(@id, 'search_job')]//div[contains(@class, 'card mt-3')]", context);

    for (int i = 0; i < job_card_html_elements->nodesetval->nodeNr; ++i)
    {

        xmlNodePtr job_card_html_element = job_card_html_elements->nodesetval->nodeTab[i];
        xmlXPathSetContextNode(job_card_html_element, context);


        xmlNodePtr name_html_element = xmlXPathEvalExpression((xmlChar*)".//div/div/div[2]/h1/a", context)->nodesetval->nodeTab[0];
        std::string name = std::string(reinterpret_cast<char*>(xmlGetProp(name_html_element, (xmlChar*)"title")));
        std::string job_url = std::string(reinterpret_cast<char*>(xmlGetProp(name_html_element, (xmlChar*)"href")));

        xmlNodePtr company_name_html_element = xmlXPathEvalExpression((xmlChar*)".//div[1]/div/div[2]/h3/a", context)->nodesetval->nodeTab[0];
        std::string company_url = std::string(reinterpret_cast<char*>(xmlGetProp(company_name_html_element, (xmlChar*)"href")));
        std::string company = std::string(reinterpret_cast<char*>(xmlNodeGetContent(company_name_html_element)));



        xmlNodePtr image_html_element = xmlXPathEvalExpression((xmlChar*)".//div/div/div[1]/img", context)->nodesetval->nodeTab[0];
        std::string image = std::string(reinterpret_cast<char*>(xmlGetProp(image_html_element, (xmlChar*)"src")));

        xmlNodePtr deadline_html_element = xmlXPathEvalExpression((xmlChar*)".//div[2]/div/div[1]/p", context)->nodesetval->nodeTab[0];
        std::string deadline = std::string(reinterpret_cast<char*>(xmlNodeGetContent(deadline_html_element)));

        xmlNodePtr location_html_element = xmlXPathEvalExpression((xmlChar*)".//div[1]/div/div[2]/div/div/div[2]/span/span", context)->nodesetval->nodeTab[0];
        std::string location = std::string(reinterpret_cast<char*>(xmlNodeGetContent(location_html_element)));




        JobCard job_card = { name, company, location, image, job_url, company_url, deadline }; //location is not written for time being cuz "," messes up the csv


        job_cards.push_back(job_card);
    }

    xmlXPathFreeObject(job_card_html_elements);
    xmlXPathFreeContext(context);
    xmlFreeDoc(doc);

    std::ofstream csv_file("output.csv");

    csv_file << "name,company,location,image,joburl,companyurl,deadline" << std::endl;
    for (JobCard industry_card : job_cards)
    {
        csv_file << industry_card.name << "," << industry_card.company << "," << industry_card.location << "," << industry_card.image << "," << industry_card.job_url << "," << industry_card.company_url << "," << industry_card.deadline << std::endl;
    }

    csv_file.close();

}

std::vector<JobCard> MeroJob::GetResults()
{
    return job_cards;
}


void MeroJob::ClearElements() {
 
    job_cards.clear();
}

void MeroJob::RetrieveCompanyDetails(std::string _key)
{
    // define the user agent for the GET request
    cpr::Header headers = { {"User-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/113.0.0.0 Safari/537.36"} };
    // make an HTTP GET request to retrieve the target page
    //std::string url_str =  _key;
    std::string url_str = "https://merojob.com/employer/cedar-gate-services-pvt-ltd/";
    cpr::Url url(url_str);
    cpr::Response response = cpr::Get(url, headers);

    // parse the HTML document returned by the server
    htmlDocPtr doc = htmlReadMemory(response.text.c_str(), response.text.length(), nullptr, nullptr, HTML_PARSE_NOWARNING | HTML_PARSE_NOERROR);


    // set the libxml2 context to the current document
    xmlXPathContextPtr context = xmlXPathNewContext(doc);

    xmlNodePtr industry_html_element = xmlXPathEvalExpression((xmlChar*)"//div[contains(@class, 'card-body p-1')]//span[2]", context)->nodesetval->nodeTab[0];
    std::string industry = std::string(reinterpret_cast<char*>(xmlNodeGetContent(industry_html_element)));
    c1.industry = industry;

    xmlNodePtr company_size_html_element = xmlXPathEvalExpression((xmlChar*)"//div[contains(@class, 'card-body p-1')]//span[4]", context)->nodesetval->nodeTab[0];
    std::string companySize = std::string(reinterpret_cast<char*>(xmlNodeGetContent(company_size_html_element)));
    c1.companysize = companySize;

    xmlNodePtr location_html_element = xmlXPathEvalExpression((xmlChar*)"//div[contains(@class, 'card-body p-1')]//span[7]", context)->nodesetval->nodeTab[0];
    std::string companyLocation = std::string(reinterpret_cast<char*>(xmlNodeGetContent(location_html_element)));
    c1.location = companyLocation;


    // select all result card HTML elements
   // with an XPath selector
    xmlXPathObjectPtr job_card_html_elements = xmlXPathEvalExpression((xmlChar*)"//div[contains(@class, 'col-md-12 mt-3')]", context);

    // iterate over the list of industry card elements
    for (int i = 0; i < job_card_html_elements->nodesetval->nodeNr; ++i)
    {

        xmlNodePtr job_card_html_element = job_card_html_elements->nodesetval->nodeTab[i];
        xmlXPathSetContextNode(job_card_html_element, context);


        xmlNodePtr name_html_element = xmlXPathEvalExpression((xmlChar*)".//div/div[1]/div[2]/h1/a", context)->nodesetval->nodeTab[0];
        std::string name = std::string(reinterpret_cast<char*>(xmlGetProp(name_html_element, (xmlChar*)"title")));
        std::string job_url = std::string(reinterpret_cast<char*>(xmlGetProp(name_html_element, (xmlChar*)"href")));

        xmlNodePtr company_name_html_element = xmlXPathEvalExpression((xmlChar*)".//div/div[1]/div[2]/h3/a", context)->nodesetval->nodeTab[0];
        std::string company_url = std::string(reinterpret_cast<char*>(xmlGetProp(company_name_html_element, (xmlChar*)"href")));
        std::string company = std::string(reinterpret_cast<char*>(xmlNodeGetContent(company_name_html_element)));




        xmlNodePtr deadline_html_element = xmlXPathEvalExpression((xmlChar*)"./div/div[3]/div/div/div[1]/p/span[2]", context)->nodesetval->nodeTab[0];
        std::string deadline = std::string(reinterpret_cast<char*>(xmlNodeGetContent(deadline_html_element)));

        xmlNodePtr location_html_element = xmlXPathEvalExpression((xmlChar*)".//div/div[2]/div[2]/div[2]/span/span/span", context)->nodesetval->nodeTab[0];
        std::string location = std::string(reinterpret_cast<char*>(xmlNodeGetContent(location_html_element)));




        JobCard job_card = { name, company, location, "image", job_url, company_url, deadline }; //location is not written for time being cuz "," messes up the csv


        c1.companyjob_cards.push_back(job_card);
  
    }

    xmlXPathFreeObject(job_card_html_elements);
    xmlXPathFreeContext(context);
    xmlFreeDoc(doc);


}

void MeroJob::RetrieveJobDetails(std::string _url)
{
    // define the user agent for the GET request
    cpr::Header headers = { {"User-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/113.0.0.0 Safari/537.36"} };
    // make an HTTP GET request to retrieve the target page
    //std::string url_str =  _key;
    std::string url_str = "https://merojob.com/software-engineer-laravel-reactjs-full-stack/";
    cpr::Url url(url_str);
    cpr::Response response = cpr::Get(url, headers);

    // parse the HTML document returned by the server
    htmlDocPtr doc = htmlReadMemory(response.text.c_str(), response.text.length(), nullptr, nullptr, HTML_PARSE_NOWARNING | HTML_PARSE_NOERROR);

    // set the libxml2 context to the current document
    xmlXPathContextPtr context = xmlXPathNewContext(doc);

    std::string temp;

    xmlNodePtr job_cat_html_element = xmlXPathEvalExpression((xmlChar*)"//table[contains(@class, 'table-hover m-0')]//tr[td[1]='Job Category']/td[3]/a", context)->nodesetval->nodeTab[0];
    temp = std::string(reinterpret_cast<char*>(xmlNodeGetContent(job_cat_html_element)));
    j1.jobcat = temp;

    
    xmlNodePtr job_level_html_element = xmlXPathEvalExpression((xmlChar*)"//table[contains(@class, 'table-hover m-0')]//tr[td[1]='Job Level']/td[3]/a", context)->nodesetval->nodeTab[0];    
    temp = std::string(reinterpret_cast<char*>(xmlNodeGetContent(job_level_html_element)));
    j1.joblevel = temp;

    xmlNodePtr emp_type_html_element = xmlXPathEvalExpression((xmlChar*)"//table[contains(@class, 'table-hover m-0')]//tr[td[1]='Employment Type']/td[3]", context)->nodesetval->nodeTab[0];
    temp = std::string(reinterpret_cast<char*>(xmlNodeGetContent(emp_type_html_element)));
    j1.emptype = temp;

    xmlNodePtr location_html_element = xmlXPathEvalExpression((xmlChar*)"//table[contains(@class, 'table-hover m-0')]//tr[td[1]='Job Location']/td[3]", context)->nodesetval->nodeTab[0];
    temp = std::string(reinterpret_cast<char*>(xmlNodeGetContent(location_html_element)));
    j1.location = temp;

    xmlNodePtr salary_html_element = xmlXPathEvalExpression((xmlChar*)"//table[contains(@class, 'table-hover m-0')]//tr[td[1]='Offered Salary']/td[3]", context)->nodesetval->nodeTab[0];
    temp = std::string(reinterpret_cast<char*>(xmlNodeGetContent(salary_html_element)));
    j1.salary = temp;

    xmlNodePtr deadline_html_element = xmlXPathEvalExpression((xmlChar*)"//table[contains(@class, 'table-hover m-0')]//tr[td[1]//span='(Deadline)']/td[3]", context)->nodesetval->nodeTab[0];
    temp = std::string(reinterpret_cast<char*>(xmlNodeGetContent(deadline_html_element)));
    j1.deadline = temp;


    xmlNodePtr edu_level_html_element = xmlXPathEvalExpression((xmlChar*)"//table[contains(@class, 'table-hover m-0')]//tr[td[1]='Education Level']/td[3]", context)->nodesetval->nodeTab[0];
    temp = std::string(reinterpret_cast<char*>(xmlNodeGetContent(edu_level_html_element)));
    j1.edulevel = temp;

    xmlNodePtr exp_level_html_element = xmlXPathEvalExpression((xmlChar*)"//table[contains(@class, 'table-hover m-0')]//tr[td[1]='Experience Required']/td[3]", context)->nodesetval->nodeTab[0];
    temp = std::string(reinterpret_cast<char*>(xmlNodeGetContent(exp_level_html_element)));
    j1.explevel = temp;

    //xmlNodePtr job_desc_html_element = xmlXPathEvalExpression((xmlChar*)"//div[@class='card-text p-2']/following-sibling::div[@class='card-text p-2']/p[1]", context)->nodesetval->nodeTab[0];
    //temp = std::string(reinterpret_cast<char*>(xmlNodeGetContent(job_desc_html_element)));
    j1.jobDesc = temp;



    // select all result card HTML elements
   // with an XPath selector
    xmlXPathObjectPtr job_card_html_elements = xmlXPathEvalExpression((xmlChar*)"//div[contains(@class, 'card mt-3 mb-0')]//div[contains(@class, 'card-group mb-md-3')]", context);

    // iterate over the list of industry card elements
    for (int i = 0; i < job_card_html_elements->nodesetval->nodeNr; ++i)
    {

        xmlNodePtr job_card_html_element = job_card_html_elements->nodesetval->nodeTab[i];
        xmlXPathSetContextNode(job_card_html_element, context);


        xmlNodePtr name_html_element = xmlXPathEvalExpression((xmlChar*)".//div/div/div/div[2]/ul/li[1]/a", context)->nodesetval->nodeTab[0];
        std::string name = std::string(reinterpret_cast<char*>(xmlNodeGetContent(name_html_element)));
        std::string job_url = std::string(reinterpret_cast<char*>(xmlGetProp(name_html_element, (xmlChar*)"href")));

        xmlNodePtr company_name_html_element = xmlXPathEvalExpression((xmlChar*)".//div/div/div/div[2]/ul/li[2]/small/a", context)->nodesetval->nodeTab[0];
        std::string company_url = std::string(reinterpret_cast<char*>(xmlGetProp(company_name_html_element, (xmlChar*)"href")));
        std::string company = std::string(reinterpret_cast<char*>(xmlNodeGetContent(company_name_html_element)));




        xmlNodePtr deadline_html_element = xmlXPathEvalExpression((xmlChar*)".//div/div/div/div[2]/ul/li[3]/small", context)->nodesetval->nodeTab[0];
        std::string deadline = std::string(reinterpret_cast<char*>(xmlNodeGetContent(deadline_html_element)));

        //xmlNodePtr location_html_element = xmlXPathEvalExpression((xmlChar*)".//div/div[2]/div[2]/div[2]/span/span/span", context)->nodesetval->nodeTab[0];
        //std::string location = std::string(reinterpret_cast<char*>(xmlNodeGetContent(location_html_element)));




        JobCard job_card = { name, company, "location", "image", job_url, company_url, deadline }; //location is not written for time being cuz "," messes up the csv


        j1.similar_job_cards.push_back(job_card);

    }

    xmlXPathFreeObject(job_card_html_elements);
    xmlXPathFreeContext(context);
    xmlFreeDoc(doc);




}

CompanyPageCard MeroJob::GetCompanyDetails()
{
    return c1;
}

JobDetailCard MeroJob::GetJobDetails()
{
    return j1;
}


