#include <iostream>
#include <cstdlib>

using namespace std;

// Linked List (Listas encadeadas)
// Desafio: 1. Criar uma linked list
//          2. Escrever a função "inserirNoFinal"
//          3. Percorrer e imprimir todos os valores

struct Node
{
    int valor;
    Node *proximo;
};

Node *head = nullptr;

void showNodes()
{
    cout << "\nExibindo lista:" << endl;
    Node *atual = head;
    while (atual != nullptr)
    {
        cout << "\n- Valor: " << atual->valor << endl;
        cout << "- Proximo: " << atual->proximo << endl;
        atual = atual->proximo;
    }
    system("pause");
}
void inserirNoFinal()
{

    Node *atual = head;

    while (atual->proximo != nullptr)
    {
        atual = atual->proximo;
    }

    Node *temp = new Node();
    temp->proximo = nullptr;

    cout << "Insira o valor desejado: ";
    cin >> temp->valor;

    atual->proximo = temp;
}

void gerarNodes(int randomQtd)
{
    if (randomQtd < 2 || randomQtd > 999)
    {
        cout << "Valor invalido." << endl;
        return;
    }

    cout << "Gerando uma lista de " << randomQtd << " posicoes..." << endl;
    for (int i = 0; i < randomQtd; i++)
    {
        if (i == 0)
        {

            Node *temp = new Node();
            temp->valor = i;
            temp->proximo = nullptr;
            head = temp;
        }
        else
        {

            Node *atual = head;
            while (atual->proximo != nullptr)
            {

                atual = atual->proximo;
            }

            Node *temp = new Node();
            temp->valor = i;
            temp->proximo = nullptr;
            atual->proximo = temp;
        }
    }
    showNodes();
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
        cout << "\n> Escolha uma opcao: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "\n\n Quantos valores voce deseja criar aleatoriamente (2 - 999)?" << endl;
            cout << "> ";
            int randomQtd;
            cin >> randomQtd;
            gerarNodes(randomQtd);
            break;

        case 2:
            inserirNoFinal();
            break;

        case 3:
            showNodes();
            break;
        }
    } while (option != 0);
}

int main()
{
    showMenu();

    return 0;
}