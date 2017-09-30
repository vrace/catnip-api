#ifndef IMAGE_H
#define IMAGE_H

#include <string>

class Image
{
public:
    Image(const std::string &image);
    
    const std::string& GetImage() const;
    std::string ToJsonObject() const;
    
private:
    std::string _image;
};

#endif
