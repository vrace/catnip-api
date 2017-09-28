#include "ImageController.h"
#include "../util/StringUtils.h"
#include "../util/FileUtils.h"
#include "../util/Path.h"

namespace
{
    const long FILE_SIZE_LIMIT = 10485760;  // 10 MB
}

ImageController::ImageController()
{
    
}

std::unique_ptr<HttpResponse> ImageController::HandleRequest(const HttpRequest &request)
{
    if (request.GetMethod() != HttpRequestMethod::GET)
        return std::make_unique<HttpResponse>(HttpStatusCode::BAD_REQUEST);
    
    return GetImage(Path(request.GetURL()));
}

std::unique_ptr<HttpResponse> ImageController::GetImage(const Path &path) const
{
    if (!path.IsValid())
        return std::make_unique<HttpResponse>(HttpStatusCode::NOT_FOUND);
    
    auto contentType = GetContentType(path);
    if (contentType.empty())
        return std::make_unique<HttpResponse>(HttpStatusCode::NOT_FOUND);
    
    auto filesize = FileUtils::GetFileSize(path.GetPath());
    if (filesize <= 0 || filesize > FILE_SIZE_LIMIT)
        return std::make_unique<HttpResponse>(HttpStatusCode::INTERNAL_SERVER_ERROR);
    
    std::vector<char> bytes;
    if (!FileUtils::ReadFile(path, bytes))
        return std::make_unique<HttpResponse>(HttpStatusCode::INTERNAL_SERVER_ERROR);
    
    return std::make_unique<HttpResponse>(HttpStatusCode::OK, HttpHeaders(), HttpResponsePayload(std::string(&bytes[0], filesize), contentType));
}

std::string ImageController::GetContentType(const Path &path) const
{
    auto ext = path.GetExtension();
    
    if (ext == ".jpg")
        return "image/jpeg";
    
    if (ext == ".png")
        return "image/png";
    
    return "";
}
