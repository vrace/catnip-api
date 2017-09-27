#include "CatnipApi.h"
#include "controller/VersionController.h"
#include "controller/ImageController.h"
#include "controller/MockJsonController.h"
#include <iostream>

CatnipApi::CatnipApi()
{
    _network.SetDelegate(*this);
}

void CatnipApi::Run()
{
    VersionController versionController;
    ImageController imageController;
    MockJsonController mockJsonController;
    
    _server.AddController("/version", versionController);
    _server.AddController("/image", imageController);
    _server.AddController("/appearance", mockJsonController);
    
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
