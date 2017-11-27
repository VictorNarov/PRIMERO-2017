#include <iostream>

using namespace std;
#define M 10
#define N 15

class tres{
    int tabla[M][N];
public:
    void cargar();
    int encontrar();
};

void tres::cargar(){
    for(int i=0;i<10;i++){
        for(int j=0;j<15;j++){
            tabla[i][j] = i*j;
        };
    };
};

int tres::encontrar(){
    int num,check=0;
    cout << "Input the value to find: ";
    cin >> num;
    for(int i=0;i<10;i++){
        for(int j=0;j<15;j++){
            if(tabla[i][j] == num){
                check=1;
            };
        };
    };
    return check;
}

int main()
{
    tres t;
    t.cargar();
    cout << t.encontrar();
    return 0;
}
