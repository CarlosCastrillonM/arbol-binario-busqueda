#include <iostream>
#include "Arbol_Bin.h"

using namespace std;

bool Arbol_Bin::arbolVacio(){
    return (raiz == nullptr);
}

void Arbol_Bin::insertarDato(NodoInt *&raiz, int x){
	
	if(raiz == nullptr){
		return;
	}

	if(x < raiz->dato){
		if(raiz->izq == nullptr){
			NodoInt *nuevo = new NodoInt(x);
			raiz->izq = nuevo;
			cout<<("Nodo izquierdo creado") <<endl;
		
		}else{
			insertarDato(raiz->izq, x);
		}
		
	}else{
		if(raiz->der == nullptr){
			NodoInt *nuevo = new NodoInt(x);
			raiz->der = nuevo;
			cout<<("Nodo derecho creado") <<endl;
		
		}else{
			insertarDato(raiz->der, x);
		}
	}
}

void Arbol_Bin::insertarDato(int x){
	if(arbolVacio()){
		NodoInt *nuevo = new NodoInt(x);
		raiz = nuevo;
		cout<<"/**Raiz Creada**/\n";
		
	}else{
		insertarDato(raiz, x);
	}
}


void Arbol_Bin::mostrarArbol(NodoInt *raiz, int n){
	
	if(raiz == nullptr){
		return;
	}
	
	mostrarArbol(raiz->der, n+1);

     for(int i=0; i<n; i++){
         cout<<"   ";
     }

     cout<<raiz->dato <<"\n";

     mostrarArbol(raiz->izq, n+1);
}


void Arbol_Bin::mostrarArbol(int n){
	mostrarArbol(raiz, n);
}

bool Arbol_Bin::buscarDato(NodoInt *raiz, int valor){
	
	if(raiz == nullptr){
		return false;
	}

	if(valor == raiz->dato){
		return true;
	}
	if(valor > raiz->dato){
		return buscarDato(raiz->der, valor);
	
	}else{
		return buscarDato(raiz->izq, valor);
	}
}

bool Arbol_Bin::buscarDato(int valor){
	buscarDato(raiz, valor);
}

void Arbol_Bin::preOrden(NodoInt *raiz){
	if(raiz == nullptr){
		return;
	
	}else{
		cout<<raiz->dato<<"  ";
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}

void Arbol_Bin::preOrden(){
	preOrden(raiz);
}

void Arbol_Bin::inOrden(NodoInt *raiz){
	if(raiz == nullptr){
		return;
	
	}else{
		inOrden(raiz->izq);
		cout<<raiz->dato<<"  ";
		inOrden(raiz->der);
	}
}

void Arbol_Bin::inOrden(){
	inOrden(raiz);
}

void Arbol_Bin::posOrden(NodoInt *raiz){
	if(raiz == nullptr){
		return;
	
	}else{
		posOrden(raiz->izq);
		posOrden(raiz->der);
		cout<<raiz->dato<<"  ";
	}
}

void Arbol_Bin::posOrden(){
	posOrden(raiz);
}

void Arbol_Bin::eliminarNodo(NodoInt *&raiz, int valor) {
    if (raiz == nullptr) {
        return;
    }
    
    if (valor < raiz->dato) {
        eliminarNodo(raiz->izq, valor);
    
	}else if(valor > raiz->dato){
        eliminarNodo(raiz->der, valor);
    
	}else{
        if(raiz->izq == nullptr){
            NodoInt *temp = raiz->der;
            delete raiz;
            raiz = temp;
        
		}else if(raiz->der == nullptr){
            NodoInt *temp = raiz->izq;
            delete raiz;
            raiz = temp;
        
		}else{
            NodoInt *temp = raiz->der;
         
		    while (temp->izq != nullptr){
                temp = temp->izq;
            }
            
            raiz->dato = temp->dato;
            eliminarNodo(raiz->der, temp->dato);
        }
    }
}

void Arbol_Bin::eliminarNodo(int valor){
	eliminarNodo(raiz, valor);
}



void Arbol_Bin::mostrarNivel(NodoInt *raiz, int nivel){
	
	if(raiz != nullptr){
		if(nivel == 0){
			cout<<raiz->dato <<" ";
		}
		mostrarNivel(raiz->izq, nivel-1);
		mostrarNivel(raiz->der, nivel-1);
	}
}

void Arbol_Bin::mostrarNivel(int x){
	mostrarNivel(raiz, x);
}




int Arbol_Bin::contarNivel(NodoInt *raiz){
	
	if(raiz != nullptr){
		int izq = contarNivel(raiz->izq) + 1;
		int der = contarNivel(raiz->der) + 1;
		
		if(izq > der){	//Esto es para saber si el arbol tiene ramificaciones hacia la izq o hacia la der en la parte final, para ver hasta donde dan los niveles
			return izq;
		
		}else{
			return der;
		}
	}
}

int Arbol_Bin::contarNivel(){
	return contarNivel(raiz);
}















