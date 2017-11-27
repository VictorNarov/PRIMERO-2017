#include <iostream>

using namespace std;

class calculo{
    int numero;
public:
    void informacion();
    int suma();
};

void calculo::informacion(){
    cout << "Input the max value:";
    cin >> numero;
}

int calculo::suma(){
    int num=0;
    for(int i=0;i<=numero;i++){
        int check=0;
        if(i >= 2){
            for(int j=2;j<=i;j++){
                if(i%j==0){
                    check++;
                };
            };
        };
        if(check >1){
        num=num+i;
        }
    };
    cout << num;
}
int main()
{
    calculo c;
    c.informacion();
    c.suma();
    return 0;
};
