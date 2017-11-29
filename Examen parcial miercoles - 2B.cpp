/*
    Víctor Manuel Rodríguez Navarro
    49278702Y
    MODELO 2B

*/

#include <iostream>
#define F 5
#define C 3

using namespace std;

class Examen{
    int tabla[F][C];
    int cantidad;

public:
    void cargar();
    void mostrar();
    bool busqueda();
    void cuantos();
};

void Examen::cargar(){
    int i, j;

    for(i=0; i<F; i++)
        for(j=0; j<C; j++)
            do{
                cout << "Introduce el valor [" << i << "][" <<j << "] -> ";
                cin >> tabla[i][j];
                if(tabla[i][j] < 0 || tabla[i][j] > 15) cout << "\nError: el valor debe estar entre [0, 15] \n";
            }while(tabla[i][j] < 0 || tabla[i][j] > 15);
}

void Examen::mostrar(){
    int i, j;
    for(i=0; i<F; i++){
        cout << endl;
        for(j=0; j<C; j++)
            cout << tabla[i][j] << "\t";
    }

}

bool Examen::busqueda(){
    int i, j, num;
    bool encontrado;

    cout << "\nIntroduce un numero para buscar sus divisores -> ";
    cin >> num;

    cantidad = 0;

    for(i=0; i<F; i++)//Se debe recorrer toda la tabla para ir almacenando cantidad
        for(j=0; j<C; j++)
            if(num % tabla[i][j] == 0) cantidad++;

    if(cantidad != 0) return true;
    else return false;
}

void Examen::cuantos(){

    cout << cantidad;

}

int main(){

Examen test;

test.cargar();
cout << "\nLa tabla es:\n";
test.mostrar();



if (test.busqueda()){
    cout << "\nSe han encontrado divisores, en concreto: " ;
    test.cuantos();
}

else cout << "\nNo se han encontrado divisores";


return 0;
}

