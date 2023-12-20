#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 50

int tamcad(char *cad);
void invert(char *cad);

int main(void)
{
    char c1[MAX] = {"DataScience"};

    cout << tamcad(c1);

    printf("\n");

    invert(c1);

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

void invert(char *cad)
{
    int k = 0;
    int l = 0;
    char *pc1;

    pc1 = cad;

    while (pc1[k] != '\0')
    {
        k++;
    }

    for (l = k - 1; l >= 0; l--)
    {
        printf("%c", cad[l]);
    }
}