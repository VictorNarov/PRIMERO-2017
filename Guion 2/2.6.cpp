#include<iostream>
#include<stdlib.h>
using namespace std;

class operaciones{

   int n1, n2;

   public:
       void informacion();
       void operacion();

};

 void operaciones::informacion(){

   cout<<"Ingrese el primer numero entero: ";
   cin>>n1;
   cout<<"Ingrese el segundo numero entero: ";
   cin>>n2;
 }

 void operaciones::operacion(){

   system("CLS");
   char seleccion;
   cout<<"Introduzca cual sera la operacion a realizar: ";
   cin>>seleccion;

   if (seleccion=='S'||seleccion=='s'||seleccion=='+'){
      cout<<endl<<"La suma de estos dos numeros es: "<<n1+n2<<endl<<endl;
   }

   else if(seleccion=='R'||seleccion=='r'||seleccion=='-'){
       cout<<endl<<"La resta de estos dos numeros es: "<<n1-n2<<endl<<endl;
             }

             else{
                   cout<<endl<<"La seleccion no es valida"<<endl<<endl;
                 }

}


 int main(){

 operaciones h;
 h.informacion();
 h.operacion();

 return 0;

 }
