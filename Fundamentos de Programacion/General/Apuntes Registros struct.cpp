#include <iostream>

using namespace std;


class Persona{

char sexo;
int edad;
float saldo;
int tlf;

};


struct Persona2{/*Sus variables (campos)son publicas por defecto,
                    se pueden editar desde el main */
char sexo;
int edad;
float saldo;
int tlf;


 };


 struct Infopersona{

 float peso, altura;

 struct nacimiento{

    int dia, mes, anio;
    };

 };

int main(){

Persona tu;
Persona2 yo = {'v',18,3000,123};

//Infopersona persona = {65,2,{01,11,1999}}

float tabla[4][8] = {{0,1,2,3,4,5,6,7}, {8,9,10,11}};//Numero de filas, columnas

tabla[2][3]=4;

Persona2[100];//declarar 100 objetos


}
