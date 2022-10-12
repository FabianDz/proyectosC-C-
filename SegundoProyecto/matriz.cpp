// Librerias y definiciones

#include <iostream>
#include <string>
#include "opciones.h"
#include "matriz.h"

using namespace std;


// Metodos del objeto Matriz

void Matriz::setOrden(int ordMat){
	
	this->ordMat = ordMat; // Asignamos el nuevo orden
	
	// Se reserva la memoria de las filas de la matriz
    this->contMat = new float*[this->ordMat];
    // Se reserva la memoria de las columnas de la matriz
    for(int i=0; i < this->ordMat; i++){
        this->contMat[i] = new float[this->ordMat];
    }
        	
    // Inicializamos la matriz en 0
    for(int i=0; i < this->ordMat; i++){ // Recorre filas
		for(int j=0; j < this->ordMat; j++){ // Recorre columnas
	
			// Asina 0.0 a la posicion [i][j]
			this->contMat[i][j] = 0.0;
					
		}
		
	}
	
}

void Matriz::setContenido(){
	
	float numero = 0.0; // Variable para almacenar el numero
	
    for(int i=0; i < this->ordMat; i++){ // Recorre filas
		for(int j=0; j < this->ordMat; j++){ // Recorre columnas
			// Imprimimos la posicion actual
			cout<<"Ingresa el valor de la posicion ["<<i+1<<"]["<<j+1<<"]: ";
			// Leemos el numero
			cin>>numero;
			// Asignamos el numero
			this->contMat[i][j] = numero;
			// Regresamos el numero a 0
			numero = 0.0;
		}
	}
	// Limpiamos el buffer
	cin.ignore();
	
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

void Matriz::transponer(){
	
	// Agarrate que me acabo de fumar esto y no se ni como me salio bien
	
	float aux = 0.0; // Variable auxiliar
	int j = 0; // Variable j para iterar en columnas, la declaramos en 0
	
	for(int i=0; i < this->ordMat; i++){ // Recorre filas
		for(j; j < this->ordMat; j++){ // Recorre columnas
			
			
			aux = this->contMat[i][j]; // Asignamos a auxiliar el dato en [i][j]
			this->contMat[i][j] = this->contMat[j][i]; // Le asignamos a [i][j] su dato espejo [j][i]
			this->contMat[j][i] = aux; // Al dato espejo le asignamos el dato [i][j]
			
		}
		
		// Al final de la iteracion en columnas, estan cambiadas en espejo toda la fila 0 y la columna 0
		// Con j = i + 2 hacemos que j vuelva a ser iterable en el for de columnas
		// pero le sumamos 2, para de esta forma no empezar desde la columna 0
		// de esta forma haciendo el siguiente espejo esperado
		j = i + 2;
		
	}
	
}

void Matriz::liberar(){
	
	// Liberamos la memoria de las columnas
	for(int i=0; i < this->ordMat; i++){
		
		delete this->contMat[i];
		
	}
	
	// Liberamos la memoria de las filas
	delete this->contMat;
	
}
