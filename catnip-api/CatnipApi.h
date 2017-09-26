#ifndef CATNIP_API_H
#define CATNIP_API_H

#include "network/SimpleServer.h"
#include "network/SimpleServerDelegate.h"
#include "base/RestServer.h"

class CatnipApi : public SimpleServerDelegate
{
public:
    CatnipApi();
    
    void Run();
    void ServerStarted() override;
    std::string RequestReceived(const std::string &request) override;
    
private:
    SimpleServer _network;
    RestServer _server;
};

#endif
