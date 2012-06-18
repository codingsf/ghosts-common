#include "Random.h"

#include <cstdlib>
#include <string>

std::string characters = "abcdefghijklomnopqrstuvwxyzABCDEFGHIJKLOMNOPQRSTUVWXYZ0123456789";

void Random::init(unsigned int seed)
{
    srand(seed);
}

int Random::integer()
{
    return (int)rand();
}

int Random::integer(int s, int e)
{
    int r = integer();
    
    if(s >= e)
        return 0;
    
    return r%(e-s) + s;
}

float Random::foating(float s, float e)
{
    return (float)rand()/(float)RAND_MAX * (e - s) + s;
}

char Random::character()
{
    return characters.at(rand()%characters.length());
}

std::string Random::string(int length)
{
    std::string result = "";
    
    for(int i = 0; i < length; i++)
        result.append(1, character());
    
    return result;
}
