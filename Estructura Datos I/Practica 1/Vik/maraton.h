#ifndef MARATON.H
#define MARATHON.H

#include <fstream>


using namespace std;

const int TAM_CADENA = 30;
typedef char cadena[TAM_CADENA];

struct Atleta {
	int dorsal;
	cadena pais;
	cadena nombre;
	cadena apellidos;
	int marca;
	int posicion;
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


#endif // MARATON
