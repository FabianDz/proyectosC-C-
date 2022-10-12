// Bibliotecas y definiciones

#include <iostream>
#include <string>
#include "opciones.h"
#include "matriz.h"

using namespace std;

// Se instancian las matrices A, B, C

Matriz A;
Matriz B;
Matriz C;

// Funciones de cada una de las opciones

void ayuda(){ // Funcion que imprime el menu de opciones

    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"|                     Calculadora de Matrices - Menu                     |"<<endl;
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"| Comando             | Funcion                                          |"<<endl;
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"| ayuda               | Imprime este menu de ayuda                       |"<<endl;
    cout<<"| redimensionar       | Cambia el orden (tamaño) de las matrices a operar|"<<endl;
    cout<<"| llenar <matriz>     | Llenar con elementos la matriz seleccionada      |"<<endl;
    cout<<"| imprimir <matriz>   | Imprimir los elementos de la matriz seleccionada |"<<endl;
    cout<<"| sumar               | Hacer la suma de A + B y guardar en C            |"<<endl;
    cout<<"| restar              | Hacer la resta de A - B y guardar en C           |"<<endl;
    cout<<"| multiplicar         | Hacer la multiplicacion de A * B y guardar en C  |"<<endl;
    cout<<"| transponer <martiz> | Traspone la matriz seleccionada                  |"<<endl;
    cout<<"| salir               | Sale de la calculadora                           |"<<endl;
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

}

void redimensionar(){ // Funcion que llama al metodo para cambiar el orden
	// Variable para el nuevo orden
	int ordMat;
	
	// Avisamos que la matriz se volvera de solo ceros al cambiar el orden
	cout<<"\nAviso: Al cambiar el orden, los datos almacenados en la matriz se perderan"<<endl<<"y todos los datos de la matriz regresaran a ceros"<<endl;
	cout<<"\nDigite el nuevo orden de las matrices: ";
	
	cin>>ordMat; // Leemos el nuevo orden
	
	A.setOrden(ordMat);	// Llamamos al metodo set Orden de A con el nuevo orden
	B.setOrden(ordMat); // Llamamos al metodo set Orden de B con el nuevo orden
	C.setOrden(ordMat); // Llamamos al metodo set Orden de C con el nuevo orden
	
	cin.ignore(); // Limpiamos el Buffer
}

void llenar(char matrizSel){ // Funcion que llama al metodo para llenar una matriz
	
	// Sentencia switch dependiendo de la matriz pedida
	switch (matrizSel){
		
		case 'A': // Si se pide imprimir A
				A.setContenido(); // Metodo para imprimir
				break;
		case 'B': // Si se pide imprimir B
				B.setContenido(); // Metodo para imprimir
				break;
	}
	
}


void imprimir(char matrizSel){ // Funcion que llama al metodo para imprimir una matriz
	
	// Sentencia switch dependiendo de la matriz pedida
	switch (matrizSel){
		
		case 'A': // Si se pide imprimir A
				A.getContenido(); // Metodo para imprimir
				break;
		case 'B': // Si se pide imprimir B
				B.getContenido(); // Metodo para imprimir
				break;
		case 'C': // Si se pide imprimir C
				C.getContenido(); // Metodo para imprimir
				break;
	}
}


void sumar(){ // Funcion que genera una suma de matrices
	
	// C = A + B
	
	for (int i=0; i < C.ordMat; i++){ // Recorremos filas
		for (int j=0; j < C.ordMat; j++){ // Recorremos Columas
	    	// Asignamos a la matriz C la suma de A y B (en los mismos indices las 3)
			*(*(C.contMat+i)+j)=*(*(A.contMat+i)+j)+*(*(B.contMat+i)+j);
		}
	}
	
}


void restar(){ // Funcion que genera una resta de matrices
	
	// C = A - B
	
	for (int i=0; i < C.ordMat; i++){ // Recorremos filas
		for (int j=0; j < C.ordMat; j++){ // Recorremos Columas
	    	// Asignamos a la matriz C la suma de A y B (en los mismos indices las 3)
			*(*(C.contMat+i)+j)=*(*(A.contMat+i)+j)-*(*(B.contMat+i)+j);
		}
	}
	
}


void multiplicar(){ // Funcion que genera una multiplicacion de matrices
	
	for(int i=0; i < C.ordMat; i++){ // Recorre filas de C
		for(int j=0; j < C.ordMat; j++){ // Recorre columnas de C
			
			C.contMat[i][j] = 0.0; // Asignamos 0 para que no se sume con valores anteriormente asignados
			
			for(int k=0; k < C.ordMat; k++){ // Elemento de A * B y se hace una suma de toda la fila de a y la columna de B
				
				C.contMat[i][j] += A.contMat[i][k] * B.contMat[k][j];
				
			}
			
		}
	}
	
	// Gracias a Yosuky por la explicacion y codigo implementado en esta funcion
	// https://www.youtube.com/watch?v=_z6dDLeRPMg
	
}


void transponer(char matrizSel){ // Funcion que llama al metodo para trasponer una matrizs
	
	// Sentencia switch dependiendo de la matriz pedida
	switch (matrizSel){
		
		case 'A': // Si se pide trasponer A
				A.transponer(); // Metodo para trasponer
				break;
		case 'B': // Si se pide trasponer B
				B.transponer(); // Metodo para trasponer
				break;
		case 'C': // Si se pide transponer C
				C.transponer(); // Metodo para transponer
				break;
	}
	
}


void liberarMat(){
	
	A.liberar();
	B.liberar();
	C.liberar();
	
}
