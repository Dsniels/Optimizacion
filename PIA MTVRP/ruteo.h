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
    int tiempoAcumulado = 0;
    unordered_set<int> visitados;
    vector<vector<double>> Distancias;
    vector<int> Demandas;

    void calcLatencia(vector<int> &ruta, int &acumulado);
    int latenciaDeRuta(vector<int> &ruta, int clienteNuevo);

public:
    MTVRP(vector<vector<double>> &distancias, int k, int nb_trips, int numClientes, vector<int> &demandas);
    int getTiempo();
    vector<vector<int>> getRutas();
};
#endif