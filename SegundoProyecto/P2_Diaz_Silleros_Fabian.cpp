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
    char matrizSel = 0; // Char que identifica con que matriz vamos a trabajar

    while (true) // loop while que no va a terminar hasta que se teclee salir
    {
		
		cout<<">>"; // Imprimimos el prompt
		getline(cin, opcion); // Leemos opcion

        // Cadena de ifs con metodo compare de la lib string

        if(opcion.compare("ayuda") == 0){ // Caso Opcion Ayuda
            
            ayuda(); // Llamamos funcion ayuda en opciones.cpp

        }
        else if(opcion.compare("redimensionar") == 0){ // Caso Opcion Redimensionar
            
            cout<<"Ahorita te la redimensiono"<<endl;

        }
        else if(opcion.compare("llenar A") == 0 || opcion.compare("llenar a") == 0){ // Caso Opcion llenar matriz A
            
            cout<<"Ahorita te la lleno a"<<endl;

        }
        else if(opcion.compare("llenar B") == 0 || opcion.compare("llenar b") == 0){ // Caso Opcion llenar matriz B
            
            cout<<"Ahorita te la lleno b"<<endl;

        }
        else if(opcion.compare("imprimir A") == 0 || opcion.compare("imprimir a") == 0){ // Caso Opcion llenar matriz A
            
            cout<<"Ahorita te imprimo a"<<endl;

        }
        else if(opcion.compare("imprimir B") == 0 || opcion.compare("imprimir b") == 0){ // Caso Opcion llenar matriz B
            
            cout<<"Ahorita te la imprimo b"<<endl;

        }
        else if(opcion.compare("sumar") == 0){ // Caso Opcion Sumar matrices A y B
            
            cout<<"Ahorita te la sumo"<<endl;

        }
        else if(opcion.compare("restar") == 0){ // Caso Opcion Restar matrices A y B
            
            cout<<"Ahorita te la resto"<<endl;

        }
        else if(opcion.compare("multiplicar") == 0){ // Caso Opcion Multiplicar matrices A y B
            
            cout<<"Ahorita te la multiplico"<<endl;

        }
        else if(opcion.compare("trasponer A") == 0 || opcion.compare("trasponer a") == 0){ // Caso Opcion trasponer matriz A
            
            cout<<"Ahorita te la traspongo a"<<endl;

        }
        else if(opcion.compare("trasponer B") == 0 || opcion.compare("trasponer b") == 0){ // Caso Opcion trasponer matriz B
            
            cout<<"Ahorita te la traspongo b"<<endl;

        }
        else if(opcion.compare("salir") == 0){ // Caso Opcion salir
            
            break; // Rompe el ciclo While

        }
		else{
            cout<<"Comando no valido, intenta de nuevo, sino, pide ayuda con 'ayuda'."<<endl;
        }

    }
    
    // Llamamos funcion que llama el metodo que libera los espacios de memoria
    liberarMat();
    
    
    cout<<"Gracias por utilizar la mejor calculadora de matrices del mundo, nos vemos!"<<endl;

    return 0;
}
