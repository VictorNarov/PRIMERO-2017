// Autor: Vik
// Fecha 20-12-17

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <limits>

using namespace std;

typedef char cad[20];

class tprod
{
    cad nombre;
    float precio;
    int stock;
public:
    tprod();
    void cambiarnombre(cad nom);
    void cambiarprecio(float prec);
    void cambiarstock(int stoc);
    void leenombre(cad nom);//Paso por referencia al ser vector
    float leeprecio();
    void leestock(int &st);
    void vender(int cantidad);

};

tprod::tprod()
{
    strcpy(nombre,"NO HAY PRODUCTO");
    precio = 0;
    stock = 0;
}

void tprod::cambiarnombre(cad nom)
{
    strcpy(nombre,nom);
}

void tprod::cambiarprecio(float prec)
{
    precio = prec;
}

void tprod::cambiarstock(int stoc)
{
    stock = stoc;
}

void tprod::leenombre(cad nom)
{
    strcpy(nom, nombre);
}

float tprod::leeprecio()
{
    return precio;
}

void tprod::leestock(int &st)
{
    st = stock;
}

void tprod::vender(int cantidad)
{
    if(cantidad <= stock)
    {
        stock -= cantidad;
        cout << "\nPrecio: " << cantidad*precio;
    }
    else
        cout << "\nError: no hay stock suficiente!\n";
}

#define MAX 5
class almacen
{
    tprod productos[MAX];
    int nprod;
public:
    almacen();
    void vaciar();
    int existe(cad nom);
    void verprod(int pos, tprod &prod);
    int insertar(tprod P);
    void vertabla();
    void vender(int pos, int cant);
    char menu();

};


almacen::almacen()
{
    almacen::vaciar();
}

void almacen::vaciar()
{
    nprod = 0;
    cad nombredefecto = "NO HAY PRODUCTO";

    for(int i=0; i<MAX; i++)
    {
        productos[i].cambiarnombre(nombredefecto);
        productos[i].cambiarprecio(0);
        productos[i].cambiarstock(0);
    }
}

int almacen::existe(cad nom)
{
   int i=0;
   int posicion=-1;
   cad nombreprod;


   while(i<nprod && posicion==-1)
   {
        productos[i].leenombre(nombreprod);
        if(strcmp(nom, nombreprod)== 0)
            posicion = i;
        else i++;
   }
    return posicion;
}

void almacen::verprod(int pos, tprod &prod)
{
    prod = productos[pos];
}

int almacen::insertar(tprod P)
{
    int resultado;
    cad nombreprod;
    P.leenombre(nombreprod);

    if (nprod >= MAX)
        resultado = 2;

    else if(existe(nombreprod) != -1)
        resultado = 1;

    else
    {
        productos[nprod] = P;
        resultado = 0;
        ++nprod;
    }

    return resultado;
}

void almacen::vertabla()
{
    if(nprod == 0)
        cout << "Error: el almacen esta vacio!\n";
    else
    {
        cad nombreprod;
        float precioprod;
        int stockprod;

        cout << "\nNOMBRE\tPRECIO\tSTOCK\n";
        for(int i=1; i<nprod; i++)
        {
            tprod prod;//Crea un objeto copia para mostrar sus datos
            verprod(i, prod);
            prod.leenombre(nombreprod);
            precioprod = prod.leeprecio();
            prod.leestock(stockprod);

            cout << nombreprod <<"\t"<< precioprod <<"\t"<<stockprod<<endl;

        }
    }
}


void almacen::vender(int pos, int cant)
{
    int stockactual;
    productos[pos].leestock(stockactual);
    if(cant <= stockactual)
        productos[pos].cambiarstock(stockactual-cant);
    else
        cout << "\nError: no hay tanto stock!";
}
char almacen::menu()
{
    char opcion='A';
    cout
    << "\n************** MENU *****************" << endl
    << "*******A.- Visualizar la tabla. *****" << endl
    << "*******B.- Insertar un producto.*****" << endl
    << "*******C.- Vender un producto.  *****" << endl
    << "*******D.- Vaciar el almacen.   *****" << endl
    << "*******E.- Salir.               *****" << endl
    << "*************************************" << endl;
    cout << "Introduzca opcion: ";
    cin >> opcion;
    cout << endl;
    return opcion;

}

int main()
{
    almacen almacen1;
    bool continuar = true;

do{
    system("cls");
    switch (almacen1.menu())
    {
    case 'A':
    case 'a':
        system("cls");
        almacen1.vertabla();
        system("pause");
        break;

    case 'B':
    case 'b':
    {//Entre llaves para limitar el alcance de las variables declaradas
        system("cls");
        tprod productonuevo;

        if(almacen1.insertar(productonuevo)==2)//Lo inserta vacio y evalua si el almacen esta lleno
        {
            cout << "\nError: almacen lleno!\n";
            break;
        }

        cad nombreinsertar;
        int stockinsertar;
        float precioinsertar;

        cout << "\nIntroduce el nombre -> ";
        cin >> nombreinsertar;
        cout << "\nIntroduce el precio -> ";
        cin >> precioinsertar;
        cout << "\nIntroduce el stock -> ";
        cin >> stockinsertar;
        //Edita los datos del objeto
        productonuevo.cambiarnombre(nombreinsertar);
        productonuevo.cambiarprecio(precioinsertar);
        productonuevo.cambiarstock(stockinsertar);

        if(almacen1.insertar(productonuevo)==1)
            cout << "\nError: el producto '" << nombreinsertar << "' ya existe!\n";

        else if(almacen1.insertar(productonuevo)==0)
            cout << "\nProducto insertado con exito!\n";

        system("pause");
        break;

    }

    case 'C':
    case 'c':
    {
        cad nombreventa;
        int iventa;

        cout << "\nIntroduce el producto a vender -> ";
        cin >> nombreventa;

        iventa = almacen1.existe(nombreventa);

        if(iventa != -1)
        {
            int cantidad;
            cout << "\nIntroduce la cantidad a vender -> ";
            cin >> cantidad;

            almacen1.vender(iventa,cantidad);
        }
        else
            cout << "\nError: el producto '" <<nombreventa << "' no existe!\n";

        system("pause");
        break;
    }

    case 'D':
    case 'd':
        almacen1.vaciar();
        break;

    case 'E':
    case 'e':
        cout << "\nAdios!";
        continuar = false;
        break;
    default:
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Evita un bucle infinito
        cout << "\nError: opcion no valida!\n";
        break;
    }

}while(continuar);

    return 0;
}
