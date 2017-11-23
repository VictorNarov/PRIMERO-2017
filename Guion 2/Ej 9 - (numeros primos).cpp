#include <iostream>
#include <vector>

using namespace std;


class clase{
    int N;
    bool esPrimo(int N);

public:
    void informacion();
    int suma();
        vector <int> almacenPrimos;

};

void clase::informacion(){

cout << "Cuántos números quieres sumar? ->";
cin >> N;


}

bool clase::esPrimo(int N){

        if(N < 2) return false;// El 1 no se considera primo
        if(N == 2) return true;// El 2 se considera primo
        if(N%2 == 0) return false; //Los pares no son primos
        for (int e=3; (e*e)<=N; e+=2){
            if(N % e == 0) return false;
        }
        return true;
}


int clase::suma(){
    int resultado=0;


    for(int i=0; i<=N; i++){
        if(!esPrimo(i)){
        resultado = resultado + i;
        cout << i <<"+";

        }
        else almacenPrimos.push_back(i);//Guarda ese numero primo en el almacen

    }

    return resultado;
}
int main(){
setlocale(LC_ALL,""); //Para usar tildes

clase prueba;

prueba.informacion();
prueba.suma();
cout <<"La suma exceptuando los primos es: "<< prueba.suma()
<< endl<< "Primos excluidos: ";
for(size_t t = 0; t < prueba.almacenPrimos.size(); t++){
    if(t == prueba.almacenPrimos.size - 1) cout << almacenPrimos[t]
    else cout << almacenPrimos[t]<<", ";
}


return 0;
};
