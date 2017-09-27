#ifndef VERSION_CONTROLLER_H
#define VERSION_CONTROLLER_H

#include "../base/RestController.h"

class VersionController : public RestController
{
public:
    VersionController();
    std::unique_ptr<HttpResponse> HandleRequest(const HttpRequest &request) override;
};

#endif
