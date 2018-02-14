#include <iostream>

using namespace std;

int main(){

float x,y;
cout << "Introduce un numero: ";
cin >> x;

y = x < 100 ? x + 50 : x - 60;

/*

if (Condicion)
    Variable = Expresion1;
else
    Variable = Expresion2;



if (x < 100)
    y = x + 50;

else
    y = x - 60;
*/

cout << "y es = " << y;

}
