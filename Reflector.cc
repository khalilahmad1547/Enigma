
#include "Reflector.h"
#include <cstring>
using namespace std;

Reflector::Reflector()
{

}

Reflector::Reflector(char *p, int plug)
    {
        char A[26] = {'a', 'b', 'c', 'n', 'l', 't', 'g', 'r', 'k', 'q', 'f', 'v', 'i', 'z', 'u', 'y', 'h', 'w', 'd', 's', 'o', 'e', 'x', 'm', 'j', 'p' };
        q = new char [26];
        if (plug == 1)
        {
            strcpy(q, p);
           // cout<<"Txt file array copied"<<endl;
        }
        else
         {
             strcpy(q, A);
            // cout<<"Default array copied"<<endl;
         }
    }

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

Reflector::~Reflector()
    {
        delete[] q;
    }
