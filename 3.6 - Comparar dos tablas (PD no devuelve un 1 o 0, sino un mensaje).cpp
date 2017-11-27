#include <iostream>



using namespace std;

class vector{

    int tab1[10],tab2[10];

public:

    void cargar();

    int comparar();

};



void vector::cargar(){

    for(int i=0;i<2;i++){

        for(int j=0;j<10;j++){

            cout << "Input the " << j << " value of the tab" << i+1 << ":";

            if(i == 1){

                cin >> tab1[j];

            }else{

                cin >> tab2[j];

            };

        };

    };

};



int vector::comparar(){

    bool iguales=true;

    for(int i=0;i<10;i++){

        if(tab1[i] != tab2[i]){

            iguales = false;

        };

    };

    bool numero=false,si=false;

    if(iguales==false){

        int i=0;

        while(!si){

            if(tab1[i] == tab2[i]){

                numero = true;

                si=true;

            };

            if(i==9){

                si=true;

            };

            i++;

        };

    };

    if(iguales==true){

        cout << "You was input the sames values in the tables";

    }else if(numero==true){

        cout << "Tables have at least one same value";

    }else{

        cout << "Tables have all different's values";

    }

};



int main()

{

    vector v;

    v.cargar();

    v.comparar();

    return 0;

}