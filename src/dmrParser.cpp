#include "dmrParser.h"


/*parse dimensions and values from the dmr document*/
std::vector<Dimension> parseDimensions(pugi::xml_node root)
{
    std::vector<Dimension> dims;
    for(pugi::xml_node node : root.children())
    {
        std::string name = node.name();
        if (name == "Dimension")
        {
            Dimension dim;
            dim.name = node.attribute("name").value();
            dim.size = node.attribute("size").value();
            dims.push_back(dim);
        } 
    }
    return dims;
}

/* get value from child node, from http://test.opendap.org/opendap/data/nc/ & 
https://thredds-test.unidata.ucar.edu/thredds/dap4/testdods/
 */
std::string getValueFromNode(pugi::xml_node node)
{
    std::string val = "";
    val = node.first_child().text().get();
    if (val.empty())
    {
        val = node.attribute("value").value();
    }
    return val;
}
//./opendap_dmrParser describe http://test.opendap.org/opendap/data/nc/coads_climatology.nc.dmr    
//./opendap_dmrParser describe https://thredds-test.unidata.ucar.edu/thredds/dap4/testdods/testData.nc.dmr
/* parse variables and their attributes from the dmr document
<Float64 name="COADSX">
        <Dim name="/COADSX"/>
        <Attribute name="units" type="String">
            <Value>degrees_east</Value>
        </Attribute>
        <Attribute name="modulo" type="String">
            <Value> </Value>
        </Attribute>
        <Attribute name="point_spacing" type="String">
            <Value>even</Value>
        </Attribute>
    </Float64>
 */
std::vector<Variable> parseVariables(pugi::xml_node root)
{
    std::vector<Variable> vars;
    for (pugi::xml_node node : root.children())
    {
        std::string name = node.name();
        if (name == "Float32" || name == "Float64")
        {
            Variable var;
            var.name = node.attribute("name").value();
            var.type = name;   // float is the type 64 or 32 bit 

            for (pugi::xml_node child : node.children())
            {
                std::string childName = child.name();
                if (childName == "Dim")
                {
                    var.dimNames.push_back(child.attribute("name").value());
                }
                else if (childName == "Attribute" && std::string(child.attribute("name").value()) == "units")
                {
                    var.units = getValueFromNode(child.first_child());
                }
                else if (childName == "Attribute" && std::string(child.attribute("name").value()) == "long_name")
                {
                    var.long_name = getValueFromNode(child.first_child());
                }
            }
            vars.push_back(var);
        }
    }
    return vars;
}