#include "maraton.h"
#include <fstream>
#include <iostream>
#include <string.h>

//metodo modificar poder cambiar un pais
using namespace std;
typedef char cadena[TAM_CADENA];

Maraton::Maraton(char FicheroOrigen[], char FicheroDestino[])
{
    numAtletas = 0;

    fich.open(FicheroOrigen, ios::in| ios::out | ios::binary);
    if(fich.fail())
    {
        fich.close();
        fich.clear();//Quitar el flag error
        fichero.open(FicheroDestino, ios::out|ios::binary);//Se abre como escritura para crearlo
        fichero.write((char *)&numAtletas, sizeof(int));//Se guarda un entero 0
        cout << "\nCreado nuevo archivo...";

    }
    else // Si el fichero existe, continuamos...
    {
        int i=0, nAtletasPais;
        Atleta Temp;

        fich.read((char*)&nAtletasPais, sizeof(int)); //Asignar n atletas que hay en fich al contador
        fichero.open(FicheroDestino, ios::out|ios::binary);
        fichero.close();
        fichero.open(FicheroDestino, ios::in | ios::out | ios::binary);
        fich.seekg(0,ios::beg);
        fichero.seekp(sizeof(int),ios::beg);

        while(!fich.eof())
        {
            nAtletasPais=0;
            fich.read((char *)&nAtletasPais, sizeof(int));

            for(i=0; i<nAtletasPais; i++)
            {
                //fich.seekg(cPaises*sizeof(int)+numAtletas*sizeof(Atleta));
                fich.read((char *)&Temp,sizeof(Atleta));//Guarda en objeto Temp
                fichero.write((char *)&Temp, sizeof(Atleta));//Sube el objeto temp
                numAtletas++;
            }

        }
        fichero.seekp(0,ios::beg);
        fichero.write((char *)&numAtletas,sizeof(int));//Escribe el total de atletas
    }
}

Maraton::~Maraton()
{
    fich.close();
    fichero.close();
}

void Maraton::consultar(cadena pais)
{
    cout << "DORSAL\tNOMBRE\tAPELLIDOS\tPAIS\n";
    int i=0;

    fichero.seekg(sizeof(int),ios::beg);
    for(i=0;i<numAtletas;i++)
    {
        Atleta Temp;

        fichero.read((char *)&Temp,sizeof(Atleta));
        if(strcmp(pais,"*")==0)
            cout << i+1 <<") "<<Temp.dorsal<<"\t"<<Temp.nombre<<"\t"<<Temp.apellidos<<"\t"<<Temp.pais<<endl;
        else if(strcmp(strupr(Temp.pais),strupr(pais))==0)
            cout << i+1 <<") "<<Temp.dorsal<<"\t"<<Temp.nombre<<"\t"<<Temp.apellidos<<"\t"<<Temp.pais<<endl;

        if(fichero.fail())
        {
            cout << "\nError en el fichero!";
            break;
        }
    }

}

void Maraton::insertar(Atleta s)
{
    Atleta *vAtletas = new Atleta[numAtletas+1];
    Atleta AtletaTemp;
    fichero.seekg(sizeof(int),ios::beg);
    bool introducido;
    int i;
    for(i=0; i<numAtletas; i++)
    {

        fichero.read((char *)&vAtletas[i],sizeof(Atleta));//Descarga de los atletas del fichero al vector
                        for(int k=0; k<numAtletas+1; k++)
                    cout << vAtletas[k].dorsal;

    }

    introducido = false;

    while(!introducido)
        {
            if(strcmp(strupr(vAtletas[i-1].pais),strupr(s.pais))==0)//i se queda en la ultima pos vector
                {
                    for(int j=numAtletas; j>=i; j--)
                    {
                        AtletaTemp = vAtletas[j-1];
                        vAtletas[j] = AtletaTemp;//hacer hueco desplazando a la derecha
                    }
                    vAtletas[i] = s;//Insertar
                    numAtletas++;
                    introducido = true;
                }
            else if(i==0)
                {
                    vAtletas[numAtletas] = s;//Insertar al final
                    numAtletas++;
                    introducido = true;
                }
            else
                i--;
        }

        fichero.seekp(0,ios::beg);
        fichero.write((char *)&numAtletas,sizeof(int));
        for(int k=0; k<numAtletas; k++)
        {
            fichero.write((char *)&vAtletas[k],sizeof(Atleta));
        }
        delete[] vAtletas;
}


void Maraton::modificar(int dor)
{

}

void Maraton::eliminar(int dor)
{

}

void Maraton::mostrarClasificacion()
{

}
