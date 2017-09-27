#include "HttpResponse.h"
#include <sstream>

HttpResponse::HttpResponse(HttpStatusCode status, const HttpHeaders &headers)
: _status(status)
, _headers(headers)
{
    _headers["Content-Length"] = "0";
}

HttpResponse::HttpResponse(HttpStatusCode status, const HttpHeaders &headers, const HttpResponsePayload &payload)
: _status(status)
, _headers(headers)
, _payload(payload)
{
    auto &contentType = _payload.GetContentType();
    
    if (!contentType.empty())
        _headers["Content-Type"] = contentType;
    
    auto &body = _payload.GetBody();
    std::stringstream ss;
    ss << body.length();
    _headers["Content-Length"] = ss.str();
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

const HttpResponsePayload& HttpResponse::GetPayload() const
{
    return _payload;
}
