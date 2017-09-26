#include "HttpStatusCodeTranslator.h"

std::string HttpStatusCodeTranslator::Translate(HttpStatusCode code)
{
    if (code == HttpStatusCode::OK)
        return "200 OK";
    
    if (code == HttpStatusCode::BAD_REQUEST)
        return "400 Bad Request";
    
    return "500 Internal Server Error";
}

std::ostream& operator <<(std::ostream &s, HttpStatusCode code)
{
    return s << HttpStatusCodeTranslator::Translate(code);
}
