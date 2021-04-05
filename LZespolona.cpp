#include "LZespolona.hh"


ostream& operator << (ostream& StrWyj, LZespolona liczba)
{
  StrWyj<< "(" << liczba.re<<showpos<<liczba.im<<"i\n";
  return StrWyj;
}
/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}
void Wyswietl(LZespolona skl)
{
  cout<<"("<<skl.re<<showpos<<skl.im<<"i)"<<endl;
}
bool operator ==(LZespolona Skl1, LZespolona Skl2)
{
  
  if((Skl1.re == Skl2.re)&&(Skl1.im == Skl2.im))
  {
    return true;

  }
  else return false;
}
LZespolona Wczytaj()
{
  LZespolona Skl;
  cout<<"czesc rzeczywista :\t";
  cin>>Skl.re;
  cout<<"czesc urojona :\t";
  cin>>Skl.im;
  return Skl;
}
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re * Skl2.re - (Skl1.im * Skl2.im);
  Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;
  return Wynik;
}
LZespolona  Sprzezenie (LZespolona  Skl)
{
  LZespolona  Wynik;

  Wynik.re = Skl.re;
  Wynik.im = -Skl.im;
  return Wynik;
}

LZespolona Modul (LZespolona  Skl)

{
  LZespolona  Wynik;

  Wynik.re = sqrt((Skl.re*Skl.re)+(Skl.im*Skl.im));
  return Wynik;
}

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona Wynik;
  Wynik = Sprzezenie(Skl2);
  Wynik = Wynik * Wynik;
  Wynik = Skl1 * Modul(Skl2) / Wynik;


  return Wynik;
}

LZespolona  operator / (LZespolona  Skl1,  double  Skl2){
  if (Skl2 == 0){
    throw std::runtime_error("Math error: Attempted to divide by Zero\n");
  }
  LZespolona  Wynik;
  Wynik.re = Skl1.re / Skl2;
  Wynik.im = Skl1.im / Skl2;
  return Wynik;
}
void WczytajTenZnak(std::istream &StrmWej, char Znak){
  char CzytanyZnak = ' ';
  StrmWej >> CzytanyZnak;
  if (CzytanyZnak != Znak) { 
    StrmWej.setstate(std::ios::failbit);}
}
std::istream& operator >> (std::istream &StrmWej, LZespolona &LZesp){
  //Korzystamy tutaj z tego, że jak strumień jest w stanie fail, to żadna operacja czytania już się nie wykona.
  WczytajTenZnak(StrmWej,'('); 
  StrmWej >> LZesp.re;
  StrmWej >> LZesp.im;
  WczytajTenZnak(StrmWej,'i');
  WczytajTenZnak(StrmWej,')');
  return StrmWej;
}
