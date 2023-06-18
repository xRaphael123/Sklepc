#include <iostream>
#include <vector>
#include "klient.h"
#include "zapis.h"
#include "zamowienie.h"
#include "produkty.h"

using namespace std;

Klient klient;
Zapis zapis;
Produkty produkt("", 0, 0);

void sprawdz_wektor(vector<Klient>& klienci)
{
    for (int i = 0; i < klienci.size(); i++) {
        cout << "Klient " << i + 1 << ": " << endl;
        cout << "Imię: " << klienci[i].imie << endl;
        cout << "Nazwisko: " << klienci[i].nazwisko << endl;
        cout << "Adres: " << klienci[i].adres << endl;
        cout << "Płeć: " << klienci[i].plec << endl;
        cout << endl;
    }
}


int main()
{
    vector <Klient> klienci;
    vector <Produkty> produkty;
    int wybor;

    klienci = klient.wczytanie_klientow();
    produkty = produkt.wczytaj_produkty();

    do {
        cout << "Menu wielokrotnego wyboru: " << endl;
        cout << "1. Dodanie klienta" << endl;
        cout << "2. Modyfikowanie klienta" << endl;
        cout << "3. Pokaz klientow" << endl;
        cout << "4. Zapis klientow w postaci tekstowej" << endl;
        cout << "5. Zapis klientow w postaci binarnej" << endl;
        cout << "6. Dodanie zamowienia" << endl;
        cout << "7. Modyfikowanie zamowienia" << endl;
        cout << "8. Pokaz produktow" << endl;
        cout << "9. Pokaz zamowien" << endl;
        cout << "10. Usuniecie zamowienia" << endl;
        cout << "11. Usuniecie klienta" << endl;
        cout << "0. Wyjscie" << endl;
        cout << "Wybor: ";
        cin >> wybor;

        switch (wybor) {
        case 1:{
            klient.dodanie_klienta(klienci);
            sprawdz_wektor(klienci);
            break;
        }
        case 2:{
            klient.edycja_klienta(klienci);
            break;
        }
        case 3:{
            klient.pokaz_klientow(klienci);
            break;
        }
        case 4:{
            zapis.zapis_tekstowy(klienci);
            break;
        }
        case 5:{
            zapis.zapis_binarny(klienci);
            break;
        }
        case 6:{
            Zamowienie zamowienie;
            if(!klienci.empty()){
                string imie, nazwisko;
                cout << "Podaj imie: ";
                cin >> imie;
                cout << "Podaj nazwisko: ";
                cin >> nazwisko;

                for(int i = 0; i < klienci.size(); i++) {
                    if(klienci[i].imie == imie && klienci[i].nazwisko == nazwisko) {
                        zamowienie.dodaj_zamowienie(klienci[i], produkty);
                        break;
                    } else {
                        cout << "Nie znaleziono takiego klienta!" << endl;
                    }
                    break;
                }
            }
            break;
        }
        case 7:{
            Zamowienie zamowienie;
            if(!klienci.empty()){
                string imie, nazwisko;
                cout << "Podaj imie: ";
                cin >> imie;
                cout << "Podaj nazwisko: ";
                cin >> nazwisko;

                for(int i = 0; i < klienci.size(); i++) {
                    if(klienci[i].imie == imie && klienci[i].nazwisko == nazwisko) {
                        zamowienie.modyfikuj_zamowienie(klienci[i]);
                        break;
                    } else {
                        cout << "Nie znaleziono takiego klienta!" << endl;
                    }
                    break;
                }
            }
            break;
        }
        case 8:{
            Produkty produkt("", 0, 0);
            produkt.wyswietl_produkty(produkty);
            break;
        }
        case 9:{
            Zamowienie zamowienie;
            if(!klienci.empty()){
                string imie, nazwisko;
                cout << "Podaj imie: ";
                cin >> imie;
                cout << "Podaj nazwisko: ";
                cin >> nazwisko;

                for(int i = 0; i < klienci.size(); i++) {
                    if(klienci[i].imie == imie && klienci[i].nazwisko == nazwisko) {
                        zamowienie.pokaz_zamowienia(klienci[i]);
                        break;
                    } else {
                        cout << "Nie znaleziono klientow!" << endl;
                    }
                    break;
                }
            }
            break;
        }
        case 10:{
            Zamowienie zamowienie;
            zamowienie.usun_zamowienie(klienci);
            break;
        }
        case 11:{
            klient.usun_klienta(klienci);
            break;
        }
        case 0:{
            cout << "Wyjscie z programu!" << endl;
            break;
        }
        }
    } while (wybor != 0);

    return 0;
}
