#include <iostream>
#define HashMod 30

using namespace std;

unsigned long long CharToInt(char entrada);
unsigned long long ObtenerNumero(string entrada);
int FuncHash(string entrada);

int main()
{
    string Tabla[HashMod];

    for (int i = 0; i < HashMod; i++)
    {
        Tabla[i] = "null";
    }

    int OpcMen = 0;

    do
    {
        cout << "---> Menu hash <---\n";
        cout << "1. Insertar clave\n";
        cout << "2. Ver elementos clave\n";
        cout << "3. Buscar un elemento \n";
        cout << "4. Salir\n";
        cout << "Digite su opcion: ";

        cin >> OpcMen;

        if (OpcMen == 1)
        {
            string Clave;

            cout << "Ingrese su clave: ";
            cin >> Clave;
            int Pos = FuncHash(Clave);
            cout << "\nEl valor ascii es: " << ObtenerNumero(Clave);
            cout << "\nValor hash: " << Pos << endl;

            if (Tabla[Pos] == "null" || Tabla[Pos] == Clave)
            {
                Tabla[Pos] = Clave;
            }

            else
            {
                for (int i = Pos; i < HashMod; i++)
                {
                    if (Tabla[i] == "null")
                    {
                        Tabla[i] = Clave;
                        break;
                    }
                }
            }
        }

        if (OpcMen == 2)
        {
            for (int i = 0; i < HashMod; i++)
            {
                cout << "Elemento #" << i << ": " << Tabla[i] << "\n";
            }
        }

        if(OpcMen == 3)
        {
            string palabra;
            cout << "Ingresa la clave que deseas buscar" << endl;
            cout << ">> Clave: ";
            cin >> palabra;

            int j = 0;
            int posicion = FuncHash(palabra);
            ObtenerNumero(palabra);
            cout << "\nPosicion: " << posicion << endl;

            cout << "Elemento encontrado #" << posicion <<": " << Tabla[posicion] << "\n";
        }

        cout << endl;

    } while (OpcMen != 4);
}

unsigned long long CharToInt(char entrada)
{
    unsigned long long Salida;
    Salida = entrada;
    return Salida;
}

unsigned long long ObtenerNumero(string entrada)
{
    unsigned long long Salida = 0;

    for (int i = 0; entrada[i] != '\0'; i++)
    {
        if (entrada[1 + i] == '\0' && i == 0)
        {
            Salida += CharToInt(entrada[i]);
        }

        else
        {
            if (i == 0)
            {
                Salida += CharToInt(entrada[i]);
                continue;
            }

            else
            {
                int miChar = CharToInt(entrada[i]);
                if (miChar > 99)
                {
                    Salida *= 1000;
                }
                else if (miChar > 9)
                {
                    Salida *= 100;
                }
                Salida += miChar;
            }
        }
    }
    return Salida;
}

int FuncHash(string entrada)
{
    unsigned long long Amodular = ObtenerNumero(entrada);
    int Salida = Amodular % HashMod;
    return Salida;
}