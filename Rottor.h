#ifndef ROTTOR_H_INCLUDED
#define ROTTOR_H_INCLUDED
class Rottor
{
private:
    int Key;                  //stores the key
    int RottorNo;             //Number of Rotto in Engima
    char* AlphaArray;         //stores the address of alphabets array
    char* TempArray;
    int Count;
    int TempCount;
public:
    Rottor();
    Rottor(int k,char* a,int RNo, int fff);   //parameterized constructor
    int GetPositionA(char ch);
    int GetPositionT(char ch);
    char GetCharA(int no);
    char GetCharT(int no);
    void Rotate(int time,bool Dir);
    void SetRottor();
    char Encrypt(char ch);
  //  char DeCrypt(char ch);
    ~Rottor();               //destructorv
    /*                   Description of GetPosition
                         Functionality
It returns the index number of any char passed to it as argument in TempArray
                         Working
It takes the char from TempArray compare it with entered char until it find match and then returns the index number
    */

    /*                   Description of GetChar
                         Functionality
It returns the char present at the index which is passed to it as argument in AlphaArray
                         Working
It only returns the char at that index in AlphaArray
    */

    /*                   Description of SetRottor
                         Functionality
SetRottor Function actually set the rotor  accordingly to the Key(present in the private part of the class)
                         Working
It determine the number of rotations using Key and than rotate the TempArray and set the array
    */

    /*                   Description of Encrypt Function
                         Functionality
It Takes char and Encrypt it and returns the Encrypted char
                         Working
    */

    /*                   Description of DeCrypt Function
                         Functionality
It Takes char and DeCrypt it and returns the De-Crypted char
                         Working
    */

    /*                   Description of Rotate
                         Functionality
It can rotate TempArray in clockwise & Anti-clockwise by n times
                         Working
    */

  //Rotate function can rotate left or right
    /*                   Description of Rottor
                         Functionality
Constructor Default
                         Working
    */
    //Default constructor
    /*                   Description of parameterized
                         Functionality
It creates the object,create the copy of the entered array,initial set the TempArray according to the key
                         Working
    */

};


#endif // ROTTOR_H_INCLUDED
