#include <iostream>
#include <stdlib.h>

using namespace std;

struct Stacki
{
    int sizestack;
    int top;
    int *arri;
};

bool Create_Stacki(Stacki *sti, int s);
void Show_Stacki(Stacki sti);
bool isStackiEmpy(Stacki sti);
bool isStackiFull(Stacki sti);
bool Push_Stacki(Stacki *sti, int elem);
int Pop_Stacki(Stacki *sti, bool *flag);

int main()
{
    Stacki s1;
    bool valid;
    int item;

    if (!Create_Stacki(&s1, 5))
    {
        cout << "Error" << endl;
        exit(1);
    }

    Show_Stacki(s1);
    cout << "Is Stacki Empy?: " << isStackiEmpy(s1) << endl;
    cout << "Is Stacki Full?: " << isStackiFull(s1) << endl;

    cout << "is Push OK: " << Push_Stacki(&s1, 1) << endl;
    cout << "is Push OK: " << Push_Stacki(&s1, 2) << endl;
    cout << "is Push OK: " << Push_Stacki(&s1, 3) << endl;
    cout << "is Push OK: " << Push_Stacki(&s1, 4) << endl;
    cout << "is Push OK: " << Push_Stacki(&s1, 5) << endl;

    cout << "Is Stacki Empy?: " << isStackiEmpy(s1) << endl;
    cout << "Is Stacki Full?: " << isStackiFull(s1) << endl;

    Show_Stacki(s1);

    cout << "Element extracted: " << Pop_Stacki(&s1, &valid) << endl;

    item = Pop_Stacki(&s1, &valid);

    if (valid)
    {
        cout << "Element extracted: " << item << endl;
    }

    item = Pop_Stacki(&s1, &valid);

    if (valid)
    {
        cout << "Element extracted: " << item << endl;
    }

    item = Pop_Stacki(&s1, &valid);

    if (valid)
    {
        cout << "Element extracted: " << item << endl;
    }

    item = Pop_Stacki(&s1, &valid);

    if (valid)
    {
        cout << "Element extracted: " << item << endl;
    }

    cout << "Is Stacki Empy?: " << isStackiEmpy(s1) << endl;
    cout << "Is Stacki Full?: " << isStackiFull(s1) << endl;

    Show_Stacki(s1);

    return 0;
}

bool Create_Stacki(Stacki *sti, int s)
{
    if ((sti->arri = new int[s]) == NULL)
    {
        cout << "Noy enough memory" << endl;
        return false;
    }

    sti->sizestack = s;
    sti->top = -1;

    return true;
}

void Show_Stacki(Stacki sti)
{
    cout << "Size: " << sti.sizestack << endl;
    cout << "Top: " << sti.top << endl;
}

bool isStackiEmpy(Stacki sti)
{
    if (sti.top < 0)
    {
        cout << "Stack Empty" << endl;
        return true;
    }
    return false;
}

bool isStackiFull(Stacki sti)
{
    if (sti.top >= (sti.sizestack - 1))
    {
        cout << "Stack Full" << endl;
        return true;
    }
    return false;
}

bool Push_Stacki(Stacki *sti, int elem)
{
    if (isStackiFull(*(sti)))
    {
        return false;
    }

    sti->arri[++sti->top] = elem;
    return true;
}

int Pop_Stacki(Stacki *sti, bool *flag)
{
    int vreturn = 0;

    if (isStackiEmpy(*(sti)))
    {
        *(flag) = false;
    }
    else
    {
        *(flag) = true;
        vreturn = sti->arri[sti->top--];
    }
    return vreturn;
}