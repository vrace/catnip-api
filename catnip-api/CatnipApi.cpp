#include "CatnipApi.h"
#include "config/CatnipApiConfig.h"
#include <iostream>

CatnipApi::CatnipApi()
: _server(CatnipApiConfig::GetRestServer())
{
    _network.SetDelegate(*this);
}

void CatnipApi::Run()
{
    _network.Start();
}

void CatnipApi::ServerStarted()
{
    std::cout << "CATNIP API STARTED" << std::endl;
}

std::string CatnipApi::RequestReceived(const std::string &request)
{
    return _server->Dispatch(request);
}
