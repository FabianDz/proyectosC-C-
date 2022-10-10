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
        	this->contMat = new float*[3];
        	// Se reserva la memoria de las columnas de la matriz
        	for(int i=0; i<3; i++){
        		this->contMat[i] = new float[3];
        	}
        	
        }
        
        // Inspiracion tomada a partir de los videos del
        // curso de C++ de Programacion ATS
        // https://www.youtube.com/playlist?list=PLWtYZ2ejMVJlUu1rEHLC0i_oibctkl0Vh
        // -
        // Así como también lo visto en el curso de Java de PROTECO
        
        // Metodos
        
        void setOrden();
        void setContenido();
        void getContenido();
        void trasponer();
		void liberar();
        
};

#endif
