#include "zamowienie.h"
#include "produkty.h"
#include "klient.h"
#include <string>


Zamowienie::Zamowienie()
{

}

void Zamowienie::dodaj_zamowienie(Klient &klient, const vector<Produkty> &produkt)
{
    Zamowienie zamowienie;
    string nazwa;
    cout << "Podaj nazwe produktu: ";
    cin.ignore();
    getline(cin, nazwa);

    bool znalezione = false;
    for(int i = 0; i < produkt.size(); i++) {
        if(produkt[i].nazwa == nazwa) {
            zamowienie.nazwa = produkt[i].nazwa;
            zamowienie.cena = produkt[i].cena;
            zamowienie.vat = produkt[i].vat;
            znalezione = true;
            break;
        }
    }

    if(!znalezione){
        cout << "Nie znaleziono takiego produktu!" << endl;
        return;
    }

    cout << "Podaj ilosc: ";
    cin >> zamowienie.ilosc;

    while (zamowienie.metoda != "Karta" && zamowienie.metoda != "Gotowka") {
        cout << "Podaj metode zaplaty (Karta/Gotowka): ";
        cin >> zamowienie.metoda;
        if(zamowienie.metoda != "Karta" && zamowienie.metoda != "Gotowka") {
            cout << "Podaj poprawna metode zaplaty" << endl;
        }
    }
    cout << "Podaj date zamowienia: ";
    cin.ignore();
    getline(cin, zamowienie.data);

    zamowienie.cenatotalna = zamowienie.cena * zamowienie.ilosc * (1 + zamowienie.vat);

    klient.zamowienia.push_back(zamowienie);

    cout << "Dodano nowe zamowienie!" << endl;
}

void Zamowienie::modyfikuj_zamowienie(Klient &klient)
{
    int numer_zamowienia;
    cout << "Podaj numer zamowienia: ";
    cin >> numer_zamowienia;

    if(numer_zamowienia >= 0 && numer_zamowienia < klient.zamowienia.size()) {
        Zamowienie& zamowienie = klient.zamowienia[numer_zamowienia];


        cout << "Podaj ilosc: ";
        cin >> zamowienie.ilosc;
        while (zamowienie.metoda != "Karta" && zamowienie.metoda != "Gotowka") {
            cout << "Podaj metode zaplaty (Karta/Gotowka): ";
            cin >> zamowienie.metoda;
            if(zamowienie.metoda != "Karta" && zamowienie.metoda != "Gotowka") {
                cout << "Podaj poprawna metode zaplaty" << endl;
            }
        }
        cout << "Podaj date zamowienia: ";
        cin.ignore();
        getline(cin, zamowienie.data);

        zamowienie.cenatotalna = zamowienie.cena * zamowienie.ilosc * (1 + zamowienie.vat);

        cout << "Zamowienie zostalo zmodyfikowane!" << endl;
    }
    else {
        cout << "Podano bledny numer zamowienia" << endl;
    }
}

void Zamowienie::pokaz_zamowienia(const Klient &klient)
{
    cout << "Zamowienie dla osoby " << klient.imie << " " << klient.nazwisko << endl;
    for(int i = 0; i < klient.zamowienia.size(); i++) {
        cout << "Produkt: " << klient.zamowienia[i].nazwa << endl;
        cout << "Ilosc: " << klient.zamowienia[i].ilosc << endl;
        cout << "Vat: " << klient.zamowienia[i].vat << endl;
        cout << "Cena produktu: " << klient.zamowienia[i].cena << endl;
        cout << "Metoda zaplaty: " << klient.zamowienia[i].metoda << endl;
        cout << "Data zamowienia: " << klient.zamowienia[i].data << endl;
        cout << "Cena calkowita: " << klient.zamowienia[i].cenatotalna << endl;
        cout << "-------" << endl;
    }
}

void Zamowienie::usun_zamowienie(vector<Klient>& klienci)
{
    string imie, nazwisko;
    int numer_zamowienia;

    cout << "Podaj imię klienta: ";
    cin >> imie;
    cout << "Podaj nazwisko klienta: ";
    cin >> nazwisko;
    cout << "Podaj numer zamówienia do usunięcia: ";
    cin >> numer_zamowienia;

    for (auto& klient : klienci)
    {
        if (klient.imie == imie && klient.nazwisko == nazwisko)
        {
            if (numer_zamowienia >= 0 && numer_zamowienia < klient.zamowienia.size())
            {
                klient.zamowienia.erase(klient.zamowienia.begin() + numer_zamowienia);
                cout << "Zamówienie zostało usunięte!" << endl;
                return;
            }
            else
            {
                cout << "Podano błędny numer zamówienia." << endl;
                return;
            }
        }
    }

    cout << "Nie znaleziono klienta o podanym imieniu i nazwisku." << endl;
}

