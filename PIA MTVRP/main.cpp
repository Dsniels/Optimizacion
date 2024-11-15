#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <numeric>
#include <climits>
using namespace std;

class MTVRP
{
private:
    int cap;
    int n;
    int trips;
    int tiempoEspera = 0;
    unordered_set<int> visitados;
    vector<vector<int>> Distancias;
    vector<int> Demandas;

public:
    MTVRP(vector<vector<int>> &distancias, int k, int nb_trips, int len, vector<int> &demandas)
        : Distancias(distancias), Demandas(demandas), cap(k), n(len), trips(nb_trips) {};

    

    int getTiempo()
    {
        return tiempoEspera;
    }

    vector<vector<int>> getRutas()
    {
        vector<vector<int>> rutas;
        vector<int> clientes(n);
        iota(clientes.begin(), clientes.end(), 1);
        int tiempoAcumulado = 0;
        int latenciaPrimeraRuta =0;

        for (int trip = 0; trip < trips && !clientes.empty(); trip++)
        {
            vector<int> ruta = {0};
            int capAcumulada = 0;

            while (true)
            {
                int prevCliente = ruta.back();
                int latenciaMin = INT_MAX;
                int nextCliente = -1;

                for (int cliente : clientes)
                {
                    if (visitados.find(cliente) != visitados.end())
                        continue;

                    int demandaCliente = Demandas[cliente - 1];
                    if (capAcumulada + demandaCliente > cap)
                        continue;

                    int latencia = latenciaDeRuta(ruta, cliente);
                    if (latencia < latenciaMin)
                    {
                        latenciaMin = latencia;
                        nextCliente = cliente;
                    }
                }

                if (nextCliente == -1)
                    break;

                ruta.push_back(nextCliente);
                capAcumulada += Demandas[nextCliente - 1];
                visitados.insert(nextCliente);
                clientes.erase(remove(clientes.begin(), clientes.end(), nextCliente), clientes.end());
                // for (size_t i = 1; i < ruta.size(); ++i)
                // {
                //     int prev = ruta[i - 1];
                //     int cur = ruta[i];
                //     tiempoAcumulado += Distancias[prev][cur];
                //     cout<<prev<<cur<<endl;
                // }
                // //tiempoEspera += calcLatencia(ruta);

                // // tiempoEspera += tiempoAcumulado;
                // if (trip == 0)
                // {
                //     latenciaPrimeraRuta += tiempoAcumulado;
                // }
                // else
                // {
                //     tiempoAcumulado += latenciaPrimeraRuta;
                //     tiempoEspera += latenciaPrimeraRuta; 
                // }

                // cout<<"tiempo espera: "<<<<endl;
            }
            tiempoEspera += Distancias[ruta.back()][0];
            cout<<endl<<tiempoAcumulado<<endl;
            ruta.push_back(0);
            rutas.push_back(ruta);
        }

        return rutas;
    }

private:
    int calcLatencia(vector<int> &ruta)
    {
        int tiempoTotal = 0;
        int tiempo = 0;
        for (int i = 1; i < ruta.size(); ++i)
        {
            int prev = ruta[i - 1];
            int cur = ruta[i];
            tiempo += Distancias[prev][cur];
        }

        return tiempo;
    }

    int latenciaDeRuta(vector<int> &ruta, int nuevoCliente)
    {
        int tiempo = calcLatencia(ruta);
        int tiempoTotal = 0;

        tiempo += Distancias[ruta.back()][nuevoCliente];
        tiempoTotal += tiempo;

        return tiempoTotal;
    }
};

int main()
{
    auto print = [](int &n){cout<<n<<" ";};
    vector<int> client_demands = {10, 20, 30, 10, 20, 10, 20, 30, 30, 30};
    vector<vector<int>> distances = {
        {0, 33, 54, 14, 70, 92, 79, 80, 61, 58, 14},
        {33, 0, 21, 18, 42, 58, 49, 55, 28, 27, 36},
        {54, 21, 0, 39, 37, 38, 29, 40, 7, 8, 57},
        {14, 18, 39, 0, 56, 77, 65, 69, 46, 44, 19},
        {70, 42, 37, 56, 0, 48, 59, 74, 35, 44, 64},
        {92, 58, 38, 77, 48, 0, 26, 42, 30, 35, 94},
        {79, 49, 29, 65, 59, 26, 0, 16, 26, 22, 85},
        {80, 55, 40, 69, 74, 42, 16, 0, 39, 32, 89},
        {61, 28, 7, 46, 35, 30, 26, 39, 0, 9, 63},
        {58, 27, 8, 44, 44, 35, 22, 32, 9, 0, 63},
        {14, 36, 57, 19, 64, 94, 85, 89, 63, 63, 0}};

    MTVRP mtvrp(distances, 120, 2, 10, client_demands);
    clock_t compTime = clock();
    vector<vector<int>> rutas = mtvrp.getRutas();
    int tiempoTotal = mtvrp.getTiempo();
    compTime = clock() - compTime;
    for (auto ruta : rutas)
    {
        for_each(ruta.begin(), ruta.end(), print);
        cout<<endl;
        
    }
    cout<< "Tiempo computacional: "<<(float)compTime/CLOCKS_PER_SEC<<endl;
    cout << "Tiempo Total de Espera: " << tiempoTotal << endl;
    return 0;
}
