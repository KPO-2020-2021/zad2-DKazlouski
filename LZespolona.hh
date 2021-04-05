#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
#include <cmath>
using namespace std;


/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

ostream& operator << (ostream& StrWyj, LZespolona liczba);
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona   Modul (LZespolona  Skl);
void Wyswietl(LZespolona skl);
LZespolona Wczytaj();
LZespolona  Sprzezenie (LZespolona  Skl);
bool operator ==(LZespolona Skl1, LZespolona Skl2);
LZespolona  operator / (LZespolona  Skl1,  double  Skl2);
std::istream& operator >> (std::istream &StrmWej, LZespolona &LZesp);
void WczytajTenZnak(std::istream &StrmWej, char Znak);
#endif
