#include "StaticHtmlController.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>

StaticHtmlController::StaticHtmlController()
{
    
}

std::unique_ptr<HttpResponse> StaticHtmlController::HandleRequest(const HttpRequest &request)
{
    if (request.GetMethod() != HttpRequestMethod::GET)
        return nullptr;
    
    auto path = request.GetURL();
    while (!path.empty() && path[0] == '/')
        path.erase(path.begin());
    
    if (path.find("/.") != std::string::npos)
        return std::make_unique<HttpResponse>(HttpStatusCode::BAD_REQUEST);
    
    if (path.rfind(".html") != path.length() - 5)
        return nullptr;
    
    auto fp = std::unique_ptr<FILE, decltype(&fclose)>(fopen(path.c_str(), "rb"), fclose);
    if (!fp)
        return nullptr;
    
    fseek(&*fp, 0, SEEK_END);
    auto size = ftell(&*fp);
    if (size <= 0 || size > 1048576)
        return std::make_unique<HttpResponse>(HttpStatusCode::INTERNAL_SERVER_ERROR);
    
    std::vector<char> bytes(size, '\0');
    rewind(&*fp);
    fread(&bytes[0], 1, size, &*fp);
    
    return std::make_unique<HttpResponse>(HttpStatusCode::OK, HttpHeaders(), HttpResponsePayload(std::string(&bytes[0], size), "text/html"));
}
