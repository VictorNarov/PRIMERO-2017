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
    float *real=NULL;
    int *entero=NULL;
    Proveedor *prov=NULL;
    Polinomio *pol=NULL;


    Cliente *tclientes= new Cliente[100];


    Cliente *tpuntcli[1000];
    for (int i=0; i<1000; i++) tpuntcli[i]=NULL;


    Proveedor *tpuntprov[120];
    for (int i=0; i<120; i++) tpuntprov[i]= new Proveedor;


    delete [] tpuntcli;
    delete [] tpuntprov;

    return 0;

}
