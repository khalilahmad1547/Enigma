#include <iostream>
#include<fstream>
#include<cstring>
/*
#include "enigma.h"
#include "Plugboard.cc"
#include "Rotor1.cc"
#include "Rotor2.cc"
#include "Rotor3.cc"
#include "Reflector.cc"
*/
#include "Rottor.h"
#include "Rottor.cc"
#include "plugboard.h"
#include "Plugboard.cc"
#include "Reflector.h"
#include "reflector.cc"

using namespace std;

int main()
{
    //################################################# File handling ##########################################//

     ifstream fin;
	fin.open("enigma.ini");
	char ch, eny;
	int i = 0,  R1, R2, R3;		// some random variable required
	char *ptr;

	try{
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
							cout<<"inside throw block"<<endl;
							throw 1;
						}
					b++;
				}
			}
		}


	//	cout<<i<<endl; 			// printing message length
		cout<<ptr<<endl;		// printing message on console

		fin.get(ch);			// getting character e/d
		eny = ch;
		cout<<"Ch for encryption is "<<eny<<endl;

		fin.get(ch);			// getting character for next line
		fin >> R1;				// getting Key1
		if(R1 >= 26)
			{
				throw true;
			}

		fin.get(ch);
		fin >> R2;
		if(R2 >= 26)
			{
				throw 'a';
			}

		fin.get(ch);
		fin >> R3;
		if(R3 >= 26)
			{
				throw 4.00;
			}

		cout<<R1<<endl<<R2<<endl<<R3<<endl;
	}

	catch (int number )
		{
			cout<<"Number is not allowed in Encryption\n please change the input string\n, .... good byee.\n";
		}

	catch (bool R1)
		{
			cout<< "Key is greater than 26 for Rotor 1, kindy enter key less than 26 and restart the enigma....\n";
		}

	catch (char R2 )
		{
			cout<< "Key is greater than 26 for Rotor 2, kindy enter key less than 26 and restart the enigma....\n";
		}

	catch (float R3 )
		{
			cout<< "Key is greater than 26 for Rotor 3, kindy enter key less than 26 and restart the enigma....\n";
		}
		//############################################################//
        char p[26]={ 'w','r','y','i','p','k','h','f','s','z','c','b','m','q', 'n','e','v','t','x','u','a','o','d','l','g','j' };
		Plugboard A;
        Reflector B;
        Rottor C(R1,p);
        Rottor D(R2,p);
        Rottor E(R2,p);
        char a;
        cout << "String is "<<ptr<<endl<<"i is "<<i<<endl;
        if(eny == 'e')
        {
             for(int y=0; y<i; y++)
            {
                  a = A.swap(ptr[y]);
                  a = C.Encrypt(a);
                  a = D.Encrypt(a);
                  a = E.Encrypt(a);
                  a = B.swap(a);


                  cout<< "After Encryption "<< a<<endl;
            }
        }
        else if(eny == 'd')
        {
            C.SetRottor();
             for(int y=0; y<i; y++)
            {
                  a = B.swap(ptr[y]);
                  a = E.DeCrypt(a);
                  a = D.DeCrypt(a);
                  a = C.DeCrypt(a);
                  a = A.swap(a);

                cout<< "After Dcryption "<< a<<endl;

            }
        }






}
