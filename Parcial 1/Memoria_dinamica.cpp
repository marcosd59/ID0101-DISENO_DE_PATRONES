#include <iostream>
#include <memory.h>
using namespace std;

void fillarr(int *arri, int s, int f);
void disparr(int *arri, int s);
int *createarr(int s);

int main(void)
{
  int *api = NULL;
  int sizearray = 0;

  cout << "Size of Array: ";
  cin >> sizearray;

  api = createarr(sizearray);
  fillarr(api, sizearray, 0);
  disparr(api, sizearray);

  *(api) = 13;

  return 0;
}

void fillarr(int *arri, int s, int f)
{
  for (int i = 0; i < s; i++)
  {
    arri[i] = f;
  }
}

void disparr(int *arri, int s)
{
  for (int j = 0; j < s; j++)
  {
    cout << arri[j];
  }
}

int *createarr(int s)
{
  int *api = NULL;

  if ((api = new int[s]) == NULL)
  {
    cout << "Not enough memory" << endl;
    return NULL;
  }

  return api;
}

/*
if ((api = (int *)malloc(sizeof(int))) == NULL)
{
  cout << "Not enough memory" << endl;
  exit (1);
}
*/

/*
  for(int i = 0; i < sizearray; i++)
{
  cin >> api[i];
}

for(int i = 0; i < sizearray; i++)
{
  cout << api[i];
}
*/
