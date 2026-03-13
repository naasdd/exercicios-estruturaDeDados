#ifndef LISTA_SIMPLES_H
#define LISTA_SIMPLES_H

struct No
{
    int valor;
    No *proximo;
};

struct ListaSimples{
    No *inicio;
};


ListaSimples *criarListaSimples();
void adicionarInicioDaListaSimples(ListaSimples *listaSimples, int valor);
void imprimirListaSimples(ListaSimples *listaSimples);
void removerUltimoDaLista(ListaSimples *ListaSimples);
void adicionarUltimoDaLista(ListaSimples *ListaSimples, int valor);
void inserirOrdenado(ListaSimples *ListaSimples, int valor);
void contarNos(ListaSimples *ListaSimples);
void inverterLista(ListaSimples *ListaSimples);
void liberarLista(ListaSimples *ListaSimples);

#endif