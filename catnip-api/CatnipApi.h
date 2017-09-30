#ifndef CATNIP_API_H
#define CATNIP_API_H

#include "network/SimpleServerDelegate.h"

class CatnipApi : public SimpleServerDelegate
{
public:
    CatnipApi();
    
    void Run();
    void ServerStarted() override;
    std::string RequestReceived(const std::string &request) override;
};

#endif
