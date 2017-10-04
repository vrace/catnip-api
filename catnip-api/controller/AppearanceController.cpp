#include "AppearanceController.h"
#include "../util/HttpResponseUtils.h"
#include "../config/AppearanceConfig.h"

AppearanceController::AppearanceController()
: _service(AppearanceConfig::GetAppearanceService())
{
    
}

std::unique_ptr<HttpResponse> AppearanceController::HandleRequest(const HttpRequest &request)
{
    if (request.GetMethod() == HttpRequestMethod::GET && request.GetURL() == "/appearance/")
        return HttpResponseUtils::JsonResponse(_service->GetAppearance());
    
    return nullptr;
}
