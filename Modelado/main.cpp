#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

class RandomNums
{
private:
    vector<string> num, centro;

public:
    RandomNums()
    {
        num.resize(10);
        centro.resize(10);
    };
    int extraerCentros(int n, int i, int len)
    {
        string nums = to_string(n);
        while (nums.length() < 8)
        {
            nums = "0" + nums;
        }

        string cntr = nums.substr(2, len);
        num[i] = nums;
        centro[i] = cntr;

        return stoi(cntr);
    }
    void productosMedios(int cant)
    {
        float r;
        int n;
        int x0, x1;
        cout << "Valor de X0:";
        cin >> x0;
        cout << "Valor de X1:";
        cin >> x1;

        for (int i = 0; i < cant; i++)
        {
            n = x0 * x1;

            x1 = extraerCentros(n, i, 4);

            r = x1 / 10000.0;
            cout << r << " " << endl;

            x0 = x1;
        }
    }
    void cuadradoMedios(int x0, int cant)
    {
        int y, x1, n;
        float r;
        for (int i = 0; i < cant; i++)
        {
            n = pow(x0, 2);
            x1 = extraerCentros(n, i, 4);
            r = x1 / 10000.0;
            cout << r << ' ';
            x0 = x1;
        }
    }
    void multiplicadorConstante(int x, int a, int cant)
    {
        float r;
        int X1, y;
        for (int i = 0; i < cant; i++)
        {
            y = a * x;
            X1 = extraerCentros(y, i, 3);
            r = X1 / 10000.0;
            cout << r << " " << endl;
            x = X1;
        }
    }
};

int main()
{

    RandomNums nums;

    nums.productosMedios(100);
     nums.multiplicadorConstante(9803, 6965,100);
    nums.cuadradoMedios(5735, 5);
    cin.get();
    cin.get();
}