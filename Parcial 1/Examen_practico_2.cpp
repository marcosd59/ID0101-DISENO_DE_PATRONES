/***************************************************************************
Fecha de creación: 22/02/2022
Fecha de última actualización: 22/02/2022
Nombre del programa: Suma de la diagonal (traza) de una matriz dinamica.
Nombre del programador: Marcos Damian Pool Canul

Descripcion:

Haga un programa en el lenguaje C que cree una matriz de números flotantes,
capture sus valores y calcule la suma de los elementos de su diagonal.

Ejemplo:

A = [2 1 1 1 1 0 1 2 3]

La suma de los elementos de la diagonal se llama traza, traza(A) = 6
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

// Zona de prototipos.

void pedirDATOS();
void mostrarMATRIZ(float **, float, float);

//Variables globales.

float **puntero_matriz, nfilas, ncol;

int main()
{
    pedirDATOS();
    mostrarMATRIZ(puntero_matriz, nfilas, ncol);

    // Liberar memoria que hemos usado en la matriz.

    for (int i = 0; i < nfilas; i++)
    {
        delete[] puntero_matriz[i];
    }

    delete[] puntero_matriz;

    return 0;
}

void pedirDATOS()
{
    printf("\nDigite el numero de filas: ");
    scanf("%f", &nfilas);
    printf("Digite el numero de columnas: ");
    scanf("%f", &ncol);

    // Reservando memoria para la matriz dinamica.

    puntero_matriz = new float*[nfilas]; // Reservando memoria para las filas.

    for (int i = 0; i < nfilas; i++)
    {
        puntero_matriz[i] = new float[ncol]; // Reservando memoria para las columnas.
    }

    printf("\nDigitando elementos de la matriz\n\n");

    for (int i = 0; i < nfilas; i++)
    {
        for (int j = 0; j < ncol; j++)
        {
            printf("Digite un numero [%d][%d]: ", i + 1, j + 1);
            scanf("%f", &puntero_matriz[i][j]); // Es igual a: *(*(puntero_matriz+i)+j)
        }
    }
}

void mostrarMATRIZ(float **puntero_matriz, float nfilas, float ncol)
{
    float suma = 0;

    printf("\nImprimiendo matriz\n\n");

    for (int i = 0; i < nfilas; i++)
    {
        for (int j = 0; j < ncol; j++)
        {
            printf("%.2f ", puntero_matriz[i][j]); // Es igual a: *(*(puntero_matriz+i)+j)
        }
        printf("\n");
    }

    printf("\nImprimiendo suma de la diagonal\n\n");
    for (int i = 0; i < nfilas; i++)
    {
        for (int j = 0; j < ncol; j++)
        {
            if (i == j)
            {
                suma += puntero_matriz[i][j];
            }
        }
    }
    printf("%.2f", suma);
}