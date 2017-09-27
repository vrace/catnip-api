#include "MockJsonController.h"
#include "../base/HttpRequestMethodTranslator.h"

#include <vector>
#include <sstream>

#include <stdio.h>
#include <stdlib.h>

MockJsonController::MockJsonController()
{
    
}

std::unique_ptr<HttpResponse> MockJsonController::HandleRequest(const HttpRequest &request)
{
    if (request.GetURL().find("/.") != std::string::npos)
        return std::make_unique<HttpResponse>(HttpStatusCode::BAD_REQUEST);
    
    auto path = (std::stringstream() << request.GetURL() << "/" << request.GetMethod() << ".json").str();
    while (!path.empty() && path[0] == '/')
        path.erase(path.begin());
    
    if (path.find("/.") != std::string::npos)
        return std::make_unique<HttpResponse>(HttpStatusCode::BAD_REQUEST);
    
    auto fp = std::unique_ptr<FILE, decltype(&fclose)>(fopen(path.c_str(), "rb"), fclose);
    if (!fp)
        return std::make_unique<HttpResponse>(HttpStatusCode::BAD_REQUEST);
    
    fseek(&*fp, 0, SEEK_END);
    auto size = ftell(&*fp);
    
    if (size <= 0 || size > 1048576)
        return std::make_unique<HttpResponse>(HttpStatusCode::INTERNAL_SERVER_ERROR);
    
    std::vector<char> buf(size, '\0');
    rewind(&*fp);
    fread(&buf[0], 1, size, &*fp);
    
    return std::make_unique<HttpResponse>(HttpStatusCode::OK, HttpHeaders(), HttpResponsePayload(std::string(&buf[0], size), "application/json"));
}
