#ifndef HTTP_STATUS_CODE_H
#define HTTP_STATUS_CODE_H

enum class HttpStatusCode
{
    // 200 series
    OK,
    
    // 400 series
    BAD_REQUEST,
    
    // 500 series
    INTERNAL_SERVER_ERROR
};

#endif
