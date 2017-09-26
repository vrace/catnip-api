#include "HttpResponse.h"

HttpResponse::HttpResponse(HttpStatusCode status, const HttpHeaders &headers)
: _status(status)
, _headers(headers)
{
    
}

HttpResponse::HttpResponse(HttpStatusCode status, const HttpHeaders &headers, const std::string &payload)
: _status(status)
, _headers(headers)
, _payload(payload)
{
    
}

HttpStatusCode HttpResponse::GetStatus() const
{
    return _status;
}

HttpHeaders& HttpResponse::GetHeaders()
{
    return _headers;
}

const HttpHeaders& HttpResponse::GetHeaders() const
{
    return _headers;
}

const std::string& HttpResponse::GetPayload() const
{
    return _payload;
}
