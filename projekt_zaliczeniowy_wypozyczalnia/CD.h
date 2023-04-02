#ifndef CD_h
#define CD_h

#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include<string>
#include<vector>
#include <windows.h>

using namespace std;

class CD:public kategoria
{
    string imie,nazwisko, tytul, jezyk, autor;
    int id;
    int bufor;
public:
    CD();
    CD(int, string, char, char, char, char);
    ~CD();
    void create();
    void show();
    void writeToFile();
    void readFromFile();
    void searchOnFile();
    void deleteFromFile();
    void losuj();

};

#endif
