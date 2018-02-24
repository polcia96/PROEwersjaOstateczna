#include<algorithm>
#include<stdexcept>
#include"ZamowieniePochodna.h"

using namespace std;

//CLASS NA WYNOS
NaWynos::NaWynos():Zamowienie(){}

NaWynos::NaWynos(int nowyNumer,Opakowanie& noweOpakowanie){

    numer=nowyNumer;
    opakowanie=noweOpakowanie;
    ustalCene();
    czasOczekiwania=podajCzasOczekiwania();

    ++liczbaZamowien;
}

void NaWynos::ustalCene(){

    double nCena=0;

    for(int i=0; i < opakowanie.podajProdukty().size(); ++i)
        nCena=nCena+opakowanie.podajProdukt(i).podajCene();

    cena=nCena;

}

void NaWynos::wyswietl(std::ostream& wyjscie){

        wyjscie<<"ZAMOWIENIE-NA WYNOS"<<std::endl;
        wyjscie<<"numer zamowienia:^ "<<numer<<std::endl;
        wyjscie<<std::endl<<opakowanie<<std::endl;
        wyjscie<<"calkowita cena zamowienia:"<<cena<<"zl"<<std::endl;
        wyjscie<<"czas oczekiwania na zamowienie:"<<podajCzasOczekiwania()<<"min"<<std::endl;

}

void NaWynos::importuj(std:: istream& wejscie)
{
    wejscie.ignore(numeric_limits<streamsize>::max(),'^');
    wejscie>>numer;

    wejscie>>opakowanie;

    wejscie.ignore(numeric_limits<streamsize>::max(),':');
    wejscie>>cena;

    wejscie.ignore(numeric_limits<streamsize>::max(),':');
    wejscie>>czasOczekiwania;

}


int NaWynos::podajCzasOczekiwania(){

int czasOczekiwania=0;
    if(opakowanie.podajProdukty().size()){
        for(int i=0;i < opakowanie.podajProdukty().size(); ++i)
            czasOczekiwania=std::max(opakowanie.podajProdukt(i).podajCzasOczekiwania(),czasOczekiwania);
    }

    return czasOczekiwania;
}

bool NaWynos::zapisz(std::string nazwaPliku){

    std::ofstream osrodek;
    osrodek.open(nazwaPliku,std::ios_base::app);

    if(osrodek.good()){
        osrodek<<*this;
        osrodek.close();
       return true;
    }///operator strumieniowy << dla klasy Stol,wywoluje operator << dla klasy produkt
    else
        return false;

}

bool NaWynos::wczytaj(std::string nazwaPliku){

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
void NaWynos::wpisz(){
    string toLiczba;

    cout<<"ZAMOWIENIE NA WYNOS-POCZATEK"<<std::endl;
    cout<<"numer zamowienia: ";
    cin>>toLiczba;
    numer=toInt(toLiczba);

    cout<<endl;
    opakowanie.wpisz();

    ustalCene();
    czasOczekiwania=podajCzasOczekiwania();
}

void NaWynos::menu(){
    cout<<"ZAMOWIENIE-NA WYNOS:wybierz co chcesz zrobic"<<endl;
    wyswietlMenuPom();

}

std::ostream& operator <<(std::ostream& wyjscie,NaWynos& naWynos){

    naWynos.wyswietl(wyjscie);
    return wyjscie;
}

std::istream& operator >>(std::istream& wejscie, NaWynos& naWynos){

    naWynos.importuj(wejscie);
    return wejscie;

}

////////////////////////////////////////////////////////
//NA WYNOS<---Z DOSTAWA

ZDostawa::ZDostawa():NaWynos(){};

ZDostawa::ZDostawa(int nowyNr,Opakowanie& noweOpakowanie,Adres& nowyAdres){
    numer=nowyNr;
    opakowanie=noweOpakowanie;
    adres=nowyAdres;


    ustalCene();
    ustalCzasDostawy();
    czasOczekiwania=podajCzasOczekiwania()+czasDostawy;

    ++liczbaZamowien;

}
void ZDostawa::ustalCene(){
    double nCena=0;

    for(int i=0; i < opakowanie.podajProdukty().size(); ++i)
        nCena+=opakowanie.podajProdukt(i).podajCene();

    //OPTYMALIZACJA CENY
    if(adres.podajOdleglosc()<=MAX_KM_1)
        nCena+=MIN_KOSZT;
    else if(adres.podajOdleglosc()<=MAX_KM_2)
        nCena+=MAX_KOSZT;
    else
        throw std::out_of_range("zbyt duza odleglosc-dostawa niemozliwa\n");

    cena=nCena;
}

void ZDostawa::ustalCzasDostawy(){
    int nowyCzas=0;
    nowyCzas=adres.podajOdleglosc()*WSPOLCZYNNIK;

    czasDostawy=nowyCzas;
}

int ZDostawa::podajCzasOczekiwania(){

int czasOczekiwania=0;
    if(opakowanie.podajProdukty().size()){
        for(int i=0;i < opakowanie.podajProdukty().size(); ++i)
            czasOczekiwania=std::max(opakowanie.podajProdukt(i).podajCzasOczekiwania(),czasOczekiwania);
    }
    ustalCzasDostawy();
    czasOczekiwania+=czasDostawy;

    return czasOczekiwania;
}
void ZDostawa::importuj(std::istream& wejscie){

    wejscie.ignore(numeric_limits<streamsize>::max(),'~');
    wejscie>>numer;

    wejscie>>opakowanie;

    wejscie.ignore(numeric_limits<streamsize>::max(),':');
    wejscie>>cena;

    wejscie.ignore(numeric_limits<streamsize>::max(),':');
    wejscie>>czasDostawy;

    wejscie.ignore(numeric_limits<streamsize>::max(),':');
    wejscie>>czasOczekiwania;

    wejscie>>adres;

}

void ZDostawa::wyswietl(std::ostream& wyjscie){

        wyjscie<<"ZAMOWIENIE-NA WYNOS-Z DOSTAWA"<<std::endl;
        wyjscie<<"numer zamowienia~ "<<numer<<std::endl;
        wyjscie<<std::endl<<opakowanie<<std::endl;
        wyjscie<<"calkowita cena zamowienia:"<<cena<<" zl"<<std::endl;
        wyjscie<<"czas dostawy:"<<czasDostawy<<" min"<<std::endl;
        wyjscie<<"calkowity czas oczekiwania na zamowienie:"<<podajCzasOczekiwania()<<" min"<<std::endl;

        wyjscie<<adres;
}
void ZDostawa::wpisz(){
    string toLiczba;

    cout<<"ZAMOWIENIE NA WYNOS Z DOSTAWA-POCZATEK"<<std::endl;
    cout<<"numer zamowienia: ";
    cin>>toLiczba;
    numer=toInt(toLiczba);

    cout<<endl;
    opakowanie.wpisz();



    cout<<endl;
    adres.wpisz();

    ustalCene();
    czasOczekiwania=podajCzasOczekiwania();
}

std::ostream& operator <<(std::ostream& wyjscie,ZDostawa& zDostawa){

    zDostawa.wyswietl(wyjscie);
    return wyjscie;
}
std::istream& operator >>(std::istream& wejscie, ZDostawa& zDostawa){

    zDostawa.importuj(wejscie);
    return wejscie;

}
//////////////////////////////////////////////////////////////////////////

//NA MIEJSU


NaMiejscu::NaMiejscu():Zamowienie(){};

NaMiejscu::NaMiejscu(int nowyNumer,Stol& nowyStol){

    numer=nowyNumer;
    stol=nowyStol;
    czasOczekiwania=podajCzasOczekiwania();
    ustalCene();

    ++liczbaZamowien;
}

void NaMiejscu::ustalCene(){

    double nCena=0;

    for(int i=0; i < stol.podajProdukty().size(); ++i)
        nCena+=stol.podajProdukt(i).podajCene();

    nCena+=NAPIWEK*nCena; //+OBOWIAZKOWY NAPIWEK DLA KELNERA

    cena=nCena;

}
int NaMiejscu::podajCzasOczekiwania(){

int czasOczekiwania=0;
    if(stol.podajProdukty().size()){
        for(int i=0;i < stol.podajProdukty().size(); ++i)
            czasOczekiwania=std::max(stol.podajProdukt(i).podajCzasOczekiwania(),czasOczekiwania);
    }

    return czasOczekiwania;

}

void NaMiejscu::wyswietl(std::ostream& wyjscie){

        wyjscie<<"ZAMOWIENIE-NA MIEJSCU"<<std::endl;
        wyjscie<<"numer zamowienia:` "<<numer<<std::endl;
        wyjscie<<std::endl<<stol<<std::endl;
        wyjscie<<"calkowita cena zamowienia:"<<cena<<"zl"<<std::endl;
        wyjscie<<"czas oczekiwania na zamowienie:"<<podajCzasOczekiwania()<<"min"<<std::endl;
        wyjscie<<"NA MIEJSCU -KONIEC"<<std::endl<<std::endl;

}

void NaMiejscu::importuj(std:: istream& wejscie){

    wejscie.ignore(numeric_limits<streamsize>::max(),'`');
    wejscie>>numer;

    wejscie>>stol;

    wejscie.ignore(numeric_limits<streamsize>::max(),':');
    wejscie>>cena;

    wejscie.ignore(numeric_limits<streamsize>::max(),':');
    wejscie>>czasOczekiwania;

}

bool NaMiejscu::zapisz(std::string nazwaPliku){

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
bool NaMiejscu::wczytaj(std::string nazwaPliku){

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
void NaMiejscu::wpisz(){
    string toLiczba;

    cout<<"ZAMOWIENIE NA MIEJSCU-POCZATEK"<<std::endl;
    cout<<"numer zamowienia: ";
    cin>>toLiczba;
    numer=toInt(toLiczba);

    cout<<endl;
    stol.wpisz();

    ustalCene();
    czasOczekiwania=podajCzasOczekiwania();

}
void NaMiejscu::menu(){
    cout<<"ZAMOWIENIE-NA MIEJSCU:wybierz co chcesz zrobic"<<endl;
    wyswietlMenuPom();
}

std::ostream& operator <<(std::ostream& wyjscie, NaMiejscu& naMiejscu){

    naMiejscu.wyswietl(wyjscie);
    return wyjscie;
}

std::istream& operator >>(std::istream& wejscie, NaMiejscu& naMiejscu){

    naMiejscu.importuj(wejscie);
    return wejscie;
}

