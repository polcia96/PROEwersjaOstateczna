#ifndef PRODUKT_H_INCLUDED
#define PRODUKT_H_INCLUDED

#include<iostream>
#include<ostream>
#include<fstream>
#include<stdexcept>
#include<limits>
#include<string>
#include<sstream>
#include<stdlib.h>
#include"interface.h"


class Produkt{

    unsigned int czasOczekiwania; ///< czas oczekiwania na dany produkt,podany w minutach
    double cena; ///< cena danego produktu, podana w zlotowkach
    std::string nazwa; ///<nazwa produktu

public:
    double DOMYSLNA_CENA=20.0;///<stala, okreslajaca domyslna cene produktu,przyjmuje warosc 20(zl)
    unsigned int DOMYSLNY_CZAS_OCZEKIWANIA=15; ///<stala,okreslajaca domyslny czas oczekiwania na produkt,przyjmuje wartsc 15(min)
    std::string DOMYSLNA_NAZWA="DANIE DNIA";///<stala,okrslajaca domyslna nazwe produktu, przyjmuje napis "DANIE DNIA"
    //KONSTRUKTORY
    ///konstruktor domyslny
    Produkt();
    ///konstruktor parametrowy
    Produkt(double nCena,int nCzasOczekiwania,std::string nNazwa);
    ///konstruktor kopiujacy
    Produkt(const Produkt& wzorzecProduktu);

    //FUNKCJE
    ///funkcja zwaracajaca cene produktu
    double podajCene();
    ///funkcja zwaracjaca czas oczekiwania na produkt
    int podajCzasOczekiwania();
    ///funckja zwaracajaca nazwe produktu
    std::string podajNazwe();

    ///funkjca umozliwiajca zmiane ceny produktu
    void zmienCene(double nowaCena);
    ///funkcja umozliwiajcaca zmiane czasu oczekiwania na produkt
    void zmienCzasOczekiwania(int nowyCzasOczekiwania);
    /// funkcja umozliwiajaca
    void zmienNazwe(std::string& nowaNazwa);
    ///funkcja zapisujaca produkt do pliku,przyjmuje nazwe pliku
    bool zapisz(std::string nazwaPliku);
    /// funkcja wczytujaca parametry opakowania z pliku, przyjmuje nazwe pliku
    bool wczytaj(std::string nazwaPliku);
    ///funkcja umozliwiajaca wpisanie uzytkownikowi parametrow opakowania
    void wpisz();
    ///funkcja wyswietlajaca menu pomocnicze dla produktu
    void menu();

    //OPERATORY
    ///operator porownuje produkty pod wzgledem ceny i zwraca tanszy z nich
    Produkt& operator < (Produkt& porownywanyProdukt);
    ///operator strumieniowy << dla klasy produkt
    friend std::ostream& operator <<(std::ostream& wyjscie,const Produkt& produkt);
    ///operator strumieniowy >> dla klasy produkt
    friend std::istream& operator >>(std::istream& wejscie,Produkt& produkt);



};

#endif // PRODUKT_H_INCLUDED
