#include <iostream>

using namespace std;

class TablasMultiplicar{
    int TablaIni, TablaFin;

public:
    void PedirNoTablas();
    void MostrarTablas();

};

void TablasMultiplicar::PedirNoTablas(){


do{
    cout << "Introduzca la tabla inicial -> ";
    cin >> TablaIni;
    cout << "Introduzca la tabla final -> ";
    cin >> TablaFin;

    if(TablaIni > TablaFin){
        int TablaTmp = TablaIni;
        TablaIni = TablaFin;
        TablaFin = TablaTmp;
    }
    if(TablaIni < 0 || TablaFin > 10) cout << "Error: valor no valido...\n";
}while(TablaIni < 0 || TablaFin > 10);

}

void TablasMultiplicar::MostrarTablas(){
int NumTablas = TablaFin - TablaIni;
int i, j;

for(i=0; i<=10; i++){
    cout << endl;
    for(j=TablaIni; j<=TablaFin; j++)
        cout << j << " x " << i << " = " << j*i <<"\t";
    }
}

int main(){

TablasMultiplicar pepe;
pepe.PedirNoTablas();
pepe.MostrarTablas();

cout << endl;
return 0;
}
