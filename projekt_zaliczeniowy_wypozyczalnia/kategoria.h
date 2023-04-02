#ifndef kategoria_h
#define kategoria_h

#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

class kategoria
{
    public:
    virtual void create()=0;
    virtual void show()=0;
    virtual void writeToFile()=0;
    virtual void readFromFile()=0;
    virtual void searchOnFile()=0;
    virtual void deleteFromFile()=0;
};


#endif // kategoria_h
