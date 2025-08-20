#pragma once
#include <iostream>
#include <vector>
using namespace std;

extern int Boyut;

class Proje{
private:

    char Yazi;

public:
    Proje( char _Yazi);
    
    void setYazi(char _Yazi);
    char getYazi() const;
};

void matrisBaslangic(vector<vector<Proje> > &vProje);
void matrisYazdir(const vector<vector<Proje> >  &vProje);
void matrisEngelAtama(vector<vector<Proje> > &vProje);
