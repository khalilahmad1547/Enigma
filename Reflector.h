#ifndef REFLECTOR_H_INCLUDED
#define REFLECTOR_H_INCLUDED

class Reflector
{
private:
    char *q;                        // Attributes
    int plug;

public:
    Reflector();                    // Behaviour
    Reflector(char *p, int plug);
    ~Reflector();
    char swap(char a);
};

#endif // REFLECTOR_H_INCLUDED
