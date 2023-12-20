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
    int item = 0;
    bool valid;

    if (!Init_QueueI(&arry, 10))
    {
        cout << "Failed to initialize" << endl;
        exit(1);
    }

    Show_QueueI(arry);

    cout << "Is Queue Empty?: " << isQueueIEmpy(arry) << endl;
    cout << "Is Queue Full?: " << isQueueIFull(arry) << endl;
    cout << endl;

    InQueueI(&arry, 1);
    InQueueI(&arry, 2);
    InQueueI(&arry, 3);
    InQueueI(&arry, 4);
    InQueueI(&arry, 5);

    Show_QueueI(arry);

    cout << "Is Queue Empty?: " << isQueueIEmpy(arry) << endl;
    cout << "Is Queue Full?: " << isQueueIFull(arry) << endl;
    cout << endl;

    cout << "Element extracted: " << DeQueueI(&arry, &valid) << endl;

    item = DeQueueI(&arry, &valid);

    if (valid)
    {
        cout << "Element extracted: " << item << endl;
    }

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
        cout << "Queue Empty" << endl;
        return true;
    }
    return false;
}

bool isQueueIFull(QueueI q)
{
    if (q.last >= (q.sizeq - 1))
    {
        cout << "Queue Full" << endl;
        return true;
    }
    return false;
}

bool InQueueI(QueueI *q, int elem)
{
    if (isQueueIFull(*(q)))
    {
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