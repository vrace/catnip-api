#include "StaticResourceController.h"
#include "../util/StringUtils.h"
#include "../util/FileUtils.h"

StaticResourceController::StaticResourceController()
{
    
}

std::unique_ptr<HttpResponse> StaticResourceController::HandleRequest(const HttpRequest &request)
{
    if (request.GetMethod() != HttpRequestMethod::GET)
        return nullptr;
    
    auto path = StringUtils::TrimLeft(request.GetURL(), '/');
    if (StringUtils::Contains(path, "/."))
        return std::make_unique<HttpResponse>(HttpStatusCode::NOT_FOUND);
    
    auto contentType = GetContentType(path);
    if (contentType.empty())
        return std::make_unique<HttpResponse>(HttpStatusCode::NOT_FOUND);
    
    std::vector<char> bytes;
    if (!FileUtils::ReadFile(path, bytes))
        return std::make_unique<HttpResponse>(HttpStatusCode::NOT_FOUND);
    
    bytes.push_back('\0');
    
    return std::make_unique<HttpResponse>(HttpStatusCode::OK, HttpHeaders(), HttpResponsePayload(std::string(&bytes[0], bytes.size() - 1), contentType));
}

std::string StaticResourceController::GetContentType(const std::string &path) const
{
    if (StringUtils::EndsWith(path, ".jpg"))
        return "image/jpeg";
    
    if (StringUtils::EndsWith(path, ".html"))
        return "text/html";
    
    return "";
}
