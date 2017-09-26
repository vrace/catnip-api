#ifndef HTTP_STATUS_CODE_TRANSLATOR_H
#define HTTP_STATUS_CODE_TRANSLATOR_H

#include "HttpStatusCode.h"
#include <string>
#include <iostream>

class HttpStatusCodeTranslator
{
public:
    static std::string Translate(HttpStatusCode code);
};

std::ostream& operator <<(std::ostream &s, HttpStatusCode code);

#endif
