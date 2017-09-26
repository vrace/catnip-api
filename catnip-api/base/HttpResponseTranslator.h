#ifndef HTTP_RESPONSE_TRANSLATOR_H
#define HTTP_RESPONSE_TRANSLATOR_H

#include "HttpResponse.h"
#include <string>

class HttpResponseTranslator
{
public:
    static std::string Translate(const HttpResponse &response);
};

#endif
