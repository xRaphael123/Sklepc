#ifndef ZAMOWIENIE_H
#define ZAMOWIENIE_H
#include <vector>
#include "klient.h"
#include "produkty.h"

class Klient;

class Zamowienie
{
public:
    string nazwa, data, metoda;
    int ilosc;
    double vat, cena;
    double cenatotalna;
    Zamowienie();
    void dodaj_zamowienie(Klient& klient, const vector<Produkty>& produkty);
    void modyfikuj_zamowienie(Klient& klient);
    void pokaz_zamowienia(const Klient& klient);
    void usun_zamowienie(vector<Klient>& klienci);
};

#endif // ZAMOWIENIE_H
