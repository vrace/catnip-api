#ifndef PATH_H
#define PATH_H

#include <string>

class Path
{
public:
    Path();
    Path(const std::string &path);
    
    bool IsValid() const;
    const std::string& GetPath() const;
    
    std::string GetExtension() const;
    operator const std::string&() const;
    
private:
    std::string _path;
};

#endif
