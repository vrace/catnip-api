#include "Appearance.h"
#include "../util/JsonUtils.h"

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

std::string Appearance::ToJsonObject() const
{
    return "{" + ToJsonKeyArray("banners", _banners) + "}";
}
