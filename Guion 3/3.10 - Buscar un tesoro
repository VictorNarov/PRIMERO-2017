#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

class Tesoro{
    char Tablero[25][2],TableroFalso[25][2];
    int puntos=15,tiradas=15,comprobante;
public:
    void iniciar();
    bool Jugar();
    void MostrarTablero();
};

void Tesoro::iniciar(){
    int buffer;
    for(int i=0;i<25;i++){
        Tablero[i][0] = 'A';
        Tablero[i][1] = ' ';
        TableroFalso[i][0] = '-';
        TableroFalso[i][1] = ' ';
    };
    for(int i=0;i<7;i++){
        srand(time(0)+i);
        if(i==0){
            buffer = rand()%25;
            Tablero[buffer][0] = 'T';
            Tablero[buffer][1] = ' ';
        }else if(i==1){
            buffer = rand()%25;
            Tablero[buffer][0] = 'B';
            Tablero[buffer][1] = '1';
        }else if(i<4){
            buffer = rand()%25;
            Tablero[buffer][0] = 'B';
            Tablero[buffer][1] = '2';
        }else if(i<7){
            buffer = rand()%25;
            Tablero[buffer][0] = 'B';
            Tablero[buffer][1] = '3';
        };
    };
};

bool Tesoro::Jugar(){
    int fila,columna,check=0;
    do{
        system("cls");
        comprobante = 0;
        cout << "\n\t      ---Find a Treasure---"<<endl;;
        for(int i=0;i<5;i++){
                cout << endl;
            for(int j=1;j<6;j++){
                cout << "\t" << TableroFalso[i*5+j-1][0]<< TableroFalso[i*5+j-1][1];
            };
        };
        cout << "\n\n\tAccumulated points: " << puntos <<"\n\tRemaining attempts: " << tiradas;
        cout << "\n\n\tInput the row(0-4): ";
        cin >> fila;
        cout << "\tInput the column(0-4): ";
        cin >> columna;
        if(TableroFalso[fila*5+columna][0] != '-'){
            comprobante = 1;
        }
        TableroFalso[fila*5+columna][0]=Tablero[fila*5+columna][0];
        TableroFalso[fila*5+columna][1]=Tablero[fila*5+columna][1];
        if(comprobante != 1){
            if(Tablero[fila*5+columna][0]=='B'){
                if(Tablero[fila*5+columna][1] == '1'){
                    puntos=puntos-3;
                }else if(Tablero[fila*5+columna][1] == '2'){
                    puntos=puntos-2;
                }else if(Tablero[fila*5+columna][1] == '3'){
                    puntos=puntos-1;
                };
            }else if(Tablero[fila*5+columna][0]=='A'){
                puntos=puntos+1;
            }else if(Tablero[fila*5+columna][0]=='T'){
                puntos=puntos+100;
            };
        };
        if(fila < 0 || fila > 4 ||columna < 0 || columna > 4){
            comprobante = 1;
        };
        if(comprobante == 1){
            cout << "\n\tError,you input not in range values or used values";
            sleep(4);
        }else{
        tiradas--;
        };
        if(puntos <= 0||tiradas == 0|| puntos > 100)
            check=1;
    }while(check == 0);
};

void Tesoro::MostrarTablero(){
    system("cls");
    cout << "\n\t      ---Find a Treasure---"<<endl;;
    for(int i=0;i<5;i++){
            cout << endl;
        for(int j=1;j<6;j++){
            cout << "\t" << Tablero[i*5+j-1][0]<< Tablero[i*5+j-1][1];
        };
    };
    if(puntos > 100){
        cout << "\n\n\tWell done,you find the treasure!!\n\tAccumulated points: " << puntos <<"\n\tRemaining attempts: " << tiradas;
    }else if(puntos <= 0){
        cout << "\n\n\tYou have lost all your points,good luck next time!!\n\tAccumulated points: " << puntos <<"\n\tRemaining attempts: " << tiradas;
    }else{
        cout << "\n\n\tYou have lost all your attempts,good luck next time!!\n\tAccumulated points: " << puntos <<"\n\tRemaining attempts: " << tiradas;
    }
    cout << "\n";
}

int main()
{
    Tesoro t;
    t.iniciar();
    t.Jugar();
    t.MostrarTablero();
    return 0;
}
