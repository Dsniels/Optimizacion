#include <iostream>
#include <vector>
#include <string>

using namespace std;

class RandomNums
{
private:
    int x0, x1, n, i;
    float r;
    vector<string> num, centro;

public:
    RandomNums(int x0, int x1) : x0(x0), x1(x1)
    {
        num.resize(100);
        centro.resize(100);
    };

    void generarNums()
    {
        for (int i = 0; i < 100; i++)
        {
            n = x0 * x1;
            string numStr = to_string(n);

            while (numStr.length() < 8)
            {
                numStr = "0" + numStr;
            }

            string centroStr = numStr.substr(2, 4);
            x1 = stoi(centroStr);

            num[i] = numStr;
            centro[i] = centroStr;

            r = x1 / 10000.0;
            cout << r << " ";

            x0 = x1;
        }
    }
};

int main()
{

    int x0, x1;
    cout << "Valor de X0:";
    cin >> x0;
    cout << "Valor de X1:";
    cin >> x1;

    RandomNums nums(x0, x1);

    nums.generarNums();

    cin.get();
    cin.get();
}