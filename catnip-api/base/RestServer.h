#ifndef REST_SERVER_H
#define REST_SERVER_H

#include "HttpResponse.h"
#include "HttpRequest.h"
#include "RestController.h"

#include <string>
#include <map>

class RestServer
{
public:
    RestServer();
    
    void AddController(const std::string &requestMapping, RestController &controller);
    std::string Dispatch(const std::string &request);
    
private:
    std::string Prepare(const HttpResponse &response);
    std::string Fallback(const HttpRequest &request);
    std::string SimpleResponse(HttpStatusCode status);
    
private:
    std::map<std::string, RestController*> _requestMappings;
};

#endif
