#include <iostream>

using namespace std;

struct NodoInt{
	
	NodoInt *izq;
	int dato;
	NodoInt *der;
	
	NodoInt(int x){				//Constructor
		dato = x;
		izq = der = nullptr;
	}
};


class Arbol_Bin{

private:
	NodoInt *raiz = nullptr;
	void insertarDato(NodoInt *&raiz, int x);
	void mostrarArbol(NodoInt *raiz, int n);
	bool buscarDato(NodoInt *raiz, int valor);
	void preOrden(NodoInt *raiz);
    void inOrden(NodoInt *raiz);
    void posOrden(NodoInt *raiz);
    void eliminarNodo(NodoInt *&raiz, int valor);
    void mostrarNivel(NodoInt *raiz, int nivel);
    int contarNivel(NodoInt *raiz);

	static NodoInt *min(NodoInt *raiz);
	static NodoInt *max(NodoInt *raiz);
	static NodoInt *padre(NodoInt *raiz, int valor);
	static NodoInt *buscarNodo(NodoInt *raiz, int valor);
    
public:
	bool arbolVacio();
	void insertarDato(int x);
	void mostrarArbol(int n = 0);
    bool buscarDato(int valor);
    void preOrden();
    void inOrden();
    void posOrden();
    bool eliminarNodo(int valor);
    void mostrarNivel(int nivel);
    int contarNivel();
};

