#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include<iostream>
#include"adres.h"
 ///funkcja wyswietlajaca klasy, informuje uzytkownika jaki numer ma wpisac aby wybrac dana klase
void wyswietlMenu();
///funkcja wyswietlajaca opcji,zwiazane z zapisem lub odczytem danego obiektu do pliku
void wyswietlMenuPom();
///funkcja wczytujaca odpowiedni wybor uzytkownika, wywoluje funcje zarzadzajMenu dla odpowiedniej klasy
void menu();
///funkcja umozliwiajaca uzytkownikowi podejecie decyzji,czy chce wpisywac parametry produktow, jest wykorzysywania w klasach zawietajacych tablice produktow
int menuProdukt();

///funkcja komwertujaca zmienna typu string na zmienna typu int, jest wykorzystywana w przypadku wpisywania wartosci zmiennych przez urzytkownika
unsigned int toInt(std::string& nazwa);
///funkcja komwertujaca zmienna typu string na zmienna typu double, jest wykorzystywana w przypadku wpisywania wartosci zmiennych przez urzytkownika
double toDouble(std::string& nazwa);

///funkcja wczytujaca wybor uzytkownika, i wyswietlajaca menu dla klasy wybranej przez uzytkownika (wywoluje funkcje menu() danej klasy)
template <typename KLASA>
void zarzadzajMenu(KLASA& klasa);



template <typename KLASA>
void zarzadzajMenu(){
    KLASA klasa;
    int wybor=0;
    std::string nazwa;

     while(wybor!=3){

        klasa.menu();
        std::cin>>wybor;

        switch(wybor){
        case 1:
        {
            klasa.wpisz();

            std::cout<<"podaj nazwe pliku: ";
            std::cin>>nazwa;

            if(klasa.zapisz(nazwa+".txt"))
                std::cout<<"Zapisywanie zakonczone"<<std::endl;
            else
                std::cout<<"Zapisywanie nie powiodlo sie"<<std::endl;
        }
            break;

        case 2:
        {
            std::cout<<"podaj nazwe pliku";
            std::cin>>nazwa;
            if(klasa.wczytaj(nazwa+".txt"))
                std::cout<<klasa;
            else
                std::cout<<"obczyt nie powiodl sie";
        }
            break;

        case 3:
            break;

        default:
            std::cout<<"Wpisano zly znak\nWpisz znak ponownie: "<<std::endl;
    }
}
}

#endif // INTERFACE_H_INCLUDED
