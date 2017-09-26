#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

#include "HttpHeaders.h"
#include "HttpRequestMethod.h"

class HttpRequest
{
public:
    HttpRequest(HttpRequestMethod method, const std::string &url, const HttpHeaders &headers, const std::string &body);
    
    HttpRequestMethod GetMethod() const;
    const std::string& GetURL() const;
    const HttpHeaders& GetHeaders() const;
    const std::string& GetBody() const;
    
private:
    HttpRequestMethod _method;
    std::string _url;
    HttpHeaders _headers;
    std::string _body;
};

#endif
