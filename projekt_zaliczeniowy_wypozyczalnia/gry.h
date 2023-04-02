#ifndef gry_h
#define gry_h
#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include<string>
#include<vector>
#include <windows.h>

using namespace std;

class gry:public kategoria
{
    string imie,nazwisko, tytul, jezyk, autor;
    int id;
    int bufor;
public:
    gry();
    ~gry();
    void create();
    void show();
    void writeToFile();
    void readFromFile();
    void searchOnFile();
    void deleteFromFile();
    void losuj();

};

#endif
