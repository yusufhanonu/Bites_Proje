#include <iostream>
#include <vector>
#include <ctime>     // srand/time için
#include <cstdlib>   // rand için
#include "Proje.h"
#include "AStar.h"
using namespace std;
int Boyut = 0;

Proje::Proje(int _Engel, int _Deger, char _Yazi){
    Engel = _Engel;
    Deger = _Deger;
    Yazi = _Yazi;
}

void Proje::setEngel(int _Engel){
    Engel= _Engel;
}

int Proje::getEngel(){
    return Engel;
}
void Proje::setDeger(int _Deger){
    Deger= _Deger;
}

int Proje::getDeger()const {
    return Deger;
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
        cout << "Start Noktasını Sırasıyla 'Satır''Sütun' olarak giriniz: ";
        cin>>k>>p;
        if((k > (Boyut-1) or p > (Boyut-1)) or (k == (Boyut-1) and p == (Boyut-1))){
        cout<< "Bu degerler boyutu aşıyor veya Goal noktasına denk geliyor. "<<endl;
        }
    }while((k > (Boyut-1) or p > (Boyut-1)) or (k == (Boyut-1) and p == (Boyut-1)));

    cout <<Boyut << "x" << Boyut << " Başlangıç matrisi yazdırılıyor.."<< endl;

    vProje.clear();
    vProje.resize(Boyut, vector<Proje>(Boyut, Proje (0,0,'0'))); //Sor

    vProje[k][p].setYazi('S');
    vProje[Boyut-1][Boyut-1].setYazi('G');
}



void matrisEngelAtama(vector<vector<Proje>> &vProje){
    int engel;
    srand(time(0));
    int rastgeleSayi,rastgeleSayi1;
    
    do{
    cout << "Matrise atamak istediğiniz engel sayısınız seçiniz: ";
    cin >> engel;
    if(engel>13 or engel == 0){
        cout << "Program calıstırılamıyor, lütfen 1-13 arası bir deger giriniz "<<endl
        <<endl;
    }
    }while(engel > 13 or engel == 0);
    
    cout<< "Matrise " << engel << " Tane  Engel (X) Atanıyor..."<<endl;
        
        for(int i=0; i<engel; i++){
            do{ 
                rastgeleSayi1=rand() % Boyut;
                rastgeleSayi=rand() % Boyut;
            }while((rastgeleSayi1 == 0 && rastgeleSayi == 0) || 
            (rastgeleSayi1 == (Boyut-1) && rastgeleSayi == (Boyut-1)));     
                vProje[rastgeleSayi1][rastgeleSayi].setYazi('X');     
    }
    matrisYazdir(vProje);
}

  

