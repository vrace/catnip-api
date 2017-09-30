#include "Image.h"
#include "../util/JsonUtils.h"

Image::Image(const std::string &image)
: _image(image)
{
    
}

const std::string& Image::GetImage() const
{
    return _image;
}

std::string Image::ToJsonObject() const
{
    return "{" + ToJsonKeyValue("image", _image) + "}";
}
