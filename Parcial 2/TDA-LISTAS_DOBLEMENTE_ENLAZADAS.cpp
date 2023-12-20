#include <iostream>

using namespace std;

struct Nodei
{
    int x;
    Nodei *next;
    Nodei *prev;
};

Nodei *CreateNode(int elem);
void CreateListD(Nodei **H, Nodei **T);
bool InsertAsciD(Nodei *H, int elem);
bool InsertSortD(Nodei *H, int elem);
bool RemoveSortD(Nodei *H, int elem);

int main()
{
    Nodei *Header = NULL;
    Nodei *Tail = NULL;
    bool isOK;

    CreateListD(&Header, &Tail);

    isOK = InsertSortD(Header, 1);

    if (isOK == 1)
    {
        cout << ".:Elemento agregado:." << endl;
    }

    isOK = InsertSortD(Header, 2);

    if (isOK == 1)
    {
        cout << ".:Elemento agregado:." << endl;
    }

    isOK = RemoveSortD(Header, 1);

    if (isOK == 1)
    {
        cout << ".:Elemento eliminado:." << endl;
    }
    else if (isOK == 0)
    {
        cout << ".:Elemento no eliminado:." << endl;
    }

    isOK = RemoveSortD(Header, 2);

    if (isOK == 1)
    {
        cout << ".:Elemento eliminado:." << endl;
    }
    else if (isOK == 0)
    {
        cout << ".:Elemento no encontrado:." << endl;
    }

    isOK = RemoveSortD(Header, 1);

    if (isOK == 1)
    {
        cout << ".:Elemento eliminado:." << endl;
    }
    else if (isOK == 0)
    {
        cout << ".:Elemento no encontrado:." << endl;
    }

    cout << Header->x << endl;
    cout << Header->next << endl;
    cout << Header->prev << endl;

    cout << endl;

    cout << Tail->x << endl;
    cout << Tail->next << endl;
    cout << Tail->prev << endl;

    return 0;
}

Nodei *CreateNode(int elem)
{
    Nodei *newnode;
    newnode = new Nodei[1];

    if (newnode == NULL)
    {
        return NULL;
    }

    newnode->x = elem;
    newnode->next = newnode;
    newnode->prev = newnode;
    return newnode;
}

void CreateListD(Nodei **H, Nodei **T)
{
    Nodei *newnodeH = NULL;
    Nodei *newnodeT = NULL;

    newnodeH = CreateNode(1);
    newnodeT = CreateNode(1);

    newnodeH->next = newnodeT;
    newnodeT->prev = newnodeH;

    *H = newnodeH;
    *T = newnodeT;
}

bool InsertAsciD(Nodei *H, int elem)
{
    Nodei *newnode = CreateNode(elem);
    Nodei *api = H;

    if (newnode == NULL)
    {
        return false;
    }
    return true;
}

bool InsertSortD(Nodei *H, int elem)
{
    Nodei *newnode = CreateNode(elem);
    Nodei *api = H;

    if (newnode == NULL)
    {
        return false;
    }

    while (api->next != api->next->next && api->next->x < newnode->x)
    {
        api = api->next;
    }
    newnode->prev = api;
    newnode->next = api->next;
    api->next = newnode;
    newnode->next->prev = newnode;

    return true;
}

bool RemoveSortD(Nodei *H, int elem)
{
    Nodei *api = H->next;
    while (api != api->next && api->x != elem)
    {
        api = api->next;
    }
    if (api == api->next)
    {
        return false;
    }
    api->prev->next = api->next;
    api->next->prev = api->prev;

    delete (api);
    return true;
}