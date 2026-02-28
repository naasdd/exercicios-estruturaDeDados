#include <iostream>

using namespace std;

bool verificaMultiplo(int value)
    {
        if(value % 3 == 0) return 1;
        return 0;
    }

string exibeTabuada(int value, int i){
    int resultado = value * i;

    if(verificaMultiplo(value)){
        
    }

    cout << value << " x " << i << " = " << resultado << endl;
    i++;


    return "s";
}

int main()
{
    int value;
    cout << "\nDigite um número inteiro: ";
    cin >> value;

    int i = 1;
    exibeTabuada(value, i);


    return 0;
}