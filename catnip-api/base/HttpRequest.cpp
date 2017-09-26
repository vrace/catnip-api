#include "HttpRequest.h"

HttpRequest::HttpRequest(const std::string &url, const HttpHeaders &headers, const std::string &body)
: _url(url)
, _headers(headers)
, _body(body)
{
    
}

const std::string& HttpRequest::GetURL() const
{
    return _url;
}

const HttpHeaders& HttpRequest::GetHeaders() const
{
    return _headers;
}

const std::string& HttpRequest::GetBody() const
{
    return _body;
}
