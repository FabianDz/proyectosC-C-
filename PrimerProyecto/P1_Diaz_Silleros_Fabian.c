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
            printf("\nmedia\n");

        else if (strcmp(opc, "mediana") == 0) // Opcion mediana : calcula la mediana
            printf("\nmediana\n");

        else if (strcmp(opc, "moda") == 0) // Opcion moda : calcula la moda
            printf("\nmoda\n");

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
    for(i=0; i<n; i++){
        pos = i;
        aux = a_datos[i];

        while ((pos>0) && (a_datos[pos-1] > aux))
        {
            a_datos[pos] = a_datos[pos-1];
            pos--;
        }
        a_datos[pos] = aux;
    }

    // Imprimimos la tabla de valores
    printf("No.\tVALOR\n");

    for(i=0; i<n; i++)
        printf("%d\t%f\n",i, a_datos[i]);

}