#include <iostream>
#include <vector>
#include <ctime>     // srand/time için
#include <cstdlib>   // rand için
#include "Proje.h"
#include "AStar.h"
using namespace std;
int Boyut = 0;

Proje::Proje( char _Yazi){
    Yazi = _Yazi;
}

void Proje::setYazi(char _Yazi){
    Yazi= _Yazi;
}
char Proje::getYazi()const {
    return Yazi;
}

void matrisYazdir(const vector<vector<Proje>> &vProje){
    cout << endl << "----Yeni Matris----" << endl;
    for(int x=0; x<Boyut; x++ ){
        for (int y=0; y<Boyut; y++){
            cout << vProje[x][y].getYazi()<< " ";
        }
        cout<<endl;
    }
    cout<< endl;
}


void matrisBaslangic(vector<vector<Proje>> &vProje){
    int k,p;
    do {
        cout << "Start noktasının 'Satırını' giriniz: ";
        cin>>k;
        cout << "Start noktasının 'Sütununu' giriniz: ";
        cin>>p;

        if((k > (Boyut-1) or p > (Boyut-1)) or (k == (Boyut-1) and p == (Boyut-1))){
        cout<< "Bu degerler boyutu aşıyor veya Goal noktasına denk geliyor. "<<endl;
        }
    }while((k > (Boyut-1) or p > (Boyut-1)) or (k == (Boyut-1) and p == (Boyut-1)));

    cout <<Boyut << "x" << Boyut << " Başlangıç matrisiniz yazdırılıyor.."<< endl;

    vProje.clear();
    vProje.resize(Boyut, vector<Proje>(Boyut, Proje ('0'))); 

    vProje[k][p].setYazi('S');
    vProje[Boyut-1][Boyut-1].setYazi('G');
}



void matrisEngelAtama(vector<vector<Proje>> &vProje){
    int engel;
    srand(time(0));
    int x,j;
    
    do{
    cout << "Matrise atamak istediğiniz engel sayısınız seçiniz: ";
    cin >> engel;
    if(engel>((Boyut*Boyut)-2) or engel == 0){
        cout << "Program calıstırılamıyor, 1 ile " <<((Boyut*Boyut)-2) <<" arasında bir deger giriniz "<<endl
        <<endl;
    }
    }while(engel > ((Boyut*Boyut)-2) or engel == 0);
    
    cout<< "Matrise " << engel << " Tane  Engel (X) Atanıyor"<<endl;
        
        for(int i=0; i<engel; i++){
            do{ 
                x=rand() % Boyut;
                j=rand() % Boyut;
            }while((vProje[x][j].getYazi()=='S') or (vProje[x][j].getYazi()=='G') or (vProje[x][j].getYazi()=='X') );     
                vProje[x][j].setYazi('X');     
    }
    matrisYazdir(vProje);
}

  

