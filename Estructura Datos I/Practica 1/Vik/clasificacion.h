#ifndef CLASIFICACION.H
#define CLASIFICACION.H

using namespace std;

struct Corredor {
    int indice;
	int dorsal;
	int marca;
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
#endif // CLASIFICACION
