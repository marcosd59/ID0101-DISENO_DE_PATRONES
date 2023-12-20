#include <string.h>
#include <iostream>
using namespace std;

const int MAX = 50;

struct caja
{
  char caracter[MAX];
  int numerodeveces;
};

caja *createCaja(int S);
int captureCajas(caja *ac, int s);
void listCajas(caja *apc, int s);
void printCaja(caja pc);
void scanCaja(caja *apc);

int main()
{

  caja *apun = NULL;
  int ele;

  cout << "Maximum number of elements:" << endl;
  cin >> ele;

  apun = createCaja(ele);

  ele = captureCajas(apun, ele); // Direcionamiento

  if (ele == 0)
  {
    cout << "No creaste/capturaste ningun elemento" << endl;
  }
  else
  {
    cout << "\n ------------ Maximum reached, showing elements --------------" << endl;
  }

  listCajas(apun, ele);

  return 0;
}

caja *createCaja(int S)
{

  caja *item = NULL;

  item = new caja[S];

  return item;
}

void scanCaja(caja *apc)
{

  cout << "Scan elements" << endl;
  cout << "Enter Character: ";
  cin >> apc->caracter;
  cout << "Enter Num of Times: ";
  cin >> apc->numerodeveces;
}

int captureCajas(caja *ac, int s)
{
  char conti;
  int i = 0;
  do
  {

    cout << "Continue? llevas -> " << i << " 'y' para continuar 'n'  para terminar " << endl;
    cin >> conti;

    if ((conti == 'y') && (i < s))
    {

      scanCaja(&(ac[i]));
      i++;
    }

  } while ((conti == 'y') && (i < s));

  return i;
}

void listCajas(caja *apc, int s)
{

  for (int i = 0; i < s; i++)
  {

    printCaja(apc[i]);
  }
}

void printCaja(caja pc)
{
  int numvece = pc.numerodeveces;
  cout << "" << endl;
  for (int i = 0; i < numvece; i++)
  {
    cout << pc.caracter;
  }
}