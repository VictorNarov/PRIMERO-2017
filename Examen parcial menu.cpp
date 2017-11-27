#include <iostream>
#include <cstdlib>
#define FILS 4
#define COLS 3

using namespace std;

class Datos
{
    float Valores[FILS][COLS];
public:
    void Cargar();
    void Mostrar();
    float Minimo();
    bool Buscar();
};


void Datos::Cargar()
{
    int i, j;

    for(i=0; i<FILS; i++)
        for(j=0; j<COLS; j++)
    {
        do{
            cout<< "Introduce el valor ["<<i<<"]["<<j<<"] ->";
            cin >> Valores[i][j];
         if(Valores[i][j] < -20.5 || Valores[i][j] > 60.5) cout<< "\nError: el valor debe estar en el rango [-20.5, 60.5] ";
        }while(Valores[i][j] < -20.5 || Valores[i][j] > 60.5);

    }
}

void Datos::Mostrar()
{
    int i, j;

    for(i=0; i<FILS; i++){
        cout << endl;
        for(j=0; j<COLS; j++)
            cout << Valores[i][j] << "\t";
    }

}

float Datos::Minimo()
{
    int i, j;
    float minimo = Valores[0][0];

    for(i=0; i<FILS; i++)
        for(j=0; j<COLS; j++)
            if(Valores[i][j] < minimo) minimo = Valores[i][j];
    return minimo;

}

bool Datos::Buscar(){
    float buscado;
    int i,j;

    cout<< "\nIntroduce el numero a buscar -> ";
    cin >> buscado;

    bool encontrado = false;

    i=0;
    while(i<FILS && !encontrado){
        j=0;
        while(j<COLS && !encontrado)
            if(Valores[i][j] == buscado) encontrado = true;
            else j++;
        i++;
    }
return encontrado;
}


int main()
{
    Datos pepe;
    char continuar;


do{
    int opcion = 0;
    continuar = 'n';
    system("cls");
    cout << "\tELIGE OPCION \n1) Rellenar tabla \n2) Mostrar tabla\n3) Mostrar minimo \n4) Buscar en la tabla\n5) Salir \n\nOpcion -> ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        system("cls");
        pepe.Cargar();
        break;
    case 2:
        system("cls");
        pepe.Mostrar();
        break;
    case 3:
        system("cls");
        cout<< "\nEl valor minimo es: "<< pepe.Minimo();
        break;
    case 4:
        system("cls");
        if(pepe.Buscar()) cout << "Se ha encontrado en la tabla ";
        else cout << "No se ha encontrado en la tabla";
        break;

    case 5:
        cout<< "\nAdios!";
        return 0;

    default: cout<< "Error: Opcion no valida...";

    }
    cout << "\nVolver al menu? (s/n) -> ";
    cin >> continuar;
}while(continuar == 's' || continuar == 'S');

return 0;
}
