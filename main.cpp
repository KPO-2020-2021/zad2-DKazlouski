#include <iostream>
#include "BazaTestu.hh"
#include "Statystyka.hh"

using namespace std;




int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona liczba1, liczba2;
  Stat statystyka;
  statystyka.prawidlowych = 0;
  statystyka.nieprawidlowych =0;
  try{
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    
   cout<<"Podaj wynik tej operacji"<<endl;
   cout<<WyrZ_PytanieTestowe<<endl;
   liczba1=Wczytaj();
   
   liczba2= Oblicz(WyrZ_PytanieTestowe);
   if(liczba1==liczba2)
   {
     statystyka.prawidlowych= statystyka.prawidlowych+1;
   }
   else
   statystyka.nieprawidlowych= statystyka.nieprawidlowych+1;
  }
  }
  catch (runtime_error& e) { 
  
        // prints that exception has occurred 
        // calls the what function 
        // using runtime_error object 
        cout << "Exception occurred" << endl 
             << e.what(); 
  } 
  Wynik(statystyka);
  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
