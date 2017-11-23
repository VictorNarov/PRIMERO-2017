#include <iostream>

using namespace std;

class Numero {
    int a,b;
public:
    void informacion(); //pedirá dos valores enteros por teclado almacenándolos en a y b.
    int mcd(); /*método mcd devolverá el máximo común divisor de a y b,
     aplicando el algoritmo sencillo de Euclides
     que dice que si a es mayor que b entonces a = a – b
     y si b es mayor que a entonces b = b – a y esto se repite
    hasta que a y b son iguales, momento en el que el máximo común divisor es a */
};

void Numero::informacion(){
    cout << "Introduce el primer numero -> ";
    cin >> a;
    cout << "Introduce el segundo numero -> ";
    cin >> b;

}

int Numero::mcd(){
    while(a != b){
        if( a > b) a = a - b;
        else if ( b > a) b = b - a;
    }
return a;
}

int main(){
setlocale(LC_ALL, "");

Numero n;
n.informacion();
cout << "El mcd es: "<< n.mcd();

}
