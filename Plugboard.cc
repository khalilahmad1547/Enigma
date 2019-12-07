
# include "plugboard.h"

char Plugboard::swap( char z)
{
    int x;

    for(int i=0; i<26;i++)
    {
        if(z == q[i])
        {
            x =i;
            break;
        }
    }

    x = 25 - x ;
    return q[x];

}
    /*
    if (z == 'A' || z == 'a' || z == 'p' || z == 'P')
	{
		if (z == 'a' || z == 'A')
		{

			z = 'p';
			return z;
		}
		else if (z == 'p' || z == 'P')
		{
			z = 'a';
			return z;
		}
	}
	else if (z == 'b' || z == 'B' || z == 'J' || z == 'j')
	{
		if (z == 'b' || z == 'B')
		{
			z = 'j';
			return z;
		}
		else if (z == 'j' || z == 'J')
		{
			z = 'b';
			return z;
		}
	}
	else if (z == 'c' || z == 'C' || z == 'M' || z == 'm')
	{
		if (z == 'm' || z == 'M')
		{
			z = 'c';
			return z;
		}
		else if (z == 'c' || z == 'C')
		{
			z = 'm';
			return z;
		}
	}
	else if (z == 'n' || z == 'N' || z == 'X' || z == 'x')
	{
		if (z == 'X' || z == 'x')
		{
			z = 'n';
			return z;
		}
		else if (z == 'n' || z == 'N')
		{
			z = 'x';
			return z;
		}
	}

	else if (z == 'L' || z == 'l' || z == 'E' || z == 'e')
	{
		if (z == 'L' || z == 'l')
		{
			z = 'e';
			return z;
		}
		else if (z == 'E' || z == 'e')
		{
			z = 'l';
			return z;
		}
	}
	else if (z == 'T' || z == 't' || z == 'o' || z == 'O')
	{
		if (z == 'T' || z == 't')
		{
			z = 'o';
			return z;
		}
		else if (z == 'o' || z == 'O')
		{
			z = 't';
			return z;
		}
	}
	else if (z == 'g' || z == 'G' || z == 's' || z == 'S')
	{
		if (z == 'g' || z == 'G')
		{
			z = 's';
			return z;
		}
		else if (z == 's' || z == 'S')
		{
			z = 'g';
			return z;
		}
	}
	else if (z == 'R' || z == 'r' || z == 'd' || z == 'D')
	{
		if (z == 'R' || z == 'r')
		{
			z = 'd';
			return z;
		}
		else if (z == 'd' || z == 'D')
		{
			z = 'r';
			return z;
		}
	}
	else if (z == 'k' || z == 'K' || z == 'w' || z == 'W')
	{
		if (z == 'k' || z == 'K')
		{
			z = 'w';
			return z;
		}
		else if (z == 'w' || z == 'W')
		{
			z = 'k';
			return z;
		}
	}
	else if (z == 'q' || z == 'Q' || z == 'h' || z == 'H')
	{
		if (z == 'q' || z == 'Q')
		{
			z = 'h';
			return z;
		}
		else if (z == 'h' || z == 'H')
		{
			z = 'q';
			return z;
		}
	}
	else if (z == 'F' || z == 'f' || z == 'Y' || z == 'y')
	{
		if (z == 'F' || z == 'f')
		{
			z = 'y';
			return z;
		}
		else if (z == 'Y' || z == 'y')
		{
			z = 'f';
			return z;
		}
	}
	else if (z == 'v' || z == 'V' || z == 'u' || z == 'U')
	{
		if (z == 'v' || z == 'V')
		{
			z = 'u';
			return z;
		}
		else if (z == 'u' || z == 'U')
		{
			z = 'v';
			return z;
		}
	}
	else if (z == 'i' || z == 'I' || z == 'z' || z == 'Z')
	{
		if (z == 'i' || z == 'I')
		{
			z = 'z';
			return z;
		}
		else if (z == 'z' || z == 'Z')
		{
			z = 'i';
			return z;
		}
	}
	*/

