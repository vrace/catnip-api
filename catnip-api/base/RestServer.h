#ifndef REST_SERVER_H
#define REST_SERVER_H

#include "HttpResponse.h"
#include "HttpRequest.h"
#include "RestController.h"
#include "RequestMapping.h"

#include <string>
#include <vector>

class RestServer
{
public:
    RestServer();
    
    void AddRequestMapping(const RequestMapping &requestMapping);
    std::string Dispatch(const std::string &request);
    
private:
    std::string Prepare(const HttpResponse &response);
    std::string Fallback(const HttpRequest &request);
    std::string SimpleResponse(HttpStatusCode status);
    
private:
    std::vector<RequestMapping> _requestMappings;
};

#endif
