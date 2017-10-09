#include "AppearanceController.h"
#include "../util/HttpResponseUtils.h"
#include "../config/AppearanceConfig.h"

AppearanceController::AppearanceController()
: _service(AppearanceConfig::GetAppearanceService())
{
    
}
