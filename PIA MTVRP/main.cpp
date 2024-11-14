#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class MTVRP
{
private:
    int cap;
    int n;
    int trips;
    int tiempoEspera = 0;
    vector<vector<int>> Distancias;
    vector<int> Demandas;

public:
    MTVRP(vector<vector<int>> &distancias, int k, int nb_trips, int len, vector<int> &demandas)
        : Distancias(distancias), Demandas(demandas), cap(k), n(len), trips(nb_trips) {};

    void printRuta(vector<int> &arr)
    {
        for (auto i : arr)
        {
            cout << i << " ";
        }
        return;
    }

    int getTiempo()
    {
        return tiempoEspera;
    }

    vector<vector<int>> getRutas()
    {
        vector<vector<int>> rutas;
        vector<int> clientes(n);

        iota(clientes.begin(), clientes.end(), 1);

        for (int trip = 0; trip < trips && !clientes.empty(); trip++)
        {
            vector<int> ruta = {0};
            int carga_actual = 0;

            for (auto it = clientes.begin(); it != clientes.end();)
            {
                int cliente = *it;
                int demanda_cliente = Demandas[cliente - 1];

                if (carga_actual + demanda_cliente <= cap)
                {
                    ruta.push_back(cliente);
                    carga_actual += demanda_cliente;
                    it = clientes.erase(it);
                }
                else
                {
                    ++it;
                }
            }
            ruta.push_back(0);
            rutas.push_back(ruta);
            tiempoEspera += calcTiempos(ruta);
        }

        return rutas;
    };

private:
    calcTiempos(vector<int> &ruta)
    {
        int tiempo = 0;
        int tiempoTotal = 0;
        for (int i = 1; i < ruta.size(); ++i)
        {
            int prev = ruta[i - 1];
            int cur = ruta[i];
            tiempo += Distancias[prev][cur];
            tiempoTotal += tiempo;
        }

        return tiempoTotal;
    };
};

int main()
{
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

    vector<vector<int>> rutas = mtvrp.getRutas();
    int tiempoTotal = mtvrp.getTiempo();
    for (auto ruta : rutas)
    {
        mtvrp.printRuta(ruta);
        cout << endl;
    }

    cout << "Tiempo Total: " << tiempoTotal;

    cin.get();

    return 0;
}