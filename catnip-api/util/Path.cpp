#include "Path.h"
#include "StringUtils.h"

Path::Path()
{
    
}

Path::Path(const std::string &path)
{
    _path = StringUtils::TrimLeft(path, '/');
    if (StringUtils::Contains(path, "/."))
        _path.clear();
}

bool Path::IsValid() const
{
    return !_path.empty();
}

const std::string& Path::GetPath() const
{
    return _path;
}

Path::operator const std::string& () const
{
    return _path;
}

std::string Path::GetExtension() const
{
    auto slash = _path.rfind('/');
    auto dot = _path.rfind('.');
    
    if (dot == std::string::npos)
        return "";
    
    if (slash != std::string::npos && slash > dot)
        return "";
    
    return _path.substr(dot);
}
