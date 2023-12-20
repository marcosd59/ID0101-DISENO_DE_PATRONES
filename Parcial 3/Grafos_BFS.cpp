/*********************************************************************
Fecha de creacion: 11/05/2022.
Fecha de ultima actualizacion: 22/05/2022.
Nombre del programador: Marcos Damian Pool Canul.
Nombre del programa: Algoritmo BFS (BREADTH-FIRST SEARCH).
Descripcion: Programa que hace una busqueda por anchura de una grafica.
Entradas: La lista de aristas.
Salidas: Los vectores d, pi y colours.
*********************************************************************/

#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
using namespace std;

struct QueueI
{
    int *arri;
    int sizeq;
    int last;
    int front;
} q;

vector<string> colour; // Vector para almacenar color;
vector<int> d;         // Vector para almacenar distancia.
vector<int> p;         // Vector para almacenar el padre.

QueueI *arri = NULL;
QueueI arry;
int item = 0;
bool valid = false;

void agregarArista(vector<int> g[], int u, int v);
void BFSprincipal(vector<int> g[], int s);
void BFSlleno(vector<int> g[], int n);
bool begin(QueueI *q, int s);
bool empty(QueueI q);
bool full(QueueI q);
bool push(QueueI *q, int elem);
int pop(QueueI *q, bool *flag);
int **leerArchivo(char *nombreArchivo);
void imprimirMatriz(int **matriz, int s);

int s; // Variable global para el tamaño.

int main()
{
    int n = 7; // Gráfico con 7 nodos y 6 aristas.
    int **MATRIZ = leerArchivo("Matriz.txt");

    // El vector del grafo
    vector<int> g[n];

    agregarArista(g, 0, 1); // Agregamos unas aristas 0 a 1.
    agregarArista(g, 0, 2); // Agregamos unas aristas 0 a 2.
    agregarArista(g, 1, 3); // Agregamos unas aristas 1 a 3.
    agregarArista(g, 1, 4); // Agregamos unas aristas 1 a 4.
    agregarArista(g, 2, 5); // Agregamos unas aristas 2 a 5.
    agregarArista(g, 2, 6); // Agregamos unas aristas 2 a 6.

    BFSlleno(g, n);

    /* Imprime el vector d. */
    cout << "d: ";
    for (auto const &value : d) // Imprimimos el vector d.
    {
        cout << value << " ";
    }
    cout << endl;

    /* Imprime el vector Pi. */
    cout << "Pi: ";
    for (auto const &value : p) // Imprimimos el vector p.
    {
        cout << value << " ";
    }
    cout << endl;

    /* Imprime el vector color. */
    cout << "color: ";
    for (auto const &value : colour) // Imprimimos el vector colour.
    {
        cout << value << " ";
    }

    return 0;
}

/* Funcion que agrega aristas al gráfico no dirigido. */
void agregarArista(vector<int> g[], int u, int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}

/* Funcion que realiza la búsqueda por anchura. */
void BFSprincipal(vector<int> g[], int s)
{
    // La cola utilizada para la operación BFS.
    queue<int> q;

    // Agregando el nodo raíz dentro de la cola.
    q.push(s);

    /* La distancia del nodo raíz es 0 y el color
    es gris ya que se visita parcialmente */
    d[s] = 0;
    colour[s] = "gray";

    /* Bucle para recorrer el gráfico. El recorrido
     pasará transversal hasta que la cola no este vacío.*/
    while (!q.empty())
    {
        /* Extrayendo el elemento frontal del nodo. */
        int u = q.front();
        q.pop();

        /* Este bucle atraviesa todos los nodos secundarios de u */
        for (auto i = g[u].begin(); i != g[u].end(); i++)
        {
            /* Si el color es blanco entonces dicho nodo no esta visitado. */
            if (colour[*i] == "white")
            {
                colour[*i] = "gray";
                d[*i] = d[u] + 1;
                p[*i] = u;

                /* Agregando el nodo dentro de
                la cola atravesar a sus hijos. */
                q.push(*i);
            }
        }

        /* Ahora el nodo "u" está completamente
        visitado, el color se cambia a "negro". */
        colour[u] = "B";
    }
}

void BFSlleno(vector<int> g[], int n)
{
    /* Inicialmente no se recorren todos los nodos.
    Por lo tanto, el color es blanco. */
    colour.assign(n, "white");
    d.assign(n, 0);
    p.assign(n, -1);

    // Llamar a BFSprincipal() para todos los vertices blancos.
    for (int i = 0; i < n; i++)
    {
        if (colour[i] == "white")
        {
            BFSprincipal(g, i);
        }
    }
}

/* Función para inicializar una cola. */
bool begin(QueueI *q, int s)
{
    q->sizeq = s;
    q->last = -1;

    if ((q->arri = new int[s]) == NULL)
    {
        cout << "Not enough memory" << endl;
        return false;
    }
    return true;
}

/* Función para indicar si una cola no tiene elementos. */
bool empty(QueueI q)
{
    if (q.last < 0)
    {
        return true;
    }
    return false;
}

/* Función para indicar si una cola esta llena. */
bool full(QueueI q)
{
    if (q.last >= (q.sizeq - 1))
    {
        return true;
    }
    return false;
}

/* Función para insertar un elemento en la cola. */
bool push(QueueI *q, int elem)
{
    if (full(*(q)))
    {
        cout << "Queue Full" << endl;
        return false;
    }

    if (empty(*(q)))
    {
        q->last = 0;
        q->arri[q->last] = elem;
        return true;
    }
    q->arri[++q->last] = elem;
    return true;
}

/* Función para extraer un elemento de la cola. */
int pop(QueueI *q, bool *flag)
{
    int elem;

    if (empty(*(q)))
    {
        cout << "Queue Empty" << endl;
        *flag = false;
    }

    else
    {
        *flag = true;
        elem = q->arri[0];

        for (int i = 0; i < q->last; i++)
        {
            q->arri[i] = q->arri[i + 1];
        }
        q->last--;
    }
    return elem;
}

/* Funcion que lee un archivo de texto y lo imprime. */
int **leerArchivo(char *nombreArchivo)
{
    FILE *fp = fopen(nombreArchivo, "r"); // Leemos el archivo.
    int nfilas, ncolumnas; // Creamos variables para almacenarlos.

    if (fp == NULL) // Confirmamos si se pudo leer el archivo.
    {
        cout << "Error al leer el archivo";
        exit(1);
    }

    char linea[100];       // Guardamos la cadena de caracteres.
    char *token = strtok(linea, " "); // El espacio es el delimitador " ".

    fgets(linea, 60, fp);
    nfilas = atoi(token);
    ncolumnas = nfilas;

    int **matriz = new int *[nfilas]; // Creamos las filas dinamicas.

    for (int i = 0; i < nfilas; i++) // Ciclo para recorrer las filas.
    {
        matriz[i] = new int[ncolumnas]; // Creamos las columnas dinamicas.
        fgets(linea, 60, fp);
        token = strtok(linea, " ");
        matriz[i][0] = atoi(token);

        for (int j = 1; j < ncolumnas; j++) // Ciclo para recorrer las columnas.
        {
            token = strtok(NULL, " ");
            matriz[i][j] = atoi(token);
        }
    }

    fclose(fp); // Cerramos el archivo.
    s = nfilas;
    return matriz;
}

/* Función que imprime una matriz */
void imprimirMatriz(int **matriz, int s)
{
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            cout << matriz[i][j];
        }
        cout << endl;
    }
}