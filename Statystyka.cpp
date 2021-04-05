#include "Statystyka.hh"

void Wynik(Stat dane)
{
    double wynik;

    wynik = ((double)dane.prawidlowych/((double)dane.nieprawidlowych+(double)dane.prawidlowych));

    cout<<"Liczba dobrych odpowiedzi"<<wynik<<"\n w proc\t"<<wynik *100<<" %"<<endl;
}