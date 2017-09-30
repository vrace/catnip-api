#include "StringUtils.h"
#include <sstream>

std::string StringUtils::TrimLeft(const std::string &str, char ch)
{
    std::string copied = str;
    return TrimLeft(copied, ch);
}

std::string& StringUtils::TrimLeft(std::string &str, char ch)
{
    while (!str.empty() && str[0] == ch)
        str.erase(str.begin());
    return str;
}

std::string StringUtils::Replace(const std::string &str, const std::string &original, const std::string &dest)
{
    std::stringstream ss;
    std::string::size_type start = 0;
    std::string::size_type pos;
    
    while ((pos = str.find(original, start)) != std::string::npos)
    {
        ss << str.substr(start, pos - start);
        ss << dest;
        start = pos + original.length();
    }
    
    ss << str.substr(start);
    return ss.str();
}

bool StringUtils::EndsWith(const std::string &str, const std::string &ends)
{
    auto pos = str.rfind(ends);
    return pos != std::string::npos && pos + ends.length() == str.length();
}

bool StringUtils::Contains(const std::string &str, const std::string &contains)
{
    return str.find(contains) != std::string::npos;
}
