#ifndef REST_SERVER_H
#define REST_SERVER_H

#include <iostream>

class RestServer
{
public:
    RestServer();
    
    std::string Dispatch(const std::string &request);
};

#endif
