#ifndef ALGORITMOIMB
#define ALGORITMOIMB

#include <vector>

using namespace std;

class IMB {
    vector<vector<double>> matrix;
    vector<int> subTour;

public:
    IMB(vector<vector<double>>& m);
    void solucion();

private:
    int delta(int i, int j,int m);
    int nodoMasCercano(int nodo);
    int arcoMasBarato(int &i, int &j, int &costoFinal);
    void printTour();
};

#endif