#include <iostream>
#include <string.h>
#define  M  3
#define  N  4
using namespace std;


typedef   char cadena[30];

class cuatro {
     cadena  tabla[M][N];
     public:

    void cargar();  //Pondrá en cada elemento de la tabla una palabra leída desde  teclado.
    void encontrar();  //Pedirá una palabra por teclado y mostrará por pantalla si esa
    //palabra está o no en la tabla y en qué fila y columna se  //encuentra



    };

 void cuatro::cargar(){

 for(int i=0;i<M;i++)
    for(int j=0;j<N;j++){
       cout<<"Introduzca la palabra que esta en la posicion ["<<i<<"]["<<j<<"]: ";
        cin>>tabla[i][j];
    }

 }

 void cuatro::encontrar(){


 cadena palabra;
 bool encontrado=false;

 cout<<"\nIntrouzca la palabra que quiere buscar: "; cin>>palabra;
int i=0,j;

 while((i<M)&& (!encontrado)){
    j=0;
    while((j<N)&&(!encontrado)){
            if((strcmp(palabra,tabla[i][j]))==0)
             encontrado =true;
            else j++;


        }
        i++;
    }
    if (encontrado)
        cout<<"\nLa palabra "<<palabra<<" SI esta y se encuentra en la posicion ["<<i-1<<"]["<<j<<"]";
    else
        cout<<"\nNo esta";

 }

int main()
{
    cuatro palabra;
    palabra.cargar();
    palabra.encontrar();


    return 0;
}
