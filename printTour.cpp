#include "printTour.h"
#include <vector>
#include <iostream>

using namespace std;


void PrintTour(std::vector<int> tour) {
    cout<<"Tour: ";
    for (int node : tour) {
        cout << node + 1 << " ";
    }
    

}