#include "maraton.h"
#include "clasificacion.h"
#include <fstream>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>//srand
//metodo modificar poder cambiar un pais
using namespace std;
typedef char cadena[TAM_CADENA];

int marcas(int semilla)
{
    srand(semilla);
    return (rand()%7000+3000);
}
void marcaDisplay(int marca, int &h, int &m, int &s)
{
    s = marca%60;
    m = marca/60;
    h = m/60;
    m = m%60;
}
Maraton::Maraton(char FicheroOrigen[], char FicheroDestino[])
{
    numAtletas = 0;

    fich.open(FicheroOrigen, ios::in| ios::out | ios::binary);
    if(fich.fail())
    {
        fich.close();
        fich.clear();//Quitar el flag error
        fichero.open(FicheroDestino, ios::out|ios::binary);//Se abre como escritura para crearlo
        fichero.seekp(0,ios::beg);
        fichero.write((char *)&numAtletas, sizeof(int));//Se guarda un entero 0
        cout << "\nCreado nuevo archivo...\n";
        system("pause");
        fichero.close();
        fichero.open(FicheroDestino, ios::in|ios::out|ios::binary);

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
    Atleta Temp;
    cadena pais_temp;

    for(i=0;i<numAtletas;i++)
    {
        fichero.seekg(sizeof(int)+i*sizeof(Atleta),ios::beg);
        fichero.read((char *)&Temp,sizeof(Atleta));
        strcpy(pais_temp,Temp.pais);
        if(strcmp(pais,"*")==0)
            cout << i+1 <<") "<<Temp.dorsal<<"\t"<<Temp.nombre<<"\t"<<Temp.apellidos<<"\t"<<Temp.pais<<endl;
        else if(strcmp(strupr(pais_temp),strupr(pais))==0)
            cout << i+1 <<") "<<Temp.dorsal<<"\t"<<Temp.nombre<<"\t"<<Temp.apellidos<<"\t"<<Temp.pais<<endl;
    }

}

void Maraton::insertar(Atleta s)
{
    //Atleta *vAtletas = new Atleta[numAtletas+1];
    Atleta AtletaTemp;

    bool bDorsal=false, bPais=false;//Ha encontrado mismo dorsal/pais
    int i=numAtletas, iPais;

    while(i>0 && !bDorsal)
    {
        fichero.seekg(sizeof(int)+(i-1)*sizeof(Atleta),ios::beg);
        fichero.read((char *)&AtletaTemp,sizeof(Atleta));//Comprueba si existe dorsal
        if(AtletaTemp.dorsal==s.dorsal)
        {
            bDorsal = true;
            cout << "\nError: dorsal ya existente!";
        }
        else
        {
            i--;

        }
        if(strcmp(AtletaTemp.pais,s.pais)==0 && !bPais)//No vuelve a entrar si ya lo ha encontrado
        {
            bPais = true;
            iPais = i;//Guarda la posicion
        }

    }

    if(!bDorsal)
    {
        if(!bPais)//Si no existe pais, añadir al final
        {
            //fichero.seekp(0, ios::end);
            fichero.seekp(sizeof(int)+numAtletas*sizeof(Atleta),ios::beg);
            fichero.write((char *)&s,sizeof(Atleta));
            numAtletas++;
            cout << "\nAtleta inscrito con exito!" <<endl;
        }
        else
            {
            //    fichero.seekp(0,ios::end);

                for(int i=numAtletas-1; i>=iPais; i--)
                {
                    fichero.seekg(sizeof(int)+i*sizeof(Atleta),ios::beg);
                    fichero.read((char *)&AtletaTemp, sizeof(Atleta));

                    fichero.seekp(sizeof(int)+(i+1)*sizeof(Atleta), ios::beg);
                    fichero.write((char *)&AtletaTemp, sizeof(Atleta));

                }
                fichero.seekp(sizeof(int)+(iPais+1)*sizeof(Atleta));
                fichero.write((char *)&s,sizeof(Atleta));
                numAtletas++;
            }
    }

}

void Maraton::modificar(int dor)
{
    int i=0;//Localiza la posicion del atleta a modificar
    bool encontrado = false;
    fichero.seekg(sizeof(int),ios::beg);
    Atleta ATemp;

    while(!encontrado&&i<numAtletas)
    {
        fichero.read((char *)&ATemp,sizeof(Atleta));
        if(ATemp.dorsal==dor)
            encontrado = true;
        else
            i++;

    }
    if(!encontrado)
        cout << "\nError: dorsal no existe!";
    else
    {
        cout << "Editando: " <<ATemp.dorsal<<" "<<ATemp.nombre<<" "<<ATemp.apellidos<<ATemp.pais<<"\n\n";
        cout << "Introduce dorsal -> ";
        cin >> ATemp.dorsal;
        cin.get();
        cout <<"\nIntroduce nombre -> ";
        gets(ATemp.nombre);
        cout <<"\nIntroduce apellidos -> ";
        gets(ATemp.apellidos);

        //Se podria reutilizar el codigo de insertar

        fichero.seekp(sizeof(int)+(i)*sizeof(Atleta), ios::beg);//Situarse al comienzo del atleta a modificar
        fichero.write((char *)&ATemp, sizeof(Atleta));
        if(!fichero.fail())
            cout << "\nAtleta modificado correctamente!";
    }

}

void Maraton::eliminar(int dor)
{
    int i=0;
    bool encontrado = false;
    Atleta ATemp;
    fichero.seekg(sizeof(int),ios::beg);
    //Encontrar el indice del atleta a eliminar, y subir elemento a elemento
    while(!encontrado && i<numAtletas)
    {
        //fichero.seekg(sizeof(int)+i*sizeof(Atleta), ios::beg);
        fichero.read((char *)&ATemp,sizeof(Atleta));
        if(ATemp.dorsal==dor)
        {
            encontrado = true;
            cout << "\nEliminando: "<< ATemp.nombre<< " "<<ATemp.apellidos << ", "<< ATemp.pais<<"...";
        }
        else i++;
    }
    if(encontrado)
    {
        for(int j=i; j<numAtletas-1; j++)
        {
            fichero.seekg(sizeof(int)+(j+1)*sizeof(Atleta),ios::beg);//Colocarse en la posicion del atleta a eliminar para empezar a sobreescribir

            fichero.read((char *)&ATemp,sizeof(Atleta));
            fichero.seekp(sizeof(int)+(j*sizeof(Atleta)),ios::beg);
            fichero.write((char *)&ATemp,sizeof(Atleta));
        }
        numAtletas--;
        fichero.seekp(0, ios::beg);
        fichero.write((char *)&numAtletas, sizeof(int));
        if(fichero.fail())
            cout << "\nError en la operacion del fichero!";
        else
            cout << "\nAtleta eliminado con exito!";
    }
    else
        cout << "\nError: dorsal no encontrado!";
}

void Maraton::mostrarClasificacion()
{
    fichero.seekg(sizeof(int),ios::beg);
    Atleta aTemp;
    Corredor cTemp;
    Clasificacion clasi;

    for(int i=0; i<numAtletas; i++)
    {
        fichero.read((char *)&aTemp, sizeof(Atleta));
        cTemp.dorsal = aTemp.dorsal;
        cTemp.indice = i+1;//Para mostrarlo igual que en inscripciones
        cTemp.marca = marcas(rand()%5000);
        clasi.anadircorredor(cTemp);

        aTemp.marca = cTemp.marca;//guardar marca en fichero
        fichero.seekp(sizeof(int)+i*sizeof(Atleta),ios::beg);
        fichero.write((char *)&aTemp, sizeof(Atleta));
    }

    clasi.OrdenacionBurbuja();
    cout << "MARCA\t\tDORSAL\tPAIS\tNOMBRE\n";
    for(int j=0; j<clasi.numcorredores(); j++)
    {
        cTemp = clasi.consultar(j);
        fichero.seekg(sizeof(int)+(cTemp.indice-1)*sizeof(Atleta),ios::beg);//Obtener el correspondiente atleta del fichero
        fichero.read((char *)&aTemp,sizeof(Atleta));

        aTemp.posicion = j+1;// guardar posicion i+1 en atleta fichero
        fichero.seekp(sizeof(int)+(cTemp.indice-1)*sizeof(Atleta),ios::beg);
        fichero.write((char *)&aTemp,sizeof(Atleta));

        int h,m,s;
        marcaDisplay(cTemp.marca,h,m,s);
        cout <<aTemp.posicion<<") "<<h<<"h "<<m<<"m "<<s<<"s \t"<<aTemp.dorsal<<"\t"<<aTemp.pais<<"\t"<<aTemp.nombre<<" "<<aTemp.apellidos<<endl;
    }
}
