#include "ImageController.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>

namespace
{
    const decltype(fseek(nullptr, 0, SEEK_SET)) FILE_SIZE_LIMIT = 10485760;  // 10 MB
}

ImageController::ImageController()
{
    
}

std::unique_ptr<HttpResponse> ImageController::HandleRequest(const HttpRequest &request)
{
    auto path = request.GetURL();
    
    while (!path.empty() && path[0] == '/')
        path.erase(path.begin());
    
    if (SanityCheck(path))
    {
        if (request.GetMethod() == HttpRequestMethod::GET)
            return GetImage(path);
    }
    
    return std::make_unique<HttpResponse>(HttpStatusCode::BAD_REQUEST);
}

bool ImageController::SanityCheck(const std::string &path) const
{
    // we dont want the consumer to use dot in the path to expolit system
    if (path.find("/.") != std::string::npos)
        return false;
    
    return true;
}

std::unique_ptr<HttpResponse> ImageController::GetImage(const std::string &path) const
{
    auto contentType = GetContentType(path);
    if (contentType.empty())
        return std::make_unique<HttpResponse>(HttpStatusCode::NOT_FOUND);
    
    auto fp = std::unique_ptr<FILE, decltype(&fclose)>(fopen(path.c_str(), "rb"), fclose);
    
    if (!fp)
        return std::make_unique<HttpResponse>(HttpStatusCode::NOT_FOUND);
    
    fseek(&*fp, 0, SEEK_END);
    auto filesize = ftell(&*fp);
    if (filesize <= 0 || filesize > FILE_SIZE_LIMIT)
        return std::make_unique<HttpResponse>(HttpStatusCode::INTERNAL_SERVER_ERROR);
    
    std::vector<char> bytes(filesize, '\0');
    rewind(&*fp);
    fread(&bytes[0], 1, filesize, &*fp);
    
    return std::make_unique<HttpResponse>(HttpStatusCode::OK, HttpHeaders(), HttpResponsePayload(std::string(&bytes[0], filesize), contentType));
}

std::string ImageController::GetContentType(const std::string &path) const
{
    if (path.rfind(".jpg"))
        return "image/jpeg";
    
    if (path.rfind(".png"))
        return "image/png";
    
    return "";
}
