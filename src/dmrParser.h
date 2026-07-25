
#pragma once

#include <pugixml.hpp>
#include <string>
#include <vector>

struct Dimension {
    std::string name;
    std::string size;
};

struct Variable {
    std::string name;
    std::string type;
    std::string units;
    std::string long_name;
    std::vector<std::string> dimNames;
};

std::vector<Dimension> parseDimensions(pugi::xml_node root);
std::vector<Variable> parseVariables(pugi::xml_node root);