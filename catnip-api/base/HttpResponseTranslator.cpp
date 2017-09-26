#include "HttpResponseTranslator.h"
#include "HttpStatusCodeTranslator.h"
#include <sstream>

namespace
{
    const char CRLF[] = "\r\n";
}

std::string HttpResponseTranslator::Translate(const HttpResponse &response)
{
    std::stringstream ss;
    
    ss << "HTTP/1.1 " << response.GetStatus() << CRLF;
    
    for (auto &it : response.GetHeaders())
        ss << it.first << ": " << it.second << CRLF;
    
    ss << CRLF;
    
    auto &payload = response.GetPayload();
    if (!payload.empty())
        ss << payload << CRLF;
    
    return ss.str();
}
