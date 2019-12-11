
#include "Reflector.h"
#include <cstring>
using namespace std;

char Reflector::swap(char a)
{
    int r;
    for (int i = 0; i<26; i++)
    {
        if (a == q[i])
        {
            r = i;
            break;
        }
    }

    r = 25 - r;
    return q[r];
}
