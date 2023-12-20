/********************************************************************
Fecha de creacion: 21/01/2022
Fecha de ultima actualizacion: 22/01/2022
Nombre del programa: Taylors Aprproximation.c v 0.1
Nombre del programador: Marcos Damian Pool Canul
Descripcion: Programa que calcula la aproximacion de Taylor de la funcion e^x para cualquier valor de x y n.

Entradas: x = El valor de la aproximacion, n = Limite del factorial o precicion.

1 //  El valor de X.
3 // El valor de n.

Salidas: La aproximacion de Taylor para e^x con n digitos de precicion.

2.667  // Aproximacion de taylor.
**********************************************************************/

#include <stdio.h>

int main()
{
	double x;			  // El valor que sera elevado a una suma de exponentes.
	double n;			  // El limite hasta donde llegara la sumatoria.
	double factorial = 1; // Factorial igual a 1 porque 0! es igual a 1.
	double sumatoria = 1; // Sumatoria con valor de 1 porque x^0 es igual a 1.

	scanf("%lf", &x); // Escaneamos el valor de x.
	scanf("%lf", &n); // Escaneamos el valor de n.

	for (int i = 1; i <= n; i++) // Ciclo inicia en 1 hasta n datos de precision.
	{
		factorial = (factorial * x) / i; // Aplicando la formula de la sumatoria.
		sumatoria += factorial;			 // Acumulando los resultados en la variable sumatoria.
	}

	printf("%.3lf", sumatoria); // Imprimiendo el resultado y redondeando a 3 decimales.

	return 0;
}
