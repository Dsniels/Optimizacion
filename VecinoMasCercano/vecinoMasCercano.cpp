#include <iostream>
#include <vector>
#include <limits>
#include "vecinoMasCercano.h"

using namespace std;

extern int n;
extern double distancia;

vector<int> vecinoMasCercano(const vector<vector<double>> &matriz, int inicio, int n)
{
    distancia =0;
    vector<int> tour;
    vector<bool> visitado(n, false);
    int nodoActual = inicio;
    tour.push_back(nodoActual);
    visitado[nodoActual] = true;

    for (int i = 0; i < n - 1; ++i)
    {
        double minDistance = INT32_MAX;
        int next = -1;

        for (int j = 0; j < n; ++j)
        {
            if (!visitado[j] && matriz[nodoActual][j] < minDistance)
            {
                minDistance = matriz[nodoActual][j];
                next = j;
            }
        }

        if (next != -1)
        {
            distancia += minDistance;
            tour.push_back(next);
            visitado[next] = true;
            nodoActual = next;
        }
    }
    distancia += matriz[nodoActual][inicio];
    tour.push_back(inicio);
    cout << endl
         << "Distancia Recorrida: " << distancia << endl;

    return tour;
}
