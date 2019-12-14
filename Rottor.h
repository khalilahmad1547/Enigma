#ifndef ROTTOR_H_INCLUDED
#define ROTTOR_H_INCLUDED
class Rottor
{

private:
                            // Attributes
    int Key;                                //stores the key
    int RottorNo;                           //Number of Rotto in Engima
    char* AlphaArray;                       //stores the address of alphabets array
    char* TempArray;
    int Count;
    int TempCount;

public:
                            // Behaviour
    Rottor();
    Rottor(int k,char* a,int RNo, int fff);   //parameterized constructor
    int GetPositionA(char ch);
    int GetPositionT(char ch);
    char GetCharA(int no);
    char GetCharT(int no);
    void Rotate(int time,bool Dir);
    void SetRottor();
    char Encrypt(char ch);
    ~Rottor();

};


#endif // ROTTOR_H_INCLUDED
