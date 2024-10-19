#include "algoritmo.h"
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

IMB::IMB(vector<vector<double>> &m)
{
    matrix = m;
}

int IMB::nodoMasCercano(int nodo)
{
    int distanciaMin = INT32_MAX;
    int distancia;
    int next = -1;
    for (int i = 0; i < matrix.size(); i++)
    {
        if (find(subTour.begin(), subTour.end(), i) == subTour.end())
        {
            distancia = matrix[nodo][i];
            if (distancia < distanciaMin)
            {
                distanciaMin = distancia;
                next = i;
            }
        }
    }
    return next;
}

int IMB::delta(int i, int j, int m)
{
    int incremento = matrix[subTour[j]][i] + matrix[i][subTour[m]] - matrix[subTour[j]][subTour[m]];

    return incremento;
}

int IMB::arcoMasBarato(int &Nodoi, int &Nodoj, int &costoFinal)
{
    int costoMin = INT32_MAX;
    int Kfinal = -1;
    for (int i = 0; i < matrix.size(); i++)
    {
        if (find(subTour.begin(), subTour.end(), i) == subTour.end())
        {
            for (int j = 0; j < subTour.size(); j++)
            {
                int m = (j + 1) % subTour.size();
                int costo = delta(i, j, m);
                if (j != m)
                {
                    //cout << "Delta de nodo " << i + 1 << " ente " << subTour[j] + 1 << " y " << subTour[m] + 1 << ": " << costo << endl;
                    if (costo < costoMin)
                    {
                        costoMin = costo;
                        Nodoi = subTour[j];
                        Nodoj = subTour[m];
                        Kfinal = i;
                    }
                }
            }
        }
    }
    costoFinal += costoMin;

    //cout << "K: " << Kfinal + 1 << endl;
    return Kfinal;
}

void IMB::printTour()
{
    for (int nodo : subTour)
    {
        cout << (nodo + 1) << " ";
    }
    cout << endl;
}

void IMB::solucion()
{
    int costoFinal;
    int inicio;
    int K;
    for (int i = 0; i < matrix.size(); i++)
    {
        costoFinal = 0;
        inicio = i;
        subTour.push_back(inicio);

        int next = nodoMasCercano(inicio);
        //cout << "Primer Nodo: ";
        //printTour();
        //cout << "Nodo mas cercano " << next + 1 << endl;
        //cout<<matrix[next][inicio]<<endl;

        costoFinal = matrix[next][inicio]*2;

        subTour.push_back(next);
        subTour.push_back(inicio);

        while (subTour.size() < matrix.size() + 1)
        {
            int NodoI, NodoJ;
            K = arcoMasBarato(NodoI, NodoJ, costoFinal);
            auto it = find(subTour.begin() + 1, subTour.end() - 1, NodoJ);
            if (it != subTour.end())
            {
           

                subTour.insert(it, K);
                //printTour();
            }
        }

        cout << "Solucion por nodo " << (inicio + 1) << ": ";
        printTour();

        cout << "Costo del tour: " << costoFinal << endl;
        subTour.clear();
    }
}
