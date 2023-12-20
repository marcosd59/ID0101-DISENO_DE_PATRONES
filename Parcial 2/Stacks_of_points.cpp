/*********************************************************************
Fecha de creacion: 17/03/2022
Fecha de ultima actualizacion: 19/03/2022
Nombre del programador: Marcos Damian Pool Canul
Nombre del programa: Stacks of points
Descripcion: Pilas y estructuras

Entradas:

1   // Option to create  stack.
5   // Size of stack.
2   // Option to insert an element to the stack.
P01 // Id of point element.
2   // X-value.
3   // Y-value.
2   // Option to insert an element to the stack.
P02 // Id of point element.
9   // X-value.
3   // Y-value.
2   // Option to insert an element to the stack.
P03 // Id of point element.
9   // X-value.
3.4 // Y-value.
3   // Extract an element to the stack.
3   // Extract an element to the stack.
3   // Extract an element to the stack.
3   // Extract an element to the stack.
3   // Extract an element to the stack.
4   // Exit.

Salidas:

ID: P03
x: 9.00
y: 3.40
ID: P02
x: 9.00
y: 3.00
ID: P01
x: 2.00
y: 3.00
pila vacia
pila vacia
*********************************************************************/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

const int MAX = 50;

// Struct for entity Points.
struct TPoint
{
    string id;
    float x;
    float y;
};

// Struct for entity Stack.
struct StackofP
{
    TPoint *arri;
    int top;
    int sizemax;
};

void GetPoint(TPoint *elem);
void PrintPoint(TPoint elem);
bool IniStack(StackofP *sp, int s);
bool EmptyStack(StackofP sp);
bool FullStack(StackofP sp);
bool PushPoint(StackofP *sp, TPoint elem);
TPoint PopPoint(StackofP *sp, bool *vok);

int main()
{
    TPoint tpo;
    TPoint tpoextracted;
    StackofP sop;

    bool flag = false;
    bool created = false;
    bool condi;
    int opt;
    int size;

    do
    {
        cin >> opt;
        switch (opt)
        {
        case 1:
            if (created == false)
            {
                cin >> size;
                created = IniStack(&sop, size);
                condi = created;
            }
            break;
        case 2:
            GetPoint(&tpo);
            condi = PushPoint(&sop, tpo);
            break;
        case 3:
            if (created == true)
            {
                tpoextracted = PopPoint(&sop, &flag);
                if (flag == true)
                {
                    // cout << "Element Extracted" << endl;
                    PrintPoint(tpoextracted);
                }
                else
                {
                    // cout << "pila vacia" << endl;
                }
            }
            break;
        default:
            exit(0);
        }
    } while (opt != 4);
}

/* Function to read interactively the fields of a structure TPoints */
void GetPoint(TPoint *elem)
{
    cin >> elem->id;
    cin >> elem->x;
    cin >> elem->y;
}

/* Function to display the fields of a structure TPoints */
void PrintPoint(TPoint elem)
{
    cout << "ID: " << elem.id << endl;
    printf("x: %.2f\n", elem.x);
    printf("y: %.2f\n", elem.y);
}

/* Function to initialize a stack */
bool IniStack(StackofP *sp, int s)
{
    sp->arri = new TPoint[s];

    if (sp->arri == NULL)
    {
        cout << "Not enought memory" << endl;
        return false;
    }
    sp->top = -1;
    sp->sizemax = s;
    return true;
}

/* Function to indicate if a stack has no elements */
bool EmptyStack(StackofP sp)
{
    if (sp.top < 0)
    {
        return true;
    }
    return false;
}

/* Function to indicate if a stack has no space to store another element */
bool FullStack(StackofP sp)
{
    if (sp.top >= (sp.sizemax - 1))
    {
        return true;
    }
    return false;
}

/* Function to insert a entity Point in a stack */
bool PushPoint(StackofP *sp, TPoint elem)
{
    TPoint aux;

    if (FullStack(*sp))
    {
        cout << "pila llena" << endl;
        return false;
    }

    sp->arri[++sp->top] = elem;

    aux = sp->arri[sp->top];

    // PrintPoint(aux)
    return true;
}

/* Function to extract a entity Point in a stack */
TPoint PopPoint(StackofP *sp, bool *vok)
{
    TPoint tpoo;

    if (EmptyStack(*sp))
    {
        cout << "pila vacia" << endl;
        *vok = false;
    }
    else
    {
        tpoo = sp->arri[sp->top--];
        *vok = true;
    }
    return tpoo;
}