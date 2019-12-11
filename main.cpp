#include <iostream>
using namespace std;
#include<fstream>
#include<cstring>
#include "Rottor.h"
#include "Rottor.cc"
#include "plugboard.h"
#include "Plugboard.cc"
#include "Reflector.h"
#include "reflector.cc"



namespace Enigmaa
{
    char ch, *ptr, *q  ,*RR2, *RR1, *RR3, *RF, eny ;
	int i = 0,  R1, R2, R3, plug, Ref, Rot1, Rot2, Rot3, g, t;		// some random variable required

    void file_handling(char * arrq, char * arrp, int p)
    {
    //               ##############             //

                plug = 0;
                Ref = 0;
                Rot1 = 0;
                Rot2 = 0;
                Rot3 = 0;

        if (p == 3)
        {
           ifstream finp;
           finp.open(arrp);
           if (finp.fail())
            {
                cout << "Couldn't find the argument for Rottor setting \n  Running Enigma with default Rotor Setting ...\n" << endl;
                plug = 0;
                Ref = 0;
                Rot1 = 0;
                Rot2 = 0;
                Rot3 = 0;
            }
            else
        {
                cout<<"Enigma setting invoked"<<endl;
                    plug = 1;
                    string word;

                        finp >> word;
                        if(word == "Plugboard:")
                        {
                            q = new char [26];
                            finp.get(ch);
                            finp.get(ch);
                            g=0;
                            t=25;
                                for(int g=0; g<=13; g++)
                                {
                                    finp.get(ch);
                                    q[g] =ch;
                                    finp.get(ch);
                                    q[t] = ch;
                                    finp.get(ch);
                                    finp.get(ch);
                                    if(int(ch) != 10)
                                    {
                                        cout<<"Enter in correct pair \n Remember no pair has more two elements\n";
                                        plug = 0;
                                        break;
                                        exit(0);
                                    }
                                    if(g == 13  || t == 13)
                                        break;
                                    t--;
                                }

                        }
                        cout<<"Plugboard Array: "<< q <<endl;



                        finp >> word;
                        if(word == "Rotor1:")
                        {
                            Rot1 = 1;
                            RR1 = new char [26];
                            finp.get(ch);
                            for (int i=0; i<26; i++)
                            {
                                finp.get(ch);
                                RR1[i] = ch;
                            }
                            //RR1[26] = '\0';
                            cout<<"Rotor1 Array: "<<RR1<<endl;
                        }


                        finp >> word;
                        if(word == "Rotor2:")
                        {
                            Rot2=1;
                            RR2 = new char [26];
                            finp.get(ch);
                            for (int i=0; i<26; i++)
                            {
                                finp.get(ch);
                                RR2[i] = ch;
                            }
                            //RR2[26] = '\0';
                            cout<<"Rotor2 Array: "<<RR2<<endl;
                        }


                        finp >> word;
                        if(word == "Rotor3:")
                        {
                            Rot3 = 1;
                            RR3 = new char [26];
                            finp.get(ch);
                            for (int i=0; i<27; i++)
                            {
                                finp.get(ch);
                                RR3[i] = ch;
                            }
                          //  RR3[26] = '\0';
                            cout<<"Rotor3 Array: "<<RR3<<endl;
                        }

                        finp >> word;
                        if(word == "Reflector:")
                        {
                            RF = new char [26];
                            finp.get(ch);
                            finp.get(ch);
                            g=0;
                            t=25;
                            Ref= 1;
                                for(int g=0; g<=13; g++)
                                {
                                    finp.get(ch);
                                    RF[g] =ch;
                                    finp.get(ch);
                                    RF[t] = ch;
                                    finp.get(ch);
                                    finp.get(ch);
                                    if(int(ch) != 10)
                                    {
                                        cout<<"Enter in correct pair \n Remember no pair has more two elements\n";
                                        Ref = 0;
                                        break;
                                        exit(0);
                                    }
                                    if(g == 13  || t == 13)
                                        break;
                                    t--;
                                }
                                cout<<"Reflector Array: "<<RF<<endl;
                        }

                     }
          finp.close();
        }
    //*******************************************//




       ifstream fin;
         fin.open(arrq);
         if (fin.fail())
            {
                cout << "Couldn't find the argument \n   opening default ini file ...\n" << endl;
                fin.open("enigma.ini");
            }

         while (!fin.eof())
            {
                fin.get(ch);
                if (ch != 13 || ch != 10 )
                  {
                     if(int(ch) == 10)
                        {
                            break;
                        }
                      else
                          i++;				// counting string length of message
                  }
             }
            i--;
          ptr = new char [i];		// creating array memory on heap
          fin.seekg(0);					// pointing cusor back to start in text file
          int b= 0;

          while (!fin.eof())
            {
                fin.get(ch);
                    if (ch != 13 || ch != 10 )
                    {
                        if(int(ch) == 10)
                        {
                            break;
                        }
                        else
                        {
                            ptr[b] = ch;
                            if (int(ch) == 48 || int(ch) == 49 || int(ch) == 50|| int(ch) == 51|| int(ch) == 52|| int(ch) == 53|| int(ch) == 54|| int(ch) == 55|| int(ch) == 56|| int(ch) == 57)
                                {
                                    cout<<"Number in Message,... but program will handle it."<<endl;
                                    //throw 1;
                                }
                            b++;
                        }
                    }
             }

             //################################################################################################//

               for(int y=0; y<i; y++)
                  {
                        if(ptr[y]>=65 && ptr[y]<=92)
                        {
                        ptr[y]=ptr[y]+32;
                        }
                  }
                //  cout<<ptr<<endl;
             //################################################################################################//

		  fin >> R1;
		  try{ if (R1 == 0)
                {
                        throw 1;
                }
             }
          catch(int a)
            {
                cout<<"Enter correct value of Rotor 1"<<endl;
                cout<<"good bye....";
                delete ptr;
                exit(0);
            }

		 fin.get(ch);
		 fin >> R2;
		  try{ if (R2 == 0)
                {
                        throw 1;
                }
             }
          catch(int a)
            {
                cout<<"Enter correct value of Rotor 2"<<endl;
                cout<<"good bye....";
                delete ptr;
                //std::abort();
                exit(0);
            }
		 fin.get(ch);
		 fin >> R3;
		  try{ if (R1 == 0)
                {
                        throw 1;
                }
             }
          catch(int a)
            {
                cout<<"Enter correct value of Rotor 3"<<endl;
                cout<<"good bye....";
                delete ptr;
                //std::abort();
                exit(0);
            }
		 cout<<"Rotor 1 key : "<<R1<<endl<<"Rotor 2 key : "<<R2<<endl<<"Rotor 3 key : "<<R3<<endl<<endl;
        // delete[] ptr;
    }

  void cipher( )
    {


            Plugboard A(q, plug);
            Reflector B(RF, Ref);
            Rottor C(R1,RR1, 1, Rot1);
            Rottor D(R2,RR2, 2, Rot2);
            Rottor E(R2,RR3, 3, Rot3);
            char a;
            cout << "String is "<<ptr<<endl<<"Message length is "<<i<<endl<<endl;

                cout<< "Encrypted message is \" ";
                 for(int y=0; y<i; y++)
                  {
                      if(ptr[y]>= 'a' && ptr[y] <= 'z' )
                        {
                          a = A.swap(ptr[y]);
                          a = C.Encrypt(a);
                          a = D.Encrypt(a);
                          a = E.Encrypt(a);
                          a = B.swap(a);
                          a = E.Encrypt(a);
                          a = D.Encrypt(a);
                         a = C.Encrypt(a);
                         a = A.swap(a);
                          cout<< a;
                        }
                      else
                        {
                         cout<<ptr[y];
                        }
                  }
               cout<<"\""<<endl;

    }

//    delete[] *ptr;

}

int main(int argc, char ** argv)
{
    Enigmaa::file_handling(argv[1], argv[2], argc);
    Enigmaa::cipher();

}

