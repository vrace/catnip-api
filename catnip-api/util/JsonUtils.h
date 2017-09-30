#ifndef JSON_UTILS_H
#define JSON_UTILS_H

#include <string>
#include <sstream>

template <class T>
std::string ToJsonObject(const T &obj)
{
    return obj.ToJsonObject();
}

std::string ToJsonObject(int value);
std::string ToJsonObject(const char *str);
std::string ToJsonObject(const std::string &str);

template <class T>
std::string ToJsonKeyValue(const std::string &key, const T &value)
{
    std::stringstream ss;
    ss << ToJsonObject(key) << ":" << ToJsonObject(value);
    return ss.str();
}

template <class T>
std::string ToJsonArray(const std::vector<T> &arr)
{
    std::stringstream ss;
    
    ss << "[";
    
    auto it = arr.begin();
    if (it != arr.end())
        ss << ToJsonObject(*it);
    
    for (; it != arr.end(); ++it)
        ss << "," << ToJsonObject(*it);
    
    ss << "]";
    
    return ss.str();
}

template <class T>
std::string ToJsonKeyArray(const std::string &key, const std::vector<T> &arr)
{
    std::stringstream ss;
    ss << ToJsonObject(key) << ":" << ToJsonArray(arr);
    return ss.str();
}

#endif
