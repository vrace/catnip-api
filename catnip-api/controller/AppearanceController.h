#ifndef APPEARANCE_CONTROLLER_H
#define APPEARANCE_CONTROLLER_H

#include "../base/RestController.h"
#include "../model/Appearance.h"

class AppearanceController : public RestController
{
public:
    AppearanceController();
    std::unique_ptr<HttpResponse> HandleRequest(const HttpRequest &request) override;
    
private:
    Appearance GetAppearance();
};

#endif
