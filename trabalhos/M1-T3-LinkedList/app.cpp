#include <iostream>
#include "lista_simples.h"

using namespace std;

int main()
{
    cout << "Criando lista simples: " << endl;
    ListaSimples *lista = criarListaSimples();
    adicionarInicioDaListaSimples(lista, 30);
    adicionarInicioDaListaSimples(lista, 6);
    adicionarInicioDaListaSimples(lista, 89);

    cout << "Adicionando 69420 ao final da lista" << endl;
    adicionarUltimoDaLista(lista, 69420);

    cout << " Imprimindo lista simples " << endl;
    imprimirListaSimples(lista);

    cout << "Removendo o ultimo da lista" << endl;
    removerUltimoDaLista(lista);

    cout << "Imprimindo lista simples " << endl;
    imprimirListaSimples(lista);

 
    

    return 0;
}