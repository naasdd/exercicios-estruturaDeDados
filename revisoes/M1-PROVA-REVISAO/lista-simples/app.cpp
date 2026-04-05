#include <iostream>

using namespace std;

struct No
{
    int valor;
    No *prox;
};

struct listaSimples
{
    No *inicio;
};

void inserir(listaSimples *lista, int valor)
{
    No *novoValor = new No();
    novoValor->valor = valor;

    if (lista->inicio == NULL)
    {
        lista->inicio = novoValor;
        return;
    }

    No *atual = lista->inicio;
    while (atual->prox != NULL)
    {
        atual = atual->prox;
    }

    atual->prox = novoValor;
}

void exibir(listaSimples *lista)
{
    No *atual = lista->inicio;
    while (atual != NULL)
    {
        cout << "\nValor: " << atual->valor << endl;
        atual = atual->prox;
    }
}

void removerUltimo(listaSimples *lista)
{
    if (lista->inicio == NULL) return;

    No *atual = lista->inicio;
    while (atual->prox->prox != NULL)
    {
        atual = atual->prox;
    }

    No* temp = atual;
    atual = atual->prox;
    free(atual);
    temp->prox = NULL;
}

int main()
{
    cout << "-- Inicio Lista Simples --" << endl;

    listaSimples *lista = new listaSimples();

    inserir(lista, 30);
    inserir(lista, 50);
    inserir(lista, 60);

    exibir(lista);
    
    removerUltimo(lista);

    exibir(lista);


    
    return 0;
}