#ifndef PRODUKTY_H
#define PRODUKTY_H

#include <vector>
using namespace std;
#include <string>

class Produkty
{
public:
    string nazwa;
    double cena, vat;
    Produkty(const string& nazwa, double cena, double vat);
    vector<Produkty> wczytaj_produkty();
    void wyswietl_produkty(const vector<Produkty>& produkty);
};

#endif // PRODUKTY_H
