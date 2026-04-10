#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

#define TAM_HASH 100003

int comparar(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

bool algoritmo_a(int *vetor, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (vetor[i] == vetor[j]) return true;
    return false;
}

bool algoritmo_b(int *vetor, int n) {
    int *copia = new int[n];
    memcpy(copia, vetor, n * sizeof(int));
    qsort(copia, n, sizeof(int), comparar);
    for (int i = 0; i < n - 1; i++) {
        if (copia[i] == copia[i + 1]) {
            delete[] copia;
            return true;
        }
    }
    delete[] copia;
    return false;
}

bool algoritmo_c(int *vetor, int n) {
    int *tabela = new int[TAM_HASH]();
    for (int i = 0; i < n; i++) {
        int h = abs(vetor[i]) % TAM_HASH;
        while (tabela[h] != 0) {
            if (tabela[h] == vetor[i] + 1) {
                delete[] tabela;
                return true;
            }
            h = (h + 1) % TAM_HASH;
        }
        tabela[h] = vetor[i] + 1;
    }
    delete[] tabela;
    return false;
}

double medir(bool (*func)(int *, int), int *vetor, int n) {
    clock_t inicio = clock();
    func(vetor, n);
    return (double)(clock() - inicio) / CLOCKS_PER_SEC * 1000.0;
}

int main() {
    srand(42);
    int tamanhos[] = {5000, 20000, 50000};

    cout << "N          A (ms)     B (ms)     C (ms)" << endl;

    for (int t = 0; t < 3; t++) {
        int n = tamanhos[t];

        int *vetor = new int[n];
        for (int i = 0; i < n; i++) vetor[i] = i;

        for (int i = n - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            int tmp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = tmp;
        }

        cout << n << "       "
             << medir(algoritmo_a, vetor, n) << "       "
             << medir(algoritmo_b, vetor, n) << "       "
             << medir(algoritmo_c, vetor, n) << endl;

        delete[] vetor;
    }

    return 0;
}