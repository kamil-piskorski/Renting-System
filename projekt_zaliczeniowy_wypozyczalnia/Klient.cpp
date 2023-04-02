#include "Klient.h"

using namespace std;


Klient::Klient(){dlugosc=0;};

Klient::~Klient(){};

void Klient::tworzenieTablic(){

            fstream p;
            p.open("klienci.txt",ios::in|ios::out);
            string linia;

                while(!p.eof()){
                  getline(p,linia);
                  this->dlugosc++;
                  if(p.eof()==true) break;                    //funkcja tworzy tablice i w zaleznosci od jej przeznaczenia jest tablica string badz tez tablica int
            }

            p.close();
            this->lista=new string*[this->dlugosc];

            for (int i=0;i<this->dlugosc;i++){
                        this->lista[i]=new string[3];
            }

      }


void Klient::wczytaj(){
            fstream p;
            p.open("klienci.txt",ios::in);
            string linia;
            int i=0;
            if(p.good())
            {
                while(!p.eof()){
                  getline(p,linia,'\t');
                  this->lista[i][0]=linia;                       //wczytywanie wartosci z pliku ranking do tablicy string
                  getline(p,linia,' ');
                  this->lista[i][1]=linia;
                  getline(p,linia,'\n');
                  this->lista[i][2]=linia;
                  i++;
            }
            }

            p.close();
      }


void Klient::wypisz(){

                  cout<<"LISTA WSZYSTKICH KLIENTOW WYPOZYCZALNI"<<endl;
                  cout<<"-------------------------------"<<endl;
                  for(int i=0;i<this->dlugosc-1;i++){
                        cout<<i+1<<". "<<this->lista[i][0]<<"\t"<<this->lista[i][1]<<"\t"<<this->lista[i][2]<<endl;                 //wypisywanie zawartosci tablicy stringow
                  }
                  cout<<"-------------------------------"<<endl;
            }
