#include <iostream>

using namespace std;

struct ListaDinamica
{
    int *dados;
    int capacidade;
    int quantidade;
};

void inicializar(ListaDinamica *l, int capacidadeInicial)
{
    l->capacidade = capacidadeInicial;
    l->quantidade = 0;
    l->dados = new int[l->capacidade];
}

bool inserir(ListaDinamica *l, int valor)
{
    if (l->quantidade >= l->capacidade)
    {
        l->capacidade *= 2;
        int *novo = new int[l->capacidade];
        for (int i = 0; i < l->quantidade; i++)
        {
            novo[i] = l->dados[i];
        }
        delete[] l->dados;
        l->dados = novo;
        cout << "Lista cheia, capacidade dobrada para: " << l->capacidade << endl;
    }
    l->dados[l->quantidade] = valor;
    l->quantidade++;
    return true;
}

void atualizar(ListaDinamica *l, int indice, int novoValor)
{
    if (indice < 0 || indice >= l->quantidade)
    {
        cout << "Indice invalido." << endl;
        return;
    }
    l->dados[indice] = novoValor;
}

int main()
{
    ListaDinamica lista;
    inicializar(&lista, 3);

    inserir(&lista, 10);
    inserir(&lista, 20);
    inserir(&lista, 30);
    inserir(&lista, 40); // aqui dobra a capacidade

    atualizar(&lista, 1, 99);
    cout << "Valor no indice 1 apos atualizar: " << lista.dados[1] << endl;

    atualizar(&lista, 99, 0); // indice invalido

    delete[] lista.dados;
    return 0;
}