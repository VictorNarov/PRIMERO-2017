#include <iostream>
#include <limits>
using namespace std;

class Juego {
    int ValorMin, ValorMax, ValorMedio;


public:

    void PedirExtremos();
    char AdivinarNumero();
    bool CompruebaEsMenor();
    bool CompruebaEsMayor();
};

void Juego::PedirExtremos(){
    do{
    cout << "Introduce valor minimo: ";
    cin >> ValorMin;
    cout << "Introduce valor maximo: ";
    cin >> ValorMax;
    if (ValorMin > ValorMax) cout << "Error...\n";
    }while(ValorMin > ValorMax);

}

char Juego::AdivinarNumero(){

    char comparacion;

    ValorMedio = (ValorMin + ValorMax)/2;

    do{
    cout << "Estoy pensando en: "<<ValorMedio<<", tu numero es mayor(>), menor(<) o igual(=)? ->";
    cin >> comparacion;
    if(comparacion!='>' && comparacion!='<' && comparacion != '='){
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Evita un bucle infinito
            cout << "Caracter no valido...\n";
            }
    }while((comparacion!='>' && comparacion!='<'&& comparacion != '='));
    return comparacion;
}

bool Juego::CompruebaEsMenor(){
    bool notrampa;
    ValorMax = ValorMedio - 1;
    if(ValorMin < ValorMax) notrampa = true;
    else notrampa = false;

    return notrampa;

}

bool Juego::CompruebaEsMayor(){
    bool notrampa;
    ValorMin = ValorMedio + 1;
    if(ValorMin < ValorMax) notrampa = true;
    else notrampa = false;

    return notrampa;
}

int main(){
char continuar, respuesta;
bool terminar;
Juego juego;

do{
terminar=false;
juego.PedirExtremos();
do{
respuesta=juego.AdivinarNumero();
if (respuesta == '=')
{
    cout <<"He adivinado el numero!\n";
    terminar = true;
}
else if (respuesta == '<')
{
    if (!juego.CompruebaEsMenor())
    {
            cout <<"Estas haciendo trampa!";
            terminar = true;
    }
}
else if (respuesta == '>')
{
    if (!juego.CompruebaEsMayor())
    {
    cout <<"Estas haciendo trampa!";
    terminar = true;
    }
}
else cout<< "\nERROR\n";
}while(!terminar);

cout <<"\nDeseas seguir jugando (s/n) -> ";
cin >> continuar;
}while(continuar=='s');
cout << "\nAdios!";
return 0;

}
