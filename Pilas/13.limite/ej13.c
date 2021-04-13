#include <stdio.h>
#include <stdlib.h>
#include "./pila.c"
#include <time.h>

int main()
{
    Pila dada, mayores, menores, limite;
    inicpila(&dada);
    inicpila(&mayores);
    inicpila(&menores);
    inicpila(&limite);

    time_t t;
    srand((unsigned)time(&t));

    apilar(&limite, rand() % 50);

    printf("Limite: %d\n", tope(&limite));

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
        if (tope(&dada) >= tope(&limite))
        {
            apilar(&mayores, desapilar(&dada));
        }
        else
        {
            apilar(&menores, desapilar(&dada));
        }
    }

    printf("\nMayores:");
    mostrar(&mayores);
    printf("Menores:");
    mostrar(&menores);

    return 0;
}