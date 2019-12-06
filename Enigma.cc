#include"Enigma.h"
Enigma::Enigma()
{
    FileName="Default.ini";
    ifstream fin;
	fin.open(FileName.c_str());
	char ch;
	int i = 0;		// some random variable required
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

		Message = new char [i+1];		// creating array memory on heap
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
					Message[b] = ch;
					if (int(ch) == 48 || int(ch) == 49 || int(ch) == 50|| int(ch) == 51|| int(ch) == 52|| int(ch) == 53|| int(ch) == 54|| int(ch) == 55|| int(ch) == 56|| int(ch) == 57)
						{
							cout<<"inside throw block"<<endl;
							throw 1;
						}
					b++;
				}
			}
		}

cout<<"Message is "<<Message<<endl;
	//	cout<<i<<endl; 			// printing message length
	//	cout<<ptr<<endl;		// printing message on console

	//	fin.get(ch);			// getting character e/d
	//	ToDo = ch;
	//	cout<<"To do is "<<ToDo<<endl;
	//	cout<<"Ch for encryption is "<<eny<<endl;

		fin.get(ch);			// getting character for next line
		fin >>KeyR1;				// getting Key1
		/*if(R1 >= 26)
			{
				throw true;
			}*/

		fin.get(ch);
		fin >> KeyR2;
		/*if(R2 >= 26)
			{
				throw 'a';
			}*/

		fin.get(ch);
		fin >> KeyR3;
		/*if(R3 >= 26)
			{
				throw 4.00;
			}*/

		//cout<<R1<<endl<<R2<<endl<<R3<<endl;
	}

	catch (int number )
		{
			cout<<"Number is not allowed in Encryption\n please change the input string\n, .... good byee.\n";
		}

	/*catch (bool R1)
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
		}*/
		//############################################################//
}
Enigma::Enigma(string FN)
{
   // FileName=new char[strlen(FN)];
    //strcpy(FileName,FN);
    FileName=FN;
    ifstream fin;
	fin.open(FileName.c_str());
	char ch;
	int i = 0;		// some random variable required
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
cout<<"Message length "<<i<<endl;
		Message = new char [i];		// creating array memory on heap
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
					Message[b] = ch;
					if (int(ch) == 48 || int(ch) == 49 || int(ch) == 50|| int(ch) == 51|| int(ch) == 52|| int(ch) == 53|| int(ch) == 54|| int(ch) == 55|| int(ch) == 56|| int(ch) == 57)
						{
							cout<<"inside throw block"<<endl;
							throw 1;
						}
					b++;
				}
			}
		}
cout<<"Data inside the file "<<Message<<endl;

	//	cout<<i<<endl; 			// printing message length
	//	cout<<ptr<<endl;		// printing message on console

		//fin.get(ch);			// getting character e/d
	//	ToDo = ch;
	//	cout<<"Ch for encryption is "<<eny<<endl;

		fin.get(ch);			// getting character for next line
		fin >>KeyR1;				// getting Key1
		cout<<"Rotor one key "<<KeyR1<<endl;
		/*if(R1 >= 26)
			{
				throw true;
			}*/

		fin.get(ch);
		fin >> KeyR2;
		cout<<"Rotor one key "<<KeyR2<<endl;
		/*if(R2 >= 26)
			{
				throw 'a';
			}*/

		fin.get(ch);
		fin >> KeyR3;
		cout<<"Rotor one key "<<KeyR3<<endl;
		/*if(R3 >= 26)
			{
				throw 4.00;
			}*/

		//cout<<R1<<endl<<R2<<endl<<R3<<endl;
	}

	catch (int number )
		{
			cout<<"Number is not allowed in Encryption\n please change the input string\n, .... good byee.\n";
		}

	/*catch (bool R1)
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
		}*/
		//############################################################//

}
void Enigma::Do()
{
        char p[26]={ 'w','r','y','i','p','k','h','f','s','z','c','b','m','q', 'n','e','v','t','x','u','a','o','d','l','g','j' };
		Plugboard Pb;
        Rottor R1(KeyR1,p,1);
        Rottor R2(KeyR2,p,2);
        Rottor R3(KeyR3,p,3);
        Reflector Re;
        ofstream FileOut;
        FileOut.open("Output.txt");
        char temp;
        for(int i=0;i<strlen(Message);i++)
        {
        if(Message[i]==' ')
        {
        FileOut<<" ";
        }
        else {
        temp=Pb.Swap(Message[i]);
        temp=R1.Encrypt(temp);
        temp=R2.Encrypt(temp);
        temp=R3.Encrypt(temp);
        temp=Re.Swap(temp);
        temp=R3.Encrypt(temp);
        temp=R2.Encrypt(temp);
        temp=R1.Encrypt(temp);
        temp=Pb.Swap(temp);
        FileOut<<temp;
        }

        }

        FileOut.close();
}
Enigma::~Enigma()
{
    delete[] Message;
}
