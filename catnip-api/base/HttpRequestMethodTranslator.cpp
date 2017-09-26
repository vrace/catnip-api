#include "HttpRequestMethodTranslator.h"

HttpRequestMethod HttpRequestMethodTranslator::Translate(const std::string &str)
{
    if (str == "GET")
        return HttpRequestMethod::GET;
    
    if (str == "HEAD")
        return HttpRequestMethod::HEAD;
    
    if (str == "POST")
        return HttpRequestMethod::POST;
    
    if (str == "PUT")
        return HttpRequestMethod::PUT;
    
    if (str == "PATCH")
        return HttpRequestMethod::PATCH;
    
    if (str == "DELETE")
        return HttpRequestMethod::DELETE;
    
    return HttpRequestMethod::Invalid;
}

std::istream& operator >>(std::istream &s, HttpRequestMethod &method)
{
    std::string str;
    s >> str;
    method = HttpRequestMethodTranslator::Translate(str);
    return s;
}
