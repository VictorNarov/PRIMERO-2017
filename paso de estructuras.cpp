#include <iostream>
#include <cstring>

using namespace std;

struct Punto
{
    int x,y,z;
};

class Persona
{
    int edad;
    char nombre[50];
public:
    //int getedad();
    void getedad(int &e);
    void getnombre(char N[50]);
};

void Persona::getnombre(char N[50])
{
    strcpy(nombre, N);
}

void f(int v[100])//Paso por REFERENCIA no hace falta &
{
    for(int i=0; i<100; i++)
        cout << v[i] << " ";
}

void f2(Punto v);// Paso por copia. Si es un elemento y no se pone &
void f3(Persona p);// Paso por copia
void f4(Persona plantilla[20]);// Paso por REFERENCIA


int main()
{
    int j[1000];
    for(int i=0; i<1000; i++)
        cin >> j[i];
    f(j);//Pasa los 100 primeros elementos. Se pasa j por referencia
}
