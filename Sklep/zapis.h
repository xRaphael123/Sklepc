#ifndef ZAPIS_H
#define ZAPIS_H
#include <string>
#include "klient.h"
#include <vector>
using namespace std;


class Zapis
{
public:
    Zapis();
    void zapis_tekstowy(vector <Klient>& klienci);
    void zapis_binarny(vector <Klient>& klienci);
};

#endif // ZAPIS_H
