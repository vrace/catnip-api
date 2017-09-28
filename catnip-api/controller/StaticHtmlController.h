#ifndef STATIC_HTML_CONTROLLER_H
#define STATIC_HTML_CONTROLLER_H

#include "../base/RestController.h"

class StaticHtmlController : public RestController
{
public:
    StaticHtmlController();
    std::unique_ptr<HttpResponse> HandleRequest(const HttpRequest &request) override;
};

#endif
