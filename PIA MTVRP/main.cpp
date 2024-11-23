#include <iostream>
#include "ruteo.h"
#include "matrices.h"
#include <iomanip>


using namespace std;

int main()
{



    MTVRP mtvrp(s0_01_Distancias, 120, s0_01_Demandas);
    MTVRP mtvrp1(s0_05_Distancias, 120, s0_05_Demandas);
    MTVRP mtvrp2(s0_03_Distancias, 120, s0_03_Demandas);
    MTVRP mtvrp3(s0_04_Distancias, 120, s0_04_Demandas);
    MTVRP mtvrp4(VRPNC3_Distancias, 200, VRPNC3_Demandas);
    MTVRP mtvrp5(VRPNC1_Distancias, 160, VRPNC1_Demandas);
    MTVRP mtvrp6(VRPNC2_Distancias, 140, VRPNC2_Demandas);
    MTVRP mtvrp7(VRPNC12_Distancias, 200, VRPNC12_Demandas);
    MTVRP mtvrp8(VRPNC4_Distancias, 200, VRPNC4_Demandas);
    // MTVRP mtvrp9(VRPNC5_Distancias, 200, VRPNC5_Demandas);  
    // MTVRP mtvrp10(VRPNC11_Distancias, 200, VRPNC11_Demandas);
    
    cout << "Instancia s0_01 " << endl;
    cout<<endl;
    mtvrp.getRutas();
    
    cout << "Instancia s0_05 " << endl;
    cout<<endl;
    mtvrp1.getRutas();
    
    cout << "Instancia s0_03 " << endl;
    cout<<endl;
    mtvrp2.getRutas();
    
    cout << "Instancia s0_04 " << endl;
    cout<<endl;
    mtvrp3.getRutas();
    
    cout << "Instancia VRPNC3 " << endl;
    cout<<endl;
    mtvrp4.getRutas();
    
    cout << "Instancia VRPNC1 " << endl;
    cout<<endl;
    mtvrp5.getRutas();
    
    cout << "Instancia VRPNC2 " << endl;
    cout<<endl;
    mtvrp6.getRutas();
    
    cout << "Instancia VRPNC12 " << endl;
    cout<<endl;
    mtvrp7.getRutas();
    
    cout << "Instancia VRPNC4 " << endl;
    cout<<endl;
    mtvrp8.getRutas();
    
    return 0;
}