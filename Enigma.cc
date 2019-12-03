Enigma::Enigma()
{
// FileName=new char[strlen(FN)];
    //strcpy(FileName,FN);
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


	//	cout<<i<<endl; 			// printing message length
	//	cout<<ptr<<endl;		// printing message on console

		fin.get(ch);			// getting character e/d
		ToDo = ch;
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


	//	cout<<i<<endl; 			// printing message length
	//	cout<<ptr<<endl;		// printing message on console

		fin.get(ch);			// getting character e/d
		ToDo = ch;
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
void Enigma::Do()
{
        char p[26]={ 'w','r','y','i','p','k','h','f','s','z','c','b','m','q', 'n','e','v','t','x','u','a','o','d','l','g','j' };
		Plugboard PB;
        Reflector Re;
        Rottor R1(KeyR1,p);
        Rottor R2(KeyR2,p);
        Rottor R3(KeyR2,p);
        ofstream FileOut;
        FileOut.open("Output.txt");
        if(ToDo == 'e')
        {
            char a;
            FileOut<<"                     En-Crypted Message is               "<<endl;
             for(int y=0; y<strlen(Message); y++)
            {
                if(Message[y]==' ')
                 {
                     FileOut<<" ";
                 }
                 else
                 {
                                       a = PB.Swap(Message[y]);
                  a = R1.Encrypt(a);
                  a = R2.Encrypt(a);
                  a = R3.Encrypt(a);
                  a = Re.Swap(a);
                  //cout<<"En "<<a<<endl;

                 FileOut<<a;
                 }

            }
        }
        else if(ToDo == 'd')
        {
            char a;
            FileOut<<"                     De-Crypted Message is               "<<endl;
            for(int y=0; y<strlen(Message); y++)
            {
                 if(Message[y]==' ')
                 {
                     FileOut<<" ";
                 }
                 else {
                    a = Re.Swap(Message[y]);
                 a=R3.DeCrypt(a);
                 a=R2.DeCrypt(a);
                 a=R1.DeCrypt(a);
                a = PB.Swap(a);
                //cout<<"De "<<a<<endl;
                 FileOut<<a;
                 }

            }
        }

        FileOut.close();
}
Enigma::~Enigma()
{
    delete[] Message;
}
