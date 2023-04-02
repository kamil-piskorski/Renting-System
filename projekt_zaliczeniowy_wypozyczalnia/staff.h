#ifndef staff_h
#define staff_h

#include <iostream>
#include <conio.h>
#include <fstream>
#include<vector>

using namespace std;

class staff
{
    string imie,nazwisko, plec;
    int wiek, pensja;
    vector<staff> ludzie;
public:
    staff(string, string, string, int, int);

    staff();

    string getName() const;
    string getSurname() const;
    string getSex() const;
    int getAge() const;
    int getSalary() const;
    void setName(string);
    void setSurname(string);
    void setSex(string);
    void setAge(int);
    void setSalary(int);
    void fillVector(vector <staff>);
    void printVector(const vector<staff>);
};

#endif // staff_h
