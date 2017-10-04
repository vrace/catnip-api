#include "AppearanceConfig.h"
#include "../service/appearance/DefaultAppearanceService.h"

AppearanceService* AppearanceConfig::GetAppearanceService()
{
    static DefaultAppearanceService service;
    return &service;
}
