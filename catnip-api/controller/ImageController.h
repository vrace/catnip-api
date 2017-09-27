#ifndef IMAGE_CONTROLLER_H
#define IMAGE_CONTROLLER_H

#include "../base/RestController.h"
#include <stdio.h>
#include <stdlib.h>

class ImageController : public RestController
{
public:
    ImageController();
    std::unique_ptr<HttpResponse> HandleRequest(const HttpRequest &request) override;
    
private:
    std::unique_ptr<HttpResponse> GetImage(const std::string &path) const;
    std::string GetContentType(const std::string &path) const;
    bool SanityCheck(const std::string &path) const;
};

#endif
