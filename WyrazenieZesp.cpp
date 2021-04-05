#include "WyrazenieZesp.hh"
#include "LZespolona.hh"

LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
    LZespolona Skl;
    switch(WyrZ.Op)
    {
        case Op_Mnoz:
        Skl =  WyrZ.Arg1*WyrZ.Arg2;
        break;

        case Op_Dodaj:
        Skl = WyrZ.Arg1+WyrZ.Arg2;
        break;

        case Op_Dziel:
        Skl = WyrZ.Arg1/WyrZ.Arg2;
        break;

        case Op_Odejmij:
        Skl = WyrZ.Arg1-WyrZ.Arg2;
        break;
    }
    return Skl;
   
}

ostream& operator<<(ostream& StrWyj, WyrazenieZesp WyrZ)
{
    StrWyj<< WyrZ.Arg1;
    StrWyj<< Wybor(WyrZ.Op);
    StrWyj<< WyrZ.Arg2<<endl;
    return StrWyj;
}
char Wybor(Operator op)
{
    char wyb;
    switch(op)
    {
        case Op_Mnoz:
        wyb = '*';
        
        break;

        case Op_Dodaj:
        wyb = '+';
        
        break;

        case Op_Dziel:
        wyb = '/';
       
        break;

        case Op_Odejmij:
        wyb = '-';
        
        break;
    }
    return wyb;
}
Operator WyborOp()
{
    Operator op;
    char znak;
    cin>>znak;
    switch(znak)
    {
        case '+':
        op = Op_Dodaj;
        
        break;

        case '/':
        op = Op_Dziel;
        break;

        case '-':
        op = Op_Odejmij;
        break;

        case '*':
        op = Op_Dziel;
        break;
    }
    return op;
}
void Wyswietl(WyrazenieZesp  WyrZ)
{

    Wyswietl(WyrZ.Arg1);
    cout<<Wybor(WyrZ.Op);
    Wyswietl(WyrZ.Arg2);

}

WyrazenieZesp WczytajWyr()
{
    WyrazenieZesp WyrZ;
    WyrZ.Arg1 = Wczytaj();
    WyrZ.Op = WyborOp();
    WyrZ.Arg2 = Wczytaj();
    return WyrZ;
}