#include <iostream>
using namespace std;

const int MAX = 3;

struct House
{
    char addres[50];
    float cost;
    int rooms;
};

// Zona de prototipos

void ScanHouse(House *h);  // Lee una sola casa.
void PrintHouse(House h);  // Imprimer una casa.
int ReadHouse(House ah[]); // Lee un arreglos de casas.

int main()
{
    House h1;
    House ArrH[MAX];

    int nroom = 0;
    char casa[100];

    // Declaración de estructura inicializada.
    // House h1 = {"Norte",1150000.00,3};

    nroom = ReadHouse(ArrH);
    cout << "\nHouses registred: " << nroom << endl;

    cout << endl;
    
    return 0;
}

void ScanHouse(House *h)
{
    cout << "Give the address: ";
    cin >> h->addres;
    cout << "Give the cost: ";
    cin >> h->cost;
    cout << "Give the number of rooms: ";
    cin >> h->rooms;
}

void PrintHouse(House h)
{
    cout << "Addres: " << h.addres << endl;
    cout << "Cost: " << h.cost << endl;
    cout << "rooms:" << h.rooms << endl;
}

int ReadHouse(House ah[])
{
    int i = 0;
    char conti;

    do
    {
        cout << "Quieres introducir valores para una casa (s/n): ";
        cin >> conti;

        if (conti == 'n')
        {
            return i;
        }

        ScanHouse(&ah[i++]);

    } while (i < MAX);

    return i;
}