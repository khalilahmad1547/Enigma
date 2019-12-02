#ifndef ENGIMA_H_INCLUDED
#define ENGIMA_H_INCLUDED
#include "Rottor.h"
#include "Rottor.cc"
#include "plugboard.h"
#include "Plugboard.cc"
#include "Reflector.h"
#include "reflector.cc"
class Enigma
{
private:
    int Key;
public:
    Enigma();
    Enigma(int k);
    char Encrypt(char ch);
    char Decrypt(char ch);
};


#endif // ENGIMA_H_INCLUDED
