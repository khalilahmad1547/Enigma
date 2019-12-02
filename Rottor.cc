Rottor::Rottor()
{
	Key=0;
    //cout<<"Enter the Rotor Number "<<endl;
    char a[26]={ 'w','r','y','i','p','k','h','f','s','z','c','b','m','q', 'n','e','v','t','x','u','a','o','d','l','g','j' };
    AlphaArray=new char[strlen(a)]; //setting the address of the AlphaArray
   strcpy(AlphaArray,a);    //copying the data from a to TempArray
   TempArray=new char[strlen(a)]; //creating a new memory with length same as AlphaArray is
   strcpy(TempArray,a);     //copying the data from a to TempArray
   SetRottor(); //calling SetRottor function to set TempArray according to the Key
}
Rottor::Rottor(int k,char* a)
{
    Key=k; //setting the Key
   AlphaArray=new char[strlen(a)]; //setting the address of the AlphaArray
   strcpy(AlphaArray,a); //copying the data from a to TempArray
   TempArray=new char[strlen(a)]; //creating a new memory with length same as AlphaArray is
   strcpy(TempArray,a); //copying the data from a to TempArray
   SetRottor(); //calling SetRottor function to set TempArray according to the Key
}
void Rottor::Rotate(int time,bool Dir)
{
    int size=(sizeof(TempArray)/sizeof(TempArray[0]));
   	if(Dir==true) //if true rotate Clock Wise
	{
		//rotating clock wise for time 'time'
        for(int i=0;i<time;i++)
            {
                char temp=TempArray[0];
                for(int i=0;i<size;i++)
                {
                TempArray[i]=TempArray[i+1];
                }
                TempArray[25]=temp;
            }
    }
	else if(Dir==false)//rotating Anti-ClockWise
	{
     for(int i=0;i<time;i++)
        {
            char temp=TempArray[25];
            for(int i=size;i>=0;i--)
            {
                TempArray[i]=TempArray[i-1];
            }
            TempArray[0]=temp;
        }
     }
}

char Rottor::Encrypt(char ch)
{
    Rotate(1,true); //rotating one time clock wise
    return GetCharA(GetPositionT(ch));
}

char Rottor::DeCrypt(char ch)
{
    Rotate(1,true);//rotating anti clock wise
 return GetCharT(GetPositionA(ch));//decrypting

}
int Rottor::GetPositionT(char ch) //getting the present position of char ah in TempArray
{
    for(int i=0;i<26;i++)
    {
        if(TempArray[i]==ch) //matching
        {
            return i; //returning the address of the matched char with ch
        }
    }
}
int Rottor::GetPositionA(char ch) //getting the present position of char ah in TempArray
{
    for(int i=0;i<26;i++)
    {
        if(AlphaArray[i]==ch) //matching
        {
            return i; //returning the address of the matched char with ch
        }
    }
}
char Rottor::GetCharA(int no)
{
    return AlphaArray[no]; //returning the char present at the index no in AlphaArray
}
char Rottor::GetCharT(int no)
{
    return TempArray[no]; //returning the char present at the index no in AlphaArray
}
void Rottor::SetRottor()
{

    int temp=GetPositionT('a'); //getting the present position of a char in the TempArray
    /*
    There appear two cases when Key>25 & Key<=25
                                        In 1st case Key>25:
    Than we have to calculate the position. As we have only available positions are 26 in Range (0 to 25) and we have to convert it
    Think about a numbering system with base 26 which will have numbers only in  Range (0 to 25) so we have to convert Key into 26-Base
    system and the remainder will be the new index or Key. And repeating the process of case 1.
                                        In 2nd case Key<=25:
    in this case there are further two cases char 'a' can be at required position or not
        When char is present at required position:
    than we have to do nothing because Rottor is already in required Position
        When char is not present at required position:
    So if Key<temp this means that we have to rotate TempArray in Clock-wise direction by (temp-Key) times
    So if Key>temp this means that we have to rotate TempArray in AntiClock-wise direction by (Key-temp) times
    */
        if(Key>25) //case1
    {
        int TempKey=Key%26;   //calculating the position according to the Key
                 if(temp!=Key)
        {
            if(TempKey<temp)
            {
                Rotate(temp-TempKey,true); //rotating Clock_wise by "temp-Key" time
            }
            else if(TempKey>temp)
            {
                Rotate(TempKey-temp,false);//rotating AntiClock_wise by "Key-temp" time
            }
        }
    }
    if(Key<=25)  //case 2
    {
        if(temp!=Key) //position is not matching
        {
            if(Key<temp) //present at behind the required position
            {
                Rotate(temp-Key,true); //rotating Clock_wise by "temp-Key" time
            }
            else if(Key>temp)//present ahead from the the required position
            {
                Rotate(Key-temp,false);//rotating AntiClock_wise by "Key-temp" time
            }
        }
    }
}
Rottor::~Rottor()
{
delete[] TempArray;
delete[] AlphaArray;
}
