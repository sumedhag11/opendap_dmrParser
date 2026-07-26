#include "HttpClient.h"
#include "describeCmd.h"

/*
Get DMR parsed data, dimensions, attributes and values using following
For DMR documents - 
./opendap-llmtool describe URL
e
./opendap-llmtool describe https://thredds-test.unidata.ucar.edu/thredds/dap4/testdods/testData.nc.dmr
./opendap-llmtool describe http://test.opendap.org/opendap/data/nc/coads_climatology.nc.dmr
*/
int main (int argc, char* argv[]) 
{
    //check how many parameters
    if (argc > 1)
    {
        //get 1st array param to see what has been passed describe or query 
        std::string command = argv[1];
        //for finding labels
        if (command == "describe")
        {
            //std::cout<< "Command passed =" <<command ;
            if( argc >2)
            {
                int status = buildCompleteDMRString(argv[2]);
            }
            else
            {
                std::cout<< "no url" ;
            }
        }
        else if(command == "query") //for findiing data
        {
            if (argc >3)
            {
                QueryArgs args;
                args.url = argv[2];
                args.var = argv[3];
                std::cout<< "url passed =" <<args.url <<"\n";
                std::cout<< "variable passed =" <<args.var <<std::endl ;
            }
            else
            {
                std::cout<< "no url or var" ;
            }
            std::cout<< "Command passed1 =" <<command ;
        }
        else if (command == "--help" || command == "-h")
        {
            std::cout << "Usage: opendap-llmtool describe <dmr-url>\n\n"
                    << "Fetches an OPeNDAP dataset's .dmr metadata and prints a\n"
                    << "human-readable description of its variables, units, and shapes.\n\n"
                    << "Examples:\n"
                    << "  opendap-llmtool describe http://test.opendap.org/opendap/data/nc/coads_climatology.nc.dmr\n"
                    << "  opendap-llmtool describe https://thredds-test.unidata.ucar.edu/thredds/dap4/testdods/testData.nc.dmr\n";
            return 0;
        }
        else
        {
           std::cout << "Usage: opendap-llmtool describe <dmr-url>\n\n"
                    << "Fetches an OPeNDAP dataset's .dmr metadata and prints a\n"
                    << "human-readable description of its variables, units, and shapes.\n\n"
                    << "Examples:\n"
                    << "  opendap-llmtool describe http://test.opendap.org/opendap/data/nc/coads_climatology.nc.dmr\n"
                    << "  opendap-llmtool describe https://thredds-test.unidata.ucar.edu/thredds/dap4/testdods/testData.nc.dmr\n";
            return 0;
        }
    }
    else
    {
        // Add usage instructions
        std::cout<< "Usage: ./opendap-llmtool describe <URL>`" ;
        std::cout<< "./opendap-llmtool describe http://test.opendap.org/opendap/data/nc/coads_climatology.nc.dmr ";
        std::cout<< "./opendap-llmtool describe https://thredds-test.unidata.ucar.edu/thredds/dap4/testdods/testData.nc.dmr";
    }

    /* function to test XML, how does it print */
/*void printNode(pugi::xml_node node)
{
    // for each child of this node:
    //   print its name
    //   call printNode on that child, to go one level deeper
    for(pugi::xml_node child : node.children())
    {
        std::string name = child.name();
        if (!(name.empty()))
        {
            if (name =="Dimension")
            {
                std::cout << "Dimension name: " << child.attribute("name").value() << "\n";
                std::cout << "Dimension size: " << child.attribute("size").value() << "\n";
            }
            if (name =="Dim")
            {
                std::cout << "Dim name: " << child.attribute("name").value() << "\n";
                std::cout << "Dim size: " << child.attribute("size").value() << "\n";
            }
            else if (name == "Attribute")
            {
                std::cout << "Attribute name: " << child.attribute("name").value() << "\n";
                std::cout << "Attribute Type: " << child.attribute("type").value() << "\n";
                for(pugi::xml_node attrchild : child.children())
                {
                    std::string attrname = attrchild.name();
                    if (!(attrname.empty()))
                    {
                        if (attrname == "Value")
                        {
                            std::cout << "Attribute value: " << attrchild.text().get() << "\n";
                        }
                    }
                }
            }
            else if (name == "Variable")
            {
                std::cout << "Variable name: " << child.attribute("name").value() << "\n";
                std::cout << "Variable type: " << child.attribute("type").value() << "\n";
            }
            else
            {
             //   std::cout << "Node name: " << child.name() << "\n";
            }
            //std::cout << "Node name: " << child.name() << "\n";
        }
        printNode(child);
    }
}
*/

}
