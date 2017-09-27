#ifndef REST_CONTROLLER_H
#define REST_CONTROLLER_H

#include "HttpRequest.h"
#include "HttpResponse.h"

class RestController
{
public:
    RestController();
    virtual HttpResponse* HandleRequest(const HttpRequest &request);
};

#endif
