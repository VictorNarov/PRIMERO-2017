    #include <iostream>
    using namespace std;
    #define M  2
    #define N  4
    typedef char cadena[30];


    struct persona{

    long dni;
    cadena nombre;


    };

    class matrices {

    persona tabla[M][N];

    public:
        void cargar();
        void encontrar();

    };

    void matrices::cargar(){

    for(int i=0;i<M;i++){
    for(int j=0;j<N;j++){
            cout << "Nombre: ";
    cin >> tabla[i][j].nombre;
    cout << "DNI: ";
    cin >> tabla[i][j].dni;

    }

    }


    }

    void matrices::encontrar(){

    int i,j;
    long dnibuscado;
    bool encontrado;

    cout << "DNI de Persona: ";
    cin >> dnibuscado;

    i= 0;
    encontrado = false;

    while(i < M && !encontrado){
            j=0;
    while (!encontrado && j < N){
        if(tabla[i][j].dni == dnibuscado)
            encontrado = true;
        else
            j++;
    }
    if(!encontrado)
    i++;
    }
if(encontrado)
    cout << "Es: " << tabla[i][j].nombre;
    else
        cout << "No esta";

    }

    int main()
    {
        matrices m;
        m.cargar();
        m.encontrar();
        return 0;
    }
