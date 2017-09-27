#ifndef HTTP_RESPONSE_PAYLOAD_H
#define HTTP_RESPONSE_PAYLOAD_H

#include <string>

class HttpResponsePayload
{
public:
    HttpResponsePayload();
    HttpResponsePayload(const std::string &body);
    HttpResponsePayload(const std::string &body, const std::string &contentType);
    
    const std::string& GetBody() const;
    const std::string& GetContentType() const;
    
private:
    std::string _body;
    std::string _contentType;
};

#endif
