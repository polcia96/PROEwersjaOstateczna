#ifndef ADRES_H_INCLUDED
#define ADRES_H_INCLUDED

#include<iostream>
#include<ostream>
#include<fstream>
#include<stdexcept>
#include<limits>

#include"produkt.h"

class Adres{

    std::string nazwaUlicy; ///< nazwa ulicy
    unsigned int numerDomu; ///<numer domu
    unsigned int odleglosc;///< odleglosc danego odresu od restauracji


    public:
    ///konstrukor bezparametrowy
    explicit Adres();
    ///konstrukor parametrowy
    explicit Adres(std::string nowaNazwaUl,unsigned int nowyNrDomu,unsigned int nowaOdleglosc);

    ///funkcja zwaracjaca nazwe ulicy danego adresu
    std::string podajNazweUl();
    ///funkcja zwracajaca numer domu danego adresu
    int podajNumerDomu();
    ///funkcja zwaracjaca odleglosc adresu od restauracji
    unsigned int podajOdleglosc();
    ///funkcja zapisujaca adres do pliku,przyjmuje nazwe pliku
    bool zapisz(std::string nazwaPliku);
    ///funkcja umozliwiajaca uzytkownikowi wpisanie parametrow adresu
    void wpisz();
    ///funkcja wczytujaca parametry adresu z pliku, przyjmuje nazwe pliku
    bool wczytaj(std::string nazwaPliku);
    ///funkcja wyswietlajaca menu pomocnicze dla klasy adres
    void menu();

    ///operator strumieniowy << dla klasy adres
    friend std::ostream& operator<<(std::ostream& wyjscie, Adres& adres);
    ///operator strumieniowy >> dla klasy adres
    friend std::istream& operator>>(std::istream& wejscie, Adres&adres);
};

#endif // ADRES_H_INCLUDED
