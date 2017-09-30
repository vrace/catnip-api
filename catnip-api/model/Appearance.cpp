#include "Appearance.h"

Appearance::Appearance()
{
    
}

std::vector<Image>& Appearance::GetBanners()
{
    return _banners;
}

const std::vector<Image>& Appearance::GetBanners() const
{
    return _banners;
}
