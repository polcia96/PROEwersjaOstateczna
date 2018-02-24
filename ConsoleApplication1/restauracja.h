#ifndef RESTAURACJA_H_INCLUDED
#define RESTAURACJA_H_INCLUDED


#include<vector>

#include"zamowieniePochodna.h"
class Restauracja{

    static const unsigned int GODZINY_OTWARCIA=2; ///<stala,ustala ilosc obiektow w tablicy godzinyOtwarcia
    unsigned const int GODZINA_OTWARCIA=8;///<stala,ustala domyslna godzine otwarcia na wartosc 8
    unsigned const int GODZINA_ZAMKNIECIA=22;///< stala,ustala domyslna godzine zamkniecia na wartosc 22

    std::string nazwa; ///<nazwa restauracji
    int godzinyOtwarcia[GODZINY_OTWARCIA]; ///< tablica,zawierajaca godzine otwarcia oraz zamkniecia restauracji
    std::vector <Zamowienie*>zamowienia; ///< wektor wskaznikow do obiektow klasy Zamowienie
    unsigned int liczbaZam;  ///<liczba zamowien,jakie obecnie posiada restauracja


public:
    ///konstruktor bezparametrowy
    Restauracja();
    ///konstruktor parametrowy
    Restauracja(std::string nNazwa,int nGodzOtwarcia[GODZINY_OTWARCIA],std::vector<Zamowienie*> nZamowienia);
    ///konstruktor kopiujacy
    Restauracja(Restauracja&wzorRestauracji);
    //~Restauracja();

    //FUNKCJE
    ///funkcja zwaracjaca nazwe restauracji
    std::string podajNazwe();
    ///funkcja zwracajaca liczbe zamowien, jakie ma restauracja
    unsigned int podajLiczbaZamowien();
    ///funkcja zwaracajaca wskaznik do tablicy,zawierajacej godziny otwarcia restauracji
    int* podajGodzOtwarcia();
     ///funkcja umowzliwajaca wybor konkretnego zamowienia,przyjmuje indeks tego zamowienia
    Zamowienie& wybierzZamowienie(unsigned int indeksZam);

    ///funckja umozliwiajaca zmiane nazwy restauracji
    void zmienNazwe(const std::string& nNazwa);
    ///funkcja umozliwiajaca zmiane godzin otwarcia
    void zmienGodzOtwarcia(int*nGodzOtwarcia);
    ///funkcja usuwajaca wszystkie zamowienia z restauracji
    void usunZamowienie(int indeksZam);
    ///funkcja wczytujaca parametry restauracji do danego wejscia
    void importuj(std::istream& wejscie);
    ///funkcja umozliwiajaca uzytkownikowi wpisanie parametrow restauracji
    void wpisz();
    ///funkcja wyswietlajaca menu pomocnicze dla restauracji
    void menu();
    ///funkcja zapisujaca parametry restauracji do pliku,przyjmuje nazwe pliku
    bool zapisz(std::string nazwaPliku);
    ///funkcja wczytujaca parametry restauracj z pliku,przyjmuje nazwe pliku
    bool wczytaj(std::string nazwaPliku);


    //OPERATORY
    ///operator += dodaje zamowienie do restauracji
    Restauracja& operator+=(Zamowienie* nZamowienie);
    ///operator konwersji,podaje liczbe zamowien,ktore obecnie posiada restauracja
    explicit operator int()const;
    ///operator =, przypisuje parametry wzorca restauracji do restauracji
    Restauracja& operator=(const Restauracja& wzorRestauracji);
    ///operator + ,dodaje do siebie dwie restauracje  i zwarac nowa,ktora jest ich suma
    Restauracja operator+(const Restauracja& dodanaRestauracja)const;
    ///operator [] zwaraca konretne zamowienie,przyjmuje numer indeksu wskaznika do tego zamowienia
    Zamowienie& operator[](unsigned int indeksZam);
    ///operator strumieniowy << dla klasy Restauracja,wywoluje funkcje wyswietl dla zamowien
    friend std::ostream& operator<<(std::ostream& wyjscie,Restauracja& restauracja);
    ///operator strumieniowy >> dla klasy Restauracja,wywoluje funkcje importuj
    friend std::iostream& operator>>(std::iostream& wejscie,Restauracja& restauracja);

};

#endif // RESTAURACJA_H_INCLUDED
