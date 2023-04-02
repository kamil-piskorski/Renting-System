#ifndef ksiazki_h
#define ksiazki_h
#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include<string>
#include<vector>
#include <windows.h>

using namespace std;

class ksiazki:public kategoria
{
    string imie,nazwisko, tytul, jezyk, autor;
    int id;
    int bufor;
public:
    ksiazki();
    ksiazki(int, string, char, char, char, char);
    ~ksiazki();
    void create();
    void show();
    void writeToFile();
    void readFromFile();
    void searchOnFile();
    void deleteFromFile();
    void losuj();

};

#endif
