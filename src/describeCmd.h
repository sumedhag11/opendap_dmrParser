#pragma once

#include "HttpClient.h"
#include "dmrParser.h"
#include <iostream>

struct DescribeArgs{
    std::string url;
};

struct QueryArgs{
    std::string url;
    std::string var;
};

int buildCompleteDMRString(std::string url);