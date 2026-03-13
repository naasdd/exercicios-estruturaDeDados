#include <iostream>
#include "lista_simples.h"

using namespace std;

int main()
{
    cout << "\nCriando lista simples: " << endl;
    ListaSimples *lista = criarListaSimples();
    adicionarInicioDaListaSimples(lista, 30);
    adicionarInicioDaListaSimples(lista, 6);
    adicionarInicioDaListaSimples(lista, 89);

    cout << "\nAdicionando 69420 ao final da lista" << endl;
    adicionarUltimoDaLista(lista, 69420);

    cout << "\nImprimindo lista simples " << endl;
    imprimirListaSimples(lista);

    cout << "\nRemovendo o ultimo da lista" << endl;
    removerUltimoDaLista(lista);

    cout << "\nImprimindo lista simples " << endl;
    imprimirListaSimples(lista);

    cout << "\nInserindo ordenado 50, 10, 30." << endl;
    inserirOrdenado(lista, 50);
    inserirOrdenado(lista, 10);
    inserirOrdenado(lista, 30);

    contarNos(lista);
 
    cout << "\nImprimindo lista simples " << endl;
    imprimirListaSimples(lista);

    cout << "\nInvertendo Lista" << endl;
    inverterLista(lista);

    cout << "\nImprimindo lista simples " << endl;
    imprimirListaSimples(lista);

    cout << "\nLiberando Lista" << endl;
    liberarLista(lista);

    cout << "\nImprimindo lista simples " << endl;
    imprimirListaSimples(lista);

    return 0;
}