#include "FileUtils.h"

#include <iostream>
#include <fstream>

using namespace std;

unsigned char *FileUtils::readFile(const string &filename, int &length)
{
    ifstream file(filename.c_str(), ios::binary);
    
    if(!file.is_open())
        return 0;
    
    unsigned char *result;
    
    file.seekg(0, ios::end);
    length = file.tellg();
    file.seekg(0, ios::beg);
    
    result = new unsigned char[length];
    
    file.read((char *)result, length);
    
    file.close();
    
    return result;
}
