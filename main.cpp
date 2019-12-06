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
    string word;
    char ch, eny;
	int i = 0,  R1, R2, R3;		// some random variable required
	char *ptr;
    void file_handling(char * arrq)
    {
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
        // cout<<ptr<<endl;		// printing message on console

		// fin.get(ch);			// getting character e/d
		 //eny = ch;
		// cout<<"Ch for encryption is "<<eny<<endl;

		// fin.get(ch);			// getting character for next line

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
		 cout<<R1<<endl<<R2<<endl<<R3<<endl;
        // delete[] ptr;
    }

    void cipher()
    {
            char p[26]={ 'w','r','y','i','p','k','h','f','s','z','c','b','m','q', 'n','e','v','t','x','u','a','o','d','l','g','j' };
            Plugboard A;
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
               cout<<"\"";

    }

//    delete[] *ptr;

}


int main(int argc, char ** argv)
{
    Enigmaa::file_handling(argv[1]);
    Enigmaa::cipher();

}

