#ifndef OPAKOWANIE_H_INCLUDED
#define OPAKOWANIE_H_INCLUDED

#include<vector>
#include<string>
#include<fstream>
#include"Produkt.h"


class Opakowanie{

    std::string nazwa;///< Nazwa opakowania
    int rodzajProduktu;///< rodzaj produktu-przyjmuje wartosci typu int, 1-oznacza rodzaj plynny, 2-oznacza rodzaj staly
    unsigned int pojemnosc;///<okresla maksymalna liczbe produktow ktore mieszcza sie w opakowaniu
    size_t liczbaProduktow; ///<okresla aktualna liczbe produktow ktora jest w opakwaniu
    std::vector<Produkt>produkty;  ///<tablica produktow

    public:
    enum RODZAJ_PRODUKTU {STALY=2, PLYNNY=1};///<przyporzadkowuje liczbe do nazwy rodzaju produktu(PLYNNY=1, STALY=2)
    std::string DOMYSLNA_NAZWA="pudelko";///< stala,definuje ustala nazwe opakowania jako pudelko
    unsigned int DOMYSLNA_POJEMNOSC=5;///<stala,ustala domyslna pojemnosc opakowania na wartosc 5

    ///konstruktor bezparametrowy
    Opakowanie();
    ///konstruktor parametrowy
    Opakowanie(std::string nowaNazwa,int rodzaj ,int maxProduktow, std::vector<Produkt>noweProdukty);

    ///funkcja zwaracajaca nazwe opakowania
    std::string podajNazwe();
    ///funkcja zwracajaca napis, okrslajacy rodzaj opakowania
    std::string podajRodzaj();
    ///funkcja zwaracjaca pojemnosc
    int podajPojemnosc();
    ///funkcja zwracajac wektor zawierajacy produkty
    std::vector <Produkt> podajProdukty();
    ///funkjca podajaca konkretny produkt z vectoru produkty,przyjmuje indeks tego produktu
    Produkt podajProdukt(unsigned int numerProduktu);
    ///funkjca usuwajaca wszystkie produkty
    void usunProdukty();
    ///funkjca zwracajaca ilosc produktow
    size_t liczProdukty();
    ///funkcja zapisujaca opakowanie do pliku,przyjmuje nazwe pliku
    bool zapisz(std::string nazwaPliku);
    ///funkcja wczytujaca z pliku paramerty opakowania,przyjmuje nazwe pliku, z ktorego ma wczytac parametry
    bool wczytaj(std::string nazwaPliku);
    ///funkcja wczytujaca rodzaj danego opakowania, przyjmuje napis okreslajacy jaki to rodzaj
    int wczytajRodzaj(std::string& nazwa);
    ///funkjca umozliwiajaca wpisanie urzytkownikowi parametrow zamowienia
    void wpisz();
    ///funkcja wyswietlajaca menu pomocnicze dla opakowania
    void menu();

    ///operator dodajacy nowy produkt do opakowania
    Opakowanie& operator+=(const Produkt& nowyProdukt);
    ///operator strumieniowy << dla klasy Opakowanie,wywoluje operator << dla klasy Produkt
    friend std::ostream& operator<<(std::ostream& wyjscie, Opakowanie& opakowanie);
    ///operator strumieniowy >> dla klasy Opakowanie,wywoluje operator >> dla klasy Produkt
    friend std::istream& operator >>(std::istream& wejscie,Opakowanie& Opakowanie);

};


#endif // OPAKOWANIE_H_INCLUDED
