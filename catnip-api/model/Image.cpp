#include "Image.h"

Image::Image(const std::string &image)
: _image(image)
{
    
}

const std::string& Image::GetImage() const
{
    return _image;
}
