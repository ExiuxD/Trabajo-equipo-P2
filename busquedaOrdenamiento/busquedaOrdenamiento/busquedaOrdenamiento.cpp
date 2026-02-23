#include <iostream>
using namespace std;

#include <vector>
#include "search.h"
#include "sort.h"
#include "view.h"
#include "randomgen.h"

int main()
{
    int opcion;
    int metodo;

    // 0/ Arreglo ahora es dinámico para soportar N, N*N, N*M
    vector<int> arregloVec;
    int n = 0;

    // 0/ Flag para mostrar proceso paso a paso
    bool verbose = false;

    // 0/ Variables para quick/merge
    int posicion;
    int valor;
    int comparaciones = 0;
    int intercambios = 0;

    // 0/ Generamos arreglo al inicio
    arregloVec = generarArregloInteractivo(n);

    do
    {
        mostrarMenu();
        cin >> opcion;

        switch (opcion)
        {
            case 0:
                // 0/ Regenerar arreglo con N, N*N o N*M y repetidos/sin repetidos
                arregloVec = generarArregloInteractivo(n);

                // 0/ Preguntar si quiere ver proceso
                cout << "Mostrar proceso paso a paso? (1=Si / 0=No): ";
                cin >> verbose;
                break;

            case 1:
                mostrarArreglo(arregloVec.data(), n);
                valor = pedirValor();

                // 0/ Búsqueda secuencial con verbose opcional
                posicion = busquedaSecuencial(arregloVec.data(), n, valor, verbose);

                if (posicion != -1) cout << "Valor encontrado en posicion: " << posicion << endl;
                else cout << "Valor no encontrado.\n";
                break;

            case 2:
                cout << "\nOrdenando arreglo con burbuja...\n";

                // 0/ Ordena y muestra el proceso si verbose está activo
                ordenarBurbuja(arregloVec.data(), n, verbose);
                mostrarArreglo(arregloVec.data(), n);

                valor = pedirValor();

                // 0/ Búsqueda binaria con verbose opcional
                posicion = busquedaBinaria(arregloVec.data(), n, valor, verbose);

                if (posicion != -1) cout << "Valor encontrado en posicion: " << posicion << endl;
                else cout << "Valor no encontrado.\n";
                break;

            case 3:
                metodo = mostrarMenuOrdenamiento();

                // 0/ reset para contar bien cada corrida
                comparaciones = 0;
                intercambios = 0;

                if (metodo == 1)
                {
                    ordenarBurbuja(arregloVec.data(), n, verbose);
                }
                else if (metodo == 2)
                {
                    ordenarSeleccion(arregloVec.data(), n, verbose);
                }
                else if (metodo == 3)
                {
                    ordenarInsercion(arregloVec.data(), n, verbose);
                }
                else if (metodo == 4)
                {
                    quickSort(arregloVec.data(), 0, n - 1, comparaciones, intercambios, verbose);
                    cout << "Comparaciones: " << comparaciones << endl;
                    cout << "Intercambios: " << intercambios << endl;
                }
                else if (metodo == 5)
                {
                    mergeSort(arregloVec.data(), 0, n - 1, comparaciones, verbose);
                    cout << "Comparaciones: " << comparaciones << endl;
                }
                else
                {
                    cout << "Metodo invalido.\n";
                }

                cout << "\nArreglo ordenado:\n";
                mostrarArreglo(arregloVec.data(), n);
                break;

            case 4:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida.\n";
        }

    } while (opcion != 4);

    return 0;
}