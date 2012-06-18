#ifndef RANDOM_H
#define RANDOM_H

#include "ghosts-common_global.h"

#include <string>

class GHOSTSCOMMONSHARED_EXPORT Random
{
public:
    static void init(unsigned int seed);
    static int integer();
    static int integer(int s, int e);
    static float foating(float s = 0.0f, float e = 1.0f);
    static char character();
    static std::string string(int length);
};

#endif // RANDOM_H
