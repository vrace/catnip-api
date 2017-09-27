#ifndef REST_CONTROLLER_H
#define REST_CONTROLLER_H

#include "HttpRequest.h"
#include "HttpResponse.h"
#include <memory>

class RestController
{
public:
    RestController();
    virtual std::unique_ptr<HttpResponse> HandleRequest(const HttpRequest &request);
};

#endif
