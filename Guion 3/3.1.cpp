#include <iostream>
#define   M  10

using namespace std;

class uno {
    int   tabla[M];

     public:

            void  cargar();   //Rellena la tabla con valores enteros leídos desde teclado
            int   maximo();  //Devuelve el valor máximo almacenado en la tabla
            int   minimo();  //Devuelve el valor mínimo almacenado en la tabla


             };

 void uno::cargar(){

 for(int i=0;i<M;i++){
    cout<<"Introduzca el numero que esta en la posicion["<<i<<"]: ";
    cin>>tabla[i];
 }
 }

 int uno::maximo(){

 int maximo;
 maximo = tabla[0];

 for(int i=0; i<M;i++){
    if(maximo< tabla[i])
    maximo =tabla[i];
 }

 return maximo;

 }

 int uno::minimo(){
 int minimo;
 minimo = tabla[0];

 for(int i=0; i<M;i++){
    if(minimo>tabla[i])
    minimo=tabla[i];
 }


 return minimo;


 }

int main()
{
    int maximo, minimo;

    uno maxymin;
    maxymin.cargar();
    maximo = maxymin.maximo();
    minimo = maxymin.minimo();

    cout<<"\nEl maximo es: "<<maximo;
    cout<<"\nEl minimo es: "<<minimo<<endl;

    return 0;
}
