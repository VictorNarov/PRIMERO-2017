#include <iostream>
#include <cstring>

using namespace std;

/*  FUNCIONES EN STRING.H

strcpy(c1, c2)  Copia c1 en c2
strcat(c1, c2)  Concatena c2 al final de c1
strlen(c1)      Devuelve la longitud de c1
strcmp(c1, c2)  Devuelve 0 si c1 == c2, menor que 0 si c1<c2 y > 0 si c1>c2
strchr(c1, car) Devuelve un indice a la primera ocurrencia de car en c1. Busca un caracter en un vector
strstr(c1, c2)  Devuelve un indice a la primera ocurrencia de c2 en c1

Funcionamiento del cout en strings

    int i=0;
    while(nombre[i] != '\0'){
        cout << nombre[i];
        i++;
    }

*/

//LOS CIN DE STRNGS ADMITEN SOLO VECTORES DE CADENAS
// TYPEDEF CREA UNA DIMENSION MAS, PARA LOS STRINGS


class x{
int v[500][500]; //Declararlo con su capacidad maxima
int TF, TC; //Tamanio de filas y columnas que el usuario va a usar

public:
    void PideTama();
    void cargar();
    bool buscar();


};

int main(){

bool En = false;
int c=1;

char texto[300];//Se declara el string como un vector de char

do{
    cout << "\nIntroduce el nombre: ";
    cin >> texto;
    if(strcmp(texto, "Jose") == 0)
        En = true;
    else{
        cout << "\nEse no es Jose";
        c++;
    }

}while(!En);

cout <<"Se ha encontrado al intento " << c;


}


