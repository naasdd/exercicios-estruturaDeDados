#ifndef G3_H
#define G3_H

struct No{
    int valor;
    No* next;
    No* prev;
};

struct ListaControle
{
    No* head;
    No* tail;
};

void inserir_Inicio(ListaControle *lista, int valor);

void inserir_Fim(ListaControle *lista, int valor);

void exibir_Direto(ListaControle *lista);

void exibir_Reverso(ListaControle *lista);

void destruir(ListaControle *lista);


#endif 
