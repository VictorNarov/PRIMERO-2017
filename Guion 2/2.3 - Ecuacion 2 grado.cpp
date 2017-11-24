#include <iostream>
#include <math.h>

using namespace std;

int main(){

int a, b, c, x1, x2;

cout << "\tResolver ecuacion de la forma ax^2 + bx + c = 0\n" <<
"\nIntroduce coeficiente a ->";
cin >> a;
cout << "Introduce coeficiente b -> ";
cin >> b;
cout << "Introduce termino independiente c -> ";
cin >> c;

if((b*b - 4*a*c) < 0){
    cout << "\nNo tiene soluciones reales" << endl;
    return 0;
}

else if((b*b - 4*a*c) == 0)
    cout << "\nTiene una solucion doble y es: " << -b/2*a;

else{

x1 = (-b + sqrt( pow(b, 2) - 4 * a * c)) / (2*a);
x2 = (-b - sqrt( pow(b, 2) - 4 * a * c)) / (2*a);

cout << "\tSoluciones: \tx1 = "<< x1 << "\t x2 = "<< x2 << endl;
}
return 0;
}
