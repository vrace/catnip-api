#include "JsonUtils.h"
#include "StringUtils.h"
#include <sstream>

std::string ToJsonObject(int value)
{
    std::stringstream ss;
    ss << value;
    return ss.str();
}

std::string ToJsonObject(const char *str)
{
    return ToJsonObject(std::string(str));
}

std::string ToJsonObject(const std::string &str)
{
    std::stringstream ss;
    ss << "\"" << StringUtils::Replace(str, "\"", "\\\"") << "\"";
    return ss.str();
}
