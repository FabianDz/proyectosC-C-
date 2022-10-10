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
