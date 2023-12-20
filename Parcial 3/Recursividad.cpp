/*
    - Factorial de un numero con recursividad -

    5! = 5 * 4! = 120
    4! = 4 * 3! = 24
    3! = 3 * 2! = 6
    2! = 2 * 1! = 2
    1! = 1 * 0! = 1
    0! = 1

    5! = 5 * 4 * 3 * 2 * 1 = 120
    4! = 4 * 3 * 2 * 1 = 24
    3! = 3 * 2 * 1 = 6
    2! = 2 * 1 = 2
    1! = 1 * 0 = 1
    0! = 1

    - Potencia de un numero con recursividad -

    2^4 = 2 * 2^3 = 16
    2^3 = 2 * 2^2 = 8
    2^2 = 2 * 2^1 = 4
    2^1 = 2 * 2^0 = 2
    2^0 = 1

    2^4 = 2 * 2 * 2 * 2 = 16
    2^3 = 2 * 2 * 2 = 8
    2^2 = 2 * 2 = 4
    2^1 = 2 = 2
    2^0 = 1
*/

#include <iostream>

using namespace std;

int factorial(int n);
float potencia(float x, float y);
int FibonacciRec(int n);

int main()
{
    int n = 5;
    float x = 2;
    float y = 4;

    cout << factorial(n) << endl;
    cout << potencia(x, y) << endl;
    cout << FibonacciRec(n) << endl;
}

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

float potencia(float x, float y)
{
    if (y == 0)
    {
        return 1;
    }
    return x * potencia(x, (y - 1));
}

int FibonacciRec(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return FibonacciRec(n - 1) + FibonacciRec(n - 2);
}