/********************************************************************
Fecha de creacion: 06/02/2022.
Fecha de ultima actualizacion: 07/02/2022.
Nombre del programa: Coprimes_in_arrays v 1.0.
Nombre del programador: Marcos Damian Pool Canul.
Descripcion: Programa que determina los numeros co-primos.
Entradas: El tamaño del arreglo N y los elementos del arreglo.

3   // The numbers of elements.
4   // The elements of the set.
7   // The elements of the set.
12  // The elements of the set.

Salidas: 'Y' si son co-primos y 'N' si no lo son.

Y   // 'Y' for co-primes or 'N' else.
*********************************************************************/

#include <stdio.h>

int main()
{
    int tama = 0; // El tamaño del arreglo.

    scanf("%d", &tama); // Escaneamos el tamaño del arreglo.

	if (tama < 1) // Si es un numero negativo
	{
		tama *= -1; // Convertimos a positivo.
	}

    int array[tama];// Creamos un arreglo con el tamaño escaneado.
    int residuo; // Una variable residuo.
    int mcd; // El maximo comun divisor igual a 1 o diferente de 1.

    for (int i = 0; i < tama; i++) // Escaneamos todos los elementos del arreglo.
    {
        scanf("%d", &array[i]); // Los guardamos en array en la posicion i.

		if (array[i] < 1) // Si los valores son negativos convertimos a positivos.
		{
			array[i] *= -1; // Convirtiendo a positivo.
		}

		if (array[i] == 0) // Si un elemento es 0.
		{
            for (int j = i; j < tama; j+=1) // Recorremos el arreglo.
            {
                array[j] = array[j+1]; // Recorremos una posicion.
            }
            array[tama]-=1; // Eleminamos un posicion.
		}

		if (array[i] < tama) // Si no se rellena por completo agrega un 0.
		{
			array[i] = 0;
		}
    }

    for (int j = 0; j < tama; j++) // Arreglo de 0 hasta el tamaño n.
    {
        do
        {
            residuo = array[j] % array[j + 1]; // Guarda el residuo de array[0] entre array[1];

            if (residuo != 0) // Conpruba si el residuo es diferente de 0.
            {
                array[j] = array[j + 1];
                array[j + 1] = residuo;
            }
            else
            {
                mcd = array[j + 1];
            }

        } while (residuo != 0); // Continuamos hasta que residuo sea diferente de 0.
    }

    if (mcd == 1) // Si maximo comun divisor es igual a 1 imprime 'Y'.
    {
        printf("Y");
    }

    else if (mcd != 1) // Si maximo comun divisor es diferente a 1 imprime 'N'.
    {
        printf("N");
    }

    return 0;
}