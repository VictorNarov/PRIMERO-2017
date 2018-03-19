#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
#include "maraton.h"
#include <cstdlib>

#define CLS system("cls")
#define PAUSE system("pause")
using namespace std;


int main()
{
    char p[]="huelvapro.dat", r[]="huelva.dat";
    cadena pais;
    Maraton uno(p,r);
    char opcion='0';
    while(toupper(opcion)!='s'){

    opcion = getch();
    switch(opcion)
    {
    case '1':
        {
            CLS;
            cadena consulta;
            cout<<"Introduce pais a consultar";
            gets(consulta);
            uno.consultar(consulta);
            PAUSE;
            break;
        }
    case '2':
        {
            CLS;
            cadena pais, nombre, apellido;
            int dorsal;
            Atleta Ainsertar;

            cout << "Introduce dorsal -> ";
            cin >> dorsal;
            cout << "\nIntroduce pais ->";
            gets(pais);
            cout <<"\nIntroduce nombre -> ";
            gets(nombre);
            cout <<"\nIntroduce apellidos -> ";
            gets(apellido);

            Ainsertar.dorsal = dorsal;
            strcpy(Ainsertar.apellidos,apellido);
            strcpy(Ainsertar.nombre,nombre);
            strcpy(Ainsertar.pais,pais);

            uno.insertar(Ainsertar);
            break;
        }
    default:
        cout<<"\nOpcion no valida, saliendo...";
        break;
    PAUSE;
    opcion='0';
    }

    }

    return 0;


}
