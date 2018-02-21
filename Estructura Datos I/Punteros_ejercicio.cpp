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
    Proveedor(int idni)
    {
        dni=idni;
        strcpy(nombre, "");
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
    pProveedor = new Proveedor();

    //3. Tabla dinamica 100 clientes
    Cliente *tablaClientes = new Cliente[100];

    //4. Tabla dinamica de 1000 punteros a clientes incializada a null
    Cliente *tablaPunterosC[1000];
    for (int i=0; i<1000; i++)
        tablaPunterosC[i]=NULL;

    //5. Tabla dinamica de 120 punteros a Prooveedores y crear 120 proveedores
    Proveedor *tablaPunterosP[120];
    for (int i=0; i<120; i++)
        tablaPunterosP[i] = new Proveedor();//Actua el constructor sin parametrizar

    //Borrar las tablas dinamicas 4 y 5
    delete [] tablaClientes;
    delete [] tablaPunterosP;

    int dni = tablaPunterosP[20]->getdni();
    cout << dni;

    return 0;
}
