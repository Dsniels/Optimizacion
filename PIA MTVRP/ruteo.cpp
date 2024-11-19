#include "ruteo.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <numeric>
#include <climits>
#include <ranges>

auto printV = [](int &n)
{ cout << n << " "; };

MTVRP::MTVRP(vector<vector<double>> &distancias, int k, int nb_trips, int len, vector<int> &demandas)
    : Distancias(distancias),
      Demandas(demandas), cap(k), n(len), trips(nb_trips) {};

MTVRP::getTiempo()
{
    return tiempoAcumulado;
}

vector<vector<int>> MTVRP::getRutas()
{
    vector<vector<int>> rutas;
    vector<int> clientes(n);
    iota(clientes.begin(), clientes.end(), 1);

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
                cout << cliente << endl;
                int latencia = latenciaDeRuta(ruta, cliente);

                if (latencia < latenciaMin)
                {
                    latenciaMin = latencia;
                    nextCliente = cliente;
                    cout << "nextCliente " << nextCliente << endl;
                }
            }

            if (nextCliente == -1)
                break;
            ruta.push_back(nextCliente);
            capAcumulada += Demandas[nextCliente - 1];
            visitados.insert(nextCliente);
            clientes.erase(remove(clientes.begin(), clientes.end(), nextCliente), clientes.end());
            calcLatencia(ruta, tiempoAcumulado);
            // cout << "Capacidad Acumulada: " << capAcumulada << endl;
        }
        tiempoAcumulado += Distancias[ruta.back()][0];
        ruta.push_back(0);

        // cout << "Ruta final: ";
        // for_each(ruta.begin(), ruta.end(), printV);
        // cout << endl;
        calcLatencia(ruta, tiempoAcumulado);
        // cout << "Tiempo espera ruta " << tiempoAcumulado << endl;
        rutas.push_back(ruta);
    }

    return rutas;
}

void MTVRP::calcLatencia(vector<int> &ruta, int &tiempoAcumulado)
{
    // cout << "Tiempo espera incio for: " << tiempoAcumulado << endl;

    for (size_t j = 1; j < ruta.size(); ++j)
    {
        // cout << "Clientes en ruta: ";
        // for_each(ruta.begin(), ruta.end(), printV);
        // cout << endl;
        // cout << "se suman al acumulado: " << Distancias[ruta[j - 1]][ruta[j]] << endl;

        tiempoAcumulado += Distancias[ruta[j - 1]][ruta[j]];

        // cout << "Tiempo espera sumado: " << tiempoAcumulado << endl;
    }
};

MTVRP::latenciaDeRuta(vector<int> &ruta, int nuevoCliente)
{
    int tiempo = 0;
    int tiempoTotal = 0;
    cout << "latencia print " << nuevoCliente << endl;

    for (size_t j = 1; j < ruta.size(); ++j)
    {
        cout << "Tama;o riuta" << ruta.size() << endl;
        tiempo += Distancias[ruta[j - 1]][ruta[j]];
    }

    tiempo += Distancias[ruta.back()][nuevoCliente];
    tiempoTotal += tiempo;

    return tiempoTotal;
};
