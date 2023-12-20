#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 3;

int **CreatematDin(int nr, int nc);
void ShowMat(int **m, int nr, int nc);
void ScanMat(int **m, int nr, int nc);

int main()
{
    int **M = NULL;
    int nrow = 0;
    int ncol = 0;

    cout << "Enter numb of rows: ";
    cin >> nrow;
    cout << "Enter numb of columns: ";
    cin >> ncol;

    M = CreatematDin(nrow, ncol);

    ScanMat(M, nrow, ncol);
    ShowMat(M, nrow, ncol);

    return 0;
}

int **CreatematDin(int nr, int nc)
{
    int **apmd = NULL;

    apmd = new int*[nr];

    for (int i = 0; i < nr; i++)
    {
        apmd[i] = new int[nc];
    }
    return apmd;
}

void ShowMat(int **m, int nr, int nc)
{
    for (int i = 0; i < nr; i++)
    {
        for (int j = 0; j < nc; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

void ScanMat(int **m, int nr, int nc)
{
    for (int i = 0; i < nr; i++)
    {
        for (int j = 0; j < nc; j++)
        {
            cout << "m["<<i<<"]["<<j<<"]: ";
            cin >> m[i][j];
        }
        cout << endl;
    }
}