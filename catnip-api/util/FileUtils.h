#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include "Path.h"
#include <vector>
#include <stdio.h>

class FileUtils
{
public:
    static auto GetFileSize(const Path &path) -> decltype(ftell(nullptr));
    static bool ReadFile(const Path &path, std::vector<char> &bytes);
};

#endif
