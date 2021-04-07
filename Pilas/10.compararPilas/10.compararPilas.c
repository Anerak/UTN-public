#include <stdio.h>
#include <stdlib.h>
#include "./pila.c"

//  Consigna:
//  Comparar las pilas A y B, evaluando si son completamente iguales (en cantidad de elementos, valores que contienen y posición de los mismos).
//  Mostrar por pantalla el resultado.

// Acá estoy declarando  las funciones de mi programa (están debajo del main).
Pila cargarValores(Pila);
int contarElementos(Pila);

/*  
    Para declarar una función de esta manera al programa, debemos seguir la siguiente estructura:
    [tipo de dato que devuelve la función] [nombre de la función] ( [argumentos/paramétros que nuestra función usa] );
    int sumarAB(int, int);
    se traduce cómo: función que devuelve un valor tipo entero/int y toma dos parametros para funcionar.
*/

int main()
{

    Pila pila1, pila2;
    inicpila(&pila1);
    inicpila(&pila2);

    // Cargamos los valores
    printf("Valores pila1\n");
    pila1 = cargarValores(pila1);
    fflush(stdin);
    printf("Valores pila2\n");
    pila2 = cargarValores(pila2);

    mostrar(&pila1);
    mostrar(&pila2);

    // Esto es cómo un contador pero no sé si es un contador realmente :shrug:
    int cantPila1 = contarElementos(pila1);
    int cantPila2 = contarElementos(pila2);

    // ¿Tienen la misma cantidad de elementos?
    if (cantPila1 == cantPila2)
    {
        printf("Tienen la misma cantidad de elementos\n%d | %d\n", cantPila1, cantPila2);
    }
    else
    {
        printf("No tienen la misma cantidad\n%d | %d\n", cantPila1, cantPila2);
    }

    // Vamos a ejecutar esto mientras pila1 y pila2 NO están vacíos.
    while (!pilavacia(&pila1) && !pilavacia(&pila2))
    {
        // Los topes de ambas pilas, ¿son iguales?
        if (tope(&pila1) == tope(&pila2))
        {
            // Si, son iguales
            printf("Son iguales\n");

            // Desapilo así comparo nuevos topes
            desapilar(&pila1);
            desapilar(&pila2);
        }
        else
        {
            // No, no son iguales
            printf("Los valores son distintos\n");

            // Acá no tiene sentido desapilar. ¿Por qué, Tobi?
            // Porque vamos a salirnos del while usando la palabra reservada break.
            // A mi no me interesa seguir comparando cuando ya sé que no hay valores iguales
            break;
            // Esta palabra dentro de un bucle while, do-while o for rompe el bucle.
            // Equivalente a decirle "Estoy atrapado en un bucle, dejame salir, maldita sea".
        }
    }

    return 0;
}

/* ¿Ya declaraste la función arriba? Ahora vamos a definir su contenido

    [tipo de dato que devuelve la función] [nombre de la función] ( [argumentos/parametros que nuestra función usa]) {
        [código de la función]
    }

    int sumarAB(int a, int b) {
        return a + b;
    }

    Los parametros son tipo entero (pueden ser mezclados, ej: "void mensajeRandom(int numeroMagico, char letra)").
    Hay que notar que nuestras variables fuera de la función no tienen que llamarse necesariamente a y b.
    Si dentro de main yo tuviera algo cómo:

    int numero1 = 15;
    int numero2 = 10;
    printf("La suma de numero1 y numero2 es %d", sumarAB(numero1, numero2));
    → "La suma de numero1 y numero2 es 25"


    La palabra reservada return se utiliza cuando queremos devolver algo en nuestra función.
    En este caso, devolvemos la suma de a y b.

*/

// Función leer junto con mensaje para seguir ingresando números
Pila cargarValores(Pila destino)
{
    char mander = 's';
    do
    {
        leer(&destino);

        printf("Desea seguir? s para continuar: ");
        fflush(stdin);
        scanf("%c", &mander);
    } while (mander == 's');

    return destino;
}

// Acá contamos los elementos de una pila.
// Grito para que se entienda
int contarElementos(Pila origen)
{
    int contador = 0;
    Pila aux;
    inicpila(&aux);

    // Desapilamos de la pila origen y autoincrementamos el contador.
    while (!pilavacia(&origen))
    {
        // ESTOY APILANDO EN AUXILIAR, VACIANDO ORIGEN
        apilar(&aux, desapilar(&origen));
        contador++;
    }

    // Como vaciamos la pila origen, ahora le volvemos a poner los valores.
    while (!pilavacia(&aux))
    {
        // ESTOY APILANDO EN ORIGEN, VACIANDO AUXILIAR
        // ASI QUEDA COMO CUANDO EMPECÉ
        apilar(&origen, desapilar(&aux));
    }

    return contador;
}