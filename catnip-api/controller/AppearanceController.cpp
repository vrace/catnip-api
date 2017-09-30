#include "AppearanceController.h"
#include "../util/HttpResponseUtils.h"

AppearanceController::AppearanceController()
{
    
}

std::unique_ptr<HttpResponse> AppearanceController::HandleRequest(const HttpRequest &request)
{
    if (request.GetMethod() == HttpRequestMethod::GET && request.GetURL() == "/appearance/")
        return HttpResponseUtils::JsonResponse(GetAppearance());
    
    return nullptr;
}

Appearance AppearanceController::GetAppearance()
{
    Appearance appearance;
    appearance.GetBanners().push_back(Image("/image/banner1.jpg"));
    appearance.GetBanners().push_back(Image("/image/banner2.jpg"));
    appearance.GetBanners().push_back(Image("/image/banner3.jpg"));
    return appearance;
}
