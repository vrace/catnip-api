#include "RestServer.h"
#include "HttpRequestTranslator.h"
#include "HttpRequestMethodTranslator.h"
#include "HttpResponseTranslator.h"
#include <iostream>
#include <memory>

RestServer::RestServer()
{
    
}

void RestServer::AddRequestMapping(const RequestMapping &requestMapping)
{
    _requestMappings.push_back(requestMapping);
}

std::string RestServer::Dispatch(const std::string &request)
{
    auto httpRequest = HttpRequestTranslator::Translate(request);
    
    if (!httpRequest)
        return SimpleResponse(HttpStatusCode::BAD_REQUEST);
    
    std::cout << httpRequest->GetMethod() << " " << httpRequest->GetURL() << std::endl;
    
    for (auto &mapping : _requestMappings)
    {
        if (httpRequest->GetURL().find(mapping.GetMapping() + "/") == 0)
        {
            auto response = mapping.GetController().HandleRequest(*httpRequest);
            if (response)
                return Prepare(*response);
        }
    }
    
    return Fallback(*httpRequest);
}

std::string RestServer::Fallback(const HttpRequest &request)
{
    if (request.GetMethod() == HttpRequestMethod::GET)
        return SimpleResponse(HttpStatusCode::NOT_FOUND);
    
    return SimpleResponse(HttpStatusCode::BAD_REQUEST);
}

std::string RestServer::Prepare(const HttpResponse &response)
{
    return HttpResponseTranslator::Translate(response);
}

std::string RestServer::SimpleResponse(HttpStatusCode status)
{
    return Prepare(HttpResponse(status));
}
