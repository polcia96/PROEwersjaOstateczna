#include"adres.h"
#include<string>
using namespace std;

Adres::Adres(){
    nazwaUlicy="PUSTA";
    numerDomu=0;
    odleglosc=0;
}


Adres::Adres(std::string nowaNazwaUl,unsigned int nowyNrDomu, unsigned int nowaOdleglosc){

    nazwaUlicy=nowaNazwaUl;
    numerDomu=nowyNrDomu;
    odleglosc=nowaOdleglosc;
}
std::string Adres::podajNazweUl(){
    return nazwaUlicy;
}
int Adres::podajNumerDomu(){
    return numerDomu;
}
unsigned int Adres::podajOdleglosc(){
    return odleglosc;
}
bool Adres::zapisz(std::string nazwaPliku){
    std::ofstream osrodek;
    osrodek.open(nazwaPliku,std::ios_base::app);

    if(osrodek.good()){
        osrodek<<*this;
        osrodek.close();
       return true;
    }
    else
        return false;

}

bool Adres::wczytaj(std::string nazwaPliku){
    std::ifstream osrodek;
    osrodek.open(nazwaPliku);

    if(osrodek.good()){
        osrodek>>*this;
        osrodek.close();
       return true;
    }
    else
        return false;
}



void Adres::wpisz(){

    string nazwa;

    cout<<"ADRES-poczatek"<<std::endl;
    cout<<"ulica: ";
    cin>>nazwaUlicy;

    cout<<std::endl;
    cout<<"numer: ";
    cin>>nazwa;
    numerDomu=toInt(nazwa);

    cout<<std::endl;
    cout<<"odleglosc od restauracji: ";
    cin>>nazwa;
    odleglosc=toInt(nazwa);


    cout<<"ADRES-koniec"<<std::endl;


}

void Adres::menu(){

    cout<<"ADRES:wybierz co chcesz zrobic"<<endl;
    wyswietlMenuPom();

}

std::istream& operator>>(std::istream& wejscie, Adres& adres){


    wejscie.ignore(numeric_limits<streamsize>::max(),';');
    wejscie>>adres.nazwaUlicy;

    wejscie.ignore(numeric_limits<streamsize>::max(),':');
    wejscie>>adres.numerDomu;

    wejscie.ignore(numeric_limits<streamsize>::max(),':');
    wejscie>>adres.odleglosc;

    return wejscie;
}


std::ostream& operator<<(std::ostream& wyjscie, Adres& adres){

    wyjscie<<"ADRES-poczatek"<<std::endl;
    wyjscie<<"ulica; "<<adres.nazwaUlicy<<std::endl;
    wyjscie<<"numer: "<<adres.numerDomu<<std::endl;
    wyjscie<<"odleglosc od restauracji: "<<adres.odleglosc<<"km"<<std::endl;
    wyjscie<<"ADRES-koniec"<<std::endl;
    return wyjscie;

 }
//////OBSLUGA PLIKOW
