// Bibliotecas
#include <string>

using namespace std;

// indef
#ifndef MATRIZ_H_
#define MATRIZ_H_

// Clase Matriz
class Matriz{

    public:
    	
		// Atributos
		
        int ordMat; // Orden de las matrices
        float **contMat; // Matriz
        
        // Constructor
        
        Matriz(){
        	
        	// Se le asigna un orden de 3 por defecto
        	this->ordMat = 3;
        	
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
        
        // Inspiracion tomada a partir de los videos del
        // curso de C++ de Programacion ATS
        // https://www.youtube.com/playlist?list=PLWtYZ2ejMVJlUu1rEHLC0i_oibctkl0Vh
        // -
        // Así como también lo visto en el curso de Java de PROTECO
        
        // Metodos
        
        void setOrden(int); // Cambia el orden de la matriz
        void setContenido(); // Cambia el contenido de la matriz
        void getContenido(); // Imprime el contenido de las matrices
        void transponer(); // Traspone la matriz
		void liberar(); // Libera la matriz
        
};

#endif
