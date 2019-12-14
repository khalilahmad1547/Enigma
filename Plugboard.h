#ifndef PLUGBOARD_H_INCLUDED
#define PLUGBOARD_H_INCLUDED

class Plugboard
{
private:
    char *q;                    // attributes
    int plug;

public:
    Plugboard();                   // Functions
    Plugboard(char *p, int plug);
    ~Plugboard();
    char swap(const char a);

};

#endif // PLUGBOARD_H_INCLUDED
