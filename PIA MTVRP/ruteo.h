#ifndef RUTEO
#define RUTEO
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class MTVRP
{
private:
    int cap;
    int n;
    int trips;
    int tiempoEspera = 0;
    unordered_set<int> visitados;
    vector<vector<double>> Distancias;
    vector<int> Demandas;

    int calcLatencia(vector<int> &ruta);
    int latenciaDeRuta(vector<int> &ruta, int clienteNuevo);

public:
    MTVRP(vector<vector<double>>&distancias, int k, int nb_trips, int numClientes, vector<int>& demandas);
    int getTiempo();
    vector<vector<int>> getRutas();
};
#endif