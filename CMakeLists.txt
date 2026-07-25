cmake_minimum_required(VERSION 3.20)
project(opendap-llmtool CXX)

add_executable(opendap-llmtool
    src/main.cpp
    src/HttpClient.cpp
    src/dmrParser.cpp
    src/describeCmd.cpp
)

find_package(CURL REQUIRED)
target_link_libraries(opendap-llmtool PRIVATE CURL::libcurl)

find_package(pugixml REQUIRED)
target_link_libraries(opendap-llmtool PRIVATE pugixml::pugixml)