#ifndef REQUEST_MAPPING_UTILS_H
#define REQUEST_MAPPING_UTILS_H

#include "JsonUtils.h"
#include "HttpResponseUtils.h"

#define BEGIN_REQUEST_MAPPING()\
std::unique_ptr<HttpResponse> HandleRequest(const HttpRequest &request) override {

#define END_REQUEST_MAPPING()\
return std::unique_ptr<HttpResponse>();}

#define REQUEST_MAPPING(method,pattern,func)\
if (request.GetMethod() == method && request.GetURL() == pattern)\
return HttpResponseUtils::JsonResponse(func(request));

#define ON_GET(pattern,func)\
REQUEST_MAPPING(HttpRequestMethod::GET, pattern, func)

#endif
