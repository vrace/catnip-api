#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

#include "HttpHeaders.h"

class HttpRequest
{
public:
    HttpRequest(const std::string &url, const HttpHeaders &headers, const std::string &body);
    
    const std::string& GetURL() const;
    const HttpHeaders& GetHeaders() const;
    const std::string& GetBody() const;
    
private:
    std::string _url;
    HttpHeaders _headers;
    std::string _body;
};

#endif
