#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH
#include <iostream>
using namespace std;

struct Stat
{
    int prawidlowych;
    int nieprawidlowych;
};
void Wynik(Stat dane);
#endif