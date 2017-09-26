#ifndef HTTP_RESPONSE_H
#define HTTP_RESPONSE_H

#include "HttpStatusCode.h"
#include "HttpHeaders.h"

class HttpResponse
{
public:
    HttpResponse(HttpStatusCode status, const HttpHeaders &headers);
    HttpResponse(HttpStatusCode status, const HttpHeaders &headers, const std::string &payload);
    
    HttpStatusCode GetStatus() const;
    HttpHeaders& GetHeaders();
    const HttpHeaders& GetHeaders() const;
    const std::string& GetPayload() const;
    
private:
    HttpStatusCode _status;
    HttpHeaders _headers;
    std::string _payload;
};

#endif
