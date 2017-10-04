#ifndef APPEARANCE_CONTROLLER_H
#define APPEARANCE_CONTROLLER_H

#include "../base/RestController.h"
#include "../service/appearance/AppearanceService.h"

class AppearanceController : public RestController
{
public:
    AppearanceController();
    std::unique_ptr<HttpResponse> HandleRequest(const HttpRequest &request) override;
    
private:
    AppearanceService *_service;
};

#endif
