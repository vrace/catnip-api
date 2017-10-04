#ifndef APPEARANCE_SERVICE_H
#define APPEARANCE_SERVICE_H

#include "../../model/Appearance.h"

class AppearanceService
{
public:
    virtual Appearance GetAppearance() = 0;
};

#endif
