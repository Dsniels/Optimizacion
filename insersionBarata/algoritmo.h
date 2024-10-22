#ifndef ALGORITMOTSP
#define ALGORITMOTSP
#include <iostream>
#include <vector>

using namespace std;

class TSP {
    vector<vector<double>> matrix;
    vector<int> subTour;
    vector<int> solucionOptima;
    int CostoMin=INT32_MAX;


public:
    TSP(vector<vector<double>>& m);
    void solucionInsercionMasBarata();
    void solucionInsersionMasCercana();
private:
    int delta(int &i, int &j,int &m);
    int nodoMasCercano(int& nodo);
    int arcoMasBarato(int &j, int &costoFinal);
    void printTour(vector<int>&array);
};

#endif