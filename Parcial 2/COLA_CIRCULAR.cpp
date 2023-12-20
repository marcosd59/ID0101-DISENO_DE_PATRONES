#include <iostream>

using namespace std;

struct QueueI
{
    int *arri;
    int sizeq;
    int last;
    int front;
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

    if (!Init_QueueI(&arry, 10))
    {
        cout << "Failed to initialize" << endl;
        exit(1);
    }

    else
    {
        cout << "Initialized" << endl;
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

    bool aux;

    cout << "Deleted item: " << DeQueueI(&arry, &aux) << endl;

    return 0;
}

void Show_QueueI(QueueI q)
{
    cout << endl;
    cout << "Address of first element on Stack: " << q.arri << endl;
    cout << "Size of Stack: " << q.sizeq << endl;
    cout << "Last position: " << q.last << endl;
    cout << "Front position: " << q.front << endl;
    cout << endl;
}

bool Init_QueueI(QueueI *q, int s)
{
    q->arri = new int[s];

    if (q->arri == NULL)
    {
        cout << "Not enough memory" << endl;
        return false;
    }

    q->sizeq = s;
    q->last = -1;
    q->front = -1;

    return true;
}

bool isQueueIEmpy(QueueI q)
{
    if (q.last < 0 || q.front < 0)
    {
        return true;
    }
    return false;
}

bool isQueueIFull(QueueI q)
{
    if ((q.last + 1) % q.sizeq == q.front)
    {
        return true;
    }
    return false;
}

bool InQueueI(QueueI *q, int elem)
{
    if (isQueueIFull(*(q)))
    {
        cout << "Queue Full";
        return false;
    }

    if (isQueueIEmpy(*(q)))
    {
        q->last = 0;
        q->arri[q->last] = elem;
        return true;
    }

    q->last = ((q->last + 1) % q->sizeq);
    q->arri[++q->last] = elem;
    cout << "Intro: " << q->arri[q->last] << endl;
    return true;
}

int DeQueueI(QueueI *q, bool *flag)
{
    int elem;

    if (isQueueIEmpy(*(q)))
    {
        cout << "Queue Empty";
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