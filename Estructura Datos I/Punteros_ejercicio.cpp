//  Autor: Vik
//  Fecha: 21/02/18

#include <iostream>
#include <cstring>

using namespace std;

typedef char cadena[40];
class Proveedor
{
    int dni;
    cadena nombre;
public:
    Proveedor()
    {
        dni=100;
        strcpy(nombre, "");
    }
    Proveedor(cadena pnombre, int pdni)
    {
        dni=pdni;
        strcpy(nombre, pnombre);
    }
    int getdni() {return dni;}
};

class Cliente
{
    cadena nombre;
public:
    Cliente()
    {
        strcpy(nombre, "");
    }
};


int main()
{
    //1. Declaracion de punteros a NULL
    float *pReal=NULL;
    int *pEntero=NULL;
    Proveedor *pProveedor=NULL;
    //Polinomio *pPolinomio=NULL;


    //2. Reserva de memoria dinamica heap
    pReal = new float;
    pEntero = new int;
    pProveedor = new Proveedor("Pepe",899899898);

    //3. Tabla dinamica 100 clientes
    Cliente *tablaClientes = new Cliente[100];

    //4. Tabla dinamica de 1000 punteros a clientes incializada a null
    //TABLA ESTAICA: Cliente *tablaPunterosC[1000];
    //Cliente* es el tipo y el segundo * indica que es dinamico
    Cliente **tablaPunterosC = new Cliente*[1000];//Tabla dinamica de punteros. Cliente* es el tipo de dato de cada casilla
    for (int i=0; i<1000; i++)
        tablaPunterosC[i]=NULL;

    //5. Tabla dinamica de 120 punteros a Prooveedores y crear 120 proveedores
    Proveedor **tablaPunterosP = new Proveedor*[120];
    for (int i=0; i<120; i++)
        tablaPunterosP[i] = new Proveedor();//Actua el constructor sin parametrizar

    //Borrar las tablas dinamicas 4 y 5
    delete [] tablaClientes;

    //delete [] tablaPunterosP; Solamente borra la tabla, pero no los datos a los que apunta
    for(int i=0; i<120; i++)
        delete tablaPunterosP[i];//Libera la memoria donde apunta
    delete [] tablaPunterosP;//Borrar la propia tabla

    //Comprobar como actua el constructor
    int dni = tablaPunterosP[20]->getdni();
    cout << dni;

    return 0;
}
