#ifndef REST_SERVER_H
#define REST_SERVER_H

#include <iostream>
#include "HttpResponse.h"

class RestServer
{
public:
    RestServer();
    
    std::string Dispatch(const std::string &request);
    
private:
    HttpResponse BadRequest();
};

#endif
