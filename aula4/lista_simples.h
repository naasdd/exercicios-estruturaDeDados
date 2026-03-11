#ifndef LISTA_SIMPLES_H
#define LISTA_SIMPLES_H

struct No
{
    int valor;
    No *proximo;
};

struct ListaSimples
{
    No *inicio;
};

ListaSimples *criarListaSimples();

void adicionarInicioDaListaSimples(ListaSimples *listaSimples, int valor);

void imprimirListaSimples(ListaSimples *listaSimples);

// Fazer:   1. Deletar ao fim da lista
//          2. Adicionar ao fim da lista

void adicionarFimDaListaSimples(ListaSimples *lista, int valor);
void deletarFimDaListaSimples(ListaSimples *lista);

#endif