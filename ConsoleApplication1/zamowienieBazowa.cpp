#include<algorithm>
#include<stdexcept>

#include"zamowienieBazowa.h"

unsigned int Zamowienie::liczbaZamowien=0;

Zamowienie::Zamowienie(){
    numer=0;
    cena=0;
    czasOczekiwania=0;
}


Zamowienie::Zamowienie(int nowyNumer){
    numer=nowyNumer;

    ++liczbaZamowien;
}


int Zamowienie::podajNumer(){
    return numer;
}

void Zamowienie::zmienNumer(int nNumer){
    numer=nNumer;
}

double Zamowienie::podajCene(){
    return cena;
}


Zamowienie::~Zamowienie(){}


Zamowienie& Zamowienie:: operator %(double rabatProcent){

    if(rabatProcent>0 && rabatProcent<=100){
        double wartoscRabatu=(rabatProcent/100)*cena;
        cena=cena-wartoscRabatu;
    }
    else
        throw std::out_of_range("wartosc rabatu spoza zakresu");
    return *this;
}
