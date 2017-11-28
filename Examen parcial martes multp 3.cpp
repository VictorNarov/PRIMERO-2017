#include <iostream>
#include <cstdlib>
#define FILS 3
#define COLS 4

using namespace std;

class clase{
    int tabla[FILS][COLS];
public:
    bool bMult3();
    int iMult3();
    void Rellenar();
    void Mostrar();
};

void clase::Rellenar(){

    int i, j;

    for(i=0; i<FILS; i++)
        for(j=0; j<COLS; j++)
            do{
                cout << "Introduce el valor ["<<i<<"]["<<j<<"] -> ";
                cin >> tabla[i][j];
            if(tabla[i][j] < 1 || tabla[i][j] > 99) cout << "\nError, el valor debe estar entra 1 y 99...\n";
            }while(tabla[i][j] < 1 || tabla[i][j] > 99);

}

void clase::Mostrar(){
    int i, j;
    for(i=0; i<FILS; i++){
        cout << "\n";
        for(j=0; j<COLS; j++)
            cout << tabla[i][j] << " ";
        }
        cout<<"\n\n";
}

bool clase::bMult3(){

    int i, j;
    bool Mult3 = false;

    i=0;

    while(i<FILS && !Mult3){
        j=0;
        while(j<COLS && !Mult3){
            if(tabla[i][j] % 3 == 0) Mult3 = true;
            else j++;
        }
        i++;
    }
return Mult3;

}

int clase::iMult3(){

    int contador=0;

    for(int i=0; i<FILS; i++)
        for(int j=0; j<COLS; j++)
            if(tabla[i][j] % 3 == 0) contador++;

return contador;
}



int main(){

clase pepe;

pepe.Rellenar();
system("cls");
pepe.Mostrar();

if(pepe.bMult3()) cout<< "\nSe ha encontrado al menos un multiplo de 3, en concreto: " << pepe.iMult3();
else cout << "\nNo se han encontrado multiplos de 3\n\n";


}
