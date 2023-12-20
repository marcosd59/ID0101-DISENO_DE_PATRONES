/* LISTAS SIMPLEMENTE ENLAZADAS CON UN CENTINELA

Un centinela es nodo que contiene basura, no se guardan datos ahi, su apuntador siguiente no sera tierra, sino que sera el mismo este evita que tengas que mandar el header a tierra, ya que el header siempre apuntara al centinela */

#include <iostream>

using namespace std;

struct Nodei
{
    int x;
    Nodei *next;
};

Nodei *CreateNode(int elem);
bool InsertNodei(Nodei *h, int elem);
bool RemoveNodei(Nodei *h);

int main()
{
    Nodei *header = NULL;
    bool isOK;
    bool isError;

    header = CreateNode(10);

    isOK = InsertNodei(header, 1);

    if (isOK == 1)
    {
        cout << ".:Elemento agregado:." << endl;
    }

    isOK = InsertNodei(header, 2);

    if (isOK == 1)
    {
        cout << ".:Elemento agregado:." << endl;
    }

    isOK = InsertNodei(header, 3);

    if (isOK == 1)
    {
        cout << ".:Elemento agregado:." << endl;
    }

    isError = RemoveNodei(header);

    if (isError == 1)
    {
        cout << ".:Elemento eliminado:." << endl;
    }

    cout << header->x << endl;
    cout << header->next << endl;

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
    return newnode;
}

bool InsertNodei(Nodei *h, int elem)
{
    Nodei *api;
    Nodei *newnodo = CreateNode(elem);
    if (newnodo == NULL)
    {
        return false;
    }
    api = h;
    while (api->next != api->next->next)
    {
        api = api->next;
    }
    api->next = newnodo;
    return true;
}

bool RemoveNodei(Nodei *h)
{
    Nodei *api = h;
    if (api->next == h)
    {
        return false;
    }
    while (api->next != api->next->next)
    {
        api = api->next;
    }
    delete (api->next);
    api->next = api;
    return true;
}