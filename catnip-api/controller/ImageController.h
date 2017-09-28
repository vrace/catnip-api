#ifndef IMAGE_CONTROLLER_H
#define IMAGE_CONTROLLER_H

#include "../base/RestController.h"
#include "../util/Path.h"

class ImageController : public RestController
{
public:
    ImageController();
    std::unique_ptr<HttpResponse> HandleRequest(const HttpRequest &request) override;
    
private:
    std::unique_ptr<HttpResponse> GetImage(const Path &path) const;
    std::string GetContentType(const Path &path) const;
};

#endif
