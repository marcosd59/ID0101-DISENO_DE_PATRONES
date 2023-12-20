/*
                - ARBOLES -

O <- Un nodo es la expresion mas simple de un arbol;

O <- Nodo padre - Nivel 0
| |
> O > O ... O <-- Nodos hijos - Nivel 1
|
> O > O ... O <-- Nodos hijos de hijos - Nivel 2
|
O > Una hoja es un nodo que ya no tiene nodos dependientes.

Una ruta es conocida una rama o sub-arbol.

h = nivel
h = 3 niveles.

            - Arboles Binarios -

O <- Apuntador a hijo izquierdo -> O Apuntador a hijo derecho
                    |
                    °
            Aputador a Padre

///////////////////////////////////////////////////////////

                            10
                        6        10
                    1        9        12
                                9

1.- Izquierda (I)
2.- Nodo (N)
3.- Derecha (D)

IND (Entre orden)
-----------------
1,6,9,9,10,10,12

NID (Pre-orden)
-----------------
10,6,1,9,9,10,12

IDN (Pos-orden)
-----------------
1,9,9,6,12,10,10

             - Recursividad -

La recursividad tiene 3 parametros.

1 - llamada recursiva con condicion simple.
2 - Condicion trivial.
3 - Backtrakin o camino de regreso.

*/

#include <iostream>

using namespace std;

struct Nodo
{
    int elem;
    Nodo *izquierda;
    Nodo *derecha;
};

Nodo *CrearNodo(int elem);
bool insertT(Nodo *arbol, int elem);
void MostrarArbol(Nodo *arbol, int cont);
bool BuscarNodo(Nodo *arbol, int elem);
void PreOrden(Nodo *arbol);
void EntreOrden(Nodo *arbol);
void PosOrden(Nodo *arbol);

int main()
{
    Nodo *arbol = NULL;
    bool Busqueda = false;

    arbol = CrearNodo(12);
    insertT(arbol, 7);
    insertT(arbol, 15);
    insertT(arbol, 3);
    insertT(arbol, 10);
    insertT(arbol, 13);
    insertT(arbol, 20);
    insertT(arbol, 1);
    insertT(arbol, 6);
    insertT(arbol, 19);

    cout << arbol->izquierda->elem << endl;
    cout << arbol->derecha->elem << endl;
    cout << arbol->izquierda->izquierda->derecha->elem << endl;

    PreOrden(arbol);

    cout << endl;

    EntreOrden(arbol);

    cout << endl;

    PosOrden(arbol);

    cout << endl;

    Busqueda = BuscarNodo(arbol, 20);

    if (Busqueda == true)
    {
        cout << "Elemento encontrado" << endl;
    }

    else
    {
        cout << "Elemento no encontrado" << endl;
    }

    MostrarArbol(arbol, 1);

    return 0;
}

Nodo *CrearNodo(int elem)
{
    Nodo *nuevo_nodo;
    nuevo_nodo = new Nodo[1];

    if (nuevo_nodo == NULL)
    {
        return NULL;
    }

    nuevo_nodo->elem = elem;
    nuevo_nodo->izquierda = NULL;
    nuevo_nodo->derecha = NULL;

    return nuevo_nodo;
}

bool insertT(Nodo *arbol, int elem)
{
    Nodo *newnodo = NULL;
    if (elem < arbol->elem)
    {
        if (arbol->izquierda == NULL)
        {
            newnodo = CrearNodo(elem);
            if (newnodo == NULL)
            {
                return false;
            }
            arbol->izquierda = newnodo;
            return true;
        }
        return insertT(arbol->izquierda, elem);
    }
    else
    {
        if (arbol->derecha == NULL)
        {
            newnodo = CrearNodo(elem);
            if (newnodo == NULL)
            {
                return false;
            }
            arbol->derecha = newnodo;
            return true;
        }
        return insertT(arbol->derecha, elem);
    }
}

void MostrarArbol(Nodo *arbol, int cont)
{
    if (arbol == NULL)
    {
        return;
    }

    else
    {
        MostrarArbol(arbol->derecha, cont + 1);
        for (int i = 0; i < cont; i++)
        {
            cout << "  ";
        }
        cout << arbol->elem << endl;
        MostrarArbol(arbol->izquierda, cont + 1);
    }
}

bool BuscarNodo(Nodo *arbol, int elem)
{
    if (arbol == NULL)
    {
        return false;
    }

    else if (arbol->elem == elem)
    {
        return true;
    }

    else if (elem < arbol->elem)
    {
        return BuscarNodo(arbol->izquierda, elem);
    }

    else
    {
        return BuscarNodo(arbol->derecha, elem);
    }
}

void PreOrden(Nodo *arbol)
{
    if (arbol == NULL)
    {
        return;
    }

    else
    {
        cout << arbol->elem << ", ";
        PreOrden(arbol->izquierda);
        PreOrden(arbol->derecha);
    }
}

void EntreOrden(Nodo *arbol)
{
    if (arbol == NULL)
    {
        return;
    }

    else
    {
        EntreOrden(arbol->izquierda);
        cout << arbol->elem << ", ";
        EntreOrden(arbol->derecha);
    }
}

void PosOrden(Nodo *arbol)
{
    if (arbol == NULL)
    {
        return;
    }

    else
    {
        PosOrden(arbol->izquierda);
        PosOrden(arbol->derecha);
        cout << arbol->elem << ", ";
    }
}