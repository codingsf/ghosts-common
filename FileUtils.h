#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <string>

class FileUtils
{
public:
    static unsigned char *readFile(const std::string &filename, int &length);
};

#endif // FILEUTILS_H