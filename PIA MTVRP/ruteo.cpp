#include "ruteo.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <numeric>
#include <climits>
#include <ranges>
#include <iomanip>

auto printV = [](int &n)
{ cout << n << " "; };

MTVRP::MTVRP(vector<vector<double>> &distancias, int k, vector<int> &demandas)
    : Distancias(distancias),
      Demandas(demandas), cap(k), n(demandas.size())
{
};

int MTVRP::getTiempo()
{
    return tiempoAcumulado;
}

void MTVRP::getRutas()
{
    clock_t compTime = clock();

    vector<int> clientes(n);
    vector<int> rutaAcumulada = {0};
    iota(clientes.begin(), clientes.end(), 1);
    int count = 0;
    while (!clientes.empty())
    {
        vector<int> ruta = {0};
        int capAcumulada = 0;

        while (true)
        {
            auto candidatos = clientes | std::views::filter([&](int cliente)
            { return visitados.find(cliente) == visitados.end() && capAcumulada + Demandas[cliente - 1] <= cap; });

            int latenciaMin = INT_MAX;
            int nextCliente = -1;

            for (auto cliente : candidatos)
            {
                int latencia = latenciaDeRuta(ruta, cliente);

                if (latencia < latenciaMin)
                {
                    latenciaMin = latencia;
                    nextCliente = cliente;
                }
            }

            if (nextCliente == -1)
                break;

            rutaAcumulada.push_back(nextCliente);
            ruta.push_back(nextCliente);
            capAcumulada += Demandas[nextCliente - 1];
            visitados.insert(nextCliente);
            clientes.erase(remove(clientes.begin(), clientes.end(), nextCliente), clientes.end());

            calcLatencia(rutaAcumulada, tiempoAcumulado);
        }
        ruta.push_back(0);
        rutaAcumulada.push_back(0);
        if (!clientes.empty())
        {
            calcLatencia(rutaAcumulada, tiempoAcumulado);
        }
        count++;
    }
    compTime = clock() - compTime;
    int tiempoTotal = this->getTiempo();
    cout << "Numero de viajes: " << count << endl;
    cout << endl;
    cout << "Ruta Completa: ";
    for_each(rutaAcumulada.begin(), rutaAcumulada.end(), printV);
    cout << endl;
    cout << fixed << setprecision(6);
    cout << endl;
    cout << "Tiempo computacional: " << (float)compTime / CLOCKS_PER_SEC << " Segs" << endl;
    cout << "Tiempo Total de Espera: " << tiempoTotal << endl;
    cout << endl;
    cout << endl;
    return;
}

void MTVRP::calcLatencia(vector<int> &ruta, int &tiempoAcumulado)
{
    for (size_t j = 1; j < ruta.size(); ++j)
    {
        tiempoAcumulado += Distancias[ruta[j - 1]][ruta[j]];
    }
};

int MTVRP::latenciaDeRuta(vector<int> &ruta, int nuevoCliente)
{
    int tiempo = 0;
    int tiempoTotal = 0;

    for (size_t j = 1; j < ruta.size(); ++j)
    {
        tiempo += Distancias[ruta[j - 1]][ruta[j]];
    }

    tiempo += Distancias[ruta.back()][nuevoCliente];
    tiempoTotal += tiempo;

    return tiempoTotal;
};
