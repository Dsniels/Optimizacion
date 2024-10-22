#include "algoritmo.h"
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

TSP::TSP(vector<vector<double>> &m)
{
    matrix = m;
}

int TSP::nodoMasCercano(int &nodo)
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

int TSP::delta(int &i, int &j, int &m)
{
    return matrix[subTour[j]][i] + matrix[i][subTour[m]] - matrix[subTour[j]][subTour[m]];
}

int TSP::arcoMasBarato(int &Nodoj, int &costoFinal)
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
                if (subTour[j] != subTour[m])
                {
                    int costo = delta(i, j, m);

                    if (costo < costoMin)
                    {

                        costoMin = costo;
                        Nodoj = subTour[m];
                        Kfinal = i;
                    }
                }
            }
        }
    }
    costoFinal += costoMin;

    return Kfinal;
}

void TSP::printTour(vector<int> &array)
{
    for (int nodo : array)
    {
        cout << (nodo + 1) << " ";
    }
    cout << endl;
}

template <typename T>
void printMessage(string message, T valor)
{
    cout << message << " " << valor << " " << endl;
}

void printMessage(string message)
{
    cout << message << endl;
}

void TSP::solucionInsercionMasBarata()
{
    int costoFinal, inicio, K;
    for (int i = 0; i < matrix.size(); i++)
    {
        costoFinal = 0;
        inicio = i;
        subTour.push_back(inicio);

        int next = nodoMasCercano(inicio);
        costoFinal = matrix[next][inicio] * 2;

        subTour.push_back(next);

        subTour.push_back(inicio);
        while (subTour.size() < matrix.size() + 1)
        {
            int NodoJ;
            K = arcoMasBarato(NodoJ, costoFinal);

            auto posicion = find(subTour.begin() + 1, subTour.end() - 1, NodoJ);
            if (posicion != subTour.end())
            {

                subTour.insert(posicion, K);
            }
        }

        printMessage("Solucion por nodo:", inicio + 1);
        printTour(subTour);
        printMessage("Costo del tour:", costoFinal);
        if (costoFinal < CostoMin)
        {
            solucionOptima.clear();
            solucionOptima = subTour;
            CostoMin = costoFinal;
        }

        subTour.clear();
    }

    printMessage("Solucion mas optima: ");
    printTour(solucionOptima);
    printMessage("Costo min:", CostoMin);
}



void TSP::solucionInsersionMasCercana(){
    int costoFinal, inicio, K;
    for(int i = 0; i < matrix.size(); i++){
        costoFinal = 0;
        inicio = i;

        subTour.push_back(inicio);

        int next = nodoMasCercano(inicio);

        subTour.push_back(next);
        subTour.push_back(inicio);
        costoFinal += matrix[inicio][next]*2;

        while(subTour.size() < matrix.size()+1){
            int nodoJ;

        }
    }
}