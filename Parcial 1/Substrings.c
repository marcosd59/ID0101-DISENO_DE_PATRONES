/********************************************************************************
Fecha de creacion: 21/01/2022
Fecha de ultima actualizacion: 22/01/2022
Nombre del programa: Busqueda de subcadenas.c v 0.1
Nombre del programador: Marcos Damian Pool Canul
Descripcion: Dadas dos cadenas A y B devuelve la posicion de la subcadena.
Entradas: Cadenas A y B.

congelado   // String A.
gel         // String B.

Salidas: La posicion dende esta la cadena B es subcadena de la cadena A.

3   // The substring "gel" is in the third position (we are using zero logic).

********************************************************************************/
// Inclusion de bibliotecas.
#include <stdio.h>
#include <string.h>

// Declaracion de constantes.
#define MAX 100

// Prototipo de la funcion.
int indice_del_substring(char stringA[], char stringB[]);

// Programa principal.
int main(void)
{
    int indice;

    char stringA[MAX]; // Declaracion de la cadena A con una constante.
    char stringB[MAX]; // Declaracion de la cadena B con una constante.

    gets(stringA); // Obetenmos la cadena A.
    gets(stringB); // Obtenemos la cadena B.

    indice = indice_del_substring(stringA, stringB); // Llamada a la funcion.

    if (indice == -1)
    {
        printf("%d", indice);
    }
    else
    {
        printf("%d", indice);
    }

    return 0;
}

int indice_del_substring(char stringA[], char stringB[])
{
    int i = 0;
    int j = 0;
    int aux;
    int aux2;

    aux2 = strlen(stringB);

    for (i = 0; stringA[i + aux2 - 1]; i++)
    {
        aux = i;

        for (j = 0; j <= aux2 - 1; j++)
        {
            if (stringA[aux] != stringB[j])
                break;
            aux++;
        }
        if (j == aux2)
            return (i);
    }
    return (-1);
}