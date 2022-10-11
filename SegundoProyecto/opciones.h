// Bibliotecas y definiciones

#include <string>
#include "matriz.h"

using namespace std;

#ifndef OPCIONES_H_
#define OPCIONES_H_

	void ayuda(); // Funcion ayuda
	void redimensionar(int ordMat); // Funcion que llama al metodo para cambiar el orden
	void llenar(char matrizSel); // Funcion que llama al metodo para llenar una matriz
	void imprimir(char matrizSel); // Funcion que llama al metodo para imprimir una matriz
	void sumar(); // Funcion que genera una suma de matrices
	void restar(); // Funcion que genera una resta de matrices
	void multiplicar(); // Funcion que genera una multiplicacion de matrices
	void trasponer(char matrizSel); // Funcion que llama al metodo para trasponer una matriz
	void liberarMat(); // Funcion que llama al metodo para liberar la memoria de las Matrices A, B y C

#endif
