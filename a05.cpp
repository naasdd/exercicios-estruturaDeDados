#include <iostream>

using namespace std;

int main()
{
    int valores[5];
    cout << "Digite 5 numeros inteiros: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> valores[i];

    }

    int maior = 0;
    int menor = 9999999;

    for(int i = 0; i < 5; i++){
        if(valores[i] > maior) maior = valores[i];
        if(valores[i] < menor) menor = valores[i];

    }

    cout << "O maior número é: " << maior << endl;
    cout << "O menor número é: " << menor << endl;

    return 0;
}