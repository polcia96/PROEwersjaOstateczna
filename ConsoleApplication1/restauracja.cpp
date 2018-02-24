#include<stdexcept>
#include<algorithm>
#include"restauracja.h"
#include<ostream>
#include<limits>
#include<fstream>

using namespace std;
Restauracja::Restauracja(){

    nazwa="NOWA RESTAURACJA";
    godzinyOtwarcia[0]=GODZINA_OTWARCIA;
    godzinyOtwarcia[1]=GODZINA_ZAMKNIECIA;
    liczbaZam=zamowienia.size();
    vector<Zamowienie*> zamowienia;
    #ifdef _DEBUG
    std::cout<<"wywolal sie konstruktor bezparametrowy obiektu Restauracja"<<std::endl;
    #endif
}


Restauracja::Restauracja(std::string nNazwa,int nGodzOtwarcia[GODZINY_OTWARCIA],std::vector<Zamowienie*>nZamowienia){

    nazwa=nNazwa;
    godzinyOtwarcia[0]=nGodzOtwarcia[0];
    godzinyOtwarcia[1]=nGodzOtwarcia[1];
    zamowienia=nZamowienia;
    liczbaZam=zamowienia.size();

    #ifdef _DEBUG
    std::cout<<"wywolal sie konstruktor inicjalizujacy obiektu Restauracja"<<std::endl;
    #endif
}

Restauracja::Restauracja(Restauracja&wzorRestauracji){

    nazwa=wzorRestauracji.nazwa;
    godzinyOtwarcia[0]=wzorRestauracji.godzinyOtwarcia[0];
    godzinyOtwarcia[1]=wzorRestauracji.godzinyOtwarcia[1];
    zamowienia=wzorRestauracji.zamowienia;
    liczbaZam=zamowienia.size();

    #ifdef _DEBUG
    std::cout<<"wywolal sie konstruktor kopiujacy obiektu Restauracja"<<std::endl;
    #endif
}


std::string Restauracja::podajNazwe(){
    return nazwa;
}

unsigned int Restauracja::podajLiczbaZamowien(){
    return liczbaZam;
}

int* Restauracja::podajGodzOtwarcia(){
    return godzinyOtwarcia;
}

Zamowienie& Restauracja::wybierzZamowienie(unsigned int indeksZam){
    if(indeksZam <zamowienia.size())
        return *zamowienia[indeksZam];
    else
        throw std::out_of_range("stol o podanym indeksie nie istnieje");
}
void Restauracja::zmienNazwe(const std::string& nNazwa){
        nazwa=nNazwa;
}

void Restauracja::zmienGodzOtwarcia(int*nGodzOtwarcia){
        godzinyOtwarcia[0]=nGodzOtwarcia[0];
        godzinyOtwarcia[1]=nGodzOtwarcia[1];
}
void Restauracja::usunZamowienie(int indeksZam){

    if(indeksZam<zamowienia.size()){
         zamowienia.erase(zamowienia.begin()+indeksZam);   //indeks zam liczyby od 0 ??

    }
    else throw std::out_of_range("stol o podanym indeksie nie istnieje");

}
bool Restauracja::zapisz(std::string nazwaPliku){

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

bool Restauracja::wczytaj(std::string nazwaPliku){

    std::ifstream osrodek;
    osrodek.open(nazwaPliku);

    if(osrodek.good()){
        importuj(osrodek);
        osrodek.close();
        return true;
    }
    else
        return false;
}
void Restauracja::wpisz(){

    string toLiczba;

    cout<<"RESTAURACJA"<<endl;
    cout<<"nazwa :";
    cin>>nazwa;

    cout<<endl;
    cout<<"godzina otwarcia: ";
    cin>>toLiczba;
    godzinyOtwarcia[0]=toInt(toLiczba);
    while(godzinyOtwarcia[0]>24){
        cout<<"bledny czas,podaj czas ponownie: ";
        cin>>toLiczba;
        godzinyOtwarcia[0]=toInt(toLiczba);
    }

    cout<<endl;
    cout<<"godzina zamkniecia: ";
    cin>>toLiczba;
    godzinyOtwarcia[1]=toInt(toLiczba);
    while(godzinyOtwarcia[1]>24){
        cout<<"bledny czas,podaj czas ponownie: ";
        cin>>toLiczba;
        godzinyOtwarcia[1]=toInt(toLiczba);
    }

}

void Restauracja::menu(){
    cout<<"RESTAURACJA:wybierz co chcesz zrobic"<<endl;
    wyswietlMenuPom();

}
//OPERATORY

Restauracja& Restauracja::operator+=(Zamowienie* nZam){
    zamowienia.push_back(nZam);

    return *this;
}

Restauracja::operator int()const{
        return zamowienia.size();
}


Zamowienie& Restauracja::operator[](unsigned int indeksZam){
    if(indeksZam<zamowienia.size())
        return *zamowienia[indeksZam];
    else
        throw std::out_of_range("nie ma stolu o podanym indeksie");
}
Restauracja Restauracja::operator+(const Restauracja& dodanaRestauracja)const{

    Restauracja sumaRestauracji;
    sumaRestauracji.godzinyOtwarcia[0]=std::min(godzinyOtwarcia[0],dodanaRestauracja.godzinyOtwarcia[0]);
    sumaRestauracji.godzinyOtwarcia[1]=std::max(godzinyOtwarcia[1],dodanaRestauracja.godzinyOtwarcia[1]);

    sumaRestauracji.zamowienia=zamowienia;
    for (int i=0; i<dodanaRestauracja.zamowienia.size();++i)
        sumaRestauracji.zamowienia.push_back(dodanaRestauracja.zamowienia[i]);

    return sumaRestauracji;
}

std::iostream& operator>>(std::iostream& wejscie,Restauracja& restauracja){

    restauracja.importuj(wejscie);
    return wejscie;
}

void Restauracja::importuj(std::istream& wejscie){

    wejscie.ignore(numeric_limits<streamsize>::max(),'-');
    wejscie>>nazwa;

    wejscie.ignore(numeric_limits<streamsize>::max(),':');
    wejscie>>godzinyOtwarcia[0];

    wejscie.ignore(numeric_limits<streamsize>::max(),':');
    wejscie>>godzinyOtwarcia[1];

    wejscie.ignore(numeric_limits<streamsize>::max(),':');
    wejscie>>liczbaZam;

}

std::ostream& operator<<(std::ostream& wyjscie,Restauracja& restauracja){

    wyjscie<<"RESTAURACJA"<<std::endl;
    wyjscie<<"nazwa:- "<<restauracja.nazwa<<std::endl;
    wyjscie<<"godzina otwarcia:"<<restauracja.godzinyOtwarcia[0]<<std::endl;
    wyjscie<<"godzina zamkniecie: "<<restauracja.godzinyOtwarcia[1]<<std::endl;
    wyjscie<<"aktualna liczba zamowien: "<<restauracja.liczbaZam<<std::endl<<std::endl;

    for(int i=0; i<restauracja.zamowienia.size();++i)
       restauracja.zamowienia[i]->wyswietl(wyjscie);
    wyjscie<<"****************KONIEC "<<restauracja.nazwa<<" *********************+"<<std::endl;

        return wyjscie;
}

