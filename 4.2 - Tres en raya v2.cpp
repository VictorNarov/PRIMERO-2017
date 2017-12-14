/*

    Autor: Vik
    Fecha: 13/12/17

*/

#include <iostream>
#include <cstdlib>

using namespace std;

class TicTacToe
{

char Tablero[3][3];


public:
    TicTacToe();
    void LimpiarTablero();
    void Pintar(int turno);//Parametro opcional, solo por estetica
    bool PonerFicha(char ficha, int fila, int columna);
    bool ComprobarFila(char ficha, int fila);
    bool ComprobarColumna(char ficha, int columna);
    bool ComprobarDiagonal(char ficha, int fila, int columna);
    bool TableroCompleto();
    void PedirPosicion(char ficha, int &fila, int &columna);

};

TicTacToe::TicTacToe()
{
    LimpiarTablero();
}

void TicTacToe::LimpiarTablero()
{
    int i, j;
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            Tablero[i][j] = ' ';

}

void TicTacToe::Pintar(int turno)
{
    system("cls");
    cout <<"TRES EN RAYA ---- TURNO: "<<turno<<"\n\n";
    for(int f=0; f<3; f++)
    {
        for(int c=0; c<3; c++)
        {
            cout << Tablero[f][c];
            if(c < 2)
                cout << '|';
            else
                cout << endl;
        }
        if(f < 2)
        cout << "-+-+-" << endl;
    }

}

bool TicTacToe::PonerFicha(char ficha, int fila, int columna)
{
    bool ok = true;
    if(Tablero[fila][columna] == ' ')
        Tablero[fila][columna] = ficha;
    else
        ok = false;//No se ha podido poner la ficha
    return ok;

}

bool TicTacToe::ComprobarFila(char ficha, int fila)
{
    bool victoria;
    if(ficha == Tablero[fila][0] && ficha == Tablero[fila][1] && ficha == Tablero[fila][2])
        victoria = true;
    else victoria = false;
    return victoria;
}

bool TicTacToe::ComprobarColumna(char ficha, int columna)
{
    bool victoria;
    if(ficha == Tablero[0][columna] && ficha == Tablero[1][columna] && ficha == Tablero[2][columna])
        victoria = true;
    else victoria = false;
    return victoria;
}

bool TicTacToe::ComprobarDiagonal(char ficha, int fila, int columna)//Sacar caracteristicas comunes que cumplen las diagonales
{
    bool victoria;
    int fc;

    if(fila==columna)//Se trata de una casilla en la diagonal ppal
    {
        victoria=true;//Suponemos victoria hasta comprobar lo contrario
        fc=0;
        while(fc<3 && victoria)
            if(Tablero[fc][fc] != Tablero[fila][columna])
                victoria = false;
            else
                fc++;
    }

    if( (fila==columna && fila+columna==2 && victoria==false) || fila+columna==2 )/*Si esta en la central y en la principal no victoria
                                                                                 O bien esta en la diagonal secundaria*/
    {

        victoria=true;
        fc=0;
        while(fc<3 && victoria)
            if(Tablero[2-fc][fc] != ficha)
                victoria = false;
            else
                fc++;

    }

    return victoria;
}

bool TicTacToe::TableroCompleto()
{
    int i, j;
    bool completo;

    completo = true;
    i = 0;

    while(i<3 && completo)
    {
        j = 0;
        while(j<3 && completo)
            if (Tablero[i][j] == ' ') return false;
            else j++;

        if(completo) i++;
    }
    return completo;

}

void TicTacToe::PedirPosicion(char ficha, int &fila, int &columna)
{

    int casilla;
    do{
        cout <<"\n["<<ficha<<"] Indica la casilla a rellenar (1-9) -> ";
        cin >> casilla;

        switch(casilla)
        {
        case 1:
            fila = columna = 0;
            break;
        case 2:
            fila = 0; columna = 1;
            break;
        case 3:
            fila = 0; columna = 2;
            break;
        case 4:
            fila = 1; columna = 0;
            break;
        case 5:
            fila = columna = 1;
            break;
        case 6:
            fila = 1; columna = 2;
            break;
        case 7:
            fila = 2; columna = 0;
            break;
        case 8:
            fila = 2; columna = 1;
            break;
        case 9:
            fila = columna = 2;
            break;

        default:
            cout << "\nError: casilla no valida...\n";
        }
    }while(casilla < 1 || casilla > 9);
}


int main()
{

TicTacToe pepe;

char ficha, continuar;
int fila, columna, turno;
do{
    ficha = 'X';
    turno = 0;
    pepe.Pintar(0);
    bool terminado = false;

    while(!terminado)
    {
        pepe.PedirPosicion(ficha, fila, columna);

        if(!pepe.PonerFicha(ficha, fila, columna))
            cout << "\nError: casilla llena\n";

    else{

        pepe.Pintar(turno);

        if(pepe.ComprobarColumna(ficha, columna) || pepe.ComprobarFila(ficha, fila) || pepe.ComprobarDiagonal(ficha, fila, columna))
        {
            cout << "\n\nFin del juego: [" << ficha <<"] ha ganado!";
            terminado = true;
        }

        else if(pepe.TableroCompleto()){
            cout << "\n\nFin del juego: Empate!";
            terminado = true;
        }

        else if(ficha == 'X')
            ficha = 'O';
        else ficha = 'X';

        turno++;
        }
    }




    pepe.LimpiarTablero();
    cout << "\nDeseas seguir jugando (s/n) -> ";
    cin >> continuar;
}while(continuar == 's' || continuar == 'S');

cout << "\nAdios!";



return 0;
}
