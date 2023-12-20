/*********************************************************************
Fecha de creacion: 24/03/2022
Fecha de ultima actualizacion: 26/03/2022
Nombre del programador: Marcos Damian Pool Canul
Nombre del programa: Queue of points
Descripcion: Colas y estructuras

Entradas:

1   // Option to create  queue.
5   // Size of queue.
2   // Option to insert an element to the queue.
P01 // Id of point element.
2   // X-value.
3   // Y-value.
2   // Option to insert an element to the queue.
P02 // Id of point element.
9   // X-value.
3   // Y-value.
2   // Option to insert an element to the queue.
P03 // Id of point element.
9   // X-value.
3.4 // Y-value.
3   // Extract an element to the queue.
3   // Extract an element to the queue.
3   // Extract an element to the queue.
3   // Extract an element to the queue.
3   // Extract an element to the queue.
4   // Exit.

Salidas:
ID: P01
X: 2.000
Y: 3.000
ID: P02
X: 9.000
Y: 3.000
ID: P03
X: 9.000
Y: 3.400
E
E
*********************************************************************/
#include <iostream>

using namespace std;

struct TPoint
{
    string ID;
    float x;
    float y;
};

struct Queue
{
    TPoint *arri;
    int sizeq;
    int last;
    int front;
};

bool InitQI(Queue *q, int s);
bool isQIEmpty(Queue q);
bool isQIFull(Queue q);
bool inQueueI(Queue *q, TPoint elemt);
TPoint DequeueI(Queue *q, bool *aux);
TPoint puntos(string Id, float x, float y);

int main()
{
    TPoint sti02;
    TPoint elem;
    Queue sti01;
    string Id;

    bool flag = true;
    bool isok = true, aux, aux2 = true;
    float x, y;
    int s;
    int opt;

    do
    {
        cin >> opt;
        switch (opt)
        {
        case 1:
            cin >> s;
            isok = InitQI(&sti01, s);
            break;
        case 2:
            cin >> Id;
            cin >> x;
            cin >> y;
            sti02 = puntos(Id, x, y);
            isok = inQueueI(&sti01, sti02);
            break;
        case 3:
            elem = DequeueI(&sti01, &flag);
            if (flag == true)
            {
                cout << "ID: " << elem.ID << endl;
                printf("X: %.3f \n", elem.x);
                printf("Y: %.3f \n", elem.y);
            }
            break;
        default:
            exit(0);
        }
    } while (opt != 4);
}

/* Function to initialize a queue */
bool InitQI(Queue *q, int s)
{
    q->arri = new TPoint[s];

    if (q->arri == NULL)
    {
        cout << "Not enough memory" << endl;
        return false;
    }

    q->sizeq = s;
    q->last = -1;
    q->front = -1;

    return true;
}

/* Function to indicate if a queue has no elements */
bool isQIEmpty(Queue q)
{
    if (q.last < 0 || q.front < 0)
    {
        cout << "E" << endl;
        return true;
    }
    return false;
}

/* Function to indicate if a queue has no space to store another element */
bool isQIFull(Queue q)
{
    if ((q.last + 1) % (q.sizeq) == q.front)
    {
        cout << "F" << endl;
        return true;
    }
    return false;
}

/* Function to insert a entity Point in a queue*/
bool inQueueI(Queue *q, TPoint elemt)
{
    if (isQIFull(*(q)))
    {
        return false;
    }
    q->front = q->last == -1 ? 0 : q->front;
    q->last = ++q->last % q->sizeq;
    q->arri[q->last] = elemt;
    return true;
}

/* Function to save the points of a queue */
TPoint puntos(string Id, float x, float y)
{
    TPoint api;
    api.ID = Id;
    api.x = x;
    api.y = y;
    return api;
}

/* Function to extract a entity Point in a queue */
TPoint DequeueI(Queue *q, bool *aux)
{
    if (isQIEmpty(*(q)))
    {
        *aux = false;
        return puntos("P00", 0, 0);
    }

    TPoint p = q->arri[q->front];

    if (q->front == q->last)
    {
        q->front = -1;
        q->last = -1;
    }

    else
    {
        q->front = ++q->front % q->sizeq;
    }

    return p;
}