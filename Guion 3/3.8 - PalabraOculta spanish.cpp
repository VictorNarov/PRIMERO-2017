#include <iostream>
#include <string.h>
#include<conio.h>
#include<cstring>
#include<windows.h>
#include<cctype>

using namespace std;

typedef char cadena[30];

class palabraoculta{

cadena palabrasecreta;
int puntos;

public:

    void iniciar(cadena palabra);    //ESTE METODO CONTIENE UN PARAMETRO, EL PROBLEMA NO LO DA, SE HA USADO APLICANDO LO DADO EN EL TEMA 5
    int jugar();


    void mostrarsecreta();

};
void palabraoculta::iniciar(cadena palabra){

puntos=9;
int i=0;

do{

       palabra[i] =getch();
       strupr(palabra);  //convierte en mayuscula cada letra que lea por teclado

       palabrasecreta[i] = palabra[i];

        if(palabra[i]!= char(8)){   //si no presiona back space

              cout<<"-"; // muestra por pantalla
               i++;
        }

        else if(i>0){
        cout<<char(8)<<char(32)<<char(8);  //sirve para borrar cuando presione backspace
         i--;
        }
        }while(palabra[i-1]!=13);  // si presiona ENTER sale

palabra[i-1] = char(00);  //para que no me muestre basura
palabrasecreta[i-1]=char(00);   //para que no me muestre basura

system("cls");   //Limpia de pantalla todo lo anterior.
}


int palabraoculta::jugar(){
    int numeroletras;


    numeroletras= strlen(palabrasecreta);  //guarda en la variable numeroletras el numero de letras de palabrasecreta

    char letra,palabra_guion[numeroletras];

    for(int i=0;i<numeroletras;i++){    //guarda en palabra_guion tantos guiones'-' como letras tiene palabrasecreta
        palabra_guion[i]='-';
    }

    palabra_guion[numeroletras]=char(00);
do{

int i=0;
bool encontrado=false;
cout<<"*******Tienes "<<puntos<<" puntos, no llegues a 0!*********";
cout<<"\n\nLa palabra a adivinar: "<<palabra_guion; //sirve para que no me genere basura
cout<<"\n\nIntroduzca una letra:";
cin>>letra;

    while((i<numeroletras)&& !encontrado){
        if(palabrasecreta[i]==toupper(letra)){
            palabra_guion[i]=toupper(letra);
            encontrado=true;


        }

        i++;

        }
        if(encontrado){
        for(int i=0;i<=numeroletras;i++){
            if(palabrasecreta[i]==toupper(letra)){
                palabra_guion[i] = toupper(letra);
            }
        }
        }
        system("cls");
        if(encontrado)  //CONTADOR DE PUNTOS
            puntos++;
        else puntos--;

    }while((strcmp(palabra_guion,palabrasecreta))!=0 && puntos!=0);   //EL JUEGO TERMINA SI ADIVINA LA PALABRA O SI LOS PUNTOS LLEGAN A 0

    return puntos;

}



void palabraoculta::mostrarsecreta(){

cout<<"La palabra secreta es: "<<palabrasecreta;

}





int main()

{
    int puntos_finales;
    palabraoculta juego;
    cadena palabramain;


cout<<"Introduzca la palabra a adivinar: ";
juego.iniciar(palabramain);
puntos_finales= juego.jugar();
juego.mostrarsecreta();

if(puntos_finales>0){
cout<<"\n\nEnhorabuena ! has adivinado la palabra!";
cout<<"\nTus puntos son: "<<puntos_finales<<endl;
}else
cout<<"\n\nSuerte la proxima!"<<endl;



return 0;

}

