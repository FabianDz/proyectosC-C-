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
#include <math.h>

// Prototipos

void menu();
int mod_n(int n);
void datos(float a_datos[], int n);
void cambiar(float a_datos[], int n);
void ordenar(float a_datos[], int n);
void imprimir(float a_datos[], int n);
float media(float a_datos[], int n);
float mediana(float a_datos[], int n);
void moda(float a_datos[], int n);
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
            moda(a_datos, n); // Llamamos a la funcion

        else if (strcmp(opc, "varianza") == 0){ // Opcion varianza : calcula la varianza
            if (n == 1){
                printf("\n\nNo se puede calcular la varianza de un solo dato.\n");
            }
            printf("\n\n%f\n",varianza(a_datos,n));
        }
        else if (strcmp(opc, "desvest") == 0){ // Opcion desvest : calcula la desviacion estandar
            if (n == 1){
                printf("\n\nNo se puede calcular la desviacion de un solo dato.\n");
            }
            printf("\n\n%f\n",desv(a_datos,n));
        }

        else if (strcmp(opc, "cuartil1") == 0) // Opcion primer cuartil : calcula el primer cuartil de los datos
            printf("\n\n%f\n",cuartil_1(a_datos,n));   
    
        else if (strcmp(opc, "cuartil3") == 0) // Opcion tercer cuartil : calcula el tercer cuartil de los datos
            printf("\n\n%f\n",cuartil_3(a_datos,n));

        else if (strcmp(opc, "ric") == 0) // Opcion rango int. : calcula el rango intercuartilico
            printf("\n\n%f\n",ric(a_datos,n));

        else if (strcmp(opc, "rango") == 0) // Opcion rango : calcula el rango de los datos
            printf("\n\n%f\n",rango(a_datos,n));

        else if (strcmp(opc, "todos") == 0){ // Opcion todos los anteriores : calcula todas las opciones
            printf("\n\nEstos son tus datos: \n");
            imprimir(a_datos, n); // Llamamos a la funcion de imprimir

            printf("\n-------------------------------------");
            printf("\n|\tmedia:\t%f",media(a_datos, n));
            printf("\n|\tmediana:\t%f",mediana(a_datos, n));
            moda(a_datos, n);
            if (n == 1){
                printf("\t| No se puede calcular la varianza y desviacion de un solo dato.");
            }
            else{
                printf("\n|\tvarianza:\t%f",varianza(a_datos, n));
                printf("\n|\tdesviacion:\t%f",desv(a_datos,n));
            }
            printf("\n|\tCuartil 1:\t%f",cuartil_1(a_datos,n));
            printf("\n|\tCuartil 3:\t%f",cuartil_3(a_datos,n));
            printf("\n|\tRango Intercuartil:\t%f",ric(a_datos,n));
            printf("\n|\tRango:\t%f",rango(a_datos,n));
        }
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
    
    while (i == 0 || i < 0 || i > 100)
    {
        printf("Digite la cantidad de datos que desea tener: ");
        scanf("%d", &i); // Leemos i
        getchar(); // Limpiamos el buffer
        if (i < 1 || i > 100) {
            printf("\nTiene que ser un valor mayor a 0 y menor a 100, intente de nuevo\n\n.");
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

void ordenar(float a_datos[], int n){ // Funcion que aplica el Metodo de ordenamiento por insercion
    
    // Declaramos las variables que usaremos para el ordenamiento y la impresion
    int i, pos;
    float aux;

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

}

void imprimir(float a_datos[], int n){ // Funcion que ordena e imprime

    int i; // Variable para iterar con for

    printf("\n\nImprimiendo datos en orden: \n\n");

    ordenar(a_datos, n); // Llamamos la funcion que ordena

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
    float m = 0.0; // Variable donde se almacenara la mediana en caso de ser un arreglo par

    if (n == 1) // Si solo hay un valor, se retorna a el mismo como mediana
        return a_datos[0];
    
    ordenar(a_datos, n); // Llamamos la funcion que ordena
    
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

void moda(float a_datos[], int n){ // Funcion que retorna la moda o modas

    int i, j, cuenta=0; // Variables para iterar sobre el arreglo y variable que lleva la cuenta de un num repetido
    float mm[2][3] = {0.0}; // Matriz de modas [repeticiones, numero][uni-bi-multimodal]

    if (n == 1){
        goto fin; // Si hay un solo dato, te manda al final
    }
    
    ordenar(a_datos, n); // Llamamos a la funcion que ordena

    for (i=1; i<n+1; i++){ // Hace un recorrido por todos los datos

        if(a_datos[i] == a_datos[i-1]){ // Si el dato actual es igual al anterior
            cuenta += 1; // Se va a sumar uno  la cuenta de la moda
        }
        else{ // Si son datos diferentes
            if(cuenta>0){ // Pero se conto que los numeros anteriores eran iguales
                for (j=0; j<3; j++){ // Se itera sobre los tres posibles espacios del arreglo de modas
                    if(cuenta > mm[0][j]){ // Si la moda recien encontrada es mayor que la anterior registrada
                        mm[0][j]=cuenta+1; // Se asigna su valor de cuenta
                        mm[1][j]=a_datos[i-1]; // Se asigna el valor de la moda
                        break; // Se cierra la iteracion
                    }
                    if (cuenta+1 == mm[0][j]){ // Si la cuenta de esta moda es del mismo tamaño que la anterior registrada
                        mm[0][j+1]=cuenta+1; // Se asigna en la segunda o tercera posicion la cuenta
                        mm[1][j+1]=a_datos[i-1]; // Se asigna el valor de la moda
                        break; // Se cierra la iteracion
                    }
                }
                cuenta=0; // cuenta vuelve a 0 para volver a buscar una moda
            }
        }
    }

    if (mm[0][0] > mm[0][1]){ // Si la moda de la primera posicion es la mayor, es unimodal y se imprime
        printf("\n|Moda Unimodal del dato: %f que aparecio %.0f veces\n",mm[1][0],mm[0][0]);
    }
    else if (mm[0][0] == mm[0][1] && mm[0][0] > mm[0][2]){ // Si las dos primeras modas registradas son mayores a la tercera, e iguales, es bimodal y se imprime
        printf("\n|Moda Bimodal de los datos: %f y %f que aparecieron %.0f veces\n",mm[1][0],mm[1][1],mm[0][0]);
    }
    else if (mm[0][0] == 0){ // Si no se tuvo moda
        fin:
        printf("\n|No existe una moda en este conjunto de datos."); 
    }
    else if (mm[0][0] == mm[0][1] && mm[0][0] == mm[0][2]){ // Si las tres modas son iguales, es multimodal y se imprime
        printf("\n|Moda Trimodal de los datos: %f , %f y %f que aparecieron %.0f veces\n",mm[1][0],mm[1][1],mm[1][2],mm[0][0]);
    }
}

float varianza(float a_datos[], int n){ // Funcion que retorna la varianza

    // Gracias Profe Alex https://www.youtube.com/watch?v=oZRaDwnpXkY

    float m = 0.0, var=0; // Variables para almacenar la media, la varianza y la suma
    int i; // Variable para iterar en los datos del arreglo
    m = media(a_datos, n); // Asignamos a m el valor de la media

    for(i=0; i<n; i++){ // Se itera sobre el arreglo para conseguir (x - m)^2 + ... + (nx - m)^2
        var += pow((a_datos[i] - m), 2);
    }
    var /= n; // Se divide el resultado entre el numero de datos

    return var; // Se retorna la varianza
 
}

float desv(float a_datos[], int n){ // Funcion que retorna la desviacion estandar

    float m = 0.0; // Variable para almacenar la varianza y la desviacion estandar

    m = varianza(a_datos, n); // Sacamos la varianza

    m = sqrt(m); // Sacamos la raiz cuadrada de la varianza

    return m; // Retornamos la desviacion estandar
 
}

float cuartil_1(float a_datos[], int n){ // Funcion que retorna el primer cuartil

    // https://www.youtube.com/watch?v=yoWyNm7nBQQ 

    if(n < 3){
        printf("\n\nNo hay cuartiles para menos de 4 datos, se retornara 0.");
        return 0.0; // Retornamos 0 porque no hay cuartiles para estos datos
    }
    float m = 0.0; // Declaramos la variable donde estara el valor del cuartil
    int aux=0; // Auxiliar para hacer operaciones con los decimales

    ordenar(a_datos, n); // Llamamos a la funcion que ordena

    m = 0.25 * n; // Asignamos la posicion
    aux = m; // Asignamos el valor de m sin decimal a aux

    if((m-aux) == 0){ // Si no tiene decimales
        return a_datos[aux-1]; // Retornamos la posicion correrspondiente
    }
    else if((m-aux) == 0.5){ // si es 0.5, el centro de dos datos
        m = (a_datos[aux-1] + a_datos[aux]) / 2; // Sacamos el cuartil de la suma y division de ambos
        return m; // Retornamos el cuartil
    }
    else if((m-aux) > 0.5){ // Si es mayor a 0.5
        return a_datos[aux]; // Redondeamos el indice hacia arriba y retornamos el dato
    }
    else{
        return a_datos[aux-1]; // Redondeamos el indice hacia abajo y retornamos el dato
    }

}

float cuartil_3(float a_datos[], int n){ // Funcion que retorna el tercer cuartil

    // https://www.youtube.com/watch?v=yoWyNm7nBQQ 

    if(n < 3){
        printf("\n\nNo hay cuartiles para menos de 4 datos, se retornara 0.");
        return 0.0; // Retornamos 0 porque no hay cuartiles para estos datos
    }

    float m = 0.0; // Declaramos la variable donde estara el valor del cuartil
    int aux=0; // Variable auxiliar

    ordenar(a_datos, n); // Llamamos a la funcion que ordena

    m = 0.75 * n; // Asignamos la posicion
    aux = m; // Asignamos el valor de m sin decimal a aux

    if((m-aux) == 0){ // Si no tiene decimales
        return a_datos[aux-1]; // Retornamos la posicion correrspondiente
    }
    else if((m-aux) == 0.5){ // si es 0.5, el centro de dos datos
        m = (a_datos[aux-1] + a_datos[aux]) / 2; // Sacamos el cuartil de la suma y division de ambos
        return m; // Retornamos el cuartil
    }
    else if((m-aux) > 0.5){ // Si es mayor a 0.5
        return a_datos[aux]; // Redondeamos el indice hacia arriba y retornamos el dato
    }
    else{
        return a_datos[aux-1]; // Redondeamos el indice hacia abajo y retornamos el dato
    }
 
}

float ric(float a_datos[], int n){ // Funcion que retorna el rango

    // https://www.youtube.com/watch?v=yoWyNm7nBQQ 

    if(n < 3){
        printf("\n\nNo hay cuartiles para menos de 4 datos, se retornara 0.");
        return 0.0; // Retornamos 0 porque no hay cuartiles para estos datos
    }
    float c1 = 0.0, c3 = 0.0; // Declaramos variables para contener el primer y el tercer cuartil

    c1 = cuartil_1(a_datos, n); // Asignamos el retorno de la funcion del primer cuartil
    c3 = cuartil_3(a_datos, n); // Asignamos el retorno de la funcion del tercer cuartil
    
    return (c3 - c1); // Retornamos el valor del ric (resta del primer y tercer cuartil)
 
}

float rango(float a_datos[], int n){ // Funcion que retorna el rango

    float m = 0.0; // Variable para almacenar el rango

    if(n == 1) // Si solo hay un dato, se retorna el mismo
        return m;
    else{
        ordenar(a_datos, n); // Ordenamos los datos
        m = a_datos[n-1] - a_datos[0]; // Asignamos en m la resta del dato mas grande y el mas pequeño
        return m; // Retornamos el rango
    }
}