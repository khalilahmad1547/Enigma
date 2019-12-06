#include <iostream>
using namespace std;
#include<fstream>
#include<cstring>
#include"PlugBoard.h"
#include"PlugBoard.cc"
#include"Rottor.h"
#include"Rottor.cc"
#include"Reflector.h"
#include"Reflector.cc"
#include"Enigma.h"
#include"Enigma.cc"
int main()
{
/*
char ch;
char a[26]={ 'w','r','y','i','p','k','h','f','s','z','c','b','m','q', 'n','e','v','t','x','u','a','o','d','l','g','j' };
Reflector Re;
Rottor R1(12,a,1);
Rottor R2(20,a,2);
Rottor R3(30,a,3);
Plugboard Pb;
char temp;
char b[11]={'a','b','d','u','r','r','a','h','m','a','n'};

//cout<<strlen(b)<<endl;

for(int i=0;i<11;i++)
{
temp=Pb.Swap(b[i]);
temp=R1.Encrypt(temp);
temp=R2.Encrypt(temp);
temp=R3.Encrypt(temp);
temp=Re.Swap(temp);
temp=R3.Encrypt(temp);
temp=R2.Encrypt(temp);
temp=R1.Encrypt(temp);
temp=Pb.Swap(temp);
cout<<temp<<" ";
b[i]=temp;
}
cout<<endl;
R1.SetRottor();
R2.SetRottor();
R3.SetRottor();
for(int i=0;i<11;i++)
{
temp=Pb.Swap(b[i]);
temp=R1.Encrypt(temp);
temp=R2.Encrypt(temp);
temp=R3.Encrypt(temp);
temp=Re.Swap(temp);
temp=R3.Encrypt(temp);
temp=R2.Encrypt(temp);
temp=R1.Encrypt(temp);
temp=Pb.Swap(temp);
cout<<temp<<" ";
b[i]=temp;
}*/
Enigma E;
E.Do();
}
