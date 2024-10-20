#include <iostream>
#include <vector>
#include "algoritmo.h"
#include "matrices.h"
using namespace std;

int main()
{


    vector<vector<vector<double>>> matrices = {matriz76, matriz52, matriz10};

    for (auto& matriz : matrices) {
        IMB imb(matriz);
        imb.solucion();
    }

    cin.get();

    return 0;
}
