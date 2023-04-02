#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "kategoria.h"
#include "CD.h"
#include "ksiazki.h"
#include "gry.h"
#include "staff.h"
#include "Klient.h"

using namespace std;

///////////////////////////////////////////DEKLARACJE FUNKCJI//////////////////////////

void haslo();
void nowehaslo();
void menuAdmin();
void menuUzytkownik();
void chooseKlienci();
void choosePracownicy();
void take(char wybor);
string &szyfruj(string &tekst);
void loguj();
void drawinfo();
void gotoxy(int x, int y) ;
void opcje();
void fillVector(vector <staff> &ludzie);
void printVector(const vector<staff> &ludzie);
vector<staff> ludzie;
void sortowanieRosnaco (Klient *K);
void sortowanieMalejaco (Klient *K);
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
bool sprawdz(string inUser, string inPass);


///////////////////////////////////////////MAIN//////////////////////////////////////////

int main()
{
    char choice;
    gotoxy(40,6);
    cout<<"WITAJ W WYPOZYCZALNI, ZALOGUJ JAKO: ";
    gotoxy(18,8);
    SetConsoleTextAttribute(hConsole,12);
    cout<<"[0]ADMIN\t\t\t[1]UZYTKOWNIK\t\t\t\t[2]WYJDZ\n";
    gotoxy(40,10);
    SetConsoleTextAttribute(hConsole,15);
    cout<<"WYBOR: ";
    cin>>choice;

        switch(choice)
        {
            case '0': haslo(); break;
            case '1': loguj(); break;
            case '2': Sleep(1000); exit(0); break;
        }

    return 0;
}

////////////////////////////////////////////MENU DLA ADMINA//////////////////////////////////////////////

void menuAdmin()
{
         char wybor;
         system("cls");
         SetConsoleTextAttribute(hConsole,10);
         cout<<"\t\t\t\t\t  _____________________________________\n";
         cout<<"\t\t\t\t\t |                                     |\n";
         cout<<"\t\t\t\t\t |             MENU GLOWNE             |\n";
         cout<<"\t\t\t\t\t |        WYPOZYCZALNIA MIEJSKA        |\n";
         cout<<"\t\t\t\t\t |               ADMIN                 |\n";
         cout<<"\t\t\t\t\t |_____________________________________|\n\n\n\n";

         SetConsoleTextAttribute(hConsole,15);
         cout<<"[1]KLIENCI\n";
         cout<<"[2]PRACOWNICY\n";
         cout<<"[3]ZMIEN HASLO\n";
         cout<<"[4]WYLOGUJ\n\n";
         cout<<"WYBOR: ";
         cin>>wybor;

         switch(wybor)
         {
         case '1': chooseKlienci(); break;
         case '2': choosePracownicy(); break;
         case '3': nowehaslo(); break;
         case '4': system("cls"); main(); break;
         default: menuAdmin();
         }
}

void chooseKlienci()
{
    char wybor;
    system("cls");
    cout<<"[1]WYSWIETL WSZYSTKICH KLIENTOW"<<endl;
    cout<<"[2]SORTUJ ROSNACO"<<endl;
    cout<<"[3]SORTUJ MALEJACO"<<endl;
    cin>>wybor;

                Klient *K = new Klient();
                K->tworzenieTablic();
                K->wczytaj();

                    if(wybor=='1') goto dalej;
                        else if(wybor=='2')
                            {
                                sortowanieRosnaco(K);
                            }
                        else if(wybor=='3')
                            {
                                sortowanieMalejaco(K);
                            }
                        else {
                            cout<<"NIEPRAWIDLOWY WYBOR! SPROBUJ JESZCZE RAZ";
                            Sleep(1000);
                            chooseKlienci();
                             }
                                dalej:
                                system("cls");
                                K->wypisz();
                                cout<<endl;
                                cout<<"\nAby kontunuowac, nacisnij dowolny klawisz..";
                                getch();
                                menuAdmin();
                                delete K;
}

void sortowanieRosnaco (Klient *K){
            for (int i=0;i<K->dlugosc-1 ;i++){
                  for (int j=i;j<K->dlugosc-1;j++){
                        if(stoi(K->lista[i][0])<stoi(K->lista[j][0])){
                              string bufor;
                              bufor=K->lista[i][1];
                              K->lista[i][1]=K->lista[j][1];
                              K->lista[j][1]=bufor;

                              bufor=K->lista[i][0];
                              K->lista[i][0]=K->lista[j][0];
                              K->lista[j][0]=bufor;
                              bufor=K->lista[i][2];
                              K->lista[i][2]=K->lista[j][2];
                              K->lista[j][2]=bufor;
                        }
                  }
            }
      }

void sortowanieMalejaco (Klient *K){
            for (int i=0;i<K->dlugosc-1 ;i++){
                  for (int j=i;j<K->dlugosc-1;j++){
                        if(stoi(K->lista[i][0])>stoi(K->lista[j][0])){
                              string bufor;
                              bufor=K->lista[i][1];
                              K->lista[i][1]=K->lista[j][1];
                              K->lista[j][1]=bufor;

                              bufor=K->lista[i][0];
                              K->lista[i][0]=K->lista[j][0];
                              K->lista[j][0]=bufor;
                              bufor=K->lista[i][2];
                              K->lista[i][2]=K->lista[j][2];
                              K->lista[j][2]=bufor;
                        }
                  }
            }
      }

void choosePracownicy()
{
    char n;

        system("cls");
        cout<<"[1]UZUPELNIJ INFORMACJE O PRACOWNIKACH\n";
        cout<<"[2]WYSWIETL INFORMACJE O PRACOWNIKACH\n";
        cout<<"WYBOR: ";
        cin>>n;

            if(n=='1')
            {
                fillVector(ludzie);
            }
            else if(n=='2')
            {
                printVector(ludzie);
            }
            else {
                cout<<"Nie ma takiego wyboru!"; Sleep(1000);
                choosePracownicy();
            }
                                cout<<"\nAby kontunuowac, nacisnij dowolny klawisz..";
                                getch();
                                menuAdmin();
}


////////////////////////////////////////////MENU DLA UZYTKOWNIKA//////////////////////////////////////////////

void menuUzytkownik()
{
    char wybor;
    system("cls");
    SetConsoleTextAttribute(hConsole,10);
     cout<<"\n\n\n";
     cout<<"\t\t\t\t\t  _____________________________________\n";
     cout<<"\t\t\t\t\t |                                     |\n";
     cout<<"\t\t\t\t\t |             MENU GLOWNE             |\n";
     cout<<"\t\t\t\t\t |        WYPOZYCZALNIA MIEJSKA        |\n";
     cout<<"\t\t\t\t\t |                USER                 |\n";
     cout<<"\t\t\t\t\t |_____________________________________|\n\n\n\n";

    SetConsoleTextAttribute(hConsole,15);
     cout<<"[1]INFORMACJE O WYPOZYCZALNI\n";
     cout<<"[2]WYPOZYCZ\n";
     cout<<"[3]POKAZ WSZYSTKIE WYPOZYCZENIA\n";
     cout<<"[4]ZNAJDZ SWOJE WYPOZYCZENIE\n";
     cout<<"[5]ZWROC\n";
     cout<<"[6]WYLOGUJ\n\n";

     cout<<"WYBOR: ";
     cin>>wybor;

    if(wybor=='1') drawinfo();
        else if(wybor>'1' && wybor<'6') take(wybor);
            else if(wybor=='6'){
                    gotoxy(44,2);
                    cout<<"DO NASTEPNEGO";
                    system("cls");
                    main();
            }
        else {
              cout<<"SPROBUJ JESZCZE RAZ";
              menuUzytkownik();
             }
}

//////////////////////////////////////////////////////////WYBOR UZYTKOWNIKA - POLIMORFIZM///////////////////////////////////

void take(char wybor)
{
    system("cls");
    char wybor2;
    cout<<"\n\n\t [1]KSIAZKI";
    cout<<"\n\n\t [2]PLYTY CD";
    cout<<"\n\n\t [3]GRY WIDEO";
    cout<<"\n\n\t [4]COFNIJ";
    cout<<"\n\n\t WYBOR: ";
    cin>>wybor2;

        kategoria *ptr;
        ksiazki A;
        CD B;
        gry C;
        system("cls");
        if(wybor=='2'){
            if(wybor2=='1')
            {
               ptr=&A;
               ptr->writeToFile();
            }
        else if(wybor2=='2')
            {
                ptr=&B;
                ptr->writeToFile();
            }
        else if(wybor2=='3')
            {
                ptr=&C;
                ptr->writeToFile();
            }
        else if(wybor2=='4') menuUzytkownik();

        else {
            cout<<"NIE MA TAKIEGO WYBORU, SPROBUJ JESZCZE RAZ";

        }
                    cout<<"\nAby kontunuowac, nacisnij dowolny klawisz..";
                    getch();
                    menuUzytkownik();

}

        else if(wybor=='3'){
            if(wybor2=='1')
            {
               ptr=&A;
               ptr->readFromFile();
            }
            else if(wybor2=='2')
            {
                ptr=&B;
                ptr->readFromFile();
            }
            else if(wybor2=='3')
            {
                ptr=&C;
                ptr->readFromFile();
            }
            else {
                cout<<"Nie ma takiego wyboru! Sprobuj jeszcze raz"<<endl;
            }
            cout<<"\nAby kontunuowac, nacisnij dowolny klawisz..";
                getch();
                menuUzytkownik();
        }
        else if(wybor=='4'){
            if(wybor2=='1')
            {
               ptr=&A;
               ptr->searchOnFile();
            }
            else if(wybor2=='2')
            {
                ptr=&B;
                ptr->searchOnFile();
            }
            else if(wybor2=='3')
            {
                ptr=&C;
                ptr->searchOnFile();
            }
            else {
                cout<<"Nie ma takiego wyboru! Sprobuj jeszcze raz";

            }
                    cout<<"\nAby kontunuowac, nacisnij dowolny klawisz..";
                    getch();
                    menuUzytkownik();
        }
        else if(wybor=='5'){
            if(wybor2=='1')
            {
               ptr=&A;
               ptr->deleteFromFile();
            }
            else if(wybor2=='2')
            {
                ptr=&B;
                ptr->deleteFromFile();
            }
            else if(wybor2=='3')
            {
                ptr=&C;
                ptr->deleteFromFile();
            }
            else {
                cout<<"Nie ma takiego wyboru! Sprobuj jeszcze raz";

            }
                cout<<"\nAby kontunuowac, nacisnij dowolny klawisz..";
                    getch();
                    menuUzytkownik();
            }

}

/////////////////////////////////////////////////////////PANEL Z LOGOWANIEM////////////////////////////////////////
/////////////////////////////////////////////////////////ADMIN////////////////////////////////////////////////////

void haslo()
{
    char p1[50],p2[50];
    ifstream wprowadz("haslo.txt");
    cin.sync();
    gotoxy(40,14);
        cout<<"WPROWADZ HASLO: ";
        cin.getline(p1,50);
        wprowadz.getline(p2,50);
        if(!strcmp(p2,p1))
            {
                cout<<endl;
                gotoxy(40,15);
                cout<<"WITAJ PANIE ADMIN :)";
                Sleep(1000);
                menuAdmin();
            }
        else
            {
                gotoxy(40,15);
                cout<<"NIEPOPRAWNE HASLO, SPROBUJ JESZCZE RAZ!";
                Sleep(1000);
                system("cls");
                main();
            }
    wprowadz.close();
}

void nowehaslo()
{
    string n;
    system("cls");
    ofstream nowe("haslo.txt");
        {
            cin.sync();
            cout<<"WPROWADZ NOWE HASLO: ";
            cin>>n;
            nowe<<n;
        }
            nowe.close();
            cout<<"TWOJE HASLO ZOSTALO ZAPISANE! "<<endl<<endl;
            cout<<"\nAby kontunuowac, nacisnij dowolny klawisz..";
            getch();
            menuAdmin();
}

string &szyfruj(string &tekst)
{
    for(char &a: tekst)
         a += 10;

    return tekst;
}

//////////////////////////////////////////////////////USER///////////////////////////////////////////////////

void loguj()
{
    fstream plik;
    char wybor;
    string login, haslo, Rlogin, Rhaslo;

        gotoxy(20,13);
        SetConsoleTextAttribute(hConsole,12);
        cout << "[1] ZALOGUJ\t\t\t\t\t\t\t\t[2] UTWORZ KONTO" << endl;
        gotoxy(40,15);
        SetConsoleTextAttribute(hConsole,15);
        cout<<"Wybor: ";
        cin >> wybor;

            switch( wybor )
            {
            case '1':

                plik.open("login.txt", ios::in);
                while(1){

                    gotoxy(0,17);
                    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;

                        do
                        {
                            gotoxy(40,18);
                            cout<<"WPROWADZ SWOJE DANE\nLOGIN: ";
                            cin >> login;
                            cout << "HASLO: ";
                            cin >> haslo;

                            if (sprawdz(login, szyfruj(haslo)) == true)
                            {
                                cout << "\nZALOGOWANO POMYSLNIE!" << endl;
                                cout << "WITAJ, " << login << endl;
                                cout << endl;
                                Sleep(2000);
                                menuUzytkownik();
                            }
                            else
                            {
                                cout << "NIEPRAWIDLOWE DANE, SPROBUJ JESZCZE RAZ" << endl;
                                Sleep(1500);
                                system("cls");
                                main();
                            }


                        } while (sprawdz(login, szyfruj(haslo)) != true);
                    }

                    case '2':
                        plik.open( "login.txt", ios::out | ios::app );
                        cin.ignore();
                        cout << "PODAJ LOGIN: ";
                        cin >> Rlogin;
                        cout<<"PODAJ HASLO: ";
                        cin>> Rhaslo;
                        plik << Rlogin << " " << szyfruj( Rhaslo ) << "\n";
                        plik.close();
                        cout<<"KONTO ZOSTALO UTWORZONE POMYSLNIE, MOZESZ SIE ZALOGOWAC";
                        Sleep(1500);
                        system("cls");
                        main();
                        break;
            }
        }

bool sprawdz(string login, string haslo)
	{
		string u;
		string p;

		bool status = false;

		ifstream f;
		f.open("login.txt", ios::out);

		if (!f.is_open())
		{
			cout << "Nie mozna otworzyc pliku!\n";
		}
		else
		{
			for (string u, p; !status && (f >> u >> p); )
			status = login == u && haslo == p;
		}

		f.close();
		return status;
	}


/////////////////////////////////////////////INFO O WYPOZYCZALNI///////////////////////////////

void drawinfo()
    {
        system("cls");
        cout<<"\n===============================\n";
        cout<<"\t\t Miejska wypozyczalnia\n";
        cout<<"\t\t\t ul. Pod Arkadami 13, 87-100 Torun\n\n";
        cout<<"\t\t\t Telefon Kontaktowy: ";
        SetConsoleTextAttribute(hConsole,12);
        cout<<"987-0123-990\n";
        SetConsoleTextAttribute(hConsole,15);
        cout<<"\n===============================\n";
        cout<<"\t\t Poniedzialek - Piatek\n";
        cout<<"\t\t\t 9:00 - 17:00\n\n";
        cout<<"\t\t Sobota\n";
        cout<<"\t\t\t 9:00 - 15:00\n";
        cout<<"\n===============================\n";
        cout<<"\t\t\t adres e-mail: "<<
        SetConsoleTextAttribute(hConsole,12);
        cout<<"wypozyczambolubie@gmail.com\n\n";
        SetConsoleTextAttribute(hConsole,15);
        cout<<"\t\t\t Facebook: ";
        SetConsoleTextAttribute(hConsole,12);
        cout<<"https://www.facebook.com/wypozyczambolubie";
        SetConsoleTextAttribute(hConsole,15);
        cout<<endl<<endl;
        cout<<"\n===============================\n";
        cout<<"\nAby kontunuowac, nacisnij dowolny klawisz..";
        getch();
        menuUzytkownik();
}


////////////////////////////////////////////////////FUNKCJA GOTOXY//////////////////////////////////////////////////////////

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

////////////////////////////////////////////////////TABLICA VECTOR Z PRACOWNIKAMI////////////////////////////////////////////

void fillVector(vector <staff> &ludzie)
    {
        system("cls");
        string imie, nazwisko, plec;
        int wiek,pensja;

        cout<<"Liczba pracownikow: ";
        int ilu;
        cin>>ilu;
        for(int i=0;i<ilu;i++)
        {
        cout<<"Podaj imie pracownika: ";
        cin>>imie;
        cout<<"Podaj nazwisko pracownika: ";
        cin>>nazwisko;
        cout<<"Podaj plec pracownika(M/K): ";
        cin>>plec;
        cout<<"Podaj wiek pracownika: ";
        cin>>wiek;
        cout<<"Podaj pensje miesieczna pracownika: ";
        cin>>pensja;

        staff Pracownik(imie, nazwisko, plec, wiek, pensja);
        ludzie.push_back(Pracownik);
        cout<<endl;

        }
        cout<<endl;
        cout<<"\nAby kontunuowac, nacisnij dowolny klawisz..";
        getch();
        menuAdmin();
    }

void printVector(const vector<staff> &ludzie)
    {
        system("cls");
        if(ludzie.empty())
        {
            cout<<"BRAK DANYCH O PRACOWNIKACH"<<endl;
        }
        else {
            for(int i=0; i<ludzie.size();i++)
        {
            cout<<i+1<< ". Imie pracownika: " << ludzie[i].getName()<<endl;
            cout<<i+1<< ". Nazwisko pracownika: " << ludzie[i].getSurname()<<endl;
            cout<<i+1<< ". Plec pracownika: " << ludzie[i].getSex()<<endl;
            cout<<i+1<< ". Wiek pracownika: " << ludzie[i].getAge()<<endl;
            cout<<i+1<< ". Pensja pracownika: " << ludzie[i].getSalary()<<endl;
            cout<<"---------------------------------------------"<<endl;
        }
        cout<<"\nAby kontunuowac, nacisnij dowolny klawisz..";
        getch();
        menuAdmin();
        }
    }
