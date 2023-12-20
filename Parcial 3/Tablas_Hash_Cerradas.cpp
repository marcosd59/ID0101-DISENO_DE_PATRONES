#include <iostream>
#include <stdio.h>
#include <string.h>

#define NCASILLAS 100
#define VACIO NULL

using namespace std;

static char *BORRADO = "";
typedef char **TablaHash;

TablaHash CrearTablaHash();
void DestruirTablaHash(TablaHash t);
int Hash(char *cad);
int Localizar(char *x, TablaHash t);
int Localizar1(char *x, TablaHash t);
int MiembroHash(char *cad, TablaHash t);
void InsertarHash(char *cad, TablaHash t);
void BorrarHash(char *cad, TablaHash t);

int main()
{
    int r = 0;
    char palabra[10] = "Windfall";

    r = Hash(palabra);

    cout << r << endl;



    return 0;
}

TablaHash CrearTablaHash()
{
    TablaHash t;
    register int i;

    t = (TablaHash)malloc(NCASILLAS * sizeof(char *));

    if (t == NULL)
    {
        printf("Memoria Insuficiente.");
    }

    for (i = 0; i < NCASILLAS; i++)
    {
        t[i] = VACIO;
    }

    return t;
}

void DestruirTablaHash(TablaHash t)
{
    register int i;

    for (i = 0; i < NCASILLAS; i++)
    {
        if (t[i] != VACIO && t[i] != BORRADO)
        {
            free(t[i]);
        }
    }

    free; t;
}

int Hash(char *cad)
{
    int valor;
    char *c;

    for (c = cad, valor = 0; *c; c++)
        valor += (int)*c;

    return (valor % NCASILLAS);
}

int Localizar(char *x, TablaHash t)
{
    int ini, i, aux;

    ini = Hash(x);

    for (i = 0; i < NCASILLAS; i++)
    {
        aux = (ini + i) % NCASILLAS;
        if (t[aux] == VACIO)
            return aux;
        if (!strcmp(t[aux], x))
            return aux;
    }
    return ini;
}

int Localizar1(char *x, TablaHash t)
{
    int ini, i, aux;

    ini = Hash(x);

    for (i = 0; i < NCASILLAS; i++)
    {
        aux = (ini + i) % NCASILLAS;
        if (t[aux] == VACIO || t[aux] == BORRADO)
            return aux;
        if (!strcmp(t[aux], x))
            return aux;
    }

    return ini;
}

int MiembroHash(char *cad, TablaHash t)
{
    int pos = Localizar(cad, t);

    if (t[pos] == VACIO)
        return 0;
    else
        return (!strcmp(t[pos], cad));
}

void InsertarHash(char *cad, TablaHash t)
{
    int pos;

    if (!cad)
        printf("Cadena inexistente.");

    if (!MiembroHash(cad, t))
    {
        pos = Localizar1(cad, t);
        if (t[pos] == VACIO || t[pos] == BORRADO)
        {
            t[pos] = (char *)malloc((strlen(cad) + 1) * sizeof(char));
            strcpy(t[pos], cad);
        }
        else
        {
            printf("Tabla Llena. \n");
        }
    }
}

void BorrarHash(char *cad, TablaHash t)
{
    int pos = Localizar(cad, t);

    if (t[pos] != VACIO && t[pos] != BORRADO)
    {
        if (!strcmp(t[pos], cad))
        {
            free(t[pos]);
            t[pos] = BORRADO;
        }
    }
}