#ifndef ALGORITMOIMB
#define ALGORITMOIMB
#include <iostream>
#include <vector>

using namespace std;

class IMB {
    vector<vector<double>> matrix;
    vector<int> subTour;
    vector<int> solucionOptima;
    int CostoMin=INT32_MAX;


public:
    IMB(vector<vector<double>>& m);
    void solucion();

private:
    int delta(int &i, int &j,int &m);
    int nodoMasCercano(int& nodo);
    int arcoMasBarato(int &j, int &costoFinal);
    void printTour(vector<int>&array);
};

#endif