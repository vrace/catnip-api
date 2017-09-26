#include "RestServer.h"
#include "HttpRequestTranslator.h"
#include <memory>

RestServer::RestServer()
{
    
}

std::string RestServer::Dispatch(const std::string &request)
{
    auto httpRequest = std::unique_ptr<HttpRequest>(HttpRequestTranslator::Translate(request));
    return "";
}
