#include "FileUtils.h"

#include <memory>

#include <stdio.h>
#include <stdlib.h>

namespace
{
    using FilePtr = std::unique_ptr<FILE, decltype(&fclose)>;
    
    FilePtr OpenFile(const std::string &path)
    {
        return FilePtr(fopen(path.c_str(), "rb"), fclose);
    }
    
    auto GetFileSizeImpl(FILE *fp) -> decltype(ftell(fp))
    {
        fseek(fp, 0, SEEK_END);
        return ftell(fp);
    }
    
    void ReadFileImpl(FILE *fp, std::vector<char> &bytes)
    {
        auto size = GetFileSizeImpl(fp);
        
        bytes.resize(size);
        if (size > 0)
        {
            rewind(fp);
            fread(&bytes[0], 1, size, fp);
        }
    }
}

auto FileUtils::GetFileSize(const Path &path) -> decltype(ftell(nullptr))
{
    auto fp = OpenFile(path);
    if (!fp)
        return -1;
    
    return GetFileSizeImpl(&*fp);
}

bool FileUtils::ReadFile(const Path &path, std::vector<char> &bytes)
{
    auto fp = OpenFile(path);
    if (!fp)
        return false;
    
    ReadFileImpl(&*fp, bytes);
    return true;
}
