#include <iostream>
#include <vector>
#include "algoritmo.h"
#include "matrices.h"
using namespace std;

int main()
{


    vector<vector<vector<double>>> matrices = {matriz10,matriz52,matriz76};

    for (auto& matriz : matrices) {
        TSP algoritmoIMB(matriz);
        algoritmoIMB.solucionInsercionMasBarata();
    }

    cin.get();

    return 0;
}
