#include <iostream>
#include <vector>
#include <limits>
#include <algorithm> // Incluir la cabecera para std::find

using namespace std;

// Encuentra el nodo más cercano a un nodo dado que no esté en el sub-tour
int nodo_mas_cercano(int nodo, const vector<vector<int>> &distancias, const vector<int> &subtour)
{
    int minDist = numeric_limits<int>::max();
    int nodoMasCercano = -1;
    for (int i = 0; i < distancias.size(); i++)
    {
        if (find(subtour.begin(), subtour.end(), i) == subtour.end())
        {
            int dist = distancias[nodo][i];
            if (dist < minDist)
            {
                minDist = dist;
                nodoMasCercano = i;
            }
        }
    }
    return nodoMasCercano;
}

// Encuentra el arco [i,j] con el menor incremento de longitud al insertar un nodo k
int arco_mas_barato(int &mejorI, int &mejorJ, const vector<vector<int>> &distancias, const vector<int> &subtour)
{   
    int minIncremento = numeric_limits<int>::max();
    int mejorNodo = -1;
    for (int k = 0; k < distancias.size(); k++)
    {
        if (std::find(subtour.begin(), subtour.end(), k) == subtour.end())
        {
            for (int i = 0; i < subtour.size() - 1; i++)
            { // Revisar pares de nodos consecutivos en el subtour
                int j = (i + 1) % subtour.size();
                
                // Cálculo del incremento (delta)
                int incremento = distancias[subtour[i]][k] + distancias[k][subtour[j]] - distancias[subtour[i]][subtour[j]];
                
                // Imprimir delta (incremento)
                cout << "Delta (incremento) al insertar nodo " << k+1 << " entre " << subtour[i]+1 << " y " << subtour[j]+1 << ": " << incremento << endl;

                if (incremento < minIncremento)
                {
                    minIncremento = incremento;
                    mejorI = subtour[i];
                    mejorJ = subtour[j];
                    mejorNodo = k;
                }
            }
        }
    }
    return mejorNodo;
}


int main()
{
    // Matriz de distancias dada
    vector<vector<int>> distancias = {
        {0, 8, 3, 7, 10},
        {8, 0, 5, 9, 4},
        {3, 5, 0, 6, 7},
        {7, 9, 6, 0, 9},
        {10, 4, 7, 9, 0}};

    for (int i = 0; i < 5; i++) // Recorremos de 0 a 4 (5 nodos)
    {
        vector<int> subtour;

        // Paso 1: Escoge un nodo inicial arbitrario
        int nodoInicial = i;
        subtour.push_back(nodoInicial);

        // Paso 2: Encuentra el nodo más cercano al nodo inicial
        int nodoCercano = nodo_mas_cercano(nodoInicial, distancias, subtour);
        subtour.push_back(nodoCercano);
        subtour.push_back(nodoInicial); // Completa el subtour inicial i-j-i

        // Paso 3-5: Inserción de nodos en el subtour
        while (subtour.size() < distancias.size() + 1)
        { // +1 porque subtour tiene el nodo inicial repetido al final
            int mejorI, mejorJ;
            int nodoAInsertar = arco_mas_barato(mejorI, mejorJ, distancias, subtour);

            // Solo insertar nodos entre el nodo inicial y el nodo final
            auto it = find(subtour.begin() + 1, subtour.end() - 1, mejorJ);
            if (it != subtour.end())
            {
                subtour.insert(it, nodoAInsertar);
            }
        }
        reverse(subtour.begin(), subtour.end());
        // Imprimir el recorrido TSP
        cout << "Recorrido TSP comenzando por " << (nodoInicial + 1) << ": ";
        for (int nodo : subtour)
        {
            cout << (nodo + 1) << " ";
        }
        cout << endl;
    }

    return 0;
}
