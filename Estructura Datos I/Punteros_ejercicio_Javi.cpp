#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
typedef char cadena[40];

class Proveedor {

    int dni;
    cadena nombre;

public:

    Proveedor() {
        dni=0;
        strcpy(nombre, "");
    }
    Proveedor(int ndni, cadena nom) {
        dni=ndni;
        strcpy(nombre, nom);
    }

};

class Cliente {

    int dni;
    cadena nombre;

public:

    Cliente() {
        dni=0;
        strcpy(nombre, "");
    }
    Cliente(int ndni, cadena nom) {
        dni=ndni;
        strcpy(nombre, nom);
    }

};

class Polinomio {

    int a, b, c;
    float sol1, sol2;

public:

    Polinomio() {
        a=b=c=sol1=sol2=0;
    }

    Polinomio(int aext, int bext, int cext)   {
        a=aext;
        b=bext;
        c=cext;
        sol1=sol2=0;
    }

    solucionar(float &sol1ext, float &sol2ext)  {
        sol1ext=sol1=(-b+sqrt(b*b-4*a*c))/(2*b);
        sol2ext=sol2=(-b-sqrt(b*b-4*a*c))/(2*b);
    }

    mostrar()   {
        cout << "\nPolinomio=>\t" << a<<"x^2+"<<b<<"x+"<<c<<"\nSoluciones=>\t"<<sol1<<" , "<<sol2<<endl;

    }

};




int main()  {
    float *real=NULL;                                       //Ejercicio 1
    int *entero=NULL;
    Proveedor *prov=NULL;
    Polinomio *pol=NULL;


    real= new float;                                        //Ejercicio 2
    entero= new int;
    prov= new Proveedor(12345678, "Pepe");
    pol= new Polinomio;

    Cliente *tclientes= new Cliente[100];                   //Ejercicio 3



    Cliente **tpuntcli=new Cliente*[1000];                  //Ejercicio 4
    for (int i=0; i<1000; i++) tpuntcli[i]=NULL;


    Proveedor **tpuntprov=new Proveedor*[120];              //Ejercicio 5
    for (int i=0; i<120; i++) tpuntprov[i]= new Proveedor;


    delete [] tpuntcli;                                     //Ejercicio 6


    for (int i=0; i<120; i++) delete [] tpuntprov[i];       //Ejercicio 7
    delete [] tpuntprov;

    return 0;

}
