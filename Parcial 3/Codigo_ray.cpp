#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;
int s;

void imprimirMatriz(int **matrizAdy, int s);
int **leerMatriz(char *fileName);

struct QueueI
{

  int *arri;
  int sizeq;
  int last;
  int front;
};

// Cola de colas
struct QueueQ
{
  QueueI *arri;
  int sizeq;
  int last;
  int front;
};

struct QueueRay
{

  int *arri;
  int sizeq;
  int last;
};

bool initQueueQ(QueueQ *Qui, int s);

bool initQueueRay(QueueRay *Qui, int s)
{

  Qui->arri = new int[s];

  if (Qui->arri == NULL)
  {
    cout << "Not enough memory" << endl;
    return false;
  }

  Qui->sizeq = s;
  Qui->last = -1;

  return true;
}

bool isQueueRayEmpty(QueueRay Qui)
{

  if (Qui.last == -1)
  {
    return true;
  }

  return false;
}
bool isQueueRayFull(QueueRay Qui)
{

  if (Qui.last >= (Qui.sizeq - 1))
  {
    return true;
  }
  return false;
}

bool InQueueRay(QueueRay *Qui, int elem)
{

  if (isQueueRayFull(*(Qui)))
  {
    return false;
  }

  if (isQueueRayEmpty(*(Qui)))
  {

    Qui->last = 0;
    Qui->arri[Qui->last] = elem;
    return true;
  }

  Qui->arri[++Qui->last] = elem;

  return true;
}

int DequeueRay(QueueRay *Qui, bool *flag)
{

  int elem = 0;

  if (isQueueRayEmpty(*Qui))
  {
    *flag = false;
  }
  else
  {
    *flag = true;
    elem = Qui->arri[0];

    for (int i = 0; i < Qui->last; i++)
    {
      Qui->arri[i] = Qui->arri[i + 1];
    }

    Qui->last--;
  }

  return elem;
}

bool initQueueI(QueueI *Qui, int s);
bool PushPointQ(QueueI *Qui, int num);
bool PushPointI(QueueQ *Qui, int num);
void showQueueP(QueueI Qui);
bool isQueuePEmpty(QueueI Qui);
int PopPointQ(QueueI *Qui, bool *flag);
void bfs(QueueQ *Queueq, int raiz);

//------------------------------------
int main()
{
  QueueQ queq;
  cout << "Hello World!\n";
  int asd = 0;
  int arreglo[s];
  int **M2 = leerMatriz("archivo.txt");

  int contador = 0;
  cout << s << endl;
  imprimirMatriz(M2, s);

  int mich = 0;

  initQueueQ(&queq, s);

  for (int i = 0; i < s; i++)
  {

    PushPointI(&queq, s);
  }

  for (int j = 0; j < s; j++)
  {

    for (int k = 0; k < s; k++)
    {

      if (M2[j][k] == 1)
      {
        PushPointQ(&queq.arri[j], k);
      }
    }
  }

  bfs(&queq, 0);

}

void imprimirMatriz(int **matrizAdy)
{

  for (int i = 0; i < s; i++)
  {

    for (int j = 0; j < s; j++)
    {

      cout << matrizAdy[i][j];
    }
    cout << endl;
  }
}

int **leerMatriz(char *fileName)
{

  FILE *fp = fopen(fileName, "r"); // Leer archivo
  int filas;
  int columnas;

  if (fp == NULL)
  {
    cout << "Hubo un error - No se pudo leer el archivo";
    exit(1);
  }

  char linea[80];       // Buffer para guardar la cadena
  fgets(linea, 79, fp); // Donde lo guardare (Linea), cuantos caracteres (79), leer el apuntador al archivo (fp)

  // Dividir la cadena en tokens (Para leer)

  char *token = strtok(linea, " "); // Delimitador es un espacio " "
  filas = atoi(token);
  columnas = filas;

  // token = strtok(NULL, " ");

  int **matriz = new int *[filas]; // Creacion de matriz
  for (int i = 0; i < filas; i++)
  {
    matriz[i] = new int[columnas];
    fgets(linea, 79, fp);
    token = strtok(linea, " ");

    matriz[i][0] = atoi(token);

    for (int j = 1; j < columnas; j++)
    {
      token = strtok(NULL, " ");
      matriz[i][j] = atoi(token);
    }
  }
  fclose(fp);

  s = filas;
  return matriz;
}

bool initQueueQ(QueueQ *Qui, int s)
{

  Qui->arri = new QueueI[s];

  if (Qui->arri == NULL)
  {
    cout << "Not enough memory" << endl;
    return false;
  }

  Qui->sizeq = s;
  Qui->last = -1;
  Qui->front = -1;

  return true;
}

bool initQueueI(QueueI *Qui, int s)
{

  Qui->arri = new int[s];

  if (Qui->arri == NULL)
  {
    cout << "Not enough memory" << endl;
    return false;
  }

  Qui->sizeq = s;
  Qui->last = -1;
  Qui->front = -1;

  return true;
}

bool PushPointQ(QueueI *Qui, int num)
{

  Qui->front = Qui->last == -1 ? 0 : Qui->front;
  Qui->last = ++Qui->last % Qui->sizeq;

  Qui->arri[Qui->last] = num;

  return true;
}

bool PushPointI(QueueQ *Qui, int num)
{
  QueueI newQui;
  initQueueI(&newQui, 5);

  Qui->front = Qui->last == -1 ? 0 : Qui->front;
  Qui->last = ++Qui->last % Qui->sizeq;

  Qui->arri[Qui->last] = newQui;

  return true;
}

bool isQueuePEmpty(QueueI Qui)
{

  if (Qui.last < 0 || Qui.front < 0)
  {
    return true;
  }

  return false;
}

int PopPointQ(QueueI *Qui, bool *flag)
{

  int elem;

  if (isQueuePEmpty(*Qui))
  {
    *flag = false;
    cout << "E " << endl;
    return elem;
  }

  elem = Qui->arri[Qui->front];

  if (Qui->front == Qui->last)
  {
    Qui->front = -1;
    Qui->last = -1;
  }
  else
  {
    Qui->front = ++Qui->front % Qui->sizeq;
  }

  return elem;
}

void bfs(QueueQ *Queueq, int raiz)
{

  bool vacio = true;
  bool flag = true;
  int u;
  int v;
  char color[s];
  int d[s];
  int pi[s];
  QueueRay qui;

  for (int i = 0; i < s; i++)
  {

    color[i] = 'w';
    d[i] = -1;
    pi[i] = -1;
  }

  color[raiz] = 'g';
  d[raiz] = 0;
  pi[raiz] = -1;

  initQueueRay(&qui, s);
  InQueueRay(&qui, raiz);


  while (vacio == true)
  { // Mientras no este vacia

    u = DequeueRay(&qui, &flag);
    cout << "U es igual a: " << u << endl;
    // cout << flag <<endl;

    for (int i = 0; i < s; i++)
    {

      if (Queueq->arri[u].arri[i] > 100 || Queueq->arri[u].arri[i] < 0)
      {
        // cout << "El numero es: " << Queueq->arri[u].arri[i] << endl;
      }
      else
      {
        // cout << "El numero es: " << Queueq->arri[u].arri[i] << endl;
        v = Queueq->arri[u].arri[i];
        // cout << "El numero es " << v;
        if (v != 0)
        {
          if (color[v] == 'w')
          {
            color[v] = 'g';
            d[v] = d[u] + 1;
            pi[v] = u;
            InQueueRay(&qui, v);
          }
        }
      }
    }
    vacio = flag;
    color[u] = 'b';
  }

  for (int i = 0; i < s; i++)
  {
    cout << "Vertice " << i + 1 << " Tiene color: " << color[i] << " Tiene distancia: " << d[i] << " Tiene de padre a: " << pi[i] << endl;
  }

}