#include "HttpRequestMethodTranslator.h"
#include <map>

namespace
{
    const std::map<std::string, HttpRequestMethod> METHOD_MAP = {
        { "GET",    HttpRequestMethod::GET },
        { "HEAD",   HttpRequestMethod::HEAD },
        { "POST",   HttpRequestMethod::POST },
        { "PUT",    HttpRequestMethod::PUT },
        { "PATCH",  HttpRequestMethod::PATCH },
        { "DELETE", HttpRequestMethod::DELETE }
    };
}

HttpRequestMethod HttpRequestMethodTranslator::Translate(const std::string &str)
{
    auto it = METHOD_MAP.find(str);
    if (it != METHOD_MAP.end())
        return it->second;
    
    return HttpRequestMethod::Invalid;
}

std::string HttpRequestMethodTranslator::Translate(HttpRequestMethod method)
{
    for (auto &it : METHOD_MAP)
    {
        if (it.second == method)
            return it.first;
    }
    
    return "UNKNOWN";
}

std::istream& operator >>(std::istream &s, HttpRequestMethod &method)
{
    std::string str;
    s >> str;
    method = HttpRequestMethodTranslator::Translate(str);
    return s;
}

std::ostream& operator <<(std::ostream &s, HttpRequestMethod method)
{
    return s << HttpRequestMethodTranslator::Translate(method);
}
