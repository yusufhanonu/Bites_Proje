#include <iostream>
#include <vector>
#include "Proje.h"
#include "AStar.h"
#include <thread>   
#include <chrono>   // saniye, milisaniye vb. için
using namespace std;


int main() {
    
    vector<vector<Proje> > vProje;

    cout<< endl <<"....Short Path Programa hoşgeldiniz..... "<<endl<<endl;
    cout << "Oluşturmak istediginiz Matris boyutunu giriniz: ";
    cin >> Boyut;

    matrisBaslangic(vProje);
    matrisYazdir(vProje);
    matrisEngelAtama(vProje);

    cout << endl << "A* algoritması başlatılıyor..." <<endl; 
    this_thread::sleep_for(chrono::seconds(1));
    astarPathFind(vProje);

    cout << "--Sonuc---";
    matrisYazdir(vProje);

    return 0;
}