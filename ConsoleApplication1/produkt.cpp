#include"Produkt.h"


using namespace std;


//KONSTRUKTORY
Produkt::Produkt(){

    cena=DOMYSLNA_CENA;
    czasOczekiwania=DOMYSLNY_CZAS_OCZEKIWANIA;
    nazwa=DOMYSLNA_NAZWA;

    #ifdef _DEBUG
    std::cout<<"wywolal sie konstruktor bezparametrowy obiektu Produkt"<<std::endl;
    #endif
}

Produkt::Produkt(double nCena,int nCzasOczekiwania,std::string nNazwa){

    czasOczekiwania=nCzasOczekiwania;
    cena=nCena;
    nazwa=nNazwa;

    #ifdef _DEBUG
    std::cout<<"wywolal sie konstruktor inicjalizujacy obiektu Produkt"<<std::endl;
    #endif
}

Produkt::Produkt(const Produkt& wzorzecProduktu){

    czasOczekiwania=wzorzecProduktu.czasOczekiwania;
    cena=wzorzecProduktu.cena;
    nazwa=wzorzecProduktu.nazwa;

    #ifdef _DEBUG
    std::cout<<"wywolal sie konstruktor kopiujacy obiektu Produkt"<<std::endl;
    #endif
}
//FUNKCJE

double Produkt::podajCene(){
    return cena;
}

int Produkt::podajCzasOczekiwania(){
    return czasOczekiwania;
}

std::string Produkt::podajNazwe(){
    return nazwa;
}


void Produkt::zmienCene(double nowaCena){
    cena=nowaCena;
}

void Produkt::zmienCzasOczekiwania(int nowyCzasOczekiwania){
    czasOczekiwania=nowyCzasOczekiwania;
}

void Produkt::zmienNazwe(std::string& nowaNazwa){
    nazwa=nowaNazwa;
}
bool Produkt::zapisz(std::string nazwaPliku){

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

bool Produkt::wczytaj(std::string nazwaPliku){
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

void Produkt::wpisz()
{
    string liczba;

    cout<<"PRODUKT-poczatek"<<endl;
    cout<<"nazwa: ";
    cin>>nazwa;

    cout<<endl;
    cout<<"cena: ";
    cin>>liczba;
    cena=toDouble(liczba);

    cout<<endl;
    cout<<"czas oczekiwania: ";
    cin>>liczba;
    czasOczekiwania=toInt(liczba);

    cout<<endl;
    cout<<"PRODUKT-koniec"<<endl;

}
void Produkt::menu(){

    cout<<"PRODUKT:wybierz co chcesz zrobic"<<endl;
    wyswietlMenuPom();
}

//OPERATORY
Produkt& Produkt::operator < (Produkt& porownywanyProdukt){
    if(cena<porownywanyProdukt.cena)
        return *this;
    else
        return porownywanyProdukt;

}
std::istream& operator >>(std::istream& wejscie,Produkt& produkt){

    wejscie.ignore(numeric_limits<streamsize>::max(),'<');
    wejscie>>produkt.nazwa;

    wejscie.ignore(numeric_limits<streamsize>::max(),':');
    wejscie>>produkt.cena;

    wejscie.ignore(numeric_limits<streamsize>::max(),':');
    wejscie>>produkt.czasOczekiwania;

    wejscie.ignore(numeric_limits<streamsize>::max(),'>');


    return wejscie;
}
std::ostream& operator <<(std::ostream& wyjscie,const Produkt& produkt){
    wyjscie<<std::endl;
    wyjscie<<"PRODUKT-poczatek"<<std::endl;
    wyjscie<<"nazwa< "<<produkt.nazwa<<std::endl;
    wyjscie<<"cena: "<<produkt.cena<<" zl"<<std::endl;
    wyjscie<<"czas oczekiwania: "<<produkt.czasOczekiwania<<" min"<<std::endl;
    wyjscie<<"PRODUKT-koniec"<<std::endl;
    return wyjscie;
}

