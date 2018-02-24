#ifndef ZAMOWIENIEPOCHODNA_H_INCLUDED
#define ZAMOWIENIEPOCHODNA_H_INCLUDED

#include"zamowienieBazowa.h"
#include"opakowanie.h"
#include"adres.h"
#include"stol.h"

class NaWynos :public Zamowienie{

protected:
    Opakowanie opakowanie; ///< opakowanie w jakim zapakowane jest zamowienie na wynos

public:
     ///konstruktor bezparametrowy
    NaWynos();
    ///konstruktor parametrowy
    NaWynos(int nowyNumer,Opakowanie& noweOpakowanie);
    ///destruktor
    virtual ~NaWynos(){};

    ///funkcja ustalajaca cene zamowienia
    virtual void ustalCene();
    ///funkcja podajaca czas oczekiwania na zamowienie
    virtual int podajCzasOczekiwania();

    ///funkcja wczytujaca zamowienie na dane wyjscie,wywoluje operator << dla opakowania
    virtual void wyswietl(std::ostream& wyjscie);
    ///funkcja wczytujaca zamowienie,wywoluje operator >> dla opakowania
    virtual void importuj(std:: istream& wejscie);
    ///funkcja umozliwiajaca uzytkownikowi wpisanie parametrow zamowienia
    virtual void wpisz();
    ///funkcja wyswietlajaca menu pomocnicze dla zamowienia
    virtual void menu();
    ///funkcja zapisujaca zamowienie do pliku
    virtual bool zapisz(std::string nazwaPliku);
    ///funkcja wczytujaca zamowienie z pliku
    virtual bool wczytaj(std::string nazwaPliku);

    ///operaror strumieniowy >> dla klasy NaWynos, wywoluje funkcje wyswietl()
    friend std::ostream& operator <<(std::ostream& wyjscie,NaWynos& NaWynos);
    ///operator strumieniowy << dla klasy NaWynos, wywoluje funkcje importuj()
    friend std::istream& operator >>(std::istream& wejscie, NaWynos& naWynos);
};

class ZDostawa:public NaWynos{
    Adres adres; ///<adres,na ktory ma byc dostarczone dane zamowienie
    unsigned int czasDostawy; ///<czas dostawy zamowienia do podanego adresu

public:
    //stale powinny byc polami prywatnymi
    const unsigned int MAX_KM_1=15; ///< stala,okreslajaca maksymalna odleglosc w obrebie ktorej koszt danego zamowienia jest tanszy
    const unsigned int MAX_KM_2=30;///< stala,okreslajaca maksymalna odleglosc w obrebie ktorej zamowienie jest mozliwe
    const unsigned int MIN_KOSZT=8; ///< wspolczynik okreslajacy koszt zamowienia dla 1 strefy odleglosci
    const unsigned int MAX_KOSZT=16; ///< wspolczynnik okreslajacy koszt zamowienia dla 2 strefy odleglosci
    const unsigned int  WSPOLCZYNNIK=2; ///< wspolczynnik uzalezniajacy czas oczekiwania na dane zamowienie od odleglosci tego zamowienia od restauracji

    ///konstruktor bezparametrowy
    ZDostawa();
    ///konstruktor parametrowy
    ZDostawa(int nowyNr,Opakowanie& noweOpakowanie,Adres& nowyAdres);

    ///fukjca ustalajaca cene zamowienia
    void ustalCene();
    ///funkcja ustalajaca czas dostawy zamowienia,czas jest zalezny od odleglosci adresu od restauracji
    void ustalCzasDostawy();
    ///funkcja umozliwiajaca wpisanie uzytkownikowi parametrow zamowienia
    void wpisz();

    ///funkcja podajaca czas oczekiwania na zamowienie,czas ten jest suma czasu oczekiwania na produkty i czasu dostawy
    int podajCzasOczekiwania();
    ///funkja wczytujaca zamowienie na dane wyjscie, wywoluje operator << dla opakowania oraz operator<< dla adresu
    void wyswietl(std::ostream& wyjscie);
    /// funkcja wczytujaca zamowienie na dane wejscie,wywoluje operator >> dla opakowania oraz >> dla adresu
    void importuj(std::istream& wejscie);

    /// operator strumieniowy << dla klasy ZDostawa,wywoluje funkcje wyswietl()
    friend std::ostream& operator <<(std::ostream& wyjscie,ZDostawa& zDostawa);
    ///operator strumieniowy >> dla klasy ZDostawa, wywoluje funkcje importuj()
    friend std::istream& operator >>(std::istream& wejscie, ZDostawa& zDostawa);

};




class NaMiejscu:public Zamowienie{

    Stol stol; ///< stol przypozadkowany do danego zamowienia na miejscu

public:

    const float NAPIWEK=0.1; ///<wspolczynnik okreslajacy wysokosc napiwku w stosunku do calkowitej ceny zamowienia

    ///konstruktor bezparametrowy
    NaMiejscu();
    ///konstruktor parametrowy
    NaMiejscu(int nowyNumer,Stol& nowyStol);

    ///funkcja ustalajaca cene zamowienia
    void ustalCene();
    ///funkca podajaca czas oczekiwania na zamowienie
    int podajCzasOczekiwania();

    ///funkja wczytujaca zamowienie na dane wyjscie, wywoluje operator << dla klasy stol
    void wyswietl(std::ostream& wyjscie);
    ///funkja wczytujaca zamowienie do danegoe wejscia, wywoluje operator >> dla klasy stol
    void importuj(std:: istream& wejscie);
    /// funkcja umozliwiajaca uzytkownikowi wpisanie parametrow zamowienia
    void wpisz();
    ///funckja wyswietlajaca menu pomocnicze dla zamowienia
    void menu();

    ///funkcja zapisujaca zamowienie w podanym pliku
    bool zapisz(std::string nazwaPliku);
    ///funkcja wczytujaca zamowienie z podanego pliku
    bool wczytaj(std::string nazwaPliku);

    ///operator strumieniowy << dla klasy NaMiejscu wywoluje funkcje wyswietl()
    friend std::ostream& operator <<(std::ostream& wyjscie, NaMiejscu& naMiejscu);
    /// operator strumieniowy >> dla klasy NaMiejscu wywoluje funkcje importuj()
    friend std::istream& operator >>(std::istream& wejscie, NaMiejscu& naMiejscu);

};

#endif // ZAMOWIENIEPOCHODNA_H_INCLUDED
