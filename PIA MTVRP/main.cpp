#include <iostream>
#include <vector>
#include <algorithm>
#include "ruteo.h"
#include "matrices.h"
#include <iomanip>
using namespace std;

int main()
{
    auto printV = [](int &n){cout<<n<<" ";};
    
    MTVRP mtvrp(matriz10, 120, 2, 10, demandaClientes);

    clock_t compTime = clock();
    vector<int> service_time(10, 0);

    vector<vector<int>> rutas = mtvrp.getRutas();
    int tiempoTotal = mtvrp.getTiempo();
    compTime = clock() - compTime;


    for (auto ruta : rutas)
    {
        for_each(ruta.begin(), ruta.end(), printV);
        cout<<endl;
    }
    cout<<fixed << setprecision(6);
    cout<< "Tiempo computacional: "<<(float)compTime/CLOCKS_PER_SEC<<" Segs"<<endl;
    cout << "Tiempo Total de Espera: " << tiempoTotal << endl;
    return 0;
}
