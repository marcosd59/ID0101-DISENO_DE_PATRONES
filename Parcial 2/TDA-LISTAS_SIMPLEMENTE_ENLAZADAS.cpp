#include <iostream>

using namespace std;

struct Node
{
    int x;
    Node *next;
};

Node *Create_Node(int elem);
bool Insert_Node(Node **H, int elem);
void mostrarLISTA(Node *H);

int main()
{
    Node *header = NULL;
    bool isOK = false;

    header = Create_Node(10);

    Insert_Node(&header, 1);
    Insert_Node(&header, 2);
    Insert_Node(&header, 3);
    Insert_Node(&header, 4);
    Insert_Node(&header, 5);

    isOK = Insert_Node(&header, 6);

    if (isOK == true)
    {
        cout << ".:Elemento agregado:." << endl;
    }
    else
    {
        cout << ".:Error:." << endl;
    }

    cout << "Element in header: " << header->x << endl;
    cout << "Next position: " << header->next << endl;

    mostrarLISTA(header);

    return 0;
}

Node *Create_Node(int elem)
{
    Node *apnew = NULL;
    apnew = new Node[1];
    apnew->x = elem;
    apnew->next = NULL;

    return apnew;
}

bool Insert_Node(Node **H, int elem)
{
    Node *apnew = Create_Node(elem);
    Node *api = *H;

    if (apnew == NULL)
    {
        return false;
    }

    if (H == NULL)
    {
        *H = apnew;
    }

    else
    {
        while (api->next != NULL)
        {
            api = api->next;
        }
        api->next = apnew;
    }

    return true;
}

void mostrarLISTA(Node *H)
{
    Node *actual = new Node(); // 1. Crar un nuevo nodo(actual).
    actual = H;                // 2. Igualar ese nuevo nodo(actual) a lista.

    while (actual != NULL) // 3. Recorrer la lista de inicio a fin.
    {
        printf("%d -> ", actual->x);
        actual = actual->next;
    }
}