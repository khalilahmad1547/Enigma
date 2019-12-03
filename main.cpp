#include <iostream>
#include<fstream>
#include<cstring>
/*
#include "enigma.h"
#include "Plugboard.cc"
#include "Rotor1.cc"
#include "Rotor2.cc"
#include "Rotor3.cc"
#include "Reflector.cc"
*/
#include "Rottor.h"
#include "Rottor.cc"
#include "plugboard.h"
#include "Plugboard.cc"
#include "Reflector.h"
#include "reflector.cc"
#include"Enigma.h"
#include"Enigma.cc"

using namespace std;
int main()
{
    string Fn;
    cout<<"Enter file name"<<endl;
    //getline(cin,Fn);
    cin>>Fn;
    Enigma E(Fn);
    E.Do();

}
