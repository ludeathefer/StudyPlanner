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
    std::string query = "Software+Engineer";
    std::string url_str = "https://merojob.com/search/?q=" + _searchKey ;
    cpr::Url url(url_str);
    cpr::Response response = cpr::Get(url, headers);

    // parse the HTML document returned by the server
    htmlDocPtr doc = htmlReadMemory(response.text.c_str(), (int) response.text.length(), nullptr, nullptr, HTML_PARSE_NOWARNING | HTML_PARSE_NOERROR);

 
 
    // set the libxml2 context to the current document
    xmlXPathContextPtr context = xmlXPathNewContext(doc);
    // select all result card HTML elements
    // with an XPath selector
    xmlXPathObjectPtr industry_card_html_elements = xmlXPathEvalExpression((xmlChar*)"//div[contains(@id, 'search_job')]//div[contains(@class, 'card mt-3')]", context);

    // iterate over the list of industry card elements
    for (int i = 0; i < industry_card_html_elements->nodesetval->nodeNr; ++i)
    {

        xmlNodePtr industry_card_html_element = industry_card_html_elements->nodesetval->nodeTab[i];
        xmlXPathSetContextNode(industry_card_html_element, context);


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



        IndustryCard industry_card = { name, company, location, image, job_url, company_url, deadline }; //location is not written for time being cuz "," messes up the csv


        industry_cards.push_back(industry_card);
    }

    xmlXPathFreeObject(industry_card_html_elements);
    xmlXPathFreeContext(context);
    xmlFreeDoc(doc);

    std::ofstream csv_file("output.csv");

    csv_file << "name,company,location,image,joburl,companyurl,deadline" << std::endl;
    for (IndustryCard industry_card : industry_cards)
    {
        csv_file << industry_card.name << "," << industry_card.company << "," << industry_card.location << "," << industry_card.image << "," << industry_card.job_url << "," << industry_card.company_url << "," << industry_card.deadline << std::endl;
    }

    csv_file.close();

}

std::vector<IndustryCard> MeroJob::GetResults()
{
    return industry_cards;
}


