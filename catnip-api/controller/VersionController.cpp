#include "VersionController.h"

VersionController::VersionController()
{
    
}

std::unique_ptr<HttpResponse> VersionController::HandleRequest(const HttpRequest &request)
{
    if (request.GetMethod() != HttpRequestMethod::GET && request.GetURL() != "/version")
        return nullptr;
    
    auto payload = HttpResponsePayload("CATNIP API VERSION 0.1", "text/plain");
    return std::make_unique<HttpResponse>(HttpStatusCode::OK, HttpHeaders(), payload);
}
