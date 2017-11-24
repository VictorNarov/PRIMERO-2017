#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <cctype>
#include <conio.h>

using namespace std;

class PalabraOculta{

char palabraSecreta[30];
int letras;
int Puntos;

public:
    void Iniciar();
    int Jugar();
    void MostrarSecreta();
    bool victoria;

};

void PalabraOculta::Iniciar(){
int i;
char caracter;
letras = 0;

cout << "\nJugador 1: Teclea la palabra y pulsa espacio para terminar -> ";
for(i=0; caracter != ' '; i++){
    caracter = getch();
    if( caracter != ' ' ){
    palabraSecreta[i] = caracter;
    letras++;
        }
    }
Puntos = 9;
strupr(palabraSecreta);
}

int PalabraOculta::Jugar(){
int i;
char intento;
bool encontrada;


char palabraMostrada[30];//Array mostrado

for(i=0; i<letras; i++)
    palabraMostrada[i] = '_';

do{

cout <<  "\nPuntos: " << Puntos<<"\n\nJugador 2: Intrduce la letra a intentar -> ";
cout << "\nPalabra: \t\t";
for(i=0; i<letras; i++) cout << palabraMostrada[i];

intento = toupper(getch());

encontrada = false;

for(i=0; i<letras; i++){

    if(palabraSecreta[i] == intento){
    palabraMostrada[i] = intento;
    encontrada = true;
    cout << "\n\nEncontrada en la posicion " << i;
    }
}
    if(!encontrada){
    Puntos--;
    cout << "\n\nLa letra no esta en la palabra oculta! -1 Punto";
    }
    victoria = true;
    for(i=0; i<letras; i++)
    if(palabraMostrada[i] == '_') victoria = false;

}while(Puntos > 0 && !victoria);

return Puntos;

}

void PalabraOculta::MostrarSecreta(){
if(Puntos <= 0){
cout << "\nLa palabra oculta era: ";
for(int i=0; i<letras; i++) cout << palabraSecreta[i];
}
else{
    cout << "\nEnhorabuena, has adivinado la palabra: ";
    for(int i=0; i<letras; i++) cout << palabraSecreta[i];
}

}

int main(){

PalabraOculta pepe;
pepe.Iniciar();
pepe.Jugar();
pepe.MostrarSecreta();



}
