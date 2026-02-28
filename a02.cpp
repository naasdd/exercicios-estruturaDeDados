#include <iostream>

using namespace std;

int main()
{
    int value;
    cout << "\nDigite um número inteiro: ";
    cin >> value;

    for (int i = 1; i <= 10; i++)
    {
        int resultado = value * i;
        if (resultado % 3 == 0)
        {
            cout << value << " x " << i << " = " << resultado << endl;
        }
    }

    return 0;
}