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
bool PushI(StackI *si, int elem);
int PopI(StackI *si, bool *vflag);

int main()
{
    StackI sti01;
    bool isOK;
    int item;
    int opt = 0;
    int size = 0;
    int elem = 0;

    do
    {
        cout << "\t---> STACK MENU <---" << endl;
        cout << "1.- Stack initialization" << endl;
        cout << "2.- Push an element" << endl;
        cout << "3.- Pop an element" << endl;
        cout << "4.- Show the estatus of stack" << endl;
        cout << "5.- Exit" << endl;
        cout << "Enter your option: ";

        cin >> opt;

        switch (opt)
        {
        case 1:
            cout << "\n=== Stack initialization ===\n"
                 << endl;
            cout << "Enter your size: ";
            cin >> size;
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
            break;
        case 2:
            cout << "\n=== Push an element ===\n"
                 << endl;
            cout << "Enter your element: ";
            cin >> elem;

            isOK = PushI(&sti01, elem);

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
        case 3:
            cout << "\n=== Pop an element ===\n"
                 << endl;
            elem = PopI(&sti01, &isOK);

            if (isOK == 0)
            {
                cout << "ERROR" << endl;
            }
            else
            {
                printf("\n.:Item \"%d\"  removed successfully:.\n\n", elem);
            }

            break;
        case 4:
            cout << "\n=== Show the estatus of stack ===\n"
                 << endl;
            ShowStackI(sti01);
            break;
        case 5:
            cout << "\nExit..." << endl;
            break;
        default:
            cout << "\n--- Ingrese una opcion valida ---\n"
                 << endl;
        }

    } while (opt != 5);

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

bool PushI(StackI *si, int elem)
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

int PopI(StackI *si, bool *vflag)
{
    int vret = 0;

    if (isStackEmpty(*si))
    {
        cout << "Stack Empty" << endl;
        *vflag = false;
    }
    else
    {
        vret = si->arri[si->top--];
        *vflag = true;
    }
    return vret;
}