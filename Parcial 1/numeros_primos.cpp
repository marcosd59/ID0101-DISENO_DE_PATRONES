#include <iostream>
using namespace std;

int main()
{
    int num = 59;
    int cont = 0;

    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            cont++;
        }
    }

    if (cont == 2)
    {
        cout << "El numero ingresado es PRIMO" << endl;
    }
    else
    {
        cout << "El numero ingresado NO ES PRIMO" << endl;
    }

    return 0;
}