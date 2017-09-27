#include "RestController.h"

RestController::RestController()
{
    
}

std::unique_ptr<HttpResponse> RestController::HandleRequest(const HttpRequest &request)
{
    return std::unique_ptr<HttpResponse>();
}
