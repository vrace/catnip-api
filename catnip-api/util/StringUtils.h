#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>

class StringUtils
{
public:
    static std::string TrimLeft(const std::string &str, char ch);
    static std::string& TrimLeft(std::string &str, char ch);
    static std::string Replace(const std::string &str, const std::string &original, const std::string &dest);
    static bool EndsWith(const std::string &str, const std::string &ends);
    static bool Contains(const std::string &str, const std::string &contains);
};

#endif
