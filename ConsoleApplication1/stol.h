#ifndef STOL_H_INCLUDED
#define STOL_H_INCLUDED

#include"produkt.h"
#include<vector>


class Stol{

    static unsigned int liczbaWszystkichStolow; ///<zmienna statyczna,okresla liczbe wszystkich stolow
    int lokalizacja; ///< cyfra okreslajaca lokalizacje stolu( wartosc 1 oznacza sale dla niepalacych, wartosc 2 palarnie)
    int stan;///< cyfra okreslajaca stan stolu(warotosc 1 oznacza stol zajety,wartosc 2 stol wolny)
    int liczbaMiejsc; ///< liczba miejsc przy stole
    size_t liczbaProduktow; ///< liczba produktow ktore znajduja sie na stole
    std::vector<Produkt>produkty; ///< wektor produktow, zawiera produkty ktore znajduja sie na stole


public:
    //KONSTRUKTORY
    ///konstruktor bezparametrowy
    Stol();
    ///konstruktor parametrowy
    Stol(int nLokalizacja,int nStan,int nLiczbaMiejsc,std::vector<Produkt>&noweProdukty );

    //FUNKCJE
     ///funckja zwracajaca napis odpowiadajacy odpowiedniej lokalizacji stolu
    std::string podajLokalizacje();
    ///funkcja zwracajaca napis odpowiadajacy odpowiedniemu stanowi stolu
    std::string podajStan();
    ///funkcja podajaca liczbe miejsc stolu
    int podajLiczbeMiejsc();
     ///funkcja podajaca liczbe wszystkich stolow
    unsigned int podajLiczbeStolow();
    ///funkcja zwracajaca wektor produktow ktore znajduja sie na stole
    std::vector <Produkt>& podajProdukty();
    ///funkcja podajaca konkrety produkt,przyjmuje indekst tego produktu
    Produkt podajProdukt(unsigned int numerProduktu);
    ///funkcja usuwajaca wszyskie produkty
    void usunProdukty();
    ///funkcja zmieniajaca lokalizacje stolu
    void zmienLokalizacje();
    ///funkcja zmieniajaca lokalizacje stolu
    void zmienStan();
    ///funkcja umozliwiajaca zmienienie liczby miejsc przy danym stole
    void zmienLiczbeMiejsc(int nowaLiczbaMiejsc);
    ///funkcja zapisujaca parametry stolu do pliku,
    bool zapisz(std::string nazwaPliku);
    ///funkcja wczytujaca lokalizacje,po podaniu odpowiedniej nazwy
    int wczytajLok(std::string& nazwa);
    ///funckja wczytujaca stan po podaniu odpowiedniej nazwy
    int wczytajStan(std::string& nazwa);
    ///funkcja zwracajaca liczbe produktow
    size_t liczProdukty();
    ///funkcja wczytujaca parametry stolu z pliku
    bool wczytaj(std::string nazwaPliku);
     ///funkcja umozliwiajaca uzytkownikowi wpisanie parametrow danego stolu
    void wpisz();
    ///funkcja wyswietlajaca menu pomocnicze dla klasy stol
    void menu();

    //OPERATORY
    ///operator != ,"czysci" stol (ustawia jego stan na WOLNY, a lokalizacje na DLA_NIEPALACYCH)
    bool operator !();
    ///operator strumieniowy << dla klasy Stol,wywoluje operator << dla klasy produkt
    friend std::ostream& operator <<(std::ostream& wyjscie,Stol& stol);
    ///operator strumieniowy >> dla klasy Stol,wywoluje operator >> dla klasy produkt
    friend std::istream& operator>>(std::istream& wejscie,Stol& stol);

};

#endif // STOL_H_INCLUDED
