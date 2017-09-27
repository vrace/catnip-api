#ifndef HTTP_RESPONSE_H
#define HTTP_RESPONSE_H

#include "HttpStatusCode.h"
#include "HttpHeaders.h"
#include "HttpResponsePayload.h"

class HttpResponse
{
public:
    HttpResponse(HttpStatusCode status, const HttpHeaders &headers);
    HttpResponse(HttpStatusCode status, const HttpHeaders &headers, const HttpResponsePayload &payload);
    
    HttpStatusCode GetStatus() const;
    HttpHeaders& GetHeaders();
    const HttpHeaders& GetHeaders() const;
    const HttpResponsePayload& GetPayload() const;
    
private:
    HttpStatusCode _status;
    HttpHeaders _headers;
    HttpResponsePayload _payload;
};

#endif
