// Librerias y definiciones

#include <iostream>
#include <string>
#include "opciones.h"
#include "matriz.h"

using namespace std;


// Metodos del objeto Matriz

void Matriz::setOrden(){
	
	
	
}

void Matriz::setContenido(){
	
	
	
}

void Matriz::getContenido(){
	
	// Usamos un doble for para imprimir la matriz
	
	for(int i=0; i < this->ordMat; i++){ // Recorre filas
		for(int j=0; j < this->ordMat; j++){ // Recorre columnas
			
			// Imprime la posicion [i][j] de la matriz
			cout<<"\t["<<*(*(this->contMat+i)+j)<<"]\t";
			
		}
		
		// Salto de linea entre cada fila
		cout<<"\n";
		
	}
	
	
}

void Matriz::trasponer(){
	
	
	
}

void Matriz::liberar(){
	
	// Liberamos la memoria de las columnas
	for(int i=0; i < this->ordMat; i++){
		
		delete this->contMat[i];
		
	}
	
	// Liberamos la memoria de las filas
	delete this->contMat;
	
}
