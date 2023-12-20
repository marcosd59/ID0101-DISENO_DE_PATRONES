/************************************************************
Fecha de creación: 22/02/2022
Fecha de última actualización: 22/02/2022
Nombre del programa: Modelos de Plano cartesiano con arreglos dinámicos
Nombre del programador: Marcos Damian Pool Canul

Descripcion:

Haga un programa que modele un punto en el plano cartesiano. La entidad punto debe tener las siguientes características:
- Posición en el eje x
- Posición en el eje y
- Tipo de marcador (char)
- Color (integer)

* Programe y pruebe una función que cree arreglos dinámicos de puntos
* Programe y pruebe una función que capture la información de los puntos que desee el usuario, no forzosamente del tamaño del arreglo dinámico
* Haga una función que imprima todos los puntos capturados.
************************************************************/
#include <iostream>
#include <string.h>
#include <memory.h>

using namespace std;
const int MAX = 20;

// Estructura planos.

struct plano
{
    int posicionX;
    int posicionY;
    char marcador[20];
    int color;
} punto;

// zona de prototipos.

plano *CreateArrayPlano(int s);
void ScanPlanos(plano *ap, int s);
void PrintPlanos(plano *ap, int s);

// Variable global.

int numero = 0;

int main()
{
    plano *app = NULL;

    int size;

    cout << "Give the size: ";
    cin >> size;

    app = CreateArrayPlano(size);

    ScanPlanos(app, size);
    PrintPlanos(app, size);

    return 0;
}

plano *CreateArrayPlano(int s)
{
    plano *appn = NULL;
    appn = new plano[s];

    return appn;
}

void ScanPlanos(plano *ap, int s)
{
    plano item;

    cout << endl;
    cout << ".:ESCANEANDO ELEMENTOS:." << endl;
    char conti;
    int i = 0;
    do
    {

        cout << endl;
        cout << "Continue? llevas -> " << i << " 'y' para continuar 'n'  para terminar " << endl;
        cout << "R = ";
        cin >> conti;

        if ((conti == 'y') && (i < s))
        {

            cout << endl;
            cout << "Item number: " << i + 1 << endl;
            cout << "Posicion de X (int): ";
            cin >> item.posicionX;
            cout << "Posicion de Y (int): ";
            cin >> item.posicionY;
            cout << "Marcador (char): ";
            cin >> item.marcador;
            cout << "Color (integer): ";
            cin >> item.color;

            ap[i] = item;

            i++;
        }

    } while ((conti == 'y') && (i < s));

    numero = i;
}

void PrintPlanos(plano *ap, int s)
{
    cout << endl;
    cout << ".:IMPRIMIENDO ELEMENTOS:." << endl;
    for (int i = 0; i < numero; i++)
    {
        cout << endl;
        cout << "Item number: " << i + 1 << endl;
        cout << "Posicion X: " << ap[i].posicionX << endl;
        cout << "Posicion Y: " << ap[i].posicionY << endl;
        cout << "Tipo de Marcador: " << ap[i].marcador << endl;
        cout << "Color: " << ap[i].color << endl;
    }
}
