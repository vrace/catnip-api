#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include "../util/JsonUtils.h"

class Image
{
public:
    Image(const std::string &image);
    
    const std::string& GetImage() const;
    
    BEGIN_DEFINE_JSON()
    WITH_JSON_OBJECT("image", _image)
    END_DEFINE_JSON()
    
private:
    std::string _image;
};

#endif
