#include <iostream>
using namespace std;

struct No {
    int valor;
    int alt;
    No* esquerdo;
    No* direito;
};

// --- ALTURA E FATOR DE BALANCEAMENTO ---

int altura(No* no) {
    if (no == NULL) return 0;
    return no->alt;
}

int fatorBalanceamento(No* no) {
    if (no == NULL) return 0;
    return altura(no->esquerdo) - altura(no->direito);
}

void atualizarAltura(No* no) {
    int altEsq = altura(no->esquerdo);
    int altDir = altura(no->direito);
    no->alt = (altEsq > altDir ? altEsq : altDir) + 1;
}

// --- ROTAÇÕES ---

//      y                x
//     / \              / \
//    x   T3    =>    T1   y
//   / \                  / \
//  T1  T2              T2  T3
No* rotacaoDireita(No* y) {
    No* x  = y->esquerdo;
    No* T2 = x->direito;

    x->direito  = y;
    y->esquerdo = T2;

    atualizarAltura(y);
    atualizarAltura(x);

    return x;
}

//    x                  y
//   / \                / \
//  T1   y     =>      x   T3
//      / \           / \
//     T2  T3        T1  T2
No* rotacaoEsquerda(No* x) {
    No* y  = x->direito;
    No* T2 = y->esquerdo;

    y->esquerdo = x;
    x->direito  = T2;

    atualizarAltura(x);
    atualizarAltura(y);

    return y;
}

// --- BALANCEAMENTO ---

No* balancear(No* no) {
    atualizarAltura(no);
    int fb = fatorBalanceamento(no);

    // Caso Esquerda-Esquerda
    if (fb > 1 && fatorBalanceamento(no->esquerdo) >= 0)
        return rotacaoDireita(no);

    // Caso Esquerda-Direita
    if (fb > 1 && fatorBalanceamento(no->esquerdo) < 0) {
        no->esquerdo = rotacaoEsquerda(no->esquerdo);
        return rotacaoDireita(no);
    }

    // Caso Direita-Direita
    if (fb < -1 && fatorBalanceamento(no->direito) <= 0)
        return rotacaoEsquerda(no);

    // Caso Direita-Esquerda
    if (fb < -1 && fatorBalanceamento(no->direito) > 0) {
        no->direito = rotacaoDireita(no->direito);
        return rotacaoEsquerda(no);
    }

    return no;
}

// --- INSERÇÃO ---

No* inserirNo(No* no, int valor) {
    // Caso base: cria o nó
    if (no == NULL) {
        No* novo   = new No();
        novo->valor    = valor;
        novo->alt      = 1;
        novo->esquerdo = NULL;
        novo->direito  = NULL;
        return novo;
    }

    // BST normal
    if (valor < no->valor)
        no->esquerdo = inserirNo(no->esquerdo, valor);
    else if (valor > no->valor)
        no->direito = inserirNo(no->direito, valor);
    else
        return no; // duplicado, ignora

    // Sobe balanceando
    return balancear(no);
}

// --- BUSCA ---

No* buscar(No* no, int valor) {
    if (no == NULL || no->valor == valor)
        return no;
    if (valor < no->valor)
        return buscar(no->esquerdo, valor);
    return buscar(no->direito, valor);
}

// --- MENOR NÓ (pra remoção) ---

No* menorNo(No* no) {
    No* atual = no;
    while (atual->esquerdo != NULL)
        atual = atual->esquerdo;
    return atual;
}

// --- REMOÇÃO ---

No* removerNo(No* no, int valor) {
    if (no == NULL) return NULL;

    if (valor < no->valor)
        no->esquerdo = removerNo(no->esquerdo, valor);
    else if (valor > no->valor)
        no->direito = removerNo(no->direito, valor);
    else {
        // Nó com um filho ou sem filhos
        if (no->esquerdo == NULL || no->direito == NULL) {
            No* temp = no->esquerdo ? no->esquerdo : no->direito;
            delete no;
            return temp;
        }
        // Nó com dois filhos: pega o sucessor in-order
        No* sucessor = menorNo(no->direito);
        no->valor   = sucessor->valor;
        no->direito = removerNo(no->direito, sucessor->valor);
    }

    return balancear(no);
}

// --- TRAVERSAL ---

void emOrdem(No* no) {
    if (no == NULL) return;
    emOrdem(no->esquerdo);
    cout << no->valor << " ";
    emOrdem(no->direito);
}

void preOrdem(No* no) {
    if (no == NULL) return;
    cout << no->valor << " ";
    preOrdem(no->esquerdo);
    preOrdem(no->direito);
}

// --- MAIN ---

int main() {
    cout << "> Iniciando app.cpp" << endl;

    No* avl = NULL;

    avl = inserirNo(avl, 30);
    avl = inserirNo(avl, 20);
    avl = inserirNo(avl, 40);
    avl = inserirNo(avl, 10);
    avl = inserirNo(avl, 25);
    avl = inserirNo(avl, 50);
    avl = inserirNo(avl, 5);  // <- dispara rotação aqui

    cout << "Em ordem:  "; emOrdem(avl);  cout << endl;
    cout << "Pre ordem: "; preOrdem(avl); cout << endl;
    cout << "Altura da raiz: " << altura(avl) << endl;

    No* encontrado = buscar(avl, 25);
    cout << "Busca por 25: " << (encontrado ? "encontrado" : "nao encontrado") << endl;

    avl = removerNo(avl, 20);
    cout << "Apos remover 20: "; emOrdem(avl); cout << endl;

    return 0;
}