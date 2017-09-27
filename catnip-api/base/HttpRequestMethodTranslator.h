#ifndef HTTP_REQUEST_METHOD_TRANSLATOR_H
#define HTTP_REQUEST_METHOD_TRANSLATOR_H

#include "HttpRequestMethod.h"
#include <string>
#include <iostream>

class HttpRequestMethodTranslator
{
public:
    static HttpRequestMethod Translate(const std::string &str);
    static std::string Translate(HttpRequestMethod method);
};

std::istream& operator >>(std::istream &s, HttpRequestMethod &method);
std::ostream& operator <<(std::ostream &s, HttpRequestMethod method);

#endif
