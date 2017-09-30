#ifndef APPEARANCE_H
#define APPEARANCE_H

#include "Image.h"
#include "../util/JsonUtils.h"
#include <vector>
#include <string>

class Appearance
{
public:
    Appearance();
    
    std::vector<Image>& GetBanners();
    const std::vector<Image>& GetBanners() const;
    
    BEGIN_DEFINE_JSON()
    WITH_JSON_ARRAY("banners", _banners)
    END_DEFINE_JSON()
    
private:
    std::vector<Image> _banners;
};

#endif
