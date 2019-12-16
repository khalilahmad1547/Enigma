#include "Enigma.h"
#include <cstdlib>
#include<fstream>
#include<cstring>
#include "Rottor.h"
#include "Rottor.cc"
#include "Plugboard.h"
#include "Plugboard.cc"
#include "Reflector.h"
#include "Reflector.cc"

using namespace std;
Enigma::Enigma()
{
                                        // constructor
}


void Enigma::FileHandling(char * arrq, char * arrp, int p)
{

                plug = 0;           //variable for checking which setting is used in Encryption
                Ref  = 0;           //  0 for default
                Rot1 = 0;           //  1 for setting read from file
                Rot2 = 0;
                Rot3 = 0;

        if (p == 3)                             // if third argument is present
        {
           ifstream finp;
           finp.open(arrp);                     // opening that file
           if (finp.fail())                     // if opening fails
            {
                cout << "Couldn't find the argument for Rottor setting \n  Running Enigma with default Rotor Setting ...\n" << endl;
                plug = 0;
                Ref  = 0;
                Rot1 = 0;
                Rot2 = 0;
                Rot3 = 0;
            }

            else
            {
                    cout<<"Enigma setting invoked"<<endl;
                    string word;
                        finp >> word;
//###################################Reading Plugboard setting#######################################
                        if(word == "Plugboard:")
                        {
                            plug = 1;
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
                        cout<<"Plugboard Array : "<< q <<endl;
//###################################Reading Rotor 1 setting#######################################

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
                            cout<<"Rotor1 Array    : "<<RR1<<endl;
                        }
//###################################Reading Rotor 2 setting#######################################

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
                            cout<<"Rotor2 Array    : "<<RR2<<endl;
                        }

//###################################Reading Rotor 3 setting#######################################

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
                            cout<<"Rotor3 Array    : "<<RR3<<endl;
                        }
//###################################Reading Reflector setting#######################################

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
                                cout<<"Reflector Array : "<<RF<<endl<<endl;
                        }

              }
          finp.close();         // closing file
        }

       ifstream fin;             // opening Enigma.ini file
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
          ptr = new char [i];		        // creating array memory on heap
          fin.seekg(0);					    // pointing cusor back to start in text file
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
                                }
                            b++;
                        }
                    }
             }

//################################Converting Upper case to Lower case ################################################################//

               for(int y=0; y<i; y++)
                  {
                        if(ptr[y]>=65 && ptr[y]<=92)
                        {
                        ptr[y]=ptr[y]+32;
                        }
                  }

//##############################Exception Handling in Key##################################################################//

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
                exit(0);
            }
		 cout<<"Rotor 1 key : "<<R1<<endl<<"Rotor 2 key : "<<R2<<endl<<"Rotor 3 key : "<<R3<<endl<<endl;

    }

void Enigma::Cipher()
{

            Plugboard A(q, plug);               // Making Objects of Classes
            Reflector B(RF, Ref);
            Rottor C(R1,RR1, 1, Rot1);
            Rottor D(R2,RR2, 2, Rot2);
            Rottor E(R3,RR3, 3, Rot3);
            char a;

            cout << "String is "<<ptr<<endl<<"Message length is "<<i<<endl<<endl;
            cout<< "Encrypted message is \" ";
            ofstream fout;
            fout.open("Output.txt");

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
                          fout<<a;
                        }
                      else
                        {
                          cout<<ptr[y];
                          fout<<ptr[y];
                        }
                  }
               cout<<"\""<<endl;
               fout<<" "<<endl;
               fout<<R1<<endl<<R2<<endl<<R3<<endl;
               fout.close();

}


Enigma::~Enigma()
{
  delete[] Instance;
  delete[] ptr;
  delete[] q;
  delete[] RR1;
  delete[] RR2;
  delete[] RR3;
  delete[] RF;                   // Destructor
}
