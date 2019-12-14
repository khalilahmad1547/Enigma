#include <iostream>
#include "Enigma.h"
#include "Enigma.cc"

using namespace std;

Enigma *Enigma::Instance = 0;                         // pointer is initialized with 0

int main(int argc, char ** argv)
{
    Enigma *E = E->GetInstance();                     // initializing Enigma Object
    E->FileHandling(argv[1], argv[2], argc);          // reading all data from file
    E->Cipher();                                      // encyption of text
    return 0;

}

