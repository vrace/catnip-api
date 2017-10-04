#ifndef CATNIP_API_CONFIG_H
#define CATNIP_API_CONFIG_H

#include "../base/RestServer.h"
#include "../base/RestController.h"

class CatnipApiConfig
{
public:
    static RestServer* GetRestServer();
    
private:
    static RestController& GetAppearanceController();
    static RestController& GetMomentController();
    static RestController& GetStaticResourceController();
};

#endif
