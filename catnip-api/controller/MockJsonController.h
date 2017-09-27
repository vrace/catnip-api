#ifndef MOCK_JSON_CONTROLLER_H
#define MOCK_JSON_CONTROLLER_H

#include "../base/RestController.h"

class MockJsonController : public RestController
{
public:
    MockJsonController();
    std::unique_ptr<HttpResponse> HandleRequest(const HttpRequest &request) override;
};

#endif
