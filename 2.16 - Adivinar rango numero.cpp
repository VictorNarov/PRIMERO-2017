#include <iostream>
#include <limits>
using namespace std;

class Juego {



public:
    int ValorMin, ValorMax, ValorMedio;
    void PedirExtremos();
    char AdivinarNumero();
    bool CompruebaEsMenor();
    bool CompruebaEsMayor();
    char comparacion;
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

    ValorMedio = (ValorMin + ValorMax)/2;

    do{
    cout << "Estoy pensando en: "<<ValorMedio<<", tu numero es mayor(>), menor(<) o igual(=)? ->";
    cin >> comparacion;
    if(comparacion!='>' && comparacion!='<' && comparacion != '='){
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Evita un bucle infinito
            cout << "Caracter no valido...\n";
            }
    }while((comparacion!='>' && comparacion!='<' && comparacion != '='));
    return comparacion;
}

bool Juego::CompruebaEsMenor(){

    ValorMax = ValorMedio - 1;
    if(ValorMin <= ValorMax) return true;
    else return false;

}

bool Juego::CompruebaEsMayor(){

    ValorMin = ValorMedio + 1;
    if(ValorMin <= ValorMax) return true;
    else return false;

}

int main(){
char continuar='s';
Juego hl3;

while(continuar=='s'){
hl3.PedirExtremos();
do{
hl3.AdivinarNumero();
if (hl3.comparacion == '=')
    cout <<"Lo adivine pinches gringos\n";
else if (hl3.comparacion == '<'){
    if (!hl3.CompruebaEsMenor()){
            cout <<"Usted intenta enganiarme, gringo";
            hl3.comparacion = '=';
    }
    else hl3.ValorMax = hl3.ValorMedio;
}

else if (hl3.comparacion == '>'){
    if (!hl3.CompruebaEsMayor()){
    cout <<"Usted intenta enganiarme, gringo";
    hl3.comparacion = '=';
    }
    else hl3.ValorMin = hl3.ValorMedio;
}
else cout<< "Error wey";
}while(hl3.comparacion != '=');

cout <<"\nDeseas seguir jugando (s/n) -> ";
cin >> continuar;
}
cout << "\nAdios!";
return 0;
}
