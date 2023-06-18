#ifndef KLIENT_H
#define KLIENT_H

#include <string>
#include <iostream>
#include <vector>
#include "zamowienie.h"
#include "produkty.h"
using namespace std;

class Zamowienie;

class Klient
{
public:
    string imie, nazwisko, adres;
    char plec;
    vector<Zamowienie> zamowienia;
    Klient();
    void dodanie_klienta(vector <Klient>& klienci);
    void edycja_klienta(vector <Klient>& klienci);
    void pokaz_klientow(vector <Klient>& klienci);
    void usun_klienta(vector<Klient>& klienci);
    vector<Klient> wczytanie_klientow();
};

#endif // KLIENT_H
