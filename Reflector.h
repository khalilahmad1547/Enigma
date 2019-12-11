#ifndef REFLECTOR_H_INCLUDED
#define REFLECTOR_H_INCLUDED

class Reflector
{
private:
    char *q;
    int plug;
public:
    Reflector()
    {

    }
    Reflector(char *p, int plug)
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
    ~Reflector()
    {
        delete[] q;
    }
    char swap(char a);
};

#endif // REFLECTOR_H_INCLUDED
