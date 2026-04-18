#include <iostream>
#include <limits.h>

using namespace std;

struct No
{
    int dado;
    No *esquerda;
    No *direita;
};

No *criarNo(int dado)
{
    No *novoNo = new No();
    novoNo->dado = dado;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;

    return novoNo;
}

No *inserir(No *noAtual, int dado)
{
    if (noAtual == NULL)
    {
        return criarNo(dado);
    }

    if (dado < noAtual->dado)
    {
        noAtual->esquerda = inserir(noAtual->esquerda, dado);
    }
    else if (dado > noAtual->dado)
    {
        noAtual->direita = inserir(noAtual->direita, dado);
    }

    return noAtual;
}

void inOrder(No *noAtual)
{
    if (noAtual != NULL)
    {
        inOrder(noAtual->esquerda);
        cout << "\n"
             << noAtual->dado;
        inOrder(noAtual->direita);
    }
}

int contarFolhas(No *noAtual)
{
    if (noAtual == NULL)
        return 0;

    if (noAtual->esquerda == NULL && noAtual->direita == NULL)
        return 1;

    return contarFolhas(noAtual->esquerda) + contarFolhas(noAtual->direita);
}

int ehBST(No *noAtual, int min, int max)
{
    if (noAtual == NULL)
        return 1;

    if (noAtual->dado < min || noAtual->dado > max)
        return 0;

    return ehBST(noAtual->esquerda, min, noAtual->dado - 1) &&
           ehBST(noAtual->direita, noAtual->dado + 1, max);
}

void listarDados(No *noAtual, int a, int b)
{
    if (noAtual == NULL)
        return;

    if (noAtual->dado > a)
        listarDados(noAtual->esquerda, a, b);

    if (noAtual->dado >= a && noAtual->dado <= b)
        cout << noAtual->dado << " ";

    if (noAtual->dado < b)
        listarDados(noAtual->direita, a, b);
}

int obterAltura(No *noAtual)
{
    if (noAtual == NULL)
        return 0;

    int esquerdo = obterAltura(noAtual->esquerda);
    int direito = obterAltura(noAtual->direita);

    return 1 + (esquerdo > direito ? esquerdo : direito);
}

int saoIguais(No *no1, No *no2)
{
    if (no1 == NULL && no2 == NULL)
        return 1;

    if (no1 != NULL && no2 != NULL)
    {
        return (no1->dado == no2->dado) &&
               saoIguais(no1->esquerda, no2->esquerda) &&
               saoIguais(no1->direita, no2->direita);
    }

    return 0;
}

int main()
{
    cout << "\n-- Inserindo valores na arvore --\n\n";
    No *arvore = NULL;

    arvore = inserir(arvore, 50);
    arvore = inserir(arvore, 30);
    arvore = inserir(arvore, 20);
    arvore = inserir(arvore, 40);
    arvore = inserir(arvore, 70);
    arvore = inserir(arvore, 60);
    arvore = inserir(arvore, 80);

    cout << "\n> Realizando o caminhamento in-order: \n";
    inOrder(arvore);

    cout << "\n\n> Realizando a contagem: \n";
    int total = contarFolhas(arvore);
    cout << "Total de " << total << " folhas." << endl;

    cout << "\n> Verificando se arvore é BST" << endl;
    int resultado = ehBST(arvore, INT_MIN, INT_MAX);
    cout << "\n> Eh um BST? ";
    if (resultado)
        cout << "Sim";
    else
        cout << "Nao";

    cout << "\n\n> Listando valores entre 25 e 65: ";
    listarDados(arvore, 25, 65);

    cout << "\n\n> Verificando a altura da arvore: ";
    int altura = obterAltura(arvore);
    cout << "\n> Altura da arvore é: " << altura;

    cout << "\n\n> Verificando a igualdade: ";
    No *arvore2 = criarNo(50);
    arvore2->esquerda = criarNo(30);

    cout << "\n> São iguais? " << saoIguais(arvore, arvore2);

    return 0;
}