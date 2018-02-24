#ifndef ZAMOWIENIEBAZOWA_H_INCLUDED
#define ZAMOWIENIEBAZOWA_H_INCLUDED

#include <vector>
#include <iostream>
#include<ostream>
#include"produkt.h"


///klasa czysto wirtualna
class Zamowienie{

private:
    ///konstruktor kopiujacy
    Zamowienie(const Zamowienie&wzorZamowienia);

protected:

    ///konstruktor z jednym parametrem
    Zamowienie(int nowyNumer);
    static unsigned int liczbaZamowien; ///<zmienna statyczna, okresla liczbe wszystkich zamowien
    int numer; ///< numer zamowienia
    double cena; ///<cena zamowienia, jest roznie okreslona w zaleznosci od rodzaju zamowienia
    unsigned int czasOczekiwania; ///<czas oczekiwania na zamowienie,jest roznie okreslony w zaleznosc od rodzaj zamowienia

public:
    ///konstruktor bezparametrowy
    Zamowienie();
    ///destrutkor
    virtual ~Zamowienie();
    ///funcja ustalajaca cene zamowienia
    virtual void ustalCene()=0;
    ///funkcja wyswietlajaca zamowienie
    virtual void wyswietl(std::ostream& wyjscie)=0;
    ///funkcja wczytujaca parametry zamowienia z pliku
    virtual void importuj(std:: istream& wejscie)=0;
    ///fukkcja zapisujaca zamowienie do pliku
    virtual bool zapisz(std::string nazwaPliku)=0;
    ///funkcja umozliwiajaca wpisanie uzytkownikowi parametrow zamowienia
    virtual void wpisz()=0;
    ///funkcja wyswietlajaca odpowiednie menu pomocnicze
    virtual void menu()=0;

    ///funkcja umozliwiajaca zmiane numeru zamowienia
    virtual void zmienNumer(int nNumer);
    ///funkcja podajaca numer zamowienia
    virtual int podajNumer();
    ///funkcja podajaca cene zamowienia
    virtual double podajCene();

    //OPERATORY
    ///operator % umozliwia obnizenie ceny zamowienia (danie rabatu na dane zamowienie )
    virtual Zamowienie& operator %(double rabatProcent);

};


#endif // ZAMOWIENIEBAZOWA_H_INCLUDED
