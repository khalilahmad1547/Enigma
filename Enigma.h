#ifndef ENIGMA_H_INCLUDED
#define ENIGMA_H_INCLUDED

using namespace std;
class Enigma
{
private:
    static Enigma *Instance;                                        // Static Pointer for Calling Constructor
    char ch, *ptr, *q  ,*RR2, *RR1, *RR3, *RF ;                     // random Variable
	int i = 0,  R1, R2, R3, plug, Ref, Rot1, Rot2, Rot3, g, t;
    Enigma();                                                       // Constructor

public:
    void FileHandling(char *a, char *b, int c);                     // reading data from file
    void Cipher();                                                  // Encrypted the text
    ~Enigma();                                                      // Destructor
    static Enigma *GetInstance()                                    // Function for Calling Constructor
    {
      if (!Instance)
      Instance = new Enigma;
      return Instance;
    }

};

#endif // ENIGMA_H_INCLUDED
