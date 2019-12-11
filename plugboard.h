#ifndef PLUGBOARD_H_INCLUDED
#define PLUGBOARD_H_INCLUDED

class Plugboard
{
private:
    char *q;
    int plug;
public:
    Plugboard()
    {
       // cout<<"Hello Plugboard::Plugboard() called"<<endl;


    }
    Plugboard(char *p, int plug)
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
      //  cout<<"Hello Plugboard::Plugboard(char *q) called"<<endl;
    }
    ~Plugboard(){delete[] q;}
    char swap(const char a);

};

#endif // PLUGBOARD_H_INCLUDED
