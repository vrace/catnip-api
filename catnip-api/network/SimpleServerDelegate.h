#ifndef SIMPLE_SERVER_DELEGATE_H
#define SIMPLE_SERVER_DELEGATE_H

#include <string>

class SimpleServerDelegate
{
public:
    virtual void ServerStarted() = 0;
    virtual std::string RequestReceived(const std::string &request) = 0;
};

#endif
