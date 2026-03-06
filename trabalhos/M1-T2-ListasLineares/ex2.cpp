#include <iostream>

using namespace std;

void inverter(int *vet, int tam)
{
    int *auxiliar = (int*)malloc(tam * sizeof(int));
    int j = tam - 1;
    for(int i = 0; i < tam; i++){
        *(auxiliar + i) = *(vet + j);
        cout << "Auxiliar + " << i << ": " << *(auxiliar + i) << endl; 
        // cout << "i = " << i << "   |   j = " << j << "\n\n";
        j--;
    }

}

int main()
{
    cout << "\n--- Inicio T2-ListasLineares - Questao 2 ---\n\n";

    int tamanhoVetor = 5;

    // Preenchendo dados no vetor
    int *vetor = (int *)malloc(tamanhoVetor * sizeof(int));
    for (int i = 0; i < tamanhoVetor; i++)
    {
        cout << "\n> Insira o valor da posicao " << i << ": ";
        int temp = i * 2; // Inserindo valores manualmente para agilizar
        *(vetor + i) = temp;
    }
    cout << "\n\n > INVERTENDO VETOR :" << endl;
    inverter(vetor, tamanhoVetor);

    return 0;
}