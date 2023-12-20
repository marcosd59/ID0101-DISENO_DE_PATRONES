/* "Un apuntador es un tipo de dato que contine una dirección de memoria." */

#include <iostream>
using namespace std;

int tamcad(char *cad);

int main(void)
{
    char *apc = 0; // char *apc = NULL;
    char c1[10] = {"SUPER_OK"};

    apc = c1;

    cout << tamcad(c1);

    return 0;
}

int tamcad(char *cad)
{
    int i = 0;
    char *pc1;

    pc1 = cad;

    while (*(pc1) != '\0')
    {
        pc1++;
        i++;
    }

    return i;
}