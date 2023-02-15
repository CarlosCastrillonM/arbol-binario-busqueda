#include <iostream>
#include <locale.h>			//incluye un soporte para amplios tipos de caracteres
#include <wchar.h>			//incluye el soporte para distintos tipos de formatos de fecha, moneda, texto, etc.
#include "Arbol_Bin.h"

using namespace std;

void test();

int main(){
	
	setlocale(LC_ALL, "Spanish");		//idioma y acentos
	
	Arbol_Bin arbolito;
	int op, num, valor, numEliminar;
	
	do{
	
	cout	<<"\n"
            << "           ===========================================\n"
            << "           |           SELECCIONE UNA OPCION         |\n"
            << "           ===========================================\n";

        cout<< "\n\n1. Insertar Número   \n2. Mostrar Árbol  \n3. Buscar Entero   \n4. Recorrer en preOrden   \n5. Recorrer en inOrden" 
			<<  "\n6. Recorrer en posOrden   \n7. Recorrer por Niveles   \n8. Eliminar Nodo del Árbol   \n9. Limpiar Pantalla   \n10. Cerrar Programa\n\n";
        cin >> op;
        
        switch (op){
        	
        	case 1:
        		cout<<"\nDigite el nï¿½mero a ingresar en el Árbol: ";
        		cin>>num;
        		
        		arbolito.insertarDato(num);
        		cout<<"\n";
        	break;
        	
			case 2:
				arbolito.mostrarArbol(0);
        	break;
        	
        	case 3:
				cout<<"Digite el número a buscar: ";
				cin>>valor;

				if(arbolito.buscarDato(valor)){
					cout<<"Se encontró el valor a buscar ...";
				
				}else{
					cout<<"No se pudo encontrar el valor buscado ...";
				}
        	break;
        	
        	case 4:
        		cout<<"Recorrido en PreOrden: [";
        		arbolito.preOrden();
        		cout<<"]\n\n";
        	break;
        	
        	case 5:
        		cout<<"Recorrido en InOrden: [";
        		arbolito.inOrden();
        		cout<<"]\n\n";
        	break;
        	
        	case 6:
        		cout<<"Recorrido en PosOrden: [";
        		arbolito.posOrden();
        		cout<<"]\n\n";
        	break;
        	
        	case 7:
        		for(int i = 0; i < arbolito.contarNivel(); i++){
        			cout<<"Nivel " <<i <<"\n";
        			arbolito.mostrarNivel(i);
        			cout<<"\n";
				}
        	break;
        	
        	case 8:
        		cout<<"Ingrese el número a eliminar del Árbol: ";
        		cin>>numEliminar;
        		arbolito.eliminarNodo(numEliminar);
        		cout<<"\n";
        	break;
        	
			case 9:
				system("cls");
			break;
		}
    } while(op!=10);
	
	
	
	system("PAUSE");
	return 0;
}
