#include"opakowanie.h"
#include<ostream>
#include<stdexcept>
#include<limits>
using namespace std;

Opakowanie::Opakowanie(){

    nazwa=DOMYSLNA_NAZWA;
    pojemnosc=DOMYSLNA_POJEMNOSC;
    rodzajProduktu=STALY;
    liczbaProduktow=0;
    vector <Produkt>produkty;

}

Opakowanie::Opakowanie(std::string nowaNazwa,int rodzaj ,int maxProduktow, std::vector<Produkt>noweProdukty){

    nazwa=nowaNazwa;
    rodzajProduktu=rodzaj;
    pojemnosc=maxProduktow;

    if(noweProdukty.size()){
        if(noweProdukty.size()<=pojemnosc)
        {
            produkty=noweProdukty;
            liczbaProduktow=liczProdukty();
        }

    else
        throw std::length_error("podana ilosc produktow przekracza pojemnosc opakowania");
    }
    else
        liczbaProduktow=0;

}

std::string Opakowanie::podajNazwe(){
    return nazwa;
}

std::string Opakowanie::podajRodzaj(){
    if(rodzajProduktu==1)
        return "PLYNNY";
    else
        return "STALY";
}

int Opakowanie::podajPojemnosc(){
    return pojemnosc;
}

std::vector <Produkt> Opakowanie::podajProdukty(){
    return produkty;
}

Produkt Opakowanie::podajProdukt(unsigned int numerProduktu){
    return produkty[numerProduktu];

}
void Opakowanie::usunProdukty(){
    produkty.clear();
}

size_t Opakowanie::liczProdukty(){
    return produkty.size();

}


bool Opakowanie::zapisz(std::string nazwaPliku){

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
bool Opakowanie::wczytaj(std::string nazwaPliku){
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
void Opakowanie::wpisz(){

    string toLiczba;
    int wartosc=5;

    cout<<"OPAKOWANIE"<<std::endl;
    cout<<"nazwa: ";
    cin>>nazwa;

    cout<<endl;
    cout<<"pojemnosc: ";
    cin>>toLiczba;
    pojemnosc=toInt(toLiczba);


    cout<<endl;
    cout<<"rodzaj produktu\n 1-plynny \n 2-staly "<<endl;
    while((wartosc!=2) &&(wartosc!=1)){
        cout<<"podaj odpowiedina cyfre: "<<endl;
        cin>>toLiczba;
        wartosc=toInt(toLiczba);
    }
    rodzajProduktu=wartosc;

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
void Opakowanie::menu(){

    cout<<"OPAKOWANIE:wybierz co chcesz zrobic"<<endl;
    wyswietlMenuPom();
}
std::ostream& operator<<(std::ostream& wyjscie, Opakowanie& opakowanie){

    wyjscie<<"'''''''''''''''''''OPAKOWANIE'''''''''''''''''"<<std::endl;
    wyjscie<<"nazwa>"<<opakowanie.nazwa<<std::endl;
    wyjscie<<"pojemnosc:"<<opakowanie.pojemnosc<<std::endl;
    wyjscie<<"rodzaj produktu:"<<opakowanie.podajRodzaj()<<std::endl;
    wyjscie<<"liczba produktow:"<<opakowanie.liczbaProduktow<<std::endl;

    if(opakowanie.produkty.size()>0){
        for(int i=0; i<opakowanie.liczbaProduktow;++i) //TO DZIALA
            wyjscie<<opakowanie.produkty[i];
    }

    return wyjscie;
}
int wczytajRodzaj(std::string& nazwa){
    if(nazwa=="STALY")
        return 2;
    else if(nazwa=="PLYNNY")
        return 1;

}

std::istream& operator >>(std::istream& wejscie,Opakowanie& opakowanie){

    std::string rodzaj;

    wejscie.ignore(numeric_limits<streamsize>::max(),'>');
    wejscie>>opakowanie.nazwa;
    wejscie.ignore(numeric_limits<streamsize>::max(),':');
    wejscie>>opakowanie.pojemnosc;
    wejscie.ignore(numeric_limits<streamsize>::max(),':');
    wejscie>>rodzaj;
    opakowanie.rodzajProduktu=wczytajRodzaj(rodzaj);
    wejscie.ignore(numeric_limits<streamsize>::max(),':');
    wejscie>>opakowanie.liczbaProduktow;

    for(size_t i=0; i<opakowanie.liczbaProduktow; ++i){
        Produkt pom;
        wejscie>>pom;
        opakowanie.produkty.push_back(pom);
    }

    return wejscie;
}

Opakowanie& Opakowanie::operator+=(const Produkt& nowyProdukt){
    if(produkty.size()<pojemnosc){
        produkty.push_back(nowyProdukt);
        ++liczbaProduktow;
        return *this;
    }
      else
        throw std::length_error("brak miejsca w opakowaniu ");
}
