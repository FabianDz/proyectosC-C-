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
    cout<<"| llenar <matriz>     | Llenar con elementos la matriz seleccionada      |"<<endl;
    cout<<"| imprimir <matriz>   | Imprimir los elementos de la matriz seleccionada |"<<endl;
    cout<<"| sumar               | Hacer la suma de A + B y guardar en C            |"<<endl;
    cout<<"| restar              | Hacer la resta de A - B y guardar en C           |"<<endl;
    cout<<"| multiplicar         | Hacer la multiplicacion de A * B y guardar en C  |"<<endl;
    cout<<"| trasponer <martiz>  | Traspone la matriz seleccionada                  |"<<endl;
    cout<<"| salir               | Sale de la calculadora                           |"<<endl;
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

}

void liberarMat(){
	
	A.liberar();
	B.liberar();
	C.liberar();
	
}
