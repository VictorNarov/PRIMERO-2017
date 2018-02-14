        #include <iostream>
        #include <ctype.h>
        #include <cstdlib>
        using namespace std;


        class Numeros{

        int n1,n2;
        public:

            void cargar();
            int Num1();
            int Num2();
            int Suma();
            int Resta();
            int Multiplicacion();
            float Division();


        };

        void Numeros::cargar(){
        cout << "Numeros: ";
        cin >> n1 >> n2;

        }

        int Numeros::Num1(){

        return n1;
        }
        int Numeros::Num2(){

        return n2;
        }

        int Numeros::Suma(){

        return n1+n2;
        }
        int Numeros::Resta(){

        return n1-n2;
        }
        int Numeros::Multiplicacion(){

        return n1*n2;
        }
        float Numeros::Division(){

        return (float)n1/n2;
        }

        int main()
        {
        Numeros N;
        char opcion;
        N.cargar();

        do
        {


                cout << "A. Sumar\nB. Restar\nC. Multiplicar\nD. Dividir\nE. Salir\nEscoja una opcion: ";
                cin >> opcion;

                opcion = toupper(opcion);

            switch(opcion){

            case 'A': cout << "Suma: " << N.Suma() << endl;
            break;
            case 'B': cout << "Resta: " <<N.Resta() << endl;
            break;
            case 'C': cout << "Multiplicacion: " <<N.Multiplicacion() << endl;
            break;
            case 'D': cout << "Division: " <<N.Division() << endl;
            break;
            case 'E': cout << "Adios" << endl;

            }



        }while(opcion!='E');







            return 0;
        }

