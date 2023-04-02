#include "staff.h"

staff::staff(string imie, string nazwisko, string plec, int wiek, int pensja)
{
    this->imie = imie;
    this->nazwisko=nazwisko;
    this->plec=plec;
    this->wiek=wiek;
    this->pensja=pensja;
}

staff::staff(){};

string staff::getName() const
{
    return imie;
}
    string staff::getSurname() const
    {
        return nazwisko;
    }
    string staff::getSex() const
    {
        return plec;
    }
    int staff::getAge() const
    {
        return wiek;
    }
    int staff::getSalary() const
    {
        return pensja;
    }
    void staff::setName(string imie)
    {
        this->imie=imie;
    }
    void staff::setSurname(string nazwisko)
    {
        this->nazwisko=nazwisko;
    }
    void staff::setSex(string plec)
    {
        this->plec=plec;
    }
    void staff::setAge(int wiek)
    {
        this->wiek=wiek;
    }
    void staff::setSalary(int pensja)
    {
        this->pensja=pensja;
    }
