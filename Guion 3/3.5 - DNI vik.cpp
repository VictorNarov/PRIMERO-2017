#include <iostream>
#define M 2
#define N 2

using namespace std;

typedef char cadena[30];

struct persona {
    int dni;
    cadena nombre;

};

class matrices {

    persona tabla[M][N];

public:
    void cargar()
    {
        int i,j;
        for(i=0; i<M; i++)
            for(j=0; j<N; j++){
                cout << "Introduzca el nombre ["<<i<<"] ["<<j<<"] -> ";
                cin >> tabla[i][j].nombre;
                cout << "Introduzca el DNI de ("<<tabla[i][j].nombre<<") -> ";
                cin >> tabla[i][j].dni;
            }
        cout << endl;
    };
    void encontrar()
    {
        int dnibuscado, i, j;
        bool encontrado;
        cout << "Introduzca el DNI a buscar -> ";
        cin >> dnibuscado;

        encontrado = false;
        i = 0;
        while(!encontrado && i < M){
            j=0;
            while(!encontrado && j < N){
                if(dnibuscado == tabla[i][j].dni)
                encontrado = true;
                else j++;
            }
            if (!encontrado) i++;
        }

        if (encontrado) cout << "Se ha encontrado el DNI perteneciente a: " << tabla[i][j].nombre;
        else cout <<"No se ha encontrado el DNI";

    };

};



int main(){

char continuar;

matrices pepe;
pepe.cargar();
do{
pepe.encontrar();
cout << "\nDeseas buscar otro DNI? (s/n)";
cin >> continuar;
}
while(continuar == 's' || continuar == 'S');



return 0;
}
