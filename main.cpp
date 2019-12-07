#include <cstdlib>
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

    char ch, *ptr ;
	int i = 0,  R1, R2, R3, plug;		// some random variable required
	char *q = new char [25];

    void file_handling(char * arrq, char * arrp, int p)
    {
        if (p == 3)
        {
       ifstream finp;
       finp.open(arrp);
       if (finp.fail())
            {
                cout << "Couldn't find the argument for plugboard setting \n  Running Enigma with default Plugboard Setting ...\n" << endl;
            }
          else
            {
                cout<<"Plugboard setting invoked"<<endl;
                    plug = 1;
                    int g=0;
                    int t=25;
                        while(!finp.eof())
                        {
                            finp.get(ch);
                            q[g] =ch;
                            finp.get(ch);
                            q[t] = ch;
                            finp.get(ch);
                            if(int(ch) != 10)
                            {
                                cout<<"Enter in correct pair \n Remember no pair has more two elements\n";
                                plug = 0;
                                break;
                            }
                            if(g == 13  || t == 13)
                                break;
                            g++;
                            t--;
                        }
            }
          finp.close();
        }
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
           // i--;
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
                std::abort();
            }

		 fin.get(ch);
		 fin >> R2;
		 fin.get(ch);
		 fin >> R3;
		 cout<<"Rotor 1 key : "<<R1<<endl<<"Rotor 2 key : "<<R2<<endl<<"Rotor 3 key : "<<R3<<endl<<endl;
        // delete[] ptr;
    }

    void cipher( )
    {
            char p[26]={ 'w','r','y','i','p','k','h','f','s','z','c','b','m','q', 'n','e','v','t','x','u','a','o','d','l','g','j' };

            Plugboard A(q, plug);
            Reflector B;
            Rottor C(R1,p, 1);
            Rottor D(R2,p, 2);
            Rottor E(R2,p, 3);
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

