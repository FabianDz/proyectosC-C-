/*
    Calculadora de Matrices por linea de comando.

    Elaboro: Diaz Silleros Fabian Josafat

    PROTECO Cursos Prebecarios: C/C++. Proyecto 2.

*/

// Bibliotecas y definiciones

#include <iostream>
#include <string>
#include "opciones.h"

using namespace std;

// Funcion main

int main(){

    string opcion; // String de opciones del menu
    char matrizSel = 'Z'; // Char que identifica con que matriz vamos a trabajar

    while (true) // loop while que no va a terminar hasta que se teclee salir
    {
		
		cout<<">>"; // Imprimimos el prompt
		getline(cin, opcion); // Leemos opcion

        // Cadena de ifs con metodo compare de la lib string

        if(opcion.compare("ayuda") == 0){ // Caso Opcion Ayuda
            
            ayuda(); // Llamamos funcion ayuda en opciones.cpp

        }
        else if(opcion.compare("redimensionar") == 0){ // Caso Opcion Redimensionar
            
            redimensionar(); // Llamamos funcion redimensionar en opciones.cpp

        }
        else if(opcion.compare("llenar A") == 0 || opcion.compare("llenar a") == 0){ // Caso Opcion llenar matriz A
            
            matrizSel = 'A'; // Asignamos A a matriz Seleccionada
            llenar(matrizSel); // Llamamos funcion llenar

        }
        else if(opcion.compare("llenar B") == 0 || opcion.compare("llenar b") == 0){ // Caso Opcion llenar matriz B
            
            matrizSel = 'B'; // Asignamos B a matriz Seleccionada
            llenar(matrizSel); // Llamamos funcion llenar

        }
        else if(opcion.compare("llenar C") == 0 || opcion.compare("llenar c") == 0){ // Si el usuario quiere rellenar matriz C
            
            cout<<"\nNo puedes llenar la matriz C"<<endl;
            
        }
        else if(opcion.compare("imprimir A") == 0 || opcion.compare("imprimir a") == 0){ // Caso Opcion llenar matriz A
            
            matrizSel = 'A'; // Asignamos A a matriz Seleccionada
            imprimir(matrizSel); // Llamamos funcion imprimir

        }
        else if(opcion.compare("imprimir B") == 0 || opcion.compare("imprimir b") == 0){ // Caso Opcion llenar matriz B
            
            matrizSel = 'B'; // Asignamos B a matriz Seleccionada
            imprimir(matrizSel); // Llamamos funcion imprimir

        }
        else if(opcion.compare("imprimir C") == 0 || opcion.compare("imprimir c") == 0){ // Caso Opcion llenar matriz B
            
            matrizSel = 'C'; // Asignamos C a matriz Seleccionada
            imprimir(matrizSel); // Llamamos funcion imprimir

        }
        else if(opcion.compare("sumar") == 0){ // Caso Opcion Sumar matrices A y B
            
            sumar(); // Llamamos a la funcion sumar

        }
        else if(opcion.compare("restar") == 0){ // Caso Opcion Restar matrices A y B
            
            restar(); // Llamamos a la funcion restar

        }
        else if(opcion.compare("multiplicar") == 0){ // Caso Opcion Multiplicar matrices A y B
            
            multiplicar(); // Llamamos a la funcion multiplicar

        }
        else if(opcion.compare("transponer A") == 0 || opcion.compare("transponer a") == 0){ // Caso Opcion transponer matriz A
            
            matrizSel = 'A'; // Asignamos A a matriz Seleccionada
            transponer(matrizSel); // Llamamos funcion transponer

        }
        else if(opcion.compare("transponer B") == 0 || opcion.compare("transponer b") == 0){ // Caso Opcion transponer matriz B
            
            matrizSel = 'B'; // Asignamos B a matriz Seleccionada
            transponer(matrizSel); // Llamamos funcion transponer

        }
        else if(opcion.compare("transponer C") == 0 || opcion.compare("transponer c") == 0){ // Caso Opcion transponer matriz B
            
            matrizSel = 'C'; // Asignamos C a matriz Seleccionada
            transponer(matrizSel); // Llamamos funcion transponer

        }
        else if(opcion.compare("salir") == 0){ // Caso Opcion salir
            
            break; // Rompe el ciclo While

        }
		else{
            cout<<"Comando no valido, intenta de nuevo, sino, pide ayuda con 'ayuda'."<<endl;
        }
        
        // Un endl para dejarlo bonito
        cout<<endl;

    }
    
    // Llamamos funcion que llama el metodo que libera los espacios de memoria
    liberarMat();
    
    
    cout<<"Gracias por utilizar la mejor calculadora de matrices del mundo, nos vemos!"<<endl;

    return 0;
}
