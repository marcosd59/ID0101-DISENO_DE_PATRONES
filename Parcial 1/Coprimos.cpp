#include <stdio.h>

int main()
{
    int numero1 = 20;
    int numero2 = 20;
    int residuo, mcd;

    // scanf("%d", &numero1);
    // scanf("%d", &numero2);

    do
    {
        residuo = numero1 % numero2;

        if (residuo != 0)
        {
            numero1 = numero2;
            numero2 = residuo;
        }
        else
        {
            mcd = numero2;
        }

    } while (residuo != 0);

    if (mcd == 1)
    {
        printf("No shared factors. They are coprime");
    }
    else if (mcd != 1)
    {
        printf("Shared factors: %d. They are not coprime", mcd);
    }

    return 0;
}