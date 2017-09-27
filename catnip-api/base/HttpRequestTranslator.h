#ifndef HTTP_REQUEST_TRANSLATOR_H
#define HTTP_REQUEST_TRANSLATOR_H

#include "HttpRequest.h"
#include <memory>

class HttpRequestTranslator
{
public:
    static std::unique_ptr<HttpRequest> Translate(const std::string &request);
};

#endif
