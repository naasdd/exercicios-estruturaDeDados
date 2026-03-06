#include <iostream>

using namespace std;

int main()
{
    cout << "\n--- Inicio T2-ListasLineares - Questao 1 ---\n\n";
    int tamanhoVetor = 5;

    int *vetor = (int *)malloc(tamanhoVetor * sizeof(int));
    for (int i = 0; i < tamanhoVetor; i++)
    {
        int temp = 0;
        cout << "> Insira o valor da posicao " << i << ": ";
        cin >> temp;
        *(vetor + i) = temp;
    }
    cout << "\nVariavel    |   Valor   |  Endereço" << endl;

    for (int i = 0; i < tamanhoVetor; i++)
    {
        cout << "vetor[" << i << "]    |   ";
        cout << *(vetor + i) << "   |  ";
        cout << (vetor + i) << endl;
    }

    return 0;
}