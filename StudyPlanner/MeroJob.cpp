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



       // xmlNodePtr deadline_html_element = xmlXPathEvalExpression((xmlChar*)".//div[2]/div/div[1]/p", context)->nodesetval->nodeTab[0];
        std::string deadline;


        try {
            xmlNodePtr deadline_html_element;
            xmlXPathObjectPtr xpathObj = xmlXPathEvalExpression((xmlChar*)".//div[2]/div/div[1]/p", context);
            if (xpathObj == NULL) {
                deadline = "N/A";

                return;
            }
            if (xpathObj->nodesetval == nullptr || xpathObj->nodesetval->nodeTab == nullptr) {
                throw "Null pointer exception";
            }
            deadline_html_element = xpathObj->nodesetval->nodeTab[0];
            if (deadline_html_element == NULL) {
                throw "Null pointer exception";
            }
            deadline = std::string(reinterpret_cast<char*>(xmlNodeGetContent(deadline_html_element)));
        }
        catch (const char* e) {

            deadline = "N/A";
        }


       // xmlNodePtr location_html_element = xmlXPathEvalExpression((xmlChar*)".//div[1]/div/div[2]/div/div/div[2]/span/span", context)->nodesetval->nodeTab[0];
        std::string location;
        

        try {
            xmlNodePtr location_html_element;
            xmlXPathObjectPtr xpathObj = xmlXPathEvalExpression((xmlChar*)".//div[1]/div/div[2]/div/div/div[2]/span/span", context);
            if (xpathObj == NULL) {
                location = "N/A";

                return;
            }
            if (xpathObj->nodesetval == nullptr || xpathObj->nodesetval->nodeTab == nullptr) {
                throw "Null pointer exception";
            }
            location_html_element = xpathObj->nodesetval->nodeTab[0];
            if (location_html_element == NULL) {
                throw "Null pointer exception";
            }
            location = std::string(reinterpret_cast<char*>(xmlNodeGetContent(location_html_element)));
        }
        catch (const char* e) {

            location = "N/A";
        }
        


        JobCard job_card = { name, company, location, "image", job_url, company_url, deadline }; //location is not written for time being cuz "," messes up the csv


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

void MeroJob::RetrieveCompanyDetails(std::string _url)
{
    // define the user agent for the GET request
    cpr::Header headers = { {"User-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/113.0.0.0 Safari/537.36"} };
    // make an HTTP GET request to retrieve the target page
    //std::string url_str =  _key;
    
    cpr::Url url(_url);
    cpr::Response response = cpr::Get(url, headers);

    // parse the HTML document returned by the server
    htmlDocPtr doc = htmlReadMemory(response.text.c_str(), response.text.length(), nullptr, nullptr, HTML_PARSE_NOWARNING | HTML_PARSE_NOERROR);


    // set the libxml2 context to the current document
    xmlXPathContextPtr context = xmlXPathNewContext(doc);

    try {
        xmlNodePtr industry_html_element;
        xmlXPathObjectPtr xpathObj = xmlXPathEvalExpression((xmlChar*)"//div[contains(@class, 'card-body p-1')]//span[2]", context);
        if (xpathObj == NULL) {
            c1.industry = "N/A";
            return;
        }
        if (xpathObj->nodesetval == nullptr || xpathObj->nodesetval->nodeTab == nullptr) {
            throw "Null pointer exception";
        }
        industry_html_element = xpathObj->nodesetval->nodeTab[0];
        if (industry_html_element == NULL) {
            throw "Null pointer exception";
        }
        std::string industry = std::string(reinterpret_cast<char*>(xmlNodeGetContent(industry_html_element)));
        c1.industry = industry;
    }
    catch (const char* e) {
        // Assign "Bye" to the pointer
        c1.industry = "N/A";
    }

    try {
        xmlNodePtr company_size_html_element;
        xmlXPathObjectPtr xpathObj = xmlXPathEvalExpression((xmlChar*)"//div[contains(@class, 'card-body p-1')]//span[4]", context);
        if (xpathObj == NULL) {
            c1.companysize = "N/A";
            return;
        }
        if (xpathObj->nodesetval == nullptr || xpathObj->nodesetval->nodeTab == nullptr) {
            throw "Null pointer exception";
        }
        company_size_html_element = xpathObj->nodesetval->nodeTab[0];
        if (company_size_html_element == NULL) {
            throw "Null pointer exception";
        }
        std::string companySize = std::string(reinterpret_cast<char*>(xmlNodeGetContent(company_size_html_element)));
        c1.companysize = companySize;
    }
    catch (const char* e) {
        // Assign "Bye" to the pointer
        c1.companysize = "N/A";
    }

    try {
        xmlNodePtr location_html_element;
        xmlXPathObjectPtr xpathObj = xmlXPathEvalExpression((xmlChar*)"//div[contains(@class, 'card-body p-1')]//span[7]", context);
        if (xpathObj == NULL) {
            c1.location = "N/A";
            return;
        }
        if (xpathObj->nodesetval == nullptr || xpathObj->nodesetval->nodeTab == nullptr) {
            throw "Null pointer exception";
        }
        location_html_element = xpathObj->nodesetval->nodeTab[0];
        if (location_html_element == NULL) {
            throw "Null pointer exception";
        }
        std::string location = std::string(reinterpret_cast<char*>(xmlNodeGetContent(location_html_element)));
        c1.location = location;
    }
    catch (const char* e) {
        // Assign "Bye" to the pointer
        c1.location = "N/A";
    }



    // select all result card HTML elements
   // with an XPath selector
    xmlXPathObjectPtr job_card_html_elements = xmlXPathEvalExpression((xmlChar*)"//div[contains(@class, 'col-md-12 mt-3')]", context);

    // iterate over the list of industry card elements
    for (int i = 0; i < job_card_html_elements->nodesetval->nodeNr; ++i)
    {

        xmlNodePtr job_card_html_element = job_card_html_elements->nodesetval->nodeTab[i];
        xmlXPathSetContextNode(job_card_html_element, context);

        std::string name, job_url, company_url, company, deadline, location;

        try {
            xmlNodePtr name_html_element;
            xmlXPathObjectPtr xpathObj = xmlXPathEvalExpression((xmlChar*)".//div/div[1]/div[2]/h1/a", context);
            if (xpathObj == NULL) {
                name = "N/A";
                job_url = "";
                return;
            }
            if (xpathObj->nodesetval == nullptr || xpathObj->nodesetval->nodeTab == nullptr) {
                throw "Null pointer exception";
            }
            name_html_element = xpathObj->nodesetval->nodeTab[0];
            if (name_html_element == NULL) {
                throw "Null pointer exception";
            }
             name = std::string(reinterpret_cast<char*>(xmlGetProp(name_html_element, (xmlChar*)"title")));
            job_url = std::string(reinterpret_cast<char*>(xmlGetProp(name_html_element, (xmlChar*)"href")));
        }
        catch (const char* e) {
           
            name = "N/A";
            job_url = "";
        }


        xmlNodePtr company_name_html_element = xmlXPathEvalExpression((xmlChar*)".//div/div[1]/div[2]/h3/a", context)->nodesetval->nodeTab[0];
        company_url = std::string(reinterpret_cast<char*>(xmlGetProp(company_name_html_element, (xmlChar*)"href")));
        company = std::string(reinterpret_cast<char*>(xmlNodeGetContent(company_name_html_element)));



        try {
            xmlNodePtr deadline_html_element;
            xmlXPathObjectPtr xpathObj = xmlXPathEvalExpression((xmlChar*)"./div/div[3]/div/div/div[1]/p/span[2]", context);
            if (xpathObj == NULL) {
                deadline = "N/A";
              
                return;
            }
            if (xpathObj->nodesetval == nullptr || xpathObj->nodesetval->nodeTab == nullptr) {
                throw "Null pointer exception";
            }
            deadline_html_element = xpathObj->nodesetval->nodeTab[0];
            if (deadline_html_element == NULL) {
                throw "Null pointer exception";
            }
            deadline = std::string(reinterpret_cast<char*>(xmlNodeGetContent(deadline_html_element)));
        }
        catch (const char* e) {

            deadline = "N/A";
        }

        try {
            xmlNodePtr location_html_element;
            xmlXPathObjectPtr xpathObj = xmlXPathEvalExpression((xmlChar*)".//div/div[2]/div[2]/div[2]/span/span/span", context);
            if (xpathObj == NULL) {
                location = "N/A";

                return;
            }
            if (xpathObj->nodesetval == nullptr || xpathObj->nodesetval->nodeTab == nullptr) {
                throw "Null pointer exception";
            }
            location_html_element = xpathObj->nodesetval->nodeTab[0];
            if (location_html_element == NULL) {
                throw "Null pointer exception";
            }
            location = std::string(reinterpret_cast<char*>(xmlNodeGetContent(location_html_element)));
        }
        catch (const char* e) {

            location = "N/A";
        }
 



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
    cpr::Url url(_url);
    cpr::Response response = cpr::Get(url, headers);

    // parse the HTML document returned by the server
    htmlDocPtr doc = htmlReadMemory(response.text.c_str(), response.text.length(), nullptr, nullptr, HTML_PARSE_NOWARNING | HTML_PARSE_NOERROR);

    // set the libxml2 context to the current document
    xmlXPathContextPtr context = xmlXPathNewContext(doc);

    std::string temp;



   
    try {
        xmlNodePtr job_cat_html_element;
        xmlXPathObjectPtr xpathObj = xmlXPathEvalExpression((xmlChar*)"//table[contains(@class, 'table-hover m-0')]//tr[td[1]='Job Category']/td[3]/a", context);
        if (xpathObj == NULL) {
            temp = "N/A";

            return;
        }
        if (xpathObj->nodesetval == nullptr || xpathObj->nodesetval->nodeTab == nullptr) {
            throw "Null pointer exception";
        }
        job_cat_html_element = xpathObj->nodesetval->nodeTab[0];
        if (job_cat_html_element == NULL) {
            throw "Null pointer exception";
        }
        temp = std::string(reinterpret_cast<char*>(xmlNodeGetContent(job_cat_html_element)));
    }
    catch (const char* e) {

        temp= "N/A";
    }

    
    j1.jobcat = temp;

    
   // xmlNodePtr job_level_html_element = xmlXPathEvalExpression((xmlChar*)"//table[contains(@class, 'table-hover m-0')]//tr[td[1]='Job Level']/td[3]/a", context)->nodesetval->nodeTab[0];    
    //temp = std::string(reinterpret_cast<char*>(xmlNodeGetContent(job_level_html_element)));
    
    

    try {
        xmlNodePtr job_level_html_element;
        xmlXPathObjectPtr xpathObj = xmlXPathEvalExpression((xmlChar*)"//table[contains(@class, 'table-hover m-0')]//tr[td[1]='Job Level']/td[3]/a", context);
        if (xpathObj == NULL) {
            temp = "N/A";

            return;
        }
        if (xpathObj->nodesetval == nullptr || xpathObj->nodesetval->nodeTab == nullptr) {
            throw "Null pointer exception";
        }
        job_level_html_element = xpathObj->nodesetval->nodeTab[0];
        if (job_level_html_element == NULL) {
            throw "Null pointer exception";
        }
        temp = std::string(reinterpret_cast<char*>(xmlNodeGetContent(job_level_html_element)));
    }
    catch (const char* e) {

        temp = "N/A";
    }
    
    j1.joblevel = temp;

   // xmlNodePtr emp_type_html_element = xmlXPathEvalExpression((xmlChar*)"//table[contains(@class, 'table-hover m-0')]//tr[td[1]='Employment Type']/td[3]", context)->nodesetval->nodeTab[0];
    //temp = std::string(reinterpret_cast<char*>(xmlNodeGetContent(emp_type_html_element)));

    try {
        xmlNodePtr emp_type_html_element;
        xmlXPathObjectPtr xpathObj = xmlXPathEvalExpression((xmlChar*)"//table[contains(@class, 'table-hover m-0')]//tr[td[1]='Employment Type']/td[3]", context);
        if (xpathObj == NULL) {
            temp = "N/A";

            return;
        }
        if (xpathObj->nodesetval == nullptr || xpathObj->nodesetval->nodeTab == nullptr) {
            throw "Null pointer exception";
        }
        emp_type_html_element = xpathObj->nodesetval->nodeTab[0];
        if (emp_type_html_element == NULL) {
            throw "Null pointer exception";
        }
        temp = std::string(reinterpret_cast<char*>(xmlNodeGetContent(emp_type_html_element)));
    }
    catch (const char* e) {

        temp = "N/A";
    }

    j1.emptype = temp;

    //xmlNodePtr location_html_element = xmlXPathEvalExpression((xmlChar*)"//table[contains(@class, 'table-hover m-0')]//tr[td[1]='Job Location']/td[3]", context)->nodesetval->nodeTab[0];
    //temp = std::string(reinterpret_cast<char*>(xmlNodeGetContent(location_html_element)));
    
    try {
        xmlNodePtr location_html_element;
        xmlXPathObjectPtr xpathObj = xmlXPathEvalExpression((xmlChar*)"//table[contains(@class, 'table-hover m-0')]//tr[td[1]='Job Location']/td[3]", context);
        if (xpathObj == NULL) {
            temp = "N/A";

            return;
        }
        if (xpathObj->nodesetval == nullptr || xpathObj->nodesetval->nodeTab == nullptr) {
            throw "Null pointer exception";
        }
        location_html_element = xpathObj->nodesetval->nodeTab[0];
        if (location_html_element == NULL) {
            throw "Null pointer exception";
        }
        temp = std::string(reinterpret_cast<char*>(xmlNodeGetContent(location_html_element)));
    }
    catch (const char* e) {

        temp = "N/A";
    }
    j1.location = temp;

    //xmlNodePtr salary_html_element = xmlXPathEvalExpression((xmlChar*)"//table[contains(@class, 'table-hover m-0')]//tr[td[1]='Offered Salary']/td[3]", context)->nodesetval->nodeTab[0];
    //temp = std::string(reinterpret_cast<char*>(xmlNodeGetContent(salary_html_element)));
   
    try {
        xmlNodePtr salary_html_element;
        xmlXPathObjectPtr xpathObj = xmlXPathEvalExpression((xmlChar*)"//table[contains(@class, 'table-hover m-0')]//tr[td[1]='Offered Salary']/td[3]", context);
        if (xpathObj == NULL) {
            temp = "N/A";

            return;
        }
        if (xpathObj->nodesetval == nullptr || xpathObj->nodesetval->nodeTab == nullptr) {
            throw "Null pointer exception";
        }
        salary_html_element = xpathObj->nodesetval->nodeTab[0];
        if (salary_html_element == NULL) {
            throw "Null pointer exception";
        }
        temp = std::string(reinterpret_cast<char*>(xmlNodeGetContent(salary_html_element)));
    }
    catch (const char* e) {

        temp = "N/A";
    }
    j1.salary = temp;


   // xmlNodePtr deadline_html_element = xmlXPathEvalExpression((xmlChar*)"//table[contains(@class, 'table-hover m-0')]//tr[td[1]//span='(Deadline)']/td[3]", context)->nodesetval->nodeTab[0];
    //temp = std::string(reinterpret_cast<char*>(xmlNodeGetContent(deadline_html_element)));
    

    try {
        xmlNodePtr deadline_html_element;
        xmlXPathObjectPtr xpathObj = xmlXPathEvalExpression((xmlChar*)"//table[contains(@class, 'table-hover m-0')]//tr[td[1]//span='(Deadline)']/td[3]", context);
        if (xpathObj == NULL) {
            temp = "N/A";

            return;
        }
        if (xpathObj->nodesetval == nullptr || xpathObj->nodesetval->nodeTab == nullptr) {
            throw "Null pointer exception";
        }
        deadline_html_element = xpathObj->nodesetval->nodeTab[0];
        if (deadline_html_element == NULL) {
            throw "Null pointer exception";
        }
        temp = std::string(reinterpret_cast<char*>(xmlNodeGetContent(deadline_html_element)));
    }
    catch (const char* e) {

        temp = "N/A";
    }

    j1.deadline = temp;


   // xmlNodePtr edu_level_html_element = xmlXPathEvalExpression((xmlChar*)"//table[contains(@class, 'table-hover m-0')]//tr[td[1]='Education Level']/td[3]", context)->nodesetval->nodeTab[0];
    //temp = std::string(reinterpret_cast<char*>(xmlNodeGetContent(edu_level_html_element)));
    try {
        xmlNodePtr edu_level_html_element;
        xmlXPathObjectPtr xpathObj = xmlXPathEvalExpression((xmlChar*)"//table[contains(@class, 'table-hover m-0')]//tr[td[1]='Education Level']/td[3]", context);
        if (xpathObj == NULL) {
            temp = "N/A";

            return;
        }
        if (xpathObj->nodesetval == nullptr || xpathObj->nodesetval->nodeTab == nullptr) {
            throw "Null pointer exception";
        }
        edu_level_html_element = xpathObj->nodesetval->nodeTab[0];
        if (edu_level_html_element == NULL) {
            throw "Null pointer exception";
        }
        temp = std::string(reinterpret_cast<char*>(xmlNodeGetContent(edu_level_html_element)));
    }
    catch (const char* e) {

        temp = "N/A";
    }
    j1.edulevel = temp;

  //  xmlNodePtr exp_level_html_element = xmlXPathEvalExpression((xmlChar*)"//table[contains(@class, 'table-hover m-0')]//tr[td[1]='Experience Required']/td[3]", context)->nodesetval->nodeTab[0];
   // temp = std::string(reinterpret_cast<char*>(xmlNodeGetContent(exp_level_html_element)));
    try {
        xmlNodePtr exp_level_html_element;
        xmlXPathObjectPtr xpathObj = xmlXPathEvalExpression((xmlChar*)"//table[contains(@class, 'table-hover m-0')]//tr[td[1]='Experience Required']/td[3]", context);
        if (xpathObj == NULL) {
            temp = "N/A";

            return;
        }
        if (xpathObj->nodesetval == nullptr || xpathObj->nodesetval->nodeTab == nullptr) {
            throw "Null pointer exception";
        }
        exp_level_html_element = xpathObj->nodesetval->nodeTab[0];
        if (exp_level_html_element == NULL) {
            throw "Null pointer exception";
        }
        temp = std::string(reinterpret_cast<char*>(xmlNodeGetContent(exp_level_html_element)));
    }
    catch (const char* e) {

        temp = "N/A";
    }
    j1.explevel = temp;

    //xmlNodePtr job_desc_html_element = xmlXPathEvalExpression((xmlChar*)"//div[@class='card-text p-2']/following-sibling::div[@class='card-text p-2']/p[1]", context)->nodesetval->nodeTab[0];
    //temp = std::string(reinterpret_cast<char*>(xmlNodeGetContent(job_desc_html_element)));
    j1.jobDesc = "N/A";



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


        std::string deadline;
        try {
            xmlNodePtr deadline_html_element;
            xmlXPathObjectPtr xpathObj = xmlXPathEvalExpression((xmlChar*)".//div/div/div/div[2]/ul/li[3]/small", context);
            if (xpathObj == NULL) {
                deadline = "N/A";

                return;
            }
            if (xpathObj->nodesetval == nullptr || xpathObj->nodesetval->nodeTab == nullptr) {
                throw "Null pointer exception";
            }
            deadline_html_element = xpathObj->nodesetval->nodeTab[0];
            if (deadline_html_element == NULL) {
                throw "Null pointer exception";
            }
            std::string deadline = std::string(reinterpret_cast<char*>(xmlNodeGetContent(deadline_html_element)));
        }
        catch (const char* e) {

            deadline = "N/A";
        }



      

        //xmlNodePtr location_html_element = xmlXPathEvalExpression((xmlChar*)".//div/div[2]/div[2]/div[2]/span/span/span", context)->nodesetval->nodeTab[0];
        //std::string location = std::string(reinterpret_cast<char*>(xmlNodeGetContent(location_html_element)));




        JobCard job_card = { name, company, "location", "image", job_url, company_url, deadline }; //location is not written for time being cuz "," messes up the csv


        j1.similar_job_cards.push_back(job_card);

    }

    xmlXPathFreeObject(job_card_html_elements);
    xmlXPathFreeContext(context);
    xmlFreeDoc(doc);




}

void MeroJob::ClearCompanyDetails()
{
    c1.companyjob_cards.clear();
}

CompanyPageCard MeroJob::GetCompanyDetails()
{
    return c1;
}

JobDetailCard MeroJob::GetJobDetails()
{
    return j1;
}


