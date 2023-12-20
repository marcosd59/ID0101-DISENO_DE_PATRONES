/*
Fecha de creacion: 20/10/2021
Fecha de ultima actualizacion: 12/11/2021
Nombre del programa: Listas_Simples.cpp V 0.1
Nombre del programador: David Flores
Descripcion: Programa que opera con Tablas Hash.

Entradas: Opciones de Menú:
          1. Crear e inicializar una Pila
          2. Insertar un elemento ordenadamente
          3. Eliminar un elemento
          4. Consultar un elemento
          5. Salir
Salida: Dependiente de las operaciones en el Menú

*/
#include <iostream>
#include <math.h>
using namespace std;

typedef struct NodeHash
{
    char Nickname[30];
    NodeHash *prev;
    NodeHash *next;
} NodeHash;

unsigned Hash_Function(char *nick, unsigned t);
NodeHash *CreateTableHash(unsigned t);
NodeHash *Create_Node(NodeHash elem);
bool InsertHash(NodeHash elem);

int main()
{

    NodeHash *HashT = CreateTableHash(5);

    cout << Hash_Function((char *)"eli", 5) << endl;
    return 0;
}

NodeHash *Create_Node(NodeHash elem)
{
    NodeHash *aux = NULL;
    if ((aux = new NodeHash[1]) == NULL)
    {
        return NULL;
    }
    *(aux) = elem;
    aux->prev = aux;
    aux->next = aux;
    return aux;
}

unsigned Hash_Function(char *nick, unsigned t)
{
    int finalv = 0;
    int i = 0;

    while (nick[i] != 0)
    {
        finalv += pow(-1, i) * nick[i];
        i++;
    }
    finalv = (abs(finalv) * i);
    finalv %= t;
    return (unsigned)finalv;
}

NodeHash *CreateTableHash(unsigned t)
{
    NodeHash *th = new NodeHash[t];

    if (th != NULL)
    {
        for (int i = 0; i < t; i++)
        {
            th[i].prev = &(th[i]);
            th[i].next = &(th[i]);
        }
    }
    return th;
}

bool InsertHash(NodeHash *TableH, unsigned t, NodeHash elem)
{
    unsigned bucket = 0;
    NodeHash *item;

    NodeHash *newitem = Create_Node(elem);
    if (newitem == NULL)
    {
        return false;
    }
    bucket = Hash_Function(newitem->Nickname, t);
    item = &(TableH[bucket]); // Ir al Header
    // Inserción por atrás
    while (item->next != item)
    {
        item = item->next;
    }
    item->next = newitem;
    newitem->prev = item;
    return true;
}