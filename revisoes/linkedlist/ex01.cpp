#include <iostream>

using namespace std;

// Linked List (Listas encadeadas)
// Desafio: 1. Criar uma linked list com 3 nós (nodes)
//          2. Escrever a função "inserirNoFinal"
//          3. Percorrer e imprimir todos os valores

struct Node
{
    int valor;
    Node *proximo;
};

void inserirNoFinal() {}

void gerarNodes(int randomQtd)
{
    if (randomQtd < 2 && randomQtd > 6)
        return;

    for (int i = 0; i < randomQtd; i++)
    {
        if (i == 0)
        {
            Node *head = new Node();
            Node *temp = new Node();
            temp->valor = i;
            temp->proximo = nullptr;
            head->proximo = temp;
        }
        else
        {
            Node *temp = new Node();
            temp->valor = i;
            temp->proximo = nullptr;
        }
    }
}

void showMenu()
{
    int option;
    do
    {
        cout << "\n--- Pratica de linkedLists - ex01 ---\n\n";
        cout << "1 - Gerar Lista" << endl;
        cout << "2 - Inserir novo valor ao final" << endl;
        cout << "3 - Exibir lista completa" << endl;
        cout << "0 - Sair do programa" << endl;
        cout << "\n> Escolha uma opção: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "\n\n Quantos valores você deseja criar aleatoriamente (2 - 6)?" << endl;
            cout << "> ";
            int randomQtd;
            cin >> randomQtd;

            break;
        }

    } while (option != 0);
}

int main()
{
    showMenu();

    return 0;
}