#ifndef APPEARANCE_H
#define APPEARANCE_H

#include "Image.h"
#include <vector>
#include <string>

class Appearance
{
public:
    Appearance();
    
    std::vector<Image>& GetBanners();
    const std::vector<Image>& GetBanners() const;
    
    std::string ToJsonObject() const;
    
private:
    std::vector<Image> _banners;
};

#endif
