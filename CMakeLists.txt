cmake_minimum_required(VERSION 3.20)
project(opendap_dmrParser CXX)

add_executable(opendap_dmrParser
    src/main.cpp
    src/HttpClient.cpp
    src/dmrParser.cpp
    src/describeCmd.cpp
)

find_package(CURL REQUIRED)
target_link_libraries(opendap_dmrParser PRIVATE CURL::libcurl)

find_package(pugixml REQUIRED)
target_link_libraries(opendap_dmrParser PRIVATE pugixml::pugixml)