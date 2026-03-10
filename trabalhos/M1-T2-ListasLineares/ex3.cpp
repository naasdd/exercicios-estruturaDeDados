#include <iostream>

using namespace std;

struct ListaEstatica
{
    int array[10];
    int qtdOcupados;
};

void inicializar(ListaEstatica *l)
{
    l->qtdOcupados = 0;
}

bool inserir(ListaEstatica *l, int valor)
{
    if (l->qtdOcupados >= 10)
    {
        cout << "Lista cheia." << endl;
        return false;
    }
    l->array[l->qtdOcupados] = valor;
    l->qtdOcupados++;
    return true;
}

int buscar(ListaEstatica *l, int valor)
{
    for (int i = 0; i < l->qtdOcupados; i++)
    {
        if (l->array[i] == valor)
            return i;
    }
    return -1;
}

bool remover(ListaEstatica *l, int valor)
{
    int indice = buscar(l, valor);
    if (indice == -1)
    {
        cout << "Valor nao encontrado." << endl;
        return false;
    }
    for (int i = indice; i < l->qtdOcupados - 1; i++)
    {
        l->array[i] = l->array[i + 1];
    }
    l->qtdOcupados--;
    return true;
}

int main()
{
    ListaEstatica lista;
    inicializar(&lista);

    inserir(&lista, 10);
    inserir(&lista, 20);
    inserir(&lista, 30);

    cout << "Buscando 20, indice: " << buscar(&lista, 20) << endl;

    remover(&lista, 20);

    cout << "Buscando 20 apos remover, indice: " << buscar(&lista, 20) << endl;

    return 0;
}