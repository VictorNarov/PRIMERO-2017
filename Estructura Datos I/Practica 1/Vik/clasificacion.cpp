#include <iostream>

#include "clasificacion.h"
#define SALTO 4
using namespace std;



Clasificacion::Clasificacion()
{
    tamano = 0;
    corredores = 0;
    Corredor *elementos = new Corredor[tamano];
}

Clasificacion::~Clasificacion()
{
    delete [] elementos;
}

void Clasificacion::anadircorredor(Corredor a)
{
    if(corredores == tamano)//Tabla llena
    {

        Corredor *Temp = new Corredor[tamano];
        for(int i=0; i<tamano; i++)
            Temp[i]=elementos[i];
        delete [] elementos;
        tamano+=SALTO;
        elementos = new Corredor[tamano];//El puntero a tabla se queda declarado
        for(int i=0; i<corredores; i++)
            elementos[i]=Temp[i];
        delete [] Temp;

    }
    //a.marca = marcas(a.dorsal);//generar una marca aleatoria
    elementos[corredores] = a;
    corredores++;
}

void Clasificacion::eliminar(int i)
{
    bool encontrado=false;
    int j=0;

    while(!encontrado && j<corredores)
        {
            if(elementos[j].indice == i)
            {
            encontrado = true;
            for(int k=j; k<corredores; k++)//Desplazar corredores a la izqda
                elementos[k+1] = elementos[k];
            corredores--;
            }
            else
                i++;
        }
        if(!encontrado)
            cout << "\nError: indice no encontrado!";
        else
            cout << "\nCorredor borrado con exito!";

}

Corredor Clasificacion::consultar(int i)
{
 return elementos[i];
}

bool Clasificacion::vacio()
{
    bool vacio=false;
    if(corredores == 0)
        vacio = true;
    return vacio;
}

void Clasificacion::OrdenacionBurbuja()
{
    int pos,ele;
    for (pos=0; pos<corredores; pos++)
        for (ele=corredores; ele>pos; ele--)
            if(elementos[ele-1].marca > elementos[ele].marca && elementos[ele].marca != 0)
                {
                    Corredor Temp=elementos[ele-1];
                    elementos[ele-1] = elementos[ele];
                    elementos[ele] = Temp;
                }
}
