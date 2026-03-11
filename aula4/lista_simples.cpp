#include <iostream>
#include "lista_simples.h"

using namespace std;

No *_criarNo(int valor)
{
    No *no = (No *)calloc(1, sizeof(No));

    no->valor = valor;
    no->proximo = NULL;
    
    return no;
}

ListaSimples *criarListaSimples()
{
    ListaSimples *lista = (ListaSimples *)calloc(1, sizeof(ListaSimples));
    lista->inicio = NULL;

    return lista;
}

void adicionarInicioDaListaSimples(ListaSimples *listaSimples, int valor)
{
    No *no = _criarNo(valor);

    no->proximo = listaSimples->inicio;
    listaSimples->inicio = no;
}

void imprimirListaSimples(ListaSimples *listaSimples)
{
    No *no = listaSimples->inicio;

    while (no != NULL)
    {
        cout << no->valor << " ";
        no = no->proximo;
    }
    cout << endl;
}

// Fazer:   1. Deletar ao fim da lista
//          2. Adicionar ao fim da lista

void adicionarFimDaListaSimples(ListaSimples *lista, int valor)
{
    No *novoNo = _criarNo(valor);
    
    if (lista->inicio == NULL)
    {
        lista->inicio = novoNo;
        return;
    }
    
    No *atual = lista->inicio;
    while (atual->proximo != NULL)
    {
        atual = atual->proximo;
    }
    
    atual->proximo = novoNo;
}

void deletarFimDaListaSimples(ListaSimples *lista)
{
    if (lista->inicio == NULL)
    {
        return;
    }
    
    if (lista->inicio->proximo == NULL)
    {
        free(lista->inicio);
        lista->inicio = NULL;
        return;
    }
    
    No *atual = lista->inicio;
    while (atual->proximo->proximo != NULL)
    {
        atual = atual->proximo;
    }
    
    free(atual->proximo);
    atual->proximo = NULL;
}
