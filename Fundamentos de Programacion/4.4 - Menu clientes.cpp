/*
	Autor: Vik
	Fecha: 01/01/18
*/
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef char Cadena[50];
#define MAX_CUENTAS 10
#define MAX_CLIENTES 100


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

class Cliente
{
    Cadena Nombre;
    Cadena Direccion;
    Cuenta Cuentas[MAX_CUENTAS];
    int noCuentas; //N de cuentas abiertas
public:
    Cliente();
    void ActualizarCliente(Cadena pNomb, Cadena pDir);
    void DameNombre(Cadena pNom) { strcpy(pNom, Nombre); } //Paso por referencia al ser vector
    void DameDireccion(Cadena pDir) { pDir = Direccion; }
    int BuscarCuentaCliente(int pNoCuenta);
    bool CrearCuenta(Cuenta pCu);
    bool ActualizarCuenta(Cuenta pCu);
    bool BorrarCuenta(int pNoCuenta);
    int DameNoCuentas() { return noCuentas; }
    Cuenta DameCuenta(int pos) { return Cuentas[pos]; }
    void Mostrar(char Campo);
};

Cliente::Cliente()
{

    strcpy(Nombre, " ");
    strcpy(Direccion, " ");
    noCuentas = 0;

}

void Cliente::ActualizarCliente(Cadena pNomb, Cadena pDir)
{
    strcpy(Nombre, pNomb);
    strcpy(Direccion, pDir);
    noCuentas = 0;
}

int Cliente::BuscarCuentaCliente(int pNoCuenta)
{
    int resultado = BuscarCuenta(Cuentas, noCuentas, pNoCuenta);
    return resultado;

}

bool Cliente::CrearCuenta(Cuenta pCu)//Mensajes de error controlados desde el metodo
{
    bool ok;
    if(noCuentas >= MAX_CUENTAS)
    {
        ok = false;
        cout << "\nError: numero maximo de cuentas de cliente alcanzado!";
    }
    else
    {
        int busqueda = BuscarCuenta(Cuentas, noCuentas, pCu.DameNoCuenta());
        if (busqueda != -1) //Ha encontrado el indice de una cuenta con el mismo num
        {
            ok = false;
            cout << "\nError: la cuenta ya existe! ";
        }
        else
        {
            Cuentas[noCuentas] = pCu;
            ok = true;
            noCuentas++;
        }
    }
    return ok;
}

bool Cliente::ActualizarCuenta(Cuenta pCu)
{
    bool ok;
    int busqueda = BuscarCuentaCliente(pCu.DameNoCuenta());

    if(busqueda == -1)//Si no existe la cuenta
        ok  = false;
    else//La llamada a este metodo se controla desde el main
    { //Edita la cuenta encontrada con los valores de la cuenta pasada por parametro
        Cuentas[busqueda].ActualizarSaldo(pCu.DameSaldo());  //No se necesita recoger el return porque el correcto funcionamiento se controla desde la llamada
        Cuentas[busqueda].ActualizarBloqueo(pCu.EstaBloqueada());
        ok = true;

    /*  FORMA ALTERNATIVA PARA CONTROLAR EL FUNCIONAMIENTO DE ESTE METODO DESDE DENTRO
        //Bool que recogen el return del metodo
        bool bloqueoActual, bloqueoFuturo, okSaldo, okBloqueo=false;

        bloqueoActual = Cuentas[busqueda].EstaBloqueada();//Objeto del vector
        bloqueoFuturo = pCu.EstaBloqueada(); //Objeto del parametro

        if(bloqueoActual==bloqueoFuturo)//Si  ninguna esta bloqueada, permite hacer la operacion de saldo
            {
                okSaldo = Cuentas[busqueda].ActualizarSaldo(pCu.DameSaldo());//False si esta bloquedada

            }
        else //Si se ha editado el atributo bloqueo en la llamada a esta funcion
        {
            Cuentas[busqueda].ActualizarBloqueo(pCu.EstaBloqueada());//Este metodo es void asi que se asume que siempre sale bien la operacion
            okBloqueo=true;
        }
        ok = okSaldo+okBloqueo; //Si ha salido bien una de las dos operaciones (Solo puede fallar la de saldo por estar bloqueda)
    */
    }
    return ok;//False si no existe la cuenta
}

bool Cliente::BorrarCuenta(int pNoCuenta)
{
    bool ok;
    int busqueda = BuscarCuenta(Cuentas, noCuentas, pNoCuenta);
    if(busqueda == -1)
        ok = false;
    else
    {

        for(int i=busqueda; i<noCuentas; i++)
            Cuentas[i] = Cuentas[i+1];
        noCuentas--;
        ok = true;

    }
    return ok;
}

void Cliente::Mostrar(char Campo)
{
    if(Campo == 's' || Campo == 't' )
        cout << "\nNombre: " << Nombre
        << "\nDireccion: " << Direccion<<endl;
    if(Campo == 'c' || Campo == 't' )

        for(int i=0; i<noCuentas; i++)
        {
            cout << "\nCUENTA: " << Cuentas[i].DameNoCuenta()<<
                        "\nSALDO: " << Cuentas[i].DameSaldo() <<
                        "\nESTADO: ";
            if(Cuentas[i].EstaBloqueada()) cout << "BLOQUEADA"<<endl;
            else cout << "DISPONIBLE"<<endl;
        }
}

int BuscarCliente(Cliente Ctes[MAX_CLIENTES], int NCtes, Cadena Nombre)
{
    int posicion = -1, i = 0;
    bool encontrado = false;
    Cadena NombreTemp;

    while(i<NCtes && !encontrado)
    {
        Ctes[i].DameNombre(NombreTemp);
        if(strcmp(Nombre,NombreTemp)==0)
        {
            encontrado = true;
            posicion = i;
        }
        else
            i++;
    }
    return posicion;
}

int Menu()
{
    int respuesta;

    cout << "\t\tMenu Principal"<<
                "\n 1 Anadir un cliente"<<
                "\n 2 Actualizar Direccion del Cliente" <<
                "\n 3 Mostrar un cliente" <<
                "\n 4 Mostrar todos los clientes" <<
                "\n 5 Submenu Gestion de Cuentas" <<
                "\n 6 Salir\n\nElige Opcion -> ";

    cin>>respuesta;
    return respuesta;
}

int MenuCuentas()
{
    int respuesta;

    cout <<"\tMenu Gestion de Cuentas" <<
                "\n 1 Anadir una cuenta a un cliente"<<
                "\n 2 Mostrar las cuentas del ciente"<<
                "\n 3 Borrar una cuenta del cliente"<<
                "\n 4 Modificar Saldo de una cuenta"<<
                "\n 5 Modificar Estado de una cuenta"<<
                "\n 6 Salir"<<
                "\n\nElige Opcion: ";
    cin >> respuesta;
    return respuesta;
}

int main()
{

    Cliente Datos[MAX_CLIENTES];

    int nClientes=0;//Numero de clientes en el vector Datos
    bool SalirMenuClientes=false;

    do
    {
        system("cls");
        switch(Menu())
        {
        case 1:
            {//Llaves para que las variables locales se destruyan
                system("cls");
                Cadena NombreNuevo;
                Cadena DireccionNuevo;

                cout << "\nIntroduce el nombre del cliente -> ";
                cin >> NombreNuevo;
                int busqueda = BuscarCliente(Datos, nClientes, NombreNuevo);
                if(busqueda != -1)//No deja crear cliente con el mismo nombre, porque si no, solo se podra operar con la primera ocurrencia en el vector de clientes
                    {
                        cout << "\nError: ya existe el cliente: ";
                        Datos[busqueda].Mostrar('t');
                    }
                else
                {
                    cout << "\nIntroduce la direccion del cliente -> ";
                    cin >> DireccionNuevo;
                    //Se actualiza el ultimo objeto de vector
                    Datos[nClientes].ActualizarCliente(NombreNuevo,DireccionNuevo);
                    nClientes++;
                    cout << "\nCliente creado con exito!";
                }
                cout << endl;
                system("pause");
                break;
            }
        case 2:
            {
                system("cls");
                Cadena NombreBuscar;
                Cadena DireccionActualizar;

                cout << "\nIntroduce el nombre del cliente -> ";
                cin >> NombreBuscar;

                int busqueda = BuscarCliente(Datos,nClientes,NombreBuscar);
                if(busqueda==-1)
                    cout << "\nError: el cliente no se ha encontrado!";
                else
                {
                    Datos[busqueda].Mostrar('s');//Muestra la direccion actual
                    cout << "\nIntroduce la nueva direccion -> ";
                    cin >> DireccionActualizar;

                    Datos[busqueda].ActualizarCliente(NombreBuscar, DireccionActualizar);
                    cout << "\nDatos actualizados con exito!";
                }
                cout << endl;
                system("pause");
                break;
            }
        case 3:
            {
                system("cls");
                Cadena NombreBuscar;

                cout<<"\nIntroduce el nombre del cliente a mostrar -> ";
                cin >> NombreBuscar;

                int busqueda = BuscarCliente(Datos, nClientes, NombreBuscar);
                if(busqueda == -1)
                    cout << "\nError: cliente no encontrado!";
                else
                    Datos[busqueda].Mostrar('t');
                cout << endl;
                system("pause");
                break;
            }
        case 4:
            {
                system("cls");
                int i;

                for(i=0; i<nClientes; i++)
                {
                    Datos[i].Mostrar('t');
                    cout<<"\n-------------\n";
                }
                system("pause");
                break;
            }
        case 5:
            {
            bool SalirMenuCuentas;
            system("cls");
            Cadena NombreCliente;
            cout << "\nIntroduce el nombre del cliente -> ";
            cin >> NombreCliente;

            int busqueda = BuscarCliente(Datos, nClientes, NombreCliente);
            if(busqueda == -1)
            {
                cout << "\nError: cliente no encontrado!"<<endl;
                system("pause");
            }
            else//Entra en el menu de cuentas del cliente
            {
                int noCuentas = Datos[busqueda].DameNoCuentas(); //Se usa en varios cases

                do{
                    SalirMenuCuentas=false;
                    system("cls");
                    switch(MenuCuentas())
                    {
                        case 1:
                        {
                            system("cls");
                            int noCuentaTemp;
                            float SaldoTemp;

                            cout << "\nIntroduce el numero de cuenta -> ";
                            cin >> noCuentaTemp;
                            cout << "\nIntroduce el saldo -> ";
                            cin >> SaldoTemp;
                            //Usando el constructor parametrizado:
                            Cuenta Temp(noCuentaTemp, SaldoTemp); //Crea una cuenta con los datos recogidos
                            if(Datos[busqueda].CrearCuenta(Temp))//Intenta añadir la cuenta al vector
                                cout << "\nCuenta creada con exito!";//Los mensajes de error se controlan en el metodo

                            cout<<endl;
                            system("pause");
                            break;
                        }
                        case 2: //Forma de mostrarlo para que no salga descuadrado
                        {
                            system("cls");
                            Datos[busqueda].Mostrar('c');
                            cout<<endl;
                            system("pause");
                            break;
                        }
                        case 3:
                        {
                            system("cls");
                            int noCuentaEliminar;

                            cout << "Introduce el numero de cuenta a eliminar -> ";
                            cin >>noCuentaEliminar;

                            bool operacion = Datos[busqueda].BorrarCuenta(noCuentaEliminar);
                            if(operacion)
                                cout << "\nCuenta eliminada con exito!";
                           else
                                cout << "\nError: cuenta no encontrada!";

                            cout<<endl;
                            system("pause");
                            break;
                        }
                        case 4:
                        {
                            system("cls");
                            int noCuentaBuscar;
                            float SaldoNuevo;

                            cout << "\nIntroduce el numero de cuenta -> ";
                            cin >> noCuentaBuscar;

                            //Comprueba que la cuenta exista
                            int busquedaCuenta = Datos[busqueda].BuscarCuentaCliente(noCuentaBuscar);
                            if(busquedaCuenta == -1)
                                cout << "\nError: no se ha encontrado la cuenta!";
                            else
                            {
                                cout << "\nIntroduce el nuevo saldo -> ";
                                cin >> SaldoNuevo;

                                //Se crea una cuenta copia para actualizarla
                                Cuenta CuentaActualizada = Datos[busqueda].DameCuenta(busquedaCuenta);
                                bool operacion = CuentaActualizada.ActualizarSaldo(SaldoNuevo);//ActualizarSaldo impide cambiar el saldo si esta bloqueada

                                if (operacion)
                                    {
                                        Datos[busqueda].ActualizarCuenta(CuentaActualizada);//Sube la cuenta al vector. La llamada a este metodo permite controlar que exista la cuenta, pero ya se ha hecho anteriormente
                                        cout << "\nSaldo actualizado con exito!";
                                    }
                                else
                                    cout << "\nError: cuenta bloqueada!";//Actualizar saldo es false
                            }
                            cout<<endl;
                            system("pause");
                            break;
                        }
                        case 5:
                        {
                        system("cls");
                        int noCuentaActualizar;
                        char respuesta;
                        bool bloquear, error=false, okActualizar;


                        cout << "\nIntroduce el numero de cuenta -> ";
                        cin >> noCuentaActualizar;

                        int busquedaCuenta = Datos[busqueda].BuscarCuentaCliente(noCuentaActualizar);
                        if(busquedaCuenta != -1)
                        {
                            do
                            {
                                cout << "\nDesea bloquear la cuenta (1) o desbloquearla (2) -> ";
                                cin >> respuesta;

                                switch(respuesta)//Uso switch pq permite controlar errores con default mas facilmente
                                {
                                case '1':
                                    bloquear = true;
                                    break;
                                case '2':
                                    bloquear = false;
                                    break;
                                default:
                                    cout << "\nError: respuesta no valida!";
                                    error = true;
                                }
                            }while(error);

                            Cuenta BloqueoActualizado = Datos[busqueda].DameCuenta(busquedaCuenta);//Crea una cuenta nueva copiando los atributos
                            if(BloqueoActualizado.EstaBloqueada()==bloquear)
                                cout << "\nError: La cuenta ya se encuentra en ese estado! No habra ningun cambio...";
                            else//Deja hacer la llamada al metodo ActualizarCuenta con bloqueoActual != bloqueoFuturo
                            {
                                BloqueoActualizado.ActualizarBloqueo(bloquear);//Edita el atributo bloqueo segun la respuesta
                                okActualizar = Datos[busqueda].ActualizarCuenta(BloqueoActualizado); //Actualiza la cuenta en el vector cuentas del cliente y recoge si la operacion ha salido bien
                                cout << "\nCuenta actualizada con exito!";

                            }
                        }
                        else //(busquedaCuenta == -1)
                            cout << "\nError: la cuenta no existe";
                        cout<<endl;
                        system("pause");
                        break;
                    }
                        case 6:
                        {
                            SalirMenuCuentas = true;
                            break;
                        }
                        default:
                        {
                            cout << "\nError: opcion no valida"<<endl;
                            system("pause");
                        }

                    }//switch cuentas
                    }while(!SalirMenuCuentas);
            }//else (cliente encontrado)
            break;
            }//case 5
        case 6:
            {
                SalirMenuClientes = true;
                cout << "\nAdios!";
                break;
            }
        default:
            {
                cout << "\nError: opcion no valida!"<<endl;
                system("pause");
            }
        }//switch

    }while(!SalirMenuClientes);

    return 0;
}
