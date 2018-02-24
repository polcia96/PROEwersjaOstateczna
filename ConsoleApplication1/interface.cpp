#include"interface.h"
#include"restauracja.h"
using namespace std;

void wyswietlMenu(){

    cout<<"Wybierz obiekt:"<<endl;
    cout<<"1-Produkt"<<endl;
    cout<<"2-Adres"<<endl;
    cout<<"3-Opakowanie"<<endl;
    cout<<"4-Stol"<<endl;
    cout<<"5-Zamowienie na wynos-bez dostawy"<<endl;
    cout<<"6-Zamowienie na wynos-z dostawa"<<endl;
    cout<<"7-Zamowienie na miejsu"<<endl;
    cout<<"8-Restauracja"<<endl;
    cout<<"9-Wyjdz"<<endl;

}

void menu(){
    string toLiczba;
    int wybor=0;
    while(wybor!=9){

        wyswietlMenu();
        cin>>toLiczba;
        wybor=toInt(toLiczba);

        switch(wybor){
        case 8:
            zarzadzajMenu<Restauracja>();
            break;
        case 7:
            zarzadzajMenu<NaMiejscu>();
            break;
        case 6:
            try{
            zarzadzajMenu<ZDostawa>();
            }
            catch(out_of_range& e){
                cout<<e.what();
            }
            break;
        case 5:
            zarzadzajMenu<NaWynos>();
            break;
        case 4:
            zarzadzajMenu<Stol>();
            break;
        case 3:
            zarzadzajMenu<Opakowanie>();
            break;
        case 2:
            zarzadzajMenu<Adres>();
            break;
        case 1:
            zarzadzajMenu<Produkt>();
            break;
        case 9:
            break;
        default:
            cout<<"wpisales zly znak \n podaj znak ponownie "<<endl;

        }
    }
}
void wyswietlMenuPom(){

    cout<<endl;
    cout<<"1-zapisz do pliku"<<endl;
    cout<<"2-Wczytaj z pliku"<<endl;
    cout<<"3-Wyjdz"<<endl<<endl;
}

int menuProdukt(){

    int wybor=0;
    string toLiczba;

    cout<<"Czy chcesz wpisac produkty:"<<endl;
    cout<<"1-brak produktow \n2-wpisz produkty "<<endl;
    cout<<"wpisz odpowiednia cyfre: ";

    cin>>toLiczba;
    wybor=toInt(toLiczba);
    while((wybor!=2) &&(wybor!=1)){
        cout<<"podaj odpowiedina cyfre: "<<endl;
        cin>>toLiczba;
        wybor=toInt(toLiczba);
    }
    return wybor;

}

unsigned int toInt(string& nazwa){

        int zmienna;
        istringstream iss(nazwa);
        iss>>zmienna;
        if(zmienna<=0){
            cout<<"podales zla wartosc,podaj liczbe"<<endl;
            cin>>nazwa;
            zmienna=toInt(nazwa);
        }
            return zmienna;
}

double toDouble(string& nazwa){

        double zmienna;
        zmienna=atof(nazwa.c_str());
        if(zmienna<=0){
            cout<<"podales zla wartosc,podaj liczbe"<<endl;
            cin>>nazwa;
            zmienna=toDouble(nazwa);
        }
            return zmienna;
}

