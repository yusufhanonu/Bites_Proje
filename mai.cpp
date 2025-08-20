#include <iostream>

using namespace std;

int main() {
    srand(time(0));
    int rastgeleSayi,rastgeleSayi1,ust=3,alt=0;
    rastgeleSayi1=rand() % 4;
    rastgeleSayi=rand() % 4;
    for (int i=0; i<3;i++){
        cout<< "Sayiniz " << rastgeleSayi1 << rastgeleSayi;
    }
    return 0;
}