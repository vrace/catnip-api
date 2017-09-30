#ifndef STATIC_RESOURCE_CONTROLLER_H
#define STATIC_RESOURCE_CONTROLLER_H

#include "../base/RestController.h"

class StaticResourceController : public RestController
{
public:
    StaticResourceController();
    std::unique_ptr<HttpResponse> HandleRequest(const HttpRequest &request) override;
    
private:
    std::string GetContentType(const std::string &path) const;
};

#endif
