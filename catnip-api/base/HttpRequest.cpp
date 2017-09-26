#include "HttpRequest.h"

HttpRequest::HttpRequest(HttpRequestMethod method, const std::string &url, const HttpHeaders &headers, const std::string &body)
: _method(method)
, _url(url)
, _headers(headers)
, _body(body)
{
    
}

HttpRequestMethod HttpRequest::GetMethod() const
{
    return _method;
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
