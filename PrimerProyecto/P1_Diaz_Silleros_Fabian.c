/*
    Calculadora de medidas de tendencia central y de dispersión
    sobre un conjunto arbitrario de datos.

    Elaboro: Diaz Silleros Fabian Josafat

    PROTECO Cursos Prebecarios: C/C++. Proyecto 1.

*/

// Bibliotecas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipos

void menu();
int mod_n(int n);
void datos(float a_datos[], int n);
void cambiar(float a_datos[], int n);
void imprimir(float a_datos[], int n);
float media(float a_datos[], int n);
float mediana(float a_datos[], int n);
float moda(float a_datos[], int n);
float varianza(float a_datos[], int n);
float desv(float a_datos[], int n);
float cuartil_1(float a_datos[], int n);
float cuartil_3(float a_datos[], int n);
float ric(float a_datos[], int n);
float rango(float a_datos[], int n);

// Funcion main

int main(){
    
    //Declaracion de la cadena de Opciones
    char opc[10];

    //Declarcion de n, total de datos
    int n = 100;

    // Declarar el arreglo dinamico de flotantes con calloc para inicializar en 0
    float *a_datos;
    a_datos = (float *) calloc(n, sizeof(float));


    // Llamado a la funcion menu para imprimirlo
    menu();

    // Bucle do while para leer opciones al menos una vez hasta que se teclee salir
    do{
        
        // Imprime > y se lee la cadena de Opciones
        
        printf("\n> ");
        fgets(opc, 10, stdin);
        opc[strcspn(opc, "\n")] = '\0'; // Asigna el final del arreglo a donde termina la string realmente (a veces puede dar errores, por culpa de saltos de linea, en el strcmp del do while) 

        // cadena de if para la ejecucion de cada una de las opciones

        if(strcmp(opc, "ayuda") == 0) // Opcion ayuda : imprime el menu
            menu();
        
        else if (strcmp(opc, "n") == 0){ // Opcion n : cambia la cantidad de datos
            n = mod_n(n); // Llamamos a la fun para cambiar n y asignamos el nuevo valor de n
            a_datos = (float*) realloc(a_datos, sizeof(float) * n); // Cambiamos el tamaño del array
        }
        
        else if (strcmp(opc, "datos") == 0) // Opcion datos : cambia todos los datos
            datos(a_datos, n); // Llamamos a la funcion
        
        else if (strcmp(opc, "cambiar") == 0) // Opcion cambiar : cambia un dato especifico
            cambiar(a_datos, n); // Llamamos a la funcion

        else if (strcmp(opc, "imprimir") == 0) // Opcion imprimir : imprime en orden todos los datos
            imprimir(a_datos, n); // Llamamos a la funcion
        
        else if (strcmp(opc, "media") == 0) // Opcion media : calcula la media
            printf("\n\n%f\n",media(a_datos, n)); // Llamamos a la funcion

        else if (strcmp(opc, "mediana") == 0) // Opcion mediana : calcula la mediana
            printf("\n\n%f\n",mediana(a_datos, n)); // Llamamos a la funcion

        else if (strcmp(opc, "moda") == 0) // Opcion moda : calcula la moda
            printf("\n\n%f\n",moda(a_datos, n)); // Llamamos a la funcion

        else if (strcmp(opc, "varianza") == 0) // Opcion varianza : calcula la varianza
            printf("\nvarianza\n");

        else if (strcmp(opc, "desvest") == 0) // Opcion desvest : calcula la desviacion estandar
            printf("\ndesvest\n");

        else if (strcmp(opc, "cuartil1") == 0) // Opcion primer cuartil : calcula el primer cuartil de los datos
            printf("\ncuartil\n");

        else if (strcmp(opc, "cuartil3") == 0) // Opcion tercer cuartil : calcula el tercer cuartil de los datos
            printf("\notrocuartil\n");

        else if (strcmp(opc, "ric") == 0) // Opcion rango int. : calcula el rango intercuartilico
            printf("\nric\n");

        else if (strcmp(opc, "rango") == 0) // Opcion rango : calcula el rango de los datos
            printf("\nrango\n");

        else if (strcmp(opc, "todos") == 0) // Opcion todos los anteriores : calcula todas las opciones
            printf("\ntodo alv\n");

        else if (strcmp(opc, "salir") == 0) // Opcion para salir
            break;

        else // En caso de digitar cualquier otra cosa
            printf("\nOpcion no valida, vuelva a intentar.\n\n");
    
    }while(1); // El bucle continuar

    // Mensaje de despedida
    printf("\n\n\tGracias por usar esta calculadora, vuelva pronto.\n\n");

    free(a_datos);
    // Retorna 0 al antes de terminar la ejecucion
    return 0;
}

void menu(){

    // Menu basado en el ejemplo de menu dado por el Titular del curso dentro del documento de especificaciones del proyecto.
    printf("\n\n------------CALCULADORA DE MEDIDAS DE TENDENCIA CENTRAL Y DISPERSION------------");
    printf("\n\nINSTRUCCIONES:  Cuando aparezca el simbolo '>', puedes teclear cualquiera de los\n\t\tcomandos que se muestran en la siguiente tabla.");
    printf("\n\n--------------------------------------------------------------------------------");
    printf("\n| COMANDO   | FUNCION                                                          |");
    printf("\n|------------------------------------------------------------------------------|");
    printf("\n| ayuda     | Imprimir nuevamente esta tabla de ayuda.                         |");
    printf("\n| salir     | Salir del Programa                                               |");
    printf("\n| n         | Cambiar cantidad de datos (por defecto, n = 100).                |");
    printf("\n| datos     | Cambiar todos los datos con los que se desea trabajar.           |");
    printf("\n| cambiar   | Cambiar un dato de una posicion en especifico.                   |");
    printf("\n| imprimir  | Imprimir los datos actuales ordenados.                           |");
    printf("\n| media     | Calcular la media aritmetica de los datos.                       |");
    printf("\n| mediana   | Calcular la mediana de los datos.                                |");
    printf("\n| moda      | Calcular la moda de los datos.                                   |");
    printf("\n| varianza  | Calcular la varianza de los datos.                               |");
    printf("\n| desvest   | Calcular la desviacion estandar de los datos.                    |");
    printf("\n| cuartil1  | Calcular el primer cuartil de los datos.                         |");
    printf("\n| cuartil3  | Calcular el tercer cuartil de los datos.                         |");
    printf("\n| ric       | Calcular el rango intercuartilico de los datos.                  |");
    printf("\n| rango     | Calcular el rango de los datos.                                  |");
    printf("\n| todos     | Calcular todas las medidas sobre los datos.                      |");
    printf("\n--------------------------------------------------------------------------------\n\n");

}

int mod_n(int n){ // Funcion de la opcion n 
    
    int i = 0; // Variable que almacenara el futuro valor de n

    printf("\nLa cantidad de datos actuales (valor de n) es: %d\n",n);
    
    while (i == 0 || i < 0)
    {
        printf("Digite la cantidad de datos que desea tener: ");
        scanf("%d", &i); // Leemos i
        getchar(); // Limpiamos el buffer
        if (i < 1) {
            printf("\nTiene que ser un valor mayor a 0, intente de nuevo\n\n.");
        }
    }

    return i; // Mandamos el nuevo valor de n

}

void datos(float a_datos[], int n){ // Funcion que cambia todos los datos

    int i=0; // Variable para iterar con el for

    for(i=0; i<n; i++){ // For para iterar dentro del arreglo de datos
        printf("\nDigite el dato de la posicion %d: ", i);
        scanf("%f", &a_datos[i]); // Leemos el valor
        getchar(); // Limpiamos buffer
    }

}

void cambiar(float a_datos[], int n){ // Funcion que cambia de un dato

    int i = -1; // Variable que va a contener la posicion de dato a cambiar 

    printf("\n\nTienes %d datos (0 - %d).", n, n-1);

    while (i < 0 || i >= n)
    {
        printf("Digite la posicion del dato que quiere cambiar: ");
        scanf("%d", &i); // Leemos i
        getchar(); // Limpiamos el buffer
        if (i < 0 || i >= n) {
            printf("\nTiene que ser un valor dentro del rango, intente de nuevo\n\n.");
        }

        printf("\nDigite el nuevo valor: ");
        scanf("%f", &a_datos[i]); // Leemos el nuevo dato
        getchar(); // Limpiamos el buffer
    }

}

void imprimir(float a_datos[], int n){ // Funcion que ordena e imprime

    // Declaramos las variables que usaremos para el ordenamiento y la impresion
    int i, pos, aux;

    printf("\n\nImprimiendo datos en orden: \n\n");

    // Metodo de ordenamiento por insercion
    for(i=0; i<n; i++){ // Fuente: Programacion ATS https://www.youtube.com/watch?v=lYNyL0HuWSg&list=PLWtYZ2ejMVJlUu1rEHLC0i_oibctkl0Vh&index=53
        pos = i; // Se asigna en posicion el valor de i
        aux = a_datos[i]; // se guarda en auxiliar el valor ubicado en el subindice (iteracion) del arreglo

        while ((pos>0) && (a_datos[pos-1] > aux)) // Mientras no sea la primera posicion y que el valor izquierdo sea mayor que el valor de la posicion actual
        {
            a_datos[pos] = a_datos[pos-1]; // Hace el cambio de valores del izquierdo al actual
            pos--; // Resta uno a la posicion para comprobar si se necesita cambiar de nuevo o ya esta acomodado el arreglo de la primera posicion a la actual
        }
        a_datos[pos] = aux; // se guarda el valor de auxiliar en la posicion que le pertenece
    }

    // Imprimimos la tabla de valores
    printf("No.\tVALOR\n");

    for(i=0; i<n; i++)
        printf("%d\t%f\n",i, a_datos[i]);

}

float media(float a_datos[], int n){ // Funcion que retorna la media

    int i; // Variable para llevar a cabo la iteracion
    float m = 0.0; // Variable donde se almacenara la media

    if (n == 1) // Si solo hay un valor, se retorna el mismo como media
        return a_datos[0];
    else{ // Si hay mas de un valor
        for (i=0; i<n; i++) // Se itera sobre el total de datos
            m += a_datos[i]; // Se suman todos los datos dentro de m
        m /= n; // Se divide la suma de los datos entre el total de datos
        return m; // Se retorna la media
    }

}

float mediana(float a_datos[], int n){ // Funcion que retorna la mediana

    int i; // Variable para guardar los indices a operar o retornar
    int j, pos, aux; // Variables para el ordenamiento
    float m = 0.0; // Variable donde se almacenara la mediana en caso de ser un arreglo par

    if (n == 1) // Si solo hay un valor, se retorna a el mismo como mediana
        return a_datos[0];
    
    // Metodo de ordenamiento por insercion
    for(j=0; j<n; j++){ // Fuente: Programacion ATS https://www.youtube.com/watch?v=lYNyL0HuWSg&list=PLWtYZ2ejMVJlUu1rEHLC0i_oibctkl0Vh&index=53
        pos = i; // Se asigna en posicion el valor de i
        aux = a_datos[i]; // se guarda en auxiliar el valor ubicado en el subindice (iteracion) del arreglo

        while ((pos>0) && (a_datos[pos-1] > aux)) // Mientras no sea la primera posicion y que el valor izquierdo sea mayor que el valor de la posicion actual
        {
            a_datos[pos] = a_datos[pos-1]; // Hace el cambio de valores del izquierdo al actual
            pos--; // Resta uno a la posicion para comprobar si se necesita cambiar de nuevo o ya esta acomodado el arreglo de la primera posicion a la actual
        }
        a_datos[pos] = aux; // se guarda el valor de auxiliar en la posicion que le pertenece
    }
    
    if ((n % 2) == 0) { // Caso de ser arreglo par
        i = (n / 2); // Se encuentra la mitad y se trunca al ser entero
        m = a_datos[i] + a_datos[i+1]; // Se suma la mitad inferior y superior
        return m; // Se devuelve la mediana
    }
    else{ // Caso de ser arreglo impar
        i = (n / 2) + 1; // Se encuentras el subindice del centro
        return a_datos[i]; // Se retorna el valor almacenado
    }

}

float moda(float a_datos[], int n){ // Funcion que retorna la moda o modas

    float m = 0.0;

    printf("\n\nModa\n");

    return m;
 
}

float varianza(float a_datos[], int n){ // Funcion que retorna la varianza

    float m = 0.0;

    printf("\n\nVarianza\n");

    return m;
 
}

float desv(float a_datos[], int n){ // Funcion que retorna la desviacion estandar

    float m = 0.0;

    printf("\n\nDesv\n");

    return m;
 
}

float cuartil_1(float a_datos[], int n){ // Funcion que retorna el primer cuartil

    float m = 0.0;

    printf("\n\nCuartil1\n");

    return m;
 
}

float cuartil_3(float a_datos[], int n){ // Funcion que retorna el tercer cuartil

    float m = 0.0;

    printf("\n\nCuartil3\n");

    return m;
 
}

float ric(float a_datos[], int n){ // Funcion que retorna el rango

    float m = 0.0;

    printf("\n\nRic\n");

    return m;
 
}

float rango(float a_datos[], int n){ // Funcion que retorna el rango

    float m = 0.0;

    printf("\n\nRango\n");

    return m;
 
}