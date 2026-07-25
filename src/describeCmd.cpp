#include "describeCmd.h"

/* find the size of dimension*/
int findDimensionSize(const std::vector<Dimension>& dimensions, const std::string& dimName)
{
    for (const auto& dim : dimensions)
    {
        if (dim.name == dimName)
        {
            return std::stoi(dim.size);
        }
    }
    return -1; // Return -1 if dimension not found
}
/* build Dimensions attributes and values string */
std::string buildDMRString(const Variable& var, const std::vector<Dimension>& dimensions)
{
    std::string dmrString = "[";
    std::string dim = var.name;
    for(int i = 0; i < var.dimNames.size(); i++)
    {
        std::string dimName = var.dimNames[i];
        std::string dimName_noSlash = dimName.substr(1);
        int size = findDimensionSize(dimensions, dimName_noSlash);
        dmrString += dimName_noSlash + "=" + std::to_string(size);
        if (i < var.dimNames.size() - 1)
        {
            dmrString += ",";
        }
    }
    dmrString += "]";
    return dmrString;
}

/* build string for user to understand from dmr document. Return -1 if unsuccessful and 0 for successful */
int buildCompleteDMRString(std::string url)
{
    int status = 0;
    DescribeArgs args;
    args.url = url;
     std::cout << ", DEBUG url = " << url << "\n";
    HttpClient client;
    HttpResponse response = client.get(args.url);
    std::cout << "status: " << response.statusCode << "\n";
    if (response.statusCode != 200)
    {
        std::cout << "Error whenn sending URL: " << response.errorMsg << "\n";
        return 1;
    }
    //std::cout << "body: " << response.body << "\n";
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_string(response.body.c_str());
    if (result)
    {
        //go through the xml
        pugi::xml_node root = doc.child("Dataset");              
        std::vector<Dimension> dimensions = parseDimensions(root);
        std::vector<Variable> variables = parseVariables(root);
        /*for(const auto& dim : dimensions)
        {
            std::cout << "Dimension name: " << dim.name << ", size: " << dim.size << std::endl;
        }*/
        for(const auto& var : variables)
        {
            //int size = findDimensionSize(dimensions, var.name);
            std::cout << "- " << var.name << " (" << var.long_name << ", " << var.units << ") "
                << "— shape " << buildDMRString(var, dimensions) << "\n";
            //std::cout << "Dimension names for the Variable are: "; 
            //find size of the variable name from dimension vector
            
        /*for(const auto& dimName : var.dimNames)
            {
                std::cout  << dimName << " , ";
            }*/
            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << "Failed to parse XML: " << result.description() << "\n";
        status = -1;
    }
    return status;
}