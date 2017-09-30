#include "CatnipApiConfig.h"
#include "../controller/MockJsonController.h"
#include "../controller/AppearanceController.h"
#include "../controller/StaticResourceController.h"

RestServer& CatnipApiConfig::GetRestServer()
{
    static RestServer *server;
    
    if (!server)
    {
        server = new RestServer();
        server->AddRequestMapping(RequestMapping("/appearance", GetAppearanceController()));
        server->AddRequestMapping(RequestMapping("/moment", GetMomentController()));
        server->AddRequestMapping(RequestMapping("", GetStaticResourceController()));
    }
    
    return *server;
}

RestController& CatnipApiConfig::GetAppearanceController()
{
    static AppearanceController controller;
    return controller;
}

RestController& CatnipApiConfig::GetMomentController()
{
    static MockJsonController controller;
    return controller;
}

RestController& CatnipApiConfig::GetStaticResourceController()
{
    static StaticResourceController controller;
    return controller;
}
