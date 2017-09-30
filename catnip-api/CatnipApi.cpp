#include "CatnipApi.h"
#include "network/SimpleServer.h"
#include "config/CatnipApiConfig.h"
#include <iostream>

CatnipApi::CatnipApi()
{
    
}

void CatnipApi::Run()
{
    SimpleServer network;
    network.SetDelegate(*this);
    network.Start();
}

void CatnipApi::ServerStarted()
{
    std::cout << "CATNIP API STARTED" << std::endl;
}

std::string CatnipApi::RequestReceived(const std::string &request)
{
    return CatnipApiConfig::GetRestServer().Dispatch(request);
}
