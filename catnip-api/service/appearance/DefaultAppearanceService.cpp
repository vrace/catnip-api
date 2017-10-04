#include "DefaultAppearanceService.h"

DefaultAppearanceService::DefaultAppearanceService()
{
    
}

Appearance DefaultAppearanceService::GetAppearance()
{
    Appearance appearance;
    appearance.GetBanners().push_back(Image("/image/banner1.jpg"));
    appearance.GetBanners().push_back(Image("/image/banner2.jpg"));
    appearance.GetBanners().push_back(Image("/image/banner3.jpg"));
    return appearance;
}
