#include "HttpResponsePayload.h"

HttpResponsePayload::HttpResponsePayload()
{
    
}

HttpResponsePayload::HttpResponsePayload(const std::string &body)
: _body(body)
{
    
}

HttpResponsePayload::HttpResponsePayload(const std::string &body, const std::string &contentType)
: _body(body)
, _contentType(contentType)
{
    
}

const std::string& HttpResponsePayload::GetBody() const
{
    return _body;
}

const std::string& HttpResponsePayload::GetContentType() const
{
    return _contentType;
}
