#pragma once
#include <iostream>
#include <vector>
using namespace std;

extern int Boyut;

class Proje{
private:
    int Deger;
    int Engel;
    char Yazi;

public:
    Proje(int _Engel, int _Deger, char _Yazi);
    void setEngel(int _Engel);
    int getEngel();

    void setDeger(int _Deger);
    int getDeger() const;

    void setYazi(char _Yazi);
    char getYazi() const;
};

void matrisBaslangic(vector<vector<Proje>> &vProje);
void matrisYazdir(const vector<vector<Proje>>  &vProje);
void matrisEngelAtama(vector<vector<Proje>> &vProje);
