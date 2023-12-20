/*
                --- GRAFOS ---

Grafos o graficas es un modelo que permite establece relaciones ente entidades.

G = {v ∈ V, e ∈ E} = {V,E}

- Grafos dirigidos

s       t
O <---> O

- Grafos no dirigidos

s      t
O------O

MATRIZ DE ADYASENCIA NO DIRIGIDO

Te dice con quién esta conectado.

Un grafo no dirigido siempre tiene una matriz de adyacencia simétrica.

Un grafo dirigido no siempre tiene una matriz adyacencia simétrica.

    s    t    u    v    w
s   1    1    1    1    0

t   1    1    0    1    1

u   1    0    1    1    1

v   1    1    1    1    1

w   0    1    0    1    1

    s    t
    O----O\
    |    | \
    |    |  Ow
    |    | /
    O----O/
    u    v

MATRIZ DE ADYACENCIA DIRIGIDO

    S    T    U    V    W
S   0    1    1    0    0
T   0    0    1    0    0
U   0    0    0    1    0
V   0    0    0    1    1
W   1    0    0    0    0

    S     T
    O---->O
    |  /
    | /
    |</
    O---->O(<->) -> Ow
    U     V

A = A^T

MATRIZ DE ADYACENCIA DIRIGIDO CON LOS PESOS

    S    T    U    V    W
S   ∞    2    2    ∞    ∞
T   ∞    ∞    7    ∞    ∞
U   ∞    ∞    ∞    4    ∞
V   ∞    ∞    ∞    ∞    1
W   9    ∞    ∞    ∞    ∞

    S   2  T
    O---->O
    |  /
  2 | /7
    |</                   9
    O---4->O(<->) ->1 Ow -->S
    U     V
*/

#include <iostream>

using namespace std;

int main()
{
    int d[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int color[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int pi[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int f[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    cout << "d     =";
    for (int i = 0; i < 10; i++)
    {
        cout <<" "<< d[i];
    }

    cout << endl;

    cout << "color =";
    for (int i = 0; i < 10; i++)
    {
        cout <<" "<< color[i];
    }

    cout << endl;

    cout << "pi    =";
    for (int i = 0; i < 10; i++)
    {
        cout <<" "<< pi[i];
    }

    cout << endl;

    cout << "f     =";
    for (int i = 0; i < 10; i++)
    {
        cout <<" "<< f[i];
    }

    return 0;
}
