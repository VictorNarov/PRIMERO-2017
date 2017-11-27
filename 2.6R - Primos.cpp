#include <iostream>
#include <math.h>
using namespace std;

class primo{

int n;

public:
    void cargar();
    bool esPrimo();


};

void primo::cargar(){

cout <<"Bamo a ver si es primo: ";
cin >>n;

}

bool primo::esPrimo(){

bool res = true;
int a = 0;
for(int i = 1;i<(n+1);i++){
    if(n%i==0){
        a++;
    }

    }
    if(a!=2){
    res = false;
}else{
    res = true;
}
return res;

}







int main()
{
    bool res;
primo p;
p.cargar();
res = p.esPrimo();
if(res==true){
    cout <<"ES PRIMO";
}else
cout <<"NO ES PRIMO";
return 0;
}
