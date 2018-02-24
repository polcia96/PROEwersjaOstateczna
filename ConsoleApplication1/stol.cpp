#include"stol.h"
#include<ostream>
#include<limits>

using namespace std;

static const unsigned int DOMYSLA_LICZBA_MIEJSC=4;
enum STAN_STOLU {WOLNY=2, ZAJETY=1};
enum MIEJSCE_STOLU {PALARNIA=2,DLA_NIEPALACYCH=1};

unsigned int Stol::liczbaWszystkichStolow=0;
Stol::Stol()
{
    lokalizacja=DLA_NIEPALACYCH;
    stan=WOLNY;
    liczbaMiejsc=DOMYSLA_LICZBA_MIEJSC;
    liczbaProduktow=liczProdukty();

    ++liczbaWszystkichStolow;

    #ifdef _DEBUG
    std::cout<<"wywolal sie konstruktor bezparametrowy obiektu Stol"<<std::endl;
    #endif
}

Stol::Stol(int nLokalizacja,int nStan,int nLiczbaMiejsc,std::vector<Produkt>&noweProdukty){

    lokalizacja=nLokalizacja;
    stan=nStan;
    liczbaMiejsc=nLiczbaMiejsc;
    produkty=noweProdukty;
    liczbaProduktow=liczProdukty();


    ++liczbaWszystkichStolow;

    #ifdef _DEBUG
    std::cout<<"wywolal sie konstruktor inicjalizujacy obiektu Stol"<<std::endl;
    #endif
}


std::string Stol::podajLokalizacje(){

    if(lokalizacja==1)
        return "SALA DLA NIEPALACYCH";
    else
        return "PALARNIA";
}
std::string Stol::podajStan(){

    if(stan==1)
        return "ZAJETY";
    else
        return "WOLNY";
}

int Stol::podajLiczbeMiejsc(){
    return liczbaMiejsc;
}
unsigned int Stol::podajLiczbeStolow(){
    return liczbaWszystkichStolow;
}

std::vector <Produkt>& Stol::podajProdukty(){
    return produkty;
}

Produkt Stol::podajProdukt(unsigned int numerProduktu){
    return produkty[numerProduktu];

}
void Stol::usunProdukty(){
    produkty.clear();
}


void Stol::zmienLokalizacje(){

if(lokalizacja)
    lokalizacja=PALARNIA;
else
    lokalizacja=DLA_NIEPALACYCH;
}

void Stol::zmienStan(){
    if(stan)
        stan=WOLNY;
    else
        stan=ZAJETY;
}

void Stol::zmienLiczbeMiejsc(int nowaLiczbaMiejsc){
    liczbaMiejsc=nowaLiczbaMiejsc;
}
size_t Stol::liczProdukty(){
    return produkty.size();
}

int wczytajStan(std::string& nazwa){
    if(nazwa=="WOLNY")
        return 2;
    else if(nazwa=="ZAJETY")
        return 1;
}

int wczytajLok(std::string& nazwa){
    if(nazwa=="PALARNIA")
        return 2;
    else if(nazwa=="SALA DLA NIEPALACYCH")
        return 1;
}

bool Stol::zapisz(std::string nazwaPliku){

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
bool Stol::wczytaj(std::string nazwaPliku){

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
void Stol::wpisz(){
    int wartosc=0;
    string toLiczba;

    cout<<"STOL-POCZATEK"<<std::endl;
    cout<<"stan stolu: \n 1-zajety \n 2-wolny"<<endl;
    while((wartosc!=2)&&(wartosc!=1)){
        cout<<"podaj odpowiedina cyfre: "<<endl;
        cin>>toLiczba;
        wartosc=toInt(toLiczba);
    }
    wartosc=0;

    cout<<endl;
    cout<<"lokalizacja: \n 1-sala dla niepalacych \n 2-palarnia"<<endl;
    while((wartosc!=2)&&(wartosc!=1)){
        cout<<"podaj odpowiedina cyfre: "<<endl;
        cin>>toLiczba;
        wartosc=toInt(toLiczba);
    }

    cout<<endl;
    cout<<"liczba miejsc: ";
    cin>>toLiczba;
    liczbaMiejsc=toInt(toLiczba);

    cout<<endl;
    wartosc=0;
    wartosc=menuProdukt();
    if(wartosc==2){
        cout<<endl;
        cout<<"liczba produktow: ";
        cin>>toLiczba;
        liczbaProduktow=toInt(toLiczba);

        for(size_t i=0; i<liczbaProduktow; ++i){
            Produkt pom;
            pom.wpisz();
            produkty.push_back(pom);
        }
    }

}
void Stol::menu(){

    cout<<"STOL:wybierz co chcesz zrobic"<<endl;
    wyswietlMenuPom();

}
//OPERATORY

bool Stol::operator !(){
    lokalizacja=DLA_NIEPALACYCH;
    stan=WOLNY;
    return true;
}

 std::ostream& operator <<(std::ostream& wyjscie,Stol& stol){

    wyjscie<<"STOL-POCZATEK"<<std::endl;
    wyjscie<<"liczba wszystkich stolow| "<<stol.liczbaWszystkichStolow<<std::endl;
    wyjscie<<"stan stolu:"<<stol.podajStan()<<std::endl;
    wyjscie<<"lokalizacja:"<<stol.podajLokalizacje()<<std::endl;
    wyjscie<<"liczba miejsc:"<<stol.liczbaMiejsc<<std::endl;
    wyjscie<<"liczba produktow:"<<stol.liczbaProduktow<<std::endl;

    if(!stol.produkty.size())
        wyjscie<<"brak produktow na stole"<<std::endl;
    else{

        for(int i=0; i < stol.produkty.size(); ++i)
            wyjscie<<stol.podajProdukt(i);
    }
    return wyjscie;

}

std::istream& operator>>(std::istream& wejscie,Stol& stol){

    std::string nazwa;

    wejscie.ignore(numeric_limits<streamsize>::max(),'|');
    wejscie>>stol.liczbaWszystkichStolow;

    wejscie.ignore(numeric_limits<streamsize>::max(),':');
    wejscie>>nazwa;
    stol.stan=wczytajStan(nazwa);

    wejscie.ignore(numeric_limits<streamsize>::max(),':');
    wejscie>>nazwa;
    stol.lokalizacja=wczytajLok(nazwa);

    wejscie.ignore(numeric_limits<streamsize>::max(),':');
    wejscie>>stol.liczbaMiejsc;

    wejscie.ignore(numeric_limits<streamsize>::max(),':');
    wejscie>>stol.liczbaProduktow;

    for(size_t i=0; i<stol.liczbaProduktow; ++i){
        Produkt pom;
        wejscie>>pom;
        stol.produkty.push_back(pom);
    }

    return wejscie;
}
