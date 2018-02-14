#include <iostream>
#define   M   10
using namespace std;


class matrices {
     int   tabla[M];


     public:
        void   cargar();  //Pondrá en cada elemento de la tabla el valor de su índice.
        bool   encontrar();  //Pedirá un número entero por teclado y devolverá true si ese
                            //número está en la tabla, en caso contrario devolverá false.


};

void matrices::cargar(){

for(int i=0;i<M;i++){
    cout<<"Introduzca el valor que estan en la posicion ["<<i<<"]: ";
    cin>>tabla[i];
        }



    }

bool matrices::encontrar(){

int num;
bool encontrado=false;
int i=0;


cout<<"\nIntroduzca el numero que quiere buscar: ";
cin>>num;
while((i<M)&& !encontrado){
    if(tabla[i]==num)
    encontrado = true;
else
    i++;

}

return encontrado;


}



int main()
{
    bool encontrado;

    matrices matriz;
    matriz.cargar();
    encontrado = matriz.encontrar();

    if(encontrado)
        cout<<"\nEl numero esta en la tabla.\n";
    else
        cout<<"\nNo esta.\n";

    return 0;
}
