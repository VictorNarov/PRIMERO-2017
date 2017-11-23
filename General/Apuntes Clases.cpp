#include <iostream>
#include <stdlib.h>

using namespace std;


class persona // FUERA DEL MAIN
    {
    /* AQUI SE
    DECLARAN
     LAS VARIABLES,
     ALGUNOS METODOS PRIVADOS
     */
     int dia,mes,anio;
     string nombre;
     int edad;
     float Saldo;
    public:
        /*
        AQUI SE
        DECLARAN LAS
        FUNCIONES, LOS PROTOTIPOS. Da informacion al compilador de que va a tener */
        int dame_edad();
        float dameSaldo();
        void PideDatos();
        string dame_nombre();

    private:
        char direcc[100]; //Se pueden añadir mas zonas privadas
    };
    int persona::dame_edad(){
        return edad;
    }

    float persona::dameSaldo(){
        return Saldo;
    }
    string persona::dame_nombre(){

        return nombre;
    }

    void persona::PideDatos() //No hay return porque es dato tipo void
    {
        cout << "Introduce nombre: ";
        cin >> nombre;
        cout << "Introduce saldo: ";
        cin >> Saldo;
        cout << "Introduce edad: ";
        cin >> edad;
    }

//EJERCICIO 18
class empleado {
    int horasnormales, horasextra;

public:
    void cargar();
    float nomina();
};

void empleado::cargar(){ //Pedirá por teclado las horas normales y las horas extras trabajadas.

    cout << "Introduzca horas normales: ";
    cin >> horasnormales;
    cout << "Introduzca horas extra: ";
    cin >> horasextra;
}
float empleado::nomina(){ //Devolverá el sueldo que cobrará después de la retención.

    return (horasextra*8 + horasnormales*5) - 0.15*(horasextra*8 + horasnormales*5);

}

class rectangulo{
    int largo, ancho;

public:
    void iniciar(), cargar();
    int area();
    void cambiar();
};

void rectangulo::iniciar(){ //poniendo 2 de ancho y 4 de largo

    ancho = 2;
    largo = 4;
}

void rectangulo::cargar(){ //poniendo el largo y el ancho que escriba el usuario por teclado

    cout << "Introduce ancho: ";
    cin >> ancho;
    cout << "Introduce largo: ";
    cin >> largo;

}
int rectangulo::area(){
    return largo * ancho;
}
void rectangulo::cambiar(){

    int temp = ancho;
    ancho = largo;
    largo = ancho;
}

class Fecha{ //EJERCICIO 5 B2


public:
    int agno;
    void leer();
    bool bisiesto();

};

void Fecha::leer(){
    agno = 1;
    cout << "Introduce el anio: ";
    cin >> agno;
    if(agno <= 0){
    cout << endl << "Anio no valido!"<<endl;
    }


}
bool Fecha::bisiesto(){

    if(agno%400 == 0 || (agno%4 == 0 && agno%100 != 0)){
        cout << "El anio " << agno << " es bisiesto" << endl;
        }
    else {
        cout << "El anio no es bisiesto o error" << endl;
    }
}
int main(){//Funcion de una clase se llama metodo

//    persona yo;
//    yo.PideDatos();

//    cout << "edad = " << yo.dame_edad() << "\nSaldo = " << yo.dameSaldo() << "\nNombre: " << yo.dame_nombre();

/*     EJERCICIO 18

empleado juan;
juan.cargar();
cout << "Juan cobra: "<< juan.nomina() << endl;
*/

/*     EJERCICIO 19

rectangulo pepe;
pepe.cargar();
pepe.cambiar();
cout << "El area es: " << pepe.area() << endl;
*/
Fecha hoy;
do hoy.leer();
while(hoy.agno <= 0);
hoy.bisiesto();
system("pause");

}
