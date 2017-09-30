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

#define BEGIN_DEFINE_JSON() std::string ToJsonObject() const { bool first = true; std::stringstream ss; ss << "{";
#define JSON_COMMA() if (!first) ss << ","; first = false;
#define WITH_JSON_OBJECT(key,obj) JSON_COMMA(); ss << ::ToJsonKeyValue(key, obj);
#define WITH_JSON_ARRAY(key,arr) JSON_COMMA(); ss << ::ToJsonKeyArray(key, arr);
#define END_DEFINE_JSON() ss << "}"; return ss.str(); }

#endif
