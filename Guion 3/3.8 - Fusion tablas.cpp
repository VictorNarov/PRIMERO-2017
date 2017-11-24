#include <iostream>

using namespace std;

class merges{
    int uno[15], dos[15], fus[30];
    int numuno;//Número de elementos almacenados en la tabla uno
    int numdos;//Número de elementos almacenados en la tabla dos

public:
    void cargar();
    void mezclar();
    void ver();
    void verfusion();
};


void merges::cargar(){
int i;

    do{
    cout << "Cuantos elementos vas a colocar en la tabla 1? (max 15) -> ";
    cin >> numuno;
    if(numuno < 1 || numuno > 15) cout << "\nError: valor no valido...\n";
    }while((numuno < 1 || numuno > 15));

    for(i=0; i<numuno; i++){
    do{
        cout << "\nIntroduce el elemento uno[" << i << "] -> ";
        cin >> uno[i];
        if(i>0 && uno[i] < uno[i-1]) cout << "\nError: el valor debe ser mayor que " << uno[i];
        }while(i>0 && uno[i] < uno[i-1]);
    }

    do{
        cout << "\nCuantos elementos vas a colocar en la tabla 2? (max 15) -> ";
        cin >> numdos;
        if(numdos < 1 || numdos > 15) cout << "\nError: valor no valido...\n";
    }while((numdos < 1 || numdos > 15));


    for(i=0; i<numdos; i++){
    do{
        cout << "\nIntroduce el elemento dos[" << i << "] -> ";
        cin >> dos[i];
        if(i>0 && uno[i] < uno[i-1]) cout << "\nError: el valor debe ser mayor que " << dos[i];
        }while(i>0 && dos[i] < dos[i-1]);
    }
}
void merges::ver(){
int i;

cout << "Tabla 1 = [";
    for(i=0; i<numuno; i++){
        cout << uno[i];
        if(i == numuno - 1) cout << "]" << endl;
    }

cout << "Tabla 2 = [";
    for(i=0; i<numdos; i++){
        cout << dos[i];
        if(i == numdos - 1) cout << "]" << endl;
    }

}

void merges::mezclar(){

int iF, i1, i2;//Indices de los vectores
iF = 0;
i1 = 0;
i2 = 0;
while(i1 < numuno && i2 < numdos){//Condicion vectores no acabados

    if( uno[i1] < dos[i2]){
        fus[iF] = uno[i1];
        i1++;
    }
    else if( uno[i1] > dos[i2]){
        fus[iF] = dos[i2];
        i2++;
    }
    else{
        fus[iF] = uno[i1];
        fus[iF+1] = dos[i2];
        iF += 2;
    }
    iF++;
}

while(i1 < numuno){//Si la 1 no se ha acabado
    fus[iF] = uno[i1];
    i1++;
    iF++;
}

while(i2 < numdos){
    fus[iF] = dos[i2];
    i2++;
    iF++;
}

}

void merges::verfusion(){

int i;

cout << "Visualizo la tabla fusion\n";
for(i=0; i < numuno + numdos; i++)
    cout << fus[i] << "\t";
cout << endl;


}

int main(){

merges pepe;

pepe.cargar();
pepe.mezclar();
pepe.ver();
pepe.verfusion();


}
