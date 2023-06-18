#include "produkty.h"
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

vector<Produkty> Produkty::wczytaj_produkty()
{
    string nazwa;
    double cena, vat;
    vector<Produkty> produkty;
    ifstream plik("produkty.txt");
    if (plik.is_open()) {
        while (plik >> nazwa >> cena >> vat) {
            Produkty produkt(nazwa, cena, vat);
            produkty.push_back(produkt);
        }
        plik.close();
        cout << "Pobrano produkty z pliku 'produkty.txt'" << endl;
    } else {
        cout << "Nie udało się pobrac produktów z pliku 'produkty.txt'" << endl;
    }
    return produkty;
}


void Produkty::wyswietl_produkty(const vector<Produkty> &produkty)
{
    cout << "Dostepne produkty: " << endl;
    for(int i = 0; i < produkty.size(); i++) {
        cout << "Nazwa: " << produkty[i].nazwa << endl;
        cout << "Cena: " << produkty[i].cena << endl;
        cout << "VAT: " << produkty[i].vat << endl;
        cout << "-----" << endl;
    }
}


Produkty::Produkty(const std::string& nazwa, double cena, double vat)
    : nazwa(nazwa), cena(cena), vat(vat)
{

}



