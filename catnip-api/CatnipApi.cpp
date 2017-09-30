#include "CatnipApi.h"
#include "controller/MockJsonController.h"
#include "controller/StaticResourceController.h"
#include <iostream>

CatnipApi::CatnipApi()
{
    _network.SetDelegate(*this);
}

void CatnipApi::Run()
{
    MockJsonController mockJsonController;
    StaticResourceController staticResourceController;
    
    _server.AddRequestMapping(RequestMapping("/appearance", mockJsonController));
    _server.AddRequestMapping(RequestMapping("/moment", mockJsonController));
    _server.AddRequestMapping(RequestMapping("", staticResourceController));
    
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
