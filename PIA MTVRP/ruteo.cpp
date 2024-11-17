#include "ruteo.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <numeric>
#include <climits>

MTVRP::MTVRP(vector<vector<double>> &distancias, int k, int nb_trips, int len, vector<int> &demandas)
    : Distancias(distancias), Demandas(demandas), cap(k), n(len), trips(nb_trips) {};

MTVRP::getTiempo()
{
    return tiempoEspera;
}

vector<vector<int>> MTVRP::getRutas()
{
    vector<vector<int>> rutas;
    vector<int> clientes(n);
    iota(clientes.begin(), clientes.end(), 1);
    int tiempoAcumulado = 0;
    int latenciaPrimeraRuta = 0;

    for (int trip = 0; trip < trips && !clientes.empty(); trip++)
    {
        vector<int> ruta = {0};
        int capAcumulada = 0;

        while (true)
        {
            int prevCliente = ruta.back();
            int latenciaMin = INT_MAX;
            int nextCliente = -1;

            for (int cliente : clientes)
            {
                if (visitados.find(cliente) != visitados.end())
                    continue;

                int demandaCliente = Demandas[cliente - 1];
                if (capAcumulada + demandaCliente > cap)
                    continue;

                int latencia = latenciaDeRuta(ruta, cliente);
                if (latencia < latenciaMin)
                {
                    latenciaMin = latencia;
                    nextCliente = cliente;
                }
            }

            if (nextCliente == -1)
                break;

            ruta.push_back(nextCliente);
            capAcumulada += Demandas[nextCliente - 1];
            visitados.insert(nextCliente);
            clientes.erase(remove(clientes.begin(), clientes.end(), nextCliente), clientes.end());
            for (size_t i = 1; i < ruta.size(); ++i)
            {
                int prev = ruta[i - 1];
                int cur = ruta[i];
                tiempoAcumulado += Distancias[prev][cur];
                cout << prev << cur << endl;
            }
            tiempoEspera += calcLatencia(ruta);
        }
        tiempoEspera += Distancias[ruta.back()][0];
        ruta.push_back(0);
        rutas.push_back(ruta);
    }

    return rutas;
}

MTVRP::calcLatencia(vector<int> &ruta)

{
    int tiempoTotal = 0;
    int tiempo = 0;
    for (int i = 1; i < ruta.size(); ++i)
    {
        int prev = ruta[i - 1];
        int cur = ruta[i];
        tiempo += Distancias[prev][cur];
    }

    return tiempo;
};

MTVRP::latenciaDeRuta(vector<int> &ruta, int nuevoCliente)
{
    int tiempo = calcLatencia(ruta);
    int tiempoTotal = 0;

    tiempo += Distancias[ruta.back()][nuevoCliente];
    tiempoTotal += tiempo;

    return tiempoTotal;
};
