#include"Reflector.h"
#include <cstring>
using namespace std;

char Reflector::Swap(char a)
{
    int q;
    char A[27] = "abcdefghijklmnopqrstuvwxyz" ;

    for (int i = 0; i<26; i++)
    {
       // cout<<A[i]<<endl;
        if (a == A[i])
        {
            q = i;
            //cout<<A[i]<<endl;
            //cout<<i<<endl;
            break;
        }
    }

    q = 25 - q;
    return A[q];
}
