/*
Tablas hash

ABIERTAS: Listas.
CERRADAS: Arreglos estaticos.

(k) llave y una funcion de dispercion f(k)

La llave seria la primera letra de una palabra, ejemplo:

Z: Zapato.
L: Libro.
A: Arbol.

k = 'C'
f(k) = f('C') = 3

k = 'R'
f(k) = f('R') = 18

------------------------------------

Buckets = [  , ,  ,  ,  ,  ]
Posicion =[0, 1, 2, 3, 4, 5]
t = 6

------------------------------------

k = "Elmerch"
t = 6;
f(k) = (n, Σ(ki), i = 1) % t

f("Elmerch") = (69 + 108 + 109 + 101 + 114 + 99 + 104 =) = 704.
f("Elmerch") = 704 % t = 2 es la posicion donde se guardara.

Buckets = [ ,  , "Elmerch" ,  ,  ,  ]
Posicion =[0, 1,    2      , 3, 4, 5]
t = 6

*/
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

struct NodeHash
{
    char Nickname[30];
    NodeHash *next;
    NodeHash *prev;
};

NodeHash *Create_Node(NodeHash elem);
NodeHash *CreateTableHash(unsigned t);
unsigned Hash_Function(char *nick, unsigned t);
bool InsertHash(NodeHash *TableH, unsigned t, NodeHash elem);

int main()
{
    NodeHash *HashT = CreateTableHash(5);
    NodeHash ELEM;
    bool isOK = false;

    cout << Hash_Function((char *)"elis", 5) << endl;

    isOK = InsertHash(HashT, 5, ELEM);

    if (isOK == true)
    {
        cout << "Elemento agregado correctamente" << endl;
    }

    else
    {
        cout << "Error" << endl;
    }

    cout << Hash_Function((char *)"Windfall", 5) << endl;

    isOK = InsertHash(HashT, 5, ELEM);

    if (isOK == true)
    {
        cout << "Elemento agregado correctamente" << endl;
    }

    else
    {
        cout << "Error" << endl;
    }

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

unsigned Hash_Function(char *nick, unsigned t)
{
    int finalv = 0;
    int i = 0;

    while (nick[i] != 0)
    {
        finalv += pow(-1, i) * nick[i];
        i++;
    }
    finalv = (::abs(finalv) * i);
    finalv %= t;
    return (unsigned)finalv;
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