#include "HttpClient.h"


HttpClient::HttpClient()
{
    initCurl();
}

HttpClient::~HttpClient()
{
    cleanupCurl();
}

static size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    size_t totalsize = size*nmemb;
    std::string* responseBody = static_cast<std::string*>(userp);
    responseBody->append(static_cast<char*>(contents), totalsize);
    return totalsize;
}

void HttpClient::initCurl()
{
    curl = curl_easy_init();
}

void HttpClient::cleanupCurl()
{
    curl_easy_cleanup(curl);
}

HttpResponse HttpClient::get(const std::string& url)
{
    HttpResponse response;
    response.statusCode = 0;

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response.body);

    CURLcode res = curl_easy_perform(curl);
    if (res == CURLE_OK) {
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response.statusCode);
    }
    else
    {
        response.errorMsg = curl_easy_strerror(res);
    }

    return response;
}
