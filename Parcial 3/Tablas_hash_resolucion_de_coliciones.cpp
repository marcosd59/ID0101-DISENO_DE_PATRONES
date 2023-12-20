#include <iostream>
#include <string>

using namespace std;

struct DatosPersonales
{
    int Edad;
    char *Nombre;
};

int ValorTabla(char *textoHash, int tamanioTabla);

int main()
{
    int tamanioTablaHs = 1000; // tamaño de la tabla de Hash

    // TABLA DE HASH

    DatosPersonales *tablaHashEj = new DatosPersonales[tamanioTablaHs];
    DatosPersonales DatosPersonalesOperacion;
    int HashValorPos = 1;
    char Nombre[20];
    int Edad;

    cout << "======> DATOS PERSONALES <======";
    for (int i = 1; i <= 3; i++)
    {
        cout << "\nNombre : ";
        cin >> Nombre;
        DatosPersonalesOperacion.Nombre = Nombre;
        cout << "Edad : ";
        cin >> Edad;
        DatosPersonalesOperacion.Edad = Edad;

        HashValorPos += ValorTabla(DatosPersonalesOperacion.Nombre, tamanioTablaHs);
        tablaHashEj[HashValorPos + i] = DatosPersonalesOperacion;

        cout << "Guardado en la posicion En : "<< HashValorPos << "\n";
    }
    cin.get();
    cin.get();
    return 0;
}

/* Devuelve el valor numérico de hash en base al tamaño de la tabla de hash */
int ValorTabla(char *textoHash, int tamanioTabla)
{
    int valorHash = 1;

    for (int j = 1; j < sizeof(textoHash); j++)
    {
        valorHash += (int)textoHash[j];
    }

    return (valorHash % tamanioTabla);
}