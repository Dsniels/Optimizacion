#include <iostream>
#include <vector>
#include "ruteo.h"
#include "matrices.h"
#include <iomanip>

using namespace std;

void ejecutar(const string& name, MTVRP& mtvrp)
{
    cout << "instancia " << name << endl << endl;
    mtvrp.getRutas();
}

int main()
{
    vector<pair<string, MTVRP>> instancias = {
        {"s0_01", MTVRP(s0_01_Distancias, 120, s0_01_Demandas)},
        {"s0_05", MTVRP(s0_05_Distancias, 120, s0_05_Demandas)},
        {"s0_03", MTVRP(s0_03_Distancias, 120, s0_03_Demandas)},
        {"s0_04", MTVRP(s0_04_Distancias, 120, s0_04_Demandas)},
        {"VRPNC1", MTVRP(VRPNC1_Distancias, 160, VRPNC1_Demandas)},
        {"VRPNC2", MTVRP(VRPNC2_Distancias, 140, VRPNC2_Demandas)},
        {"VRPNC3", MTVRP(VRPNC3_Distancias, 200, VRPNC3_Demandas)},
        {"VRPNC4", MTVRP(VRPNC4_Distancias, 200, VRPNC4_Demandas)},
        {"VRPNC5", MTVRP(VRPNC5_Distancias, 200, VRPNC5_Demandas)},
        {"VRPNC11", MTVRP(VRPNC11_Distancias, 200, VRPNC11_Demandas)},
        {"VRPNC12", MTVRP(VRPNC12_Distancias, 200, VRPNC12_Demandas)},
    };

    for (auto& [name, instancia] : instancias)
    {
        ejecutar(name, instancia);
    }

    return 0;
}