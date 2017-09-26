#ifndef HTTP_HEADERS_H
#define HTTP_HEADERS_H

#include <string>
#include <map>

class HttpHeaders : public std::map<std::string, std::string>
{
public:
    HttpHeaders();
};

#endif
