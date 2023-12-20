#include <iostream>

using namespace std;

struct QueueI
{
    int *arri;
    int sizeq;
    int last;
};

void Show_QueueI(QueueI q);
bool Init_QueueI(QueueI *q, int s);
bool isQueueIEmpy(QueueI q);
bool isQueueIFull(QueueI q);
bool InQueueI(QueueI *q, int elem);
int DeQueueI(QueueI *q, bool *flag);

int main()
{
    QueueI *arri = NULL;
    QueueI arry;
    bool isOK;
    int item;
    int opt = 0;
    int size = 0;
    int elem = 0;

    do
    {
        cout << "\t---> QUEUE MENU <---" << endl;
        cout << "1.- Queue initialization" << endl;
        cout << "2.- Push an element" << endl;
        cout << "3.- Pop an element" << endl;
        cout << "4.- Show the estatus of queue" << endl;
        cout << "5.- Exit" << endl;
        cout << "Enter your option: ";

        cin >> opt;

        switch (opt)
        {
        case 1:
            cout << "\n=== Queue initialization ===\n"
                 << endl;
            cout << "Enter your size: ";
            cin >> size;
            isOK = Init_QueueI(&arry, size);

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

            isOK = InQueueI(&arry, elem);

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
            elem = DeQueueI(&arry, &isOK);

            if (isOK == 0)
            {
                cout << "ERROR" << endl;
            }
            else
            {
                printf("\n.:Item \"%d\" removed successfully:.\n\n", elem);
            }
            break;
        case 4:
            cout << "\n=== Show the estatus of stack ===\n"
                 << endl;
            Show_QueueI(arry);
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

void Show_QueueI(QueueI q)
{
    cout << endl;
    cout << "Address of first element on Stack: " << q.arri << endl;
    cout << "Size of queue: " << q.sizeq << endl;
    cout << "Last position: " << q.last << endl;
    cout << endl;
}

bool Init_QueueI(QueueI *q, int s)
{
    q->sizeq = s;
    q->last = -1;

    if ((q->arri = new int[s]) == NULL)
    {
        cout << "Not enough memory" << endl;
        return false;
    }
    return true;
}

bool isQueueIEmpy(QueueI q)
{
    if (q.last < 0)
    {
        return true;
    }
    return false;
}

bool isQueueIFull(QueueI q)
{
    if (q.last >= (q.sizeq - 1))
    {
        return true;
    }
    return false;
}

bool InQueueI(QueueI *q, int elem)
{
    if (isQueueIFull(*(q)))
    {
        cout << "Queue Full" << endl;
        return false;
    }

    if (isQueueIEmpy(*(q)))
    {
        q->last = 0;
        q->arri[q->last] = elem;
        return true;
    }
    q->arri[++q->last] = elem;
    cout << "Intro: " << q->arri[q->last] << endl;
    return true;
}

int DeQueueI(QueueI *q, bool *flag)
{
    int elem;

    if (isQueueIEmpy(*(q)))
    {
        cout << "Queue Empty" << endl;
        *flag = false;
    }

    else
    {
        *flag = true;
        elem = q->arri[0];

        for (int i = 0; i < q->last; i++)
        {
            q->arri[i] = q->arri[i + 1];
        }
        q->last--;
    }
    return elem;
}