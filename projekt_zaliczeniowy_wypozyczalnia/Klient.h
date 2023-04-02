#ifndef Klient_h
#define Klient_h
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>

using namespace std;

class Klient{
      string **lista;
      int dlugosc;

public:
      Klient();
      ~Klient();
      friend void sortowanieRosnaco(Klient *K);
      friend void sortowanieMalejaco(Klient *K);
      char z;

      void tworzenieTablic();
      void wczytaj();
      void wczytaj_int();
      void wypisz();
      void suma();

};
#endif
