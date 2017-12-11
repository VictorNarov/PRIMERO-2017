// Autor: Blueko
// Fecha: 09-12-17

#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cstring>
using namespace std;
#define MAX 15

typedef char cad[20];

class tprod
{
    cad nombre;
    float precio;
    int stock;
public:
    tprod();
    void cambiarnombre(cad nom) { strcpy(nombre,nom); }
    void cambiarprecio(float prec) { precio = prec; }
    void cambiarstock (int stoc) { stock = stoc; }
    void leenombre(cad nom) { strcpy(nom,nombre); }
    float leeprecio() { return precio; }
    void leestock (int &st) { st = stock; }
    void vender (int cantidad);
    void leer(cad nom, float &prec, int &st);
    void cambiar(cad nom, float &prec, int &st);
};

tprod::tprod()
{
    strcpy(nombre,"NO HAY PRODUCTO");
    precio = 0;
    stock = 0;
}

void tprod::vender(int cantidad)
{
    if (stock-cantidad >= 0)
    {
        stock -= cantidad;
        cout << "Precio a cobrar: " << cantidad*precio << endl;
    }
    else
    {
        cout << "Error. Stock insuficiente" << endl;
    }
    cout << endl;
}

void tprod::leer(cad nom, float &prec, int &st)
{
    leenombre(nom);
    prec = leeprecio();
    leestock(st);
    cout << endl;
}

void tprod::cambiar(cad nom, float &prec, int &st)
{
    cambiarnombre(nom);
    cambiarprecio(prec);
    cambiarstock(st);
}

class almacen
{
    tprod productos[MAX];
    int nprod;
public:
    almacen() { vaciar(); }
    void vaciar();
    int existe(cad nom);
    void verprod (int pos, tprod &prod);
    int insertar(tprod p);
    void vertabla();
    void vender(int pos, int cant);
};
void almacen::vaciar()
{
    for (int i=0; i<MAX; ++i)
    {
        cad nombrei="NO HAY PRODUCTO";
        float precioi=0;
        int stocki=0;
        productos[i].cambiar(nombrei,precioi,stocki);
    }
    nprod = 0;
}

int almacen::existe(cad nom)
{
    int posicion=-1;
    cad nombrei;
    int i=0;

    while (posicion==-1 && i<nprod)
    {
        productos[i].leenombre(nombrei);
        if (strcmp(nom,nombrei)==0)
            posicion = i;
        ++i;
    }
    return posicion;
}

void almacen::verprod(int pos, tprod &prod)
{
    cad nombrex;
    float preciox;
    int stockx;

    productos[pos].leer(nombrex,preciox,stockx);
    prod.cambiar(nombrex,preciox,stockx);
}

int almacen::insertar(tprod P)
{
    if (nprod==MAX)
        return 2;
    else
    {
        cad nombrep;
        float preciop;
        int stockp;

        //Usa metodos para sacar datos de P
        P.leer(nombrep,preciop,stockp);

        if (existe(nombrep)!=-1)
            return 1;
        else
        {
            productos[nprod].cambiar(nombrep,preciop,stockp);
            ++nprod;
            return 0;
        }
    }
}

void almacen::vertabla() //Esta un poco buged cuando los nombres son un poco largos
{
    if (nprod)
    {//El doble \t es un intento para arreglar lo de los nombres largos. Aumenta la longitud pero meh, no va muy bien tampoco...
        cout << "Pos" << "\t\t" << "Prod" << "\t\t" << "Precio" << "\t\t" << "Stock" << endl;
        for (int i=0; i<nprod; ++i)
        {
            cad nombrei;
            float precioi;
            int stocki;
            productos[i].leer(nombrei,precioi,stocki);
            cout << i << "\t\t" << nombrei << "\t\t" << precioi << "\t\t" << stocki << endl;
        }
    }
    else
        cout << "El almacen esta vacio" << endl;
}

void almacen::vender(int pos, int cant)
{
    productos[pos].vender(cant);
}

char menu()
{
    char opcion='A';
    cout
    << "************** MENU *****************" << endl
    << "*******A.- Visualizar la tabla. *****" << endl
    << "*******B.- Insertar un producto.*****" << endl
    << "*******C.- Vender un producto.  *****" << endl
    << "*******D.- Vaciar el almacen.   *****" << endl
    << "*******E.- Salir.               *****" << endl
    << "*************************************" << endl;
    cout << "Pon la opcion que desee: ";
    cin >> opcion;
    cout << endl;
    return opcion;
}

int main()
{
    almacen central;
    tprod prod;
    cad nombrex;
    float preciox;
    int stockx;
    int checkinsertar;
    int posicion;
    int cantidad;
    bool fin=false;

    do
    {
        system("cls");
        switch (menu())
        {
        case 'a':
        case 'A': central.vertabla();
                  break;
        case 'b':
        case 'B': cout << "Introduzca datos del nuevo producto: " << endl;
                  cout << "Nombre: ";
                  cin >> nombrex;
                  cout << "Precio: ";
                  cin >> preciox;
                  cout << "Stock: ";
                  cin >> stockx;
                  prod.cambiar(nombrex,preciox,stockx);
                  checkinsertar = central.insertar(prod);
                  if (checkinsertar==2)
                    cout << "El almacen esta lleno." << endl;
                  else if (checkinsertar==1)
                    cout << "El producto ya existe en el almacen." << endl;
                  else
                    cout << "Producto insertado en el almacen!" << endl;
                  break;
        case 'c':
        case 'C': cout << "Introduce el nombre del producto: ";
                  cin >> nombrex;
                  posicion = central.existe(nombrex);
                  if (posicion!=-1)
                  {
                      cout << "Cantidad a vender?: ";
                      cin >> cantidad;
                      central.vender(posicion,cantidad);
                  }
                  else
                    cout << "El producto no existe en el almacen." << endl;
                  break;
        case 'd':
        case 'D': central.vaciar();
                  cout << "Almacen vaciado!" << endl;
                  break;
        case 'e':
        case 'E': cout << "Gracias por usar el programa ^^/" << endl;
                  fin = true;
                  break;
        default: cout << "Error. Elija una opcion correcta." << endl;
        }
        cout << endl;
        system ("pause");
    } while (!fin);
    return 0;
}
