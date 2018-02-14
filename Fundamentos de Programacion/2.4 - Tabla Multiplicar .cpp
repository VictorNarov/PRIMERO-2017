#include <iostream>

using namespace std;

class TablaMultiplicar{
    int Tabla;

public:
    void PedirNoTabla();
    void MostrarTabla();
};

    void TablaMultiplicar::PedirNoTabla(){

    do{
        cout << "Tabla: ";
        cin >> Tabla;

    }while(Tabla<0 || Tabla>10);

}

    void TablaMultiplicar::MostrarTabla(){

    int NoTablas = Tabla;
    int i;

    for(i=0;i<=10;i++){
        cout<< NoTablas << " x " << i << " = " << NoTablas*i<<endl;
    }

}
int main()
{
    TablaMultiplicar t;
    t.PedirNoTabla();
    t.MostrarTabla();
    return 0;
}
