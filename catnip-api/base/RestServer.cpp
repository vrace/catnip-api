#include "RestServer.h"
#include "HttpRequestTranslator.h"
#include "HttpRequestMethodTranslator.h"
#include "HttpResponseTranslator.h"
#include <iostream>
#include <memory>

RestServer::RestServer()
{
    
}

void RestServer::AddController(const std::string &requestMapping, RestController &controller)
{
    _requestMappings[requestMapping] = &controller;
}

std::string RestServer::Dispatch(const std::string &request)
{
    auto httpRequest = HttpRequestTranslator::Translate(request);
    
    if (!httpRequest)
        return Prepare(HttpResponse(HttpStatusCode::BAD_REQUEST));
    
    std::cout << httpRequest->GetMethod() << " " << httpRequest->GetURL() << std::endl;
    
    for (auto &mapping : _requestMappings)
    {
        if (httpRequest->GetURL() == mapping.first || httpRequest->GetURL().find(mapping.first + "/") == 0)
        {
            auto response = mapping.second->HandleRequest(*httpRequest);
            if (response)
                return Prepare(*response);
        }
    }
        
    return Prepare(HttpResponse(HttpStatusCode::NOT_FOUND));
}

std::string RestServer::Prepare(const HttpResponse &response)
{
    return HttpResponseTranslator::Translate(response);
}
