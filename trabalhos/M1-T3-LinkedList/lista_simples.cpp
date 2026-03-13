#include <iostream>
#include <cstdlib>
#include "lista_simples.h"

using namespace  std;

No *_criarNo(int valor){
    No *no = (No*)calloc(1, sizeof(No));

    no->valor = valor;
    no->proximo = NULL;

    return no;
}

ListaSimples *criarListaSimples(){
    ListaSimples *lista = (ListaSimples*)calloc(1, sizeof(ListaSimples));
    lista->inicio = NULL;

    return lista;
}

void adicionarInicioDaListaSimples(ListaSimples *listaSimples, int valor){
    No *no = _criarNo(valor);

    no->proximo = listaSimples->inicio;
    listaSimples->inicio = no;
}

void imprimirListaSimples(ListaSimples *listaSimples){
    No *no = listaSimples->inicio;

    while(no != NULL){
        cout<< no->valor <<" ";
        no = no->proximo;
    }
    cout<<endl;
}

void removerUltimoDaLista(ListaSimples *listaSimples){
    No *atual = listaSimples->inicio;
    
    while (atual->proximo->proximo != NULL)
    {
        atual = atual->proximo;    
    }
    No *temp = atual;
    atual->proximo = NULL;
    free(temp);
    
}

void adicionarUltimoDaLista(ListaSimples *listaSimples, int valor){
    No *no = _criarNo(valor);

    No *atual = listaSimples->inicio;
    while(atual->proximo != NULL){
        atual = atual->proximo;
    }
    atual->proximo = no;
}

void inserirOrdenado(ListaSimples *listaSimples, int valor){
    No *novoNo = _criarNo(valor);

    No *atual = listaSimples->inicio;

    while(atual->valor > valor && (atual->proximo != NULL && atual->proximo->valor < valor)){
        atual = atual->proximo;
    }


    novoNo->proximo = atual->proximo;
    atual->proximo = novoNo;



}



