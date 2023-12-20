/************************************************************
Fecha de creación: 29/03/2022.
Fecha de última actualización: 29/03/2022.
Nombre del programador: Marcos Damian Pool Canul.
Nombre del programa: Pilas con caracteres.
************************************************************/
#include <iostream>
#include <stdio.h>

using namespace std;
const int MAX = 3;

struct StackI
{
    int *arri;
    int top;
    int sizemax;
};

bool IniStackI(StackI *si, int s);
bool isStackEmpty(StackI si);
bool isStackFull(StackI si);
void ShowStackI(StackI si);
bool PushI(StackI *si, char elem);
char PopI(StackI *si, bool *vflag);

int main()
{
    StackI sti01;
    bool isOK;
    int item;
    int opt = 0;
    int size = 50;
    char elem = 0;
    int contador = 0;

    isOK = IniStackI(&sti01, size);

    if (isOK == 0)
    {
        cout << "ERROR" << endl;
    }
    else
    {
        cout << "\n.:Size created successfully:.\n"
             << endl;
    }

    do
    {
        cout << "\t---> STACK MENU <---" << endl;
        cout << "1.- Push a caracter" << endl;
        cout << "2.- Pop a caracter" << endl;
        cout << "3.- Clear all" << endl;
        cout << "4.- Exit" << endl;
        cout << "Enter your option: ";

        cin >> opt;

        switch (opt)
        {
        case 1:
            cout << "\n=== Push a caracter ===\n"
                 << endl;
            cout << "Enter your caracter: ";
            cin >> elem;
            isOK = PushI(&sti01, elem);
            contador++;
            if (isOK == 0)
            {
                cout << "ERROR" << endl;
            }
            else
            {
                cout << "\n.:Item added successfully:.\n"
                     << endl;
            }

            break;
        case 2:
            cout << "\n=== Pop a caracter ===\n"
                 << endl;
            elem = PopI(&sti01, &isOK);
            contador--;
            if (isOK == 0)
            {
                cout << "" << endl;
            }
            else
            {
                printf("\n.:Item \"%c\"  removed successfully:.\n\n", elem);
            }

            break;
        case 3:
            cout << "\n=== Limpiando ===\n"
                 << endl;
            if (contador <= 0)
            {
                contador = 1;
            }
            for (int i = 0; i < contador; i++)
            {
                elem = PopI(&sti01, &isOK);
                printf("\n.:Item \"%c\"  removed successfully:.\n\n", elem);
            }
            break;
        case 4:
            cout << "\nExit..." << endl;
            break;
        default:
            cout << "\n--- Ingrese una opcion valida ---\n"
                 << endl;
        }

    } while (opt != 4);

    return 0;
}

bool IniStackI(StackI *si, int s)
{
    si->arri = new int[s];

    if (si->arri == NULL)
    {
        cout << "Not enough memory" << endl;
        return false;
    }
    si->top = -1;
    si->sizemax = s;
    return true;
}

bool isStackEmpty(StackI si)
{
    if (si.top < 0)
    {
        return true;
    }
    return false;
}

bool isStackFull(StackI si)
{
    if (si.top >= (si.sizemax - 1))
    {
        return true;
    }
    return false;
}

void ShowStackI(StackI si)
{
    cout << "Address of first element on Stack: " << si.arri << endl;
    cout << "Size of Stack: " << si.sizemax << endl;
    cout << "Position of top: " << si.top << endl;
    cout << endl;
}

bool PushI(StackI *si, char elem)
{
    if (isStackFull(*si))
    {
        cout << "Stack Full" << endl;
        return false;
    }

    si->arri[++si->top] = elem;
    cout << "Intro: " << si->arri[si->top] << endl;

    return true;
}

char PopI(StackI *si, bool *vflag)
{
    char vret;

    if (isStackEmpty(*si))
    {
        cout << "#" << endl;
        *vflag = false;
    }
    else
    {
        vret = si->arri[si->top--];
        *vflag = true;
    }
    return vret;
}