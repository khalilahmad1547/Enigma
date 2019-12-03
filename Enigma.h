#ifndef ENIGMA_H_INCLUDED
#define ENIGMA_H_INCLUDED
class Enigma
{
private:
string FileName;
char *Message;
char ToDo;
int KeyR1;
int KeyR2;
int KeyR3;
public:
Enigma();
Enigma(string FN);
~Enigma();
void Do();
};


#endif // ENIGMA_H_INCLUDED
