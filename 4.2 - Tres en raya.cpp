/*

    Autor: Vik
    Fecha: 08/12/17

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
    cout <<"TRES EN RAYA ---- TURNO: "<<turno<<"\n\n1 2 3\t"<<Tablero[0][0]<<'|'<<Tablero[0][1]<<'|'<<Tablero[0][2]<<
    "\n\t-+-+-\n4 5 6\t"<<Tablero[1][0]<<'|'<<Tablero[1][1]<<'|'<<Tablero[1][2]<<
    "\n\t-+-+-\n7 8 9\t"<<Tablero[2][0]<<'|'<<Tablero[2][1]<<'|'<<Tablero[2][2]<<"\n\n\n";

}

bool TicTacToe::PonerFicha(char ficha, int fila, int columna)
{
    if(Tablero[fila][columna] == ' ')
        Tablero[fila][columna] = ficha;
    else
        return false;
    return true;

}

bool TicTacToe::ComprobarFila(char ficha, int fila)
{
    if(ficha == Tablero[fila][0] && ficha == Tablero[fila][1] && ficha == Tablero[fila][2])
        return true;
    else return false;
}

bool TicTacToe::ComprobarColumna(char ficha, int columna)
{
    if(ficha == Tablero[0][columna] && ficha == Tablero[1][columna] && ficha == Tablero[2][columna])
        return true;
    else return false;
}

bool TicTacToe::ComprobarDiagonal(char ficha, int fila, int columna)
{
    if((fila==0 && columna!=1)|| (fila==1 && columna==1) || (fila == 2 && columna != 1))
    {
        if(fila==1 && columna==1)
        {
            if((ficha == Tablero[fila-1][columna+1] && ficha==Tablero[fila+1][columna-1]) || (ficha == Tablero[fila-1][columna-1] && ficha==Tablero[fila+1][columna+1]))
                return true;
            else return false;
        }

        else if(fila == 0)
        {
            if((ficha==Tablero[1][columna+1] && ficha==Tablero[2][columna+2]) || (ficha==Tablero[1][columna-1] && ficha==Tablero[2][columna-2]))
                return true;
            else return false;
        }

        else if(fila == 2)
        {
            if((ficha==Tablero[1][columna+1] && ficha==Tablero[0][columna+2]) || (ficha==Tablero[1][columna-1] && ficha==Tablero[0][columna-2]))
                return true;
            else return false;
        }
    }
    else return false;
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
        cout <<"["<<ficha<<"] Indica la casilla a rellenar (1-9) -> ";
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
