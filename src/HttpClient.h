 
 #pragma once
 
 #include <curl/curl.h>
 #include <string>

 struct HttpResponse{
        long statusCode;
        std::string body;
        std::string errorMsg;
    };
class HttpClient{
 public:
        HttpClient();
        ~HttpClient();
        HttpResponse get(const std::string& url);
    
    private:
        void initCurl();
        void cleanupCurl();
        CURL* curl;
 
 } ;