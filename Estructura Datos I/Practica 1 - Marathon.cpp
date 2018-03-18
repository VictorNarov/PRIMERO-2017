#include <iostream>
#include "Marathon.h"
#include <fstream>
#include <string.h>
#include <cstdlib>

using namespace std;

Maraton::Maraton(char FicheroOrigen[], char FicheroDestino[])
{
    numAtletas = 0;
    fich.open(FicheroOrigen, ios::in | ios::out | ios::binary);

    if(fich.fail())
    {
        fich.close();
        fich.clear();
        fich.open(FicheroDestino, ios::out | ios::binary);
        fichero.write((char *)&numAtletas, sizeof(int)); 
    }
    else
    {
        fichero.open(FicheroDestino, ios::out | ios::binary);
        fichero.close();
        fichero.open(FicheroDestino, ios::in | ios::out | ios::binary);
        fichero.seekg(sizeof(int), ios::beg);
        Atleta Temp;

        while(!fich.eof())
        {
            int numAtletasPais=0;
            fich.read((char *)&numAtletasPais, sizeof(int));

            for(int i=0; i<numAtletasPais; i++)
            {
                fich.read((char *)&Temp, sizeof(Atleta));
                fichero.write((char *)&Temp, sizeof(Atleta));
                numAtletas++;
            }
        }
        fichero.seekp(0, ios::beg);
        fichero.write((char *)&numAtletas, sizeof(int));
    }
}
