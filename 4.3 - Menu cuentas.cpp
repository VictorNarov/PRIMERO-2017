/*
	Autor: Vik
	Fecha: 27/12/17
*/
#include <iostream>
#include <cstdlib>

using namespace std;

typedef char Cadena[50];
#define MAX_CUENTAS 100

class Cuenta
{
    float Saldo;
    int NoCuenta;
    bool Bloqueada;
public:
    Cuenta();
    Cuenta(int pNo, float pSal);
    bool ActualizarSaldo(int pSal);
    void ActualizarBloqueo(bool pBloq);
    float DameSaldo()  { return Saldo; }
    int DameNoCuenta() { return NoCuenta; }
    bool EstaBloqueada() { return Bloqueada; }
};

Cuenta::Cuenta()
{
    Saldo = 0;
    NoCuenta = 0;
    Bloqueada = false;
}

Cuenta::Cuenta(int pNo, float pSal)
{
    NoCuenta = pNo;
    Saldo = pSal;
    Bloqueada = false;
}

bool Cuenta::ActualizarSaldo(int pSal)
{
    bool ok;
    if(!Bloqueada)
    {
        Saldo = pSal;
        ok = true;
    }
    else
        ok = false;
    return ok;
}

void Cuenta::ActualizarBloqueo(bool pBloq)
{
    Bloqueada = pBloq;
}

int BuscarCuenta(Cuenta Ctas[MAX_CUENTAS], int NCuentas, int NoCuenta)
{
    int i=0, posicion = -1;
    bool encontrado = false;

    while(i<NCuentas && !encontrado)
        if(NoCuenta == Ctas[i].DameNoCuenta())
        {
            encontrado = true;
            posicion = i;
        }
        else
            i++;
    return posicion;
}

int MenuCuentas()
{
    int opcion;
    cout <<"\tMenu Gestion de Cuentas" <<
                "\n 1 Anadir una cuenta a un cliente"<<
                "\n 2 Mostrar las cuentas del ciente"<<
                "\n 3 Borrar una cuenta del cliente"<<
                "\n 4 Modificar Saldo de una cuenta"<<
                "\n 5 Modificar Estado de una cuenta"<<
                "\n 6 Salir"<<
                "\n\nElige Opcion: ";
    cin >> opcion;
    return opcion;
}

int main()
{
    Cuenta DatosCuentas[MAX_CUENTAS];
    int nCuentas=0;
    char continuar;
    bool forzarSalida=false;

    do
    {
    system("cls");

    switch(MenuCuentas())
    {
    case 1:
        {//Llaves para que las variables locales se destruyan
        system("cls");
        if(nCuentas < MAX_CUENTAS)
        {
            int noCuentaTemp;
            float SaldoTemp;

            cout << "\nIntroduce el numero de cuenta -> ";
            cin >> noCuentaTemp;

            if(BuscarCuenta(DatosCuentas, nCuentas, noCuentaTemp)== -1)
            {
                cout << "\nIntroduce el saldo -> ";
                cin >> SaldoTemp;
                //Usando el constructor parametrizado:
                Cuenta Temp(noCuentaTemp,SaldoTemp);//Crea una con los datos ingresados
				//El objeto de indice nCuentas es el ultimo en el vector
                DatosCuentas[nCuentas]=Temp;

                nCuentas++;

                cout << "\nCuenta anadida con exito!";

            }
            else
                cout << "\nError: la cuenta "<<noCuentaTemp<<" ya existe!";
        }
        else
            cout << "\nError: maximo numero de cuentas alcanzado!";
        break;
        }
    case 2: //Se ve descuadrado
        system("cls");
        int i;
        cout << "NoCuenta\tSaldo\tEstado\n";
        for(i=0; i<nCuentas; i++)
        {
            cout << DatosCuentas[i].DameNoCuenta() <<
            "\t\t"<< DatosCuentas[i].DameSaldo();
            if(DatosCuentas[i].EstaBloqueada())
                cout << "\t\tBLOQUEADA";
            else
                cout << "\t\tDISPONIBLE";
            cout << endl;

        }
        break;

    case 3:
        {
        system("cls");
        int noCuentaEliminar;

        cout << "Introduce el numero de cuenta a eliminar -> ";
        cin >>noCuentaEliminar;

        int busqueda = BuscarCuenta(DatosCuentas, nCuentas, noCuentaEliminar);
        if(busqueda != -1)
        {
            for(int i=busqueda; i<nCuentas; i++)
                DatosCuentas[i] = DatosCuentas[i+1];

            nCuentas--;
            cout << "\nCuenta eliminada con exito!";
        }
        else
            cout << "\nError: la cuenta no existe!";

        break;
    }


    case 4:
        {
            system("cls");
            int noCuentaBuscar;
            float SaldoNuevo;

            cout << "\nIntroduce el numero de cuenta -> ";
            cin >> noCuentaBuscar;

            int busqueda = BuscarCuenta(DatosCuentas, nCuentas, noCuentaBuscar);
            if(busqueda != -1)
            {
                cout << "\nIntroduce el nuevo saldo -> ";
                cin >> SaldoNuevo;
                bool operacion = DatosCuentas[busqueda].ActualizarSaldo(SaldoNuevo);

                if (operacion) cout << "\nSaldo actualizado con exito!";
                else cout << "\nError: cuenta bloqueada!";
            }
            else
                cout << "\nError: la cuenta no existe";

        break;
        }


    case 5:
        {
            system("cls");
            int noCuentaActualizar;
            char respuesta;
            bool bloquear;

            cout << "\nIntroduce el numero de cuenta -> ";
            cin >> noCuentaActualizar;

            int busqueda = BuscarCuenta(DatosCuentas, nCuentas, noCuentaActualizar);
            if(busqueda != -1)
            {
                do
                {
                    cout << "\nDesea bloquear la cuenta (s) o desbloquearla (n) -> ";
                    cin >> respuesta;
                    if(respuesta!='s' && respuesta!='n') cout << "\nError: respuesta no valida!";
                }while(respuesta!='s' && respuesta!='n');

                if(respuesta == 's' && !DatosCuentas[busqueda].EstaBloqueada())
                {
                    bloquear = true;
                    DatosCuentas[busqueda].ActualizarBloqueo(bloquear);
                    cout << "\nEstado actualizado con exito!";
                }
                else if(respuesta == 's' && DatosCuentas[busqueda].EstaBloqueada() || respuesta=='n' && !DatosCuentas[busqueda].EstaBloqueada())
                    cout << "\nError: la cuenta ya se encuentra en ese estado!";
            }
            else
                cout << "\nError: la cuenta no existe";

            break;
        }


    case 6:
        forzarSalida = true;
        cout << "\nAdios!";
        break;

    default:
        cout << "\nError: opcion no valida!";
    }

        cout<<endl;
        system("pause");

    }while(!forzarSalida);

    return 0;
}
