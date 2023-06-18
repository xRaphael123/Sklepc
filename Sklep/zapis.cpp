#include "zapis.h"
#include <iostream>
#include <fstream>
#include "klient.h"
#include <vector>

using namespace std;

Zapis::Zapis()
{

}

void Zapis::zapis_tekstowy(vector<Klient>& klienci)
{
    ofstream plik("klienci.txt", ios::trunc);
    if (plik.is_open()) {
        for (const Klient& klient : klienci) {
            plik << klient.imie << "\n" << klient.nazwisko << "\n" << klient.adres << "\n" << klient.plec << endl;
            plik << klient.zamowienia.size() << endl;
            for (const Zamowienie& zamowienie : klient.zamowienia) {
                plik << zamowienie.nazwa << "\n" << zamowienie.ilosc << "\n" << zamowienie.vat << "\n" << zamowienie.cena << "\n"
                     << zamowienie.metoda << "\n" << zamowienie.data << "\n" << zamowienie.cenatotalna << endl;
            }
        }
        plik.close();
        cout << "Zapisano klientów do pliku 'klienci.txt'" << endl;
    } else {
        cout << "Nie udało się zapisać klientów do pliku 'klienci.txt'" << endl;
    }
}



void Zapis::zapis_binarny(vector<Klient> &klienci)
{
    ofstream plik("kilenci.bin", ios::binary);


    if(plik.is_open()){
        for(int i=0; i < klienci.size(); i++)
        {
            plik.write(reinterpret_cast<char*>(&klienci), sizeof(Klient));
        }
        plik.close();
        cout << "Zapisano klientow do pliku 'klienci.bin'" << endl;
    }
    else {
        cout << "Nie udalo sie zapisac klientow do pliku 'klienci.bin'" << endl;
    }
}
