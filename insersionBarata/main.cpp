#include <iostream>
#include <vector>
#include "algoritmo.h"
#include "matrices.h"
using namespace std;


int main()
{

    IMB imb(matriz76);
    IMB imb2(matriz52);
    IMB imb3(matriz10);
    imb.solucion();
    imb2.solucion();
    imb3.solucion();
    

    cin.get();

    return 0;
}
