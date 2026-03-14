#include <iostream>
#include <cstdlib>
#include "g3.h"

using namespace std;

void inserir_Inicio(ListaControle *lista, int valor)
{

    No *novoValor = new No();
    novoValor->valor = valor;

    if (lista->head == NULL)
    {
        lista->head = novoValor;
        lista->tail = novoValor;
        return;
    }

    lista->head->prev = novoValor;
    novoValor->next = lista->head;
    lista->head = novoValor;
}

void inserir_Fim(ListaControle *lista, int valor)
{
    No *novoValor = new No();
    novoValor->valor = valor;

    if (lista->tail == NULL)
    {
        lista->head = novoValor;
        lista->tail = novoValor;
        return;
    }

    No *atual = lista->tail;

    novoValor->prev = atual;

    atual->next = novoValor;
    lista->tail = novoValor;
}

void exibir_Direto(ListaControle *lista)
{
    No *atual = lista->head;
    if (atual == NULL)
        return;

    while (atual != NULL)
    {
        cout << atual->valor << ", ";
        atual = atual->next;
    }
}

void exibir_Reverso(ListaControle *lista)
{
    No *atual = lista->tail;
    if (atual == NULL)
        return;

    while (atual != NULL)
    {
        cout << atual->valor << ", ";
        atual = atual->prev;
    }
}

void destruir(ListaControle *lista)
{
    No *atual = lista->head;
    while (atual != NULL)
    {
        No *proximo = atual->next;
        free(atual);
        atual = proximo;
    }
    lista->head = NULL;
    lista->tail = NULL;
}
