const int TAM_CADENA = 30;

typedef char cadena[TAM_CADENA];

#define SALTO 4

struct Atleta {
	int dorsal;
	cadena pais;
	cadena nombre;
	cadena apellidos;
	int marca;
	int posicion;
};

struct Corredor {
    int indice;
	int dorsal;
	int marca;
};


class Maraton {
		fstream fich; //fichero primera fase
        fstream fichero; //fichero segunda fase
        int numAtletas;
	   
public:
		Maraton(char FicheroOrigen[],char FicheroDestino[]);
		~Maraton();
		int getNumAtletas() { return numAtletas; };
		void consultar(cadena pais);
		void insertar(Atleta s);
		void modificar(int dor);
		void eliminar(int dor);
		void mostrarClasificacion();
};


class Clasificacion {
		Corredor  *elementos; //elementos de la tabla
		int corredores;
		int tamano;
public:
		Clasificacion();
		~Clasificacion();
		void anadircorredor(Corredor a);
		void eliminar(int i);
		Corredor consultar(int i);
		bool vacio();
		int numcorredores();   
};

int marcas(int s) {
    return (rand()%s + 7000);
}

// METODO DE ORDENACION BURBUJA de una clase vector con los elementos en el atributo celda
void vector::Burbuja(int inicio, int fin)
        {
        int pos,ele;
        for (pos=inicio; pos<fin; pos++)
            for (ele=fin; ele>pos; ele--)
                if(celda[ele-1]>celda[ele])
                    intercambiar(celda[ele-1],celda[ele]);//Funciín genérica que tendrá que ser implementada
        }
