#include "HttpHeaders.h"

HttpHeaders::HttpHeaders()
{
    
}

bool HttpHeaders::Append(const std::string &header)
{
    auto delim = header.find(':');
    
    if (delim == std::string::npos)
        return false;
    
    auto key = header.substr(0, delim);
    auto value = header.substr(delim + 1);
    
    while (!value.empty() && value[0] == ' ')
        value.erase(value.begin());
    
    (*this)[key] = value;
    return true;
}
