#include <stdio.h>
#include <stdlib.h>
#include "./pila.c"

int main()
{
    Pila dada, aux, par, impar;
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&par);
    inicpila(&impar);

    int esImpar = 0;

    char seguir = 's';
    do
    {
        leer(&dada);

        printf("Desea seguir? s para continuar: ");
        fflush(stdin);
        scanf("%c", &seguir);
    } while (seguir == 's');

    while (!pilavacia(&dada))
    {
        // 5 4 3 2 1
        // Saque 1 2 -> Queda 5 4 3
        // Saque 3 4 -> Queda 5
        // Saque 5

        apilar(&aux, desapilar(&dada));

        if (!pilavacia(&dada))
        {
            apilar(&aux, desapilar(&dada));
        }
        else
        {
            // es impar
            esImpar = 1;
        }
    }

    // Acá tenemos que pasar el tope de AUX a la pila PAR si DADA es par
    // Si DADA es impar, lo pasamos a la pila IMPAR

        if (esImpar)
    {
        mostrar(&aux);
        while (!pilavacia(&aux))
        {
            apilar(&impar, desapilar(&aux));
        }
        printf("Es impar\n");
        mostrar(&impar);
    }
    else
    {
        mostrar(&aux);
        apilar(&par, desapilar(&aux));
        printf("Es par\n");
        mostrar(&par);
    }

    return 0;
}