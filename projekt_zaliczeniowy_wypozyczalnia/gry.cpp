#include "kategoria.h"
#include "gry.h"

gry::gry(){};

gry::~gry(){};

void gry::create()
{
    fstream plik;
    plik.open("ID.txt",ios::app);
    losuj();
    plik<<'\n'<<this->id;
    cout<<"Podaj imie i nazwisko: ";
    cin>>this->imie>>this->nazwisko;
    cout<<"Podaj tytul, ktory chcesz wypozyczyc: ";
    cin>>this->tytul;
    cout<<"Autor: ";
    cin>>this->autor;
    cout<<"Jezyk: ";
    cin>>this->jezyk;
    cout<<"Twoje ID to: "<<this->id<<endl;

    cout<<"Wypozyczono! "<<endl;

}

void gry::show()
{
    string dane;
    cout<<"Imie i nazwisko: "<<this->imie<<" "<<this->nazwisko<<endl;
    cout<<"Tytul: "<<this->tytul<<endl;
    cout<<"Autor: "<<this->autor<<endl;
    cout<<"Jezyk: "<<this->jezyk<<endl;
}

void gry::writeToFile()
{
    char ch;
    ofstream f1,f;
    f1.open("zapis_gry.txt", ios::in | ios::app);
    f.open("klienci.txt", ios::in|ios::app);

    do{
    if(f1.good()==true && f.good()==true)
    {
        create();
        f1<<this->id<<"\t"<<this->imie<<" "<<this->nazwisko<<"\t"<<this->tytul<<"\t"<<this->autor<<"\t"<<this->jezyk<<"\n";
        f<<this->id<<"\t"<<this->imie<<" "<<this->nazwisko<<"\n";
    }

    cout<<"Czy chcesz wypozyczyc cos jeszcze?(t/n)"<<endl;
    cin>>ch;
    } while(ch=='t' || ch=='T');

    cout<<"Twoje wypozyczenie zostalo pomyslnie utworzone!";
    f1.close();
    f.close();
}

void gry::readFromFile()
{
    fstream f2;
    string linia;
    int licznik=1;
    f2.open("zapis_gry.txt", ios::out|ios::in|ios::app);

    cout<<"\n================================\n";
    cout<<"\tWYPOZYCZONE GRY";
    cout<<"\n================================\n";
    if(f2.good()==1)
    {
        while(!f2.eof())
        {
            getline(f2,linia);
            cout<<licznik++<<". "<<linia<<endl;
        }
    }
    else{
        cout<<"Nie znaleziono pliku!";
    }
    f2.close();
}

void gry::searchOnFile()
{
    ifstream f3;
    int liczba;
    bool znal = true;
    string linia;
    cout<<"Podaj nr ID wypozyczenia: ";
    cin>>liczba;
    f3.open("zapis_gry.txt", ios::in | ios::app | ios::out);


    while(!f3.eof())
    {
        getline(f3,linia,'\t');
        if(f3.eof()==true) break;
        if(liczba == stoi(linia))
        {
            cout<<"Znaleziono wypozyczenie!"<<endl;
            getline(f3,this->imie,' ');
            getline(f3,this->nazwisko,'\t');
            getline(f3,this->tytul,'\t');
            getline(f3,this->autor,'\t');
            getline(f3,this->jezyk,'\n');
            show();
            cout<<"ID: "<<liczba<<endl;
            znal = false;
            break;
        }
        else{
            getline(f3,linia);
        }
    }
        if(znal) cout<<"Nie znaleziono wypozyczenia!";
         f3.close();
}

void gry::deleteFromFile()
{
    fstream f5;
    fstream f4;
    bool usun = false;
    int liczba;
    string linia;
    f4.open("zapis_gry.txt", ios::in|ios::out|ios::app);
    f5.open("bufor2.txt", ios::in|ios::out|ios::app);

    cout<<"Podaj nr ID wypozyczenia: ";
    cin>>liczba;

    if(f4.good())
    {
        while(!f4.eof())

    {
        getline(f4,linia,'\t');
        if(f4.eof()==true) break;
        else if(liczba == stoi(linia))
        {
            getline(f4,linia,'\n');
            usun = true;

            if(usun==true)
            {
                getline(f4,linia);
                f5<<linia<<'\n';
            }
        }
        else{
            f5<<linia;
            getline(f4,linia,'\n');
            f5<<'\t'<<linia<<'\n';
            }

        }
    }

        if(usun==true) cout<<"Pomyslnie zwrocono gre!";
        else cout<<"Nie znaleziono gry!";

    f5.close();
    f4.close();
    remove("zapis_gry.txt");
    rename("bufor2.txt", "zapis_gry.txt");


}
void gry::losuj()
{
    srand(time(NULL));
    id= rand () % 200 + 1;
    string linia;
    fstream plik;
    plik.open("ID.txt", ios::out|ios::in|ios::app);
    while(!plik.eof())
    {
        getline(plik,linia);
        if(this->id == stoi(linia)) losuj();
        else
        {

            break;
        }
    }
}
