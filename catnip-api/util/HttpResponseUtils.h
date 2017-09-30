#ifndef HTTP_RESPONSE_UTILS_H
#define HTTP_RESPONSE_UTILS_H

#include "../base/HttpResponse.h"
#include "JsonUtils.h"
#include <memory>

class HttpResponseUtils
{
public:
    template <class T>
    static std::unique_ptr<HttpResponse> JsonResponse(const T &obj)
    {
        return std::make_unique<HttpResponse>(HttpStatusCode::OK, HttpHeaders(), HttpResponsePayload(ToJsonObject(obj), "application/json"));
    }
};

#endif
