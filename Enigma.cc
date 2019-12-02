#include "Rottor.h"
#include "Rottor.cc"
#include "plugboard.h"
#include "Plugboard.cc"
#include "Reflector.h"
#include "reflector.cc"
Enigma::Enigma()
{
    Key=0;
    int KeyR1=k%100; //key for rotor one
    k=k/100;
    int KeyR2=k%100;//key for rotor two
    k=k/100;
    int KeyR3=k;//key for rotor three
    char c[26]={ 'w','r','y','i','p','k','h','f','s','z','c','b','m','q', 'n','e','v','t','x','u','a','o','d','l','g','j' };
    Rottor R1(KeyR1,c);
    Rottor R2(KeyR2,c);
    Rottor R3(KeyR3,c);
    Reflector Re;
    Plugboard Pb;
}
Enigma::Enigma(int k)
{
    int KeyR1=k%100; //key for rotor one
    k=k/100;
    int KeyR2=k%100;//key for rotor two
    k=k/100;
    int KeyR3=k;//key for rotor three
    char c[26]={ 'w','r','y','i','p','k','h','f','s','z','c','b','m','q', 'n','e','v','t','x','u','a','o','d','l','g','j' };
    Rottor R1(KeyR1,c);
    Rottor R2(KeyR2,c);
    Rottor R3(KeyR3,c);
    Reflector Re;
    Plugboard Pb;

}
Enigma::Encrypt(char ch)
{
    return Re.Swap(R3(R2(R1(Pb.Swap(ch)))));

}
