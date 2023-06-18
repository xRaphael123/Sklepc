#include "klient.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <limits>

Klient::Klient()
{

}

void Klient::dodanie_klienta(vector <Klient>& klienci)
{
    Klient klient;
    cout << "Podaj imie: ";
    cin >> klient.imie;
    cout << "Podaj nazwisko: ";
    cin >> klient.nazwisko;
    cout << "Podaj adres: ";
    cin.ignore();
    getline(cin, klient.adres);
    while (klient.plec != 'M' && klient.plec != 'K') {
        cout << "Podaj plec (M/K): ";
        cin >> klient.plec;
        if(klient.plec != 'M' && klient.plec != 'K') {
            cout << "Podaj poprawna plec" << endl;
        }
    }
    klienci.push_back(klient);
    cout << "Dodano klienta!" << endl;
}

void Klient::edycja_klienta(vector <Klient>& klienci)
{
    cout << "Podaj imie klienta do zmodyfikowania: ";
    cin >> imie;
    cout << "Podaj nazwisko klienta do zmodyfikowania: ";
    cin >> nazwisko;
    for(int i = 0; i < klienci.size(); i++) {
        if(klienci[i].imie == imie && klienci[i].nazwisko == nazwisko) {
            cout << "Dodaj nowy adres: ";
            cin.ignore();
            getline(cin, klienci[i].adres);
            cout << "Zmodyfikowano klienta!" << endl;
            return;
        } else {
            cout << "Nie znaleziono klienta!" << endl;
        }
    }
}

void Klient::pokaz_klientow(vector<Klient> &klienci)
{
    if (klienci.empty()) {
            cout << "Brak klientow do wyswietlenia." << endl;
        } else {
            cout << "Lista klientow:" << endl;
            for (const Klient& klient : klienci) {
                cout << "Imie: " << klient.imie << endl;
                cout << "Nazwisko: " << klient.nazwisko << endl;
                cout << "Adres: " << klient.adres << endl;
                cout << "Plec: " << klient.plec << endl;
                cout << endl;
            }
        }
}

void Klient::usun_klienta(vector<Klient>& klienci)
{
    cout << "Podaj imie klienta do usuniecia: ";
    string imie;
    cin >> imie;
    cout << "Podaj nazwisko klienta do usuniecia: ";
    string nazwisko;
    cin >> nazwisko;

    for (auto it = klienci.begin(); it != klienci.end(); ++it)
    {
        if (it->imie == imie && it->nazwisko == nazwisko)
        {
            if (it->zamowienia.empty()) {
                klienci.erase(it);
                cout << "Usunieto klienta!" << endl;
                return;
            } else {
                cout << "Nie mozna usunac klienta, poniewaz ma zamowienia!" << endl;
                return;
            }
        }
    }

    cout << "Nie znaleziono klienta o podanym imieniu i nazwisku!" << endl;
}



vector<Klient> Klient::wczytanie_klientow()
{
    vector<Klient> klienci;
    ifstream plik("klienci.txt");
    if (plik.is_open()) {
        string imie, nazwisko, adres;
        char plec;
        while (getline(plik, imie) && getline(plik, nazwisko) && getline(plik, adres) && plik.get(plec)) {
            plik.ignore(numeric_limits<streamsize>::max(), '\n');
            Klient klient;
            klient.imie = imie;
            klient.nazwisko = nazwisko;
            klient.adres = adres;
            klient.plec = plec;

            int liczba_zamowien;
            plik >> liczba_zamowien;
            plik.ignore(numeric_limits<streamsize>::max(), '\n');
            for (int i = 0; i < liczba_zamowien; i++) {
                Zamowienie zamowienie;
                getline(plik, zamowienie.nazwa);
                plik >> zamowienie.ilosc >> zamowienie.vat >> zamowienie.cena;
                plik.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(plik, zamowienie.metoda);
                getline(plik, zamowienie.data);
                plik >> zamowienie.cenatotalna;
                plik.ignore(numeric_limits<streamsize>::max(), '\n');
                klient.zamowienia.push_back(zamowienie);
            }

            klienci.push_back(klient);
        }
        plik.close();
        cout << "Udało się wczytać klientów z pliku 'klienci.txt'!" << endl;
    } else {
        cout << "Nie udało się wczytać klientów z pliku 'klienci.txt'!" << endl;
    }
    return klienci;
}


