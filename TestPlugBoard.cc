#include<iostream>
using namespace std;
#include<fstream>
#include"plugboard.h"
#include"plugboard.cc"
int main()
{
    Plugboard Pb;
    char MyEnArray[26];
    char MyDeArray[26];
    char MyArray={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for(int i=0;i<26;i++)
    {
    MyEnArray[i]=Pb.Swap(MyArray[i]);
    }
    for(int i=0;i<26;i++)
    {
    MyDeArray[i]=Pb.Swap(MyEnArray[i]);
    }
    int MCount=0;
    int NCount=0;
    for(int i=0;i<26;i++)
    {
        if(MyDeArray[i]==MyArray[i])
            MCount++;
            else if(MyDeArray[i]!=MyArray[i])
            NCount++;
    }
    cout<<"Mached "<<MCount<<endl<<"Not matched "<<NCount;
}
