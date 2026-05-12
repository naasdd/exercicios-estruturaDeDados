#include <iostream>
using namespace std;

// --- STRUCT ---

struct No
{
    // seu codigo aqui
    int valor;
    int altura;
    No *esquerda;
    No *direita;
};

// --- ALTURA E FATOR DE BALANCEAMENTO ---

int altura(No *no)
{
    if (no == NULL)
        return 0;
    return no->altura;
}

int fatorBalanceamento(No *no)
{
    return (altura(no->esquerda) - altura(no->direita));
}

void atualizarAltura(No *no)
{
    no->altura = max(altura(no->esquerda), altura(no->direita)) + 1;
}

// --- ROTAÇÕES ---

No *rotacaoDireita(No *y)
{
    No* x = y->esquerda;
    No* temp = x->direita;

    x->direita = y;
    y->esquerda = temp;

    atualizarAltura(x);
    atualizarAltura(y);

    return y;
}

No *rotacaoEsquerda(No *x)
{
    No* y = x->direita;
    No* temp = y->esquerda;

    y->esquerda = x;
    x->direita = temp;

    atualizarAltura(x);
    atualizarAltura(y);

    return x;
}

No *rotacaoDuplaDireita(No *no)
{
    // seu codigo aqui
}

No *rotacaoDuplaEsquerda(No *no)
{
    // seu codigo aqui
}

// --- BALANCEAMENTO ---

No *balancear(No *no)
{
    // seu codigo aqui
}

// --- INSERÇÃO ---

No *inserirNo(No *no, int valor)
{
    if (no == NULL){
        no = new No();
        no->valor = valor;
        no->altura = 0;
        no->esquerda = NULL;
        no->direita = NULL;
    }

    if (valor > no->valor)
    {
        no->direita = inserirNo(no->direita, valor);
    }
    else if (valor < no->valor)
    {
        no->esquerda = inserirNo(no->esquerda, valor);
    }

    return no;
}

// --- BUSCA ---

No *buscar(No *no, int valor)
{
    if (no->valor == valor) return no;

    if (valor > no->valor)
    {
       return buscar(no->direita, valor);
    }
    else if (valor < no->valor)
    {
        return buscar(no->esquerda, valor);
    }
}

// --- MENOR NÓ ---

No *menorNo(No *no)
{
    // seu codigo aqui
}

// --- REMOÇÃO ---

No *removerNo(No *no, int valor)
{
    // seu codigo aqui
}

// --- TRAVERSAL ---

void emOrdem(No *no)
{
    // seu codigo aqui
}

void preOrdem(No *no)
{
    // seu codigo aqui
}

// --- MAIN ---

int main()
{
    No *avl = NULL;

    // insercoes que vao triggar todas as rotacoes
    avl = inserirNo(avl, 30);
    avl = inserirNo(avl, 20);
    avl = inserirNo(avl, 40);
    avl = inserirNo(avl, 10);
    avl = inserirNo(avl, 25);
    avl = inserirNo(avl, 50);
    avl = inserirNo(avl, 5); // LL
    avl = inserirNo(avl, 35);
    avl = inserirNo(avl, 27); // LR
    avl = inserirNo(avl, 45);
    avl = inserirNo(avl, 47); // RR
    avl = inserirNo(avl, 43); // RL

    cout << "Em ordem:       ";
    emOrdem(avl);
    cout << endl;
    cout << "Pre ordem:      ";
    preOrdem(avl);
    cout << endl;
    cout << "Altura da raiz: " << altura(avl) << endl;

    No *encontrado = buscar(avl, 25);
    cout << "Busca por 25: " << (encontrado ? "encontrado" : "nao encontrado") << endl;

    avl = removerNo(avl, 30);
    cout << "Apos remover 30: ";
    emOrdem(avl);
    cout << endl;

    return 0;
}