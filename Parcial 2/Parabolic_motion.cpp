/*********************************************************************
Fecha de creacion: 03/03/2022
Fecha de ultima actualizacion: 03/03/2022
Nombre del programa: Parabolic Motion v 0.1
Nombre del programador: Marcos Damian Pool Canul
Descripcion: Calcula la posición del proyectil en el plano X/Y a partir del movimiento parabólico en diferentes pasos de tiempo.

Entradas:

1. Initial Velocity // 9.0
2. Angle            // 1.24
3. Initial Height   // 30.0
4. Initial Time     // 0.0
5. Step Size        // 0.1
6. Number of Steps  // 6

Salidas:

1. ID
2. time
3. Position of x
4. Position of y
6. Velocity in X
7. Velocity in y

ID: IDA
time: 0.0
x: 0.000
y: 30.000
vx: 2.923
vy: 8.512

ID: IDB
time: 0.1
x: 0.292
y: 30.802
vx: 2.923
vy: 7.532

ID: IDC
time: 0.2
x: 0.585
y: 31.506
vx: 2.923
vy: 6.552

ID: IDD
time: 0.3
x: 0.877
y: 32.113
vx: 2.923
vy: 5.572

ID: IDE
time: 0.4
x: 1.169
y: 32.621
vx: 2.923
vy: 4.592

ID: IDF
time: 0.5
x: 1.462
y: 33.031
vx: 2.923
vy: 3.612
*********************************************************************/
#include <iostream>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <cmath>

using namespace std;
const int MAX = 25;

struct Parabolic
{
    float time;
    float posicionX;
    float posicionY;
    float velocityX;
    float velocityY;
};

// Zona de prototipos

Parabolic *CreateArrayPlano(int s);
void ScanPlanos(Parabolic *ap, int s);
void PrintPlanos(Parabolic *ap, int s);

// Variables globales

float Initial_velocity = 0;
float Angle = 0;
float Initial_height = 0;
float Initial_time = 0;
float Step_size = 0;
int Number_of_steps = 0;
float tiempo = 0;

int main()
{
    Parabolic *app = NULL;

    app = CreateArrayPlano(MAX);
    ScanPlanos(app, Number_of_steps);
    PrintPlanos(app, Number_of_steps);

    return 0;
}

Parabolic *CreateArrayPlano(int s)
{
    Parabolic *appn = NULL;
    appn = new Parabolic[s];

    return appn;
}

void ScanPlanos(Parabolic *ap, int s)
{
    Parabolic item;

    cin >> Initial_velocity;
    cin >> Angle;
    cin >> Initial_height;
    cin >> Initial_time;
    cin >> Step_size;
    cin >> Number_of_steps;

    ap->time = Initial_time;
    ap->posicionX = Initial_velocity * std::cos(Angle) * Initial_time;
    ap->posicionY = (Initial_velocity)*std::sin(Angle) * (Initial_time) - (0.5) * (9.8) * (Initial_time * Initial_time) + (Initial_height);
    ap->velocityX = Initial_velocity * std::cos(Angle);
    ap->velocityY = Initial_velocity * std::sin(Angle) - (9.8) * (Initial_time);
}

void PrintPlanos(Parabolic *ap, int s)
{
    char letter = 'A';

    float x = 0;
    float y = 0;
    float vx = 0;
    float vy = 0;

    if (Number_of_steps >= 25)
    {
        Number_of_steps = 25;
    }

    for (int i = 0; i < Number_of_steps; i++)
    {
        cout << endl;
        cout << "ID: ID" << letter++ << endl;

        ap[i].time = tiempo;
        tiempo += Step_size;

        printf("time: %.1f\n", ap[i].time);

        printf("x: %.3f\n", ap[i].posicionX);
        x = Initial_velocity * std::cos(Angle) * tiempo;
        ap[i + 1].posicionX = x;

        printf("y: %.3f\n", ap[i].posicionY);
        y = (Initial_velocity)*std::sin(Angle) * (tiempo) - (0.5) * (9.8) * (tiempo * tiempo) + (Initial_height);
        ap[i + 1].posicionY = y;

        printf("vx: %.3f\n", ap[i].velocityX);
        vx = Initial_velocity * std::cos(Angle);
        ap[i + 1].velocityX = vx;

        printf("vy: %.3f\n", ap[i].velocityY);
        vy = Initial_velocity * std::sin(Angle) - (9.8) * (tiempo);
        ap[i + 1].velocityY = vy;
    }
}