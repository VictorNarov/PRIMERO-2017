#include <iostream>
#include <limits> //Para usar numeric_limits

using namespace std;


int main(){
setlocale(LC_ALL,"");//Permite mostrar tildes

char opcion;
int n1=0, n2=0;
bool valido=false;//Controla la entrada al bucle

while(!valido){
cout << "Introduce número 1: ";
cin >> n1;

if(cin.fail()){//boleano
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');//Ignora todo el cin
    cout <<"Error: dígito no valido..." << endl;
    }
else valido=true;
}

valido=false; //Devolver el valor a false

while(!valido){
cout << "\nIntroduce número 2: ";
cin >> n2;

if(cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout <<"Error: dígito no valido..." << endl;
    }
else valido=true;
}

do{
cout << "         MENU" <<endl<< "A. Sumar" <<endl<< "B. Restar" <<endl<< "C. Multiplicar" <<endl<<
"D. Dividir" <<endl << "E. Salir" << endl << "\nElija opción: ";

cin >> opcion;
if((opcion < 61 || opcion > 69) && (opcion < 91 || opcion > 101)){//Caracteres validos
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Muestra el mensaje de error 1 vez
    cout << "Opcion incorrecta..." <<endl;
    }
}while((opcion < 61 || opcion > 69) && (opcion < 91 || opcion > 101));


if(opcion == 'A' || opcion == 'a')
    cout << endl <<n1<<" + "<<n2<<" = "<< n1+n2;

else if(opcion == 'B' || opcion == 'b')
    cout << endl <<n1<<" - "<<n2<<" = "<< n1-n2;

else if(opcion == 'C' || opcion == 'c')
    cout << endl <<n1<<" X "<<n2<<" = "<< (float)n1*n2;

else if(opcion == 'D' || opcion == 'd')
    cout << endl <<n1<<" : "<<n2<<" = "<< (float)n1/n2;
else cout << "\nAdios!" <<endl;



return 0;
}
