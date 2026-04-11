#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Algoritmo A: Força Bruta (Dois laços aninhados)
bool temDuplicadoA(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vetor[i] == vetor[j]) return true;
        }
    }
    return false;
}

// Comparador para o qsort
int comparar(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Algoritmo B: Ordenação + Varredura Linear
bool temDuplicadoB(int vetor[], int n) {
    qsort(vetor, n, sizeof(int), comparar);
    for (int i = 0; i < n - 1; i++) {
        if (vetor[i] == vetor[i + 1]) return true;
    }
    return false;
}

// Algoritmo C: Otimizado (Tabela Hash simples)
bool temDuplicadoC(int vetor[], int n) {
    int maxVal = 0;
    for(int i = 0; i < n; i++) if(vetor[i] > maxVal) maxVal = vetor[i];

    bool* controle = (bool*)calloc(maxVal + 1, sizeof(bool));
    bool duplicado = false;
    for (int i = 0; i < n; i++) {
        if (controle[vetor[i]]) {
            duplicado = true;
            break;
        }
        controle[vetor[i]] = true;
    }
    free(controle);
    return duplicado;
}

void rodarTeste(int n) {
    int* v = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) v[i] = rand();

    clock_t t;

    // Teste A
    t = clock();
    temDuplicadoA(v, n);
    double tempoA = (double)(clock() - t) / CLOCKS_PER_SEC;

    // Teste B
    t = clock();
    temDuplicadoB(v, n);
    double tempoB = (double)(clock() - t) / CLOCKS_PER_SEC;

    // Teste C
    t = clock();
    temDuplicadoC(v, n);
    double tempoC = (double)(clock() - t) / CLOCKS_PER_SEC;

    cout << "N=" << n << " | A: " << tempoA << "s | B: " << tempoB << "s | C: " << tempoC << "s" << endl;

    free(v);
}

int main() {
    srand(time(NULL));
    cout << "Iniciando testes de complexidade..." << endl;
    rodarTeste(5000);
    rodarTeste(20000);
    rodarTeste(50000);
    return 0;
}