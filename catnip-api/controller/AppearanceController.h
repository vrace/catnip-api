#ifndef APPEARANCE_CONTROLLER_H
#define APPEARANCE_CONTROLLER_H

#include "../base/RestController.h"
#include "../service/appearance/AppearanceService.h"
#include "../util/RequestMappingUtils.h"

class AppearanceController : public RestController
{
public:
    AppearanceController();
    
    BEGIN_REQUEST_MAPPING()
    ON_GET("/appearance/", [this] (const HttpRequest&) { return _service->GetAppearance(); })
    END_REQUEST_MAPPING()
    
private:
    AppearanceService *_service;
};

#endif
