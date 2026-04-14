#include <iostream>
#include "lista_simples.h"

using namespace std;

int main()
{
    cout << "Criando lista simples" << endl;
    ListaSimples *lista = criarListaSimples();

    cout << "Adicionando os numeros 30, 6 e 89 na lista simples";
    adicionarInicioDaListaSimples(lista, 30);
    adicionarInicioDaListaSimples(lista, 6);
    adicionarInicioDaListaSimples(lista, 89);

    cout << "Imprimindo lista simples" << endl;
    imprimirListaSimples(lista);

    cout << "Adicionando 42 ao fim da lista" << endl;
    adicionarFimDaListaSimples(lista, 42);
    imprimirListaSimples(lista);

    cout << "Adicionando 100 ao fim da lista" << endl;
    adicionarFimDaListaSimples(lista, 100);
    imprimirListaSimples(lista);

    cout << "Deletando do fim da lista" << endl;
    deletarFimDaListaSimples(lista);
    imprimirListaSimples(lista);


    return 0;
}