#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;


//Programa que vaya almacenando las notas de los alumnos. Ira pidiendo si deseamos cargar mas notas o no.
//Cuando no deemos mas notas, nos mostrara la media y cuantos alumnos tienen nota superior a la media

#define SALTO 10
int main()
{

char continuar;
float *notas = new float[SALTO], total=0, media; //Va rellenando notas de 10 en 10
int i=0;
do
{
    cout << "\nIntroduce nota " << i+1 << " -> ";
    cin >> notas[i];
    total+=notas[i];
    i++;


    if(i%SALTO==0)//Detecta que se ha llegado al final del vector
    {
        float *nuevatabla = new float[i+SALTO];
        if (nuevatabla==NULL)
            cout << "\nError: sin memoria!";
        else
        {
            for(int j=0; j<i; j++)
                nuevatabla[j] = notas[j];//Copiar los elementos de la tabla antigua a la nueva

            delete [] notas;
            notas = nuevatabla;//El puntero antiguo apunta a la nueva tabla
        }

    }cout << "\nContinuar? (s/n) -> ";
    continuar = toupper(getche()); // terminada en e no sale por pantalla


}while(continuar!='N');

media=total/i;
cout << "La media es " << media << endl;
for(int j=0; j<i; j++)
    if(notas[j]>media)
        cout << "El alumno "<< j << "("<<notas[j]<< ") tiene nota superior a la media ("<<media<<") \n11";

system("pause");
delete [] notas;
return 0;
}
