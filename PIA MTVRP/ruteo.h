#pragma once
#ifndef RUTEO
#define RUTEO
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class MTVRP
{
private:
    int cap = 0;
    int n;
    int tiempoAcumulado = 0;
    unordered_set<int> visitados;
    vector<vector<double>> Distancias;
    vector<int> Demandas;

    int getTiempo();
    void calcLatencia(vector<int> &ruta, int &acumulado);
    int latenciaDeRuta(vector<int> &ruta, int clienteNuevo);

public:
    MTVRP(vector<vector<double>> &distancias, int k, vector<int> &demandas);
    void getRutas();
};
#endif