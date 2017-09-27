#include "CatnipApi.h"
#include "controller/VersionController.h"
#include <iostream>

CatnipApi::CatnipApi()
{
    _network.SetDelegate(*this);
}

void CatnipApi::Run()
{
    VersionController versionController;
    _server.AddController("/version", versionController);
    _network.Start();
}

void CatnipApi::ServerStarted()
{
    std::cout << "CATNIP API STARTED" << std::endl;
}

std::string CatnipApi::RequestReceived(const std::string &request)
{
    return _server.Dispatch(request);
}
