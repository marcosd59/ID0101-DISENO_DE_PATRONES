#include <iostream>
#include <string.h>
#include <memory.h>

using namespace std;
const int MAX = 20;

struct packet
{
    int ID;
    char description[50];
    float weight;
    float dimension;
};

// zona de prototipos

packet *CreateArrayPackets(int s);
void ScanPackets(packet *ap, int s);
void PrintPackets(packet *ap, int s);

int main()
{
    packet *app = NULL;

    app = CreateArrayPackets(2);
    ScanPackets(app, 2);
    PrintPackets(app, 2);

    return 0;
}

packet *CreateArrayPackets(int s)
{
    packet *appn = NULL;
    appn = new packet[s];
    return appn;
}

void ScanPackets(packet *ap, int s)
{
    packet item;

    cout << "\t.:ESCANEANDO ELEMENTOS:.\n" << endl;

    for (int i = 0; i < s; i++)
    {
        cout << "Item number: " << i + 1 << endl;
        cout << "ID: ";
        cin >> item.ID;
        cout << "Description: ";
        cin >> item.description;
        cout << "Weight: ";
        cin >> item.weight;
        cout << "Dimension: ";
        cin >> item.dimension;

        cout << endl;

        ap[i] = item;
    }
}

void PrintPackets(packet *ap, int s)
{

cout << "\t.:IMPRIMIENDO ELEMENTOS:.\n" << endl;

    for (int i = 0; i < s; i++)
    {
        cout << "Item number: " << i + 1 << endl;
        cout << "ID: " << ap[i].ID << endl;
        cout << "Description: " << ap[i].description << endl;
        cout << "Weight: " << ap[i].weight << endl;
        cout << "Dimension: " << ap[i].dimension << endl;
    
        cout << endl;
    }
}