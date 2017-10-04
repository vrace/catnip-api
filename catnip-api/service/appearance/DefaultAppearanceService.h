#ifndef DEFAULT_APPEARANCE_SERVICE_H
#define DEFAULT_APPEARANCE_SERVICE_H

#include "AppearanceService.h"

class DefaultAppearanceService : public AppearanceService
{
public:
    DefaultAppearanceService();
    Appearance GetAppearance() override;
};

#endif
