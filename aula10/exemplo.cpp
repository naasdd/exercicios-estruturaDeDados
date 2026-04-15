#include <iostream>
#include <climits>
using namespace std;

struct No {
    int valor;
    No* esquerda;
    No* direita;
};

struct Arvore {
    No* raiz;
};

No* inserirNo(No* no, int valor) {
    if (no == NULL) {
        No* novoNo = new No();
        novoNo->valor    = valor;
        novoNo->esquerda = NULL;
        novoNo->direita  = NULL;
        return novoNo;
    }
    if (valor > no->valor)
        no->direita = inserirNo(no->direita, valor);
    else if (valor < no->valor)
        no->esquerda = inserirNo(no->esquerda, valor);
    return no;
}

// retorna quantos nos nao tem filho nenhum
int contarFolhas(No* no) {
    if (no == NULL) return 0;
    if (no->esquerda == NULL && no->direita == NULL) return 1;
    return contarFolhas(no->esquerda) + contarFolhas(no->direita);
}

// helper: verifica se todo no respeita os limites min/max
bool bstValida(No* no, int minVal, int maxVal) {
    if (no == NULL) return true;
    if (no->valor <= minVal || no->valor >= maxVal) return false;
    return bstValida(no->esquerda, minVal, no->valor) &&
           bstValida(no->direita, no->valor, maxVal);
}

// verifica se a arvore respeita a regra esq < raiz < dir em todos os nos
bool verificarSeBinaria(No* no) {
    return bstValida(no, INT_MIN, INT_MAX);
}

// percorre em ordem e imprime so os valores entre valorA e valorB
void listarEntre(No* no, int valorA, int valorB) {
    if (no == NULL) return;
    if (no->valor > valorA)
        listarEntre(no->esquerda, valorA, valorB);
    if (no->valor >= valorA && no->valor <= valorB)
        cout << no->valor << " ";
    if (no->valor < valorB)
        listarEntre(no->direita, valorA, valorB);
}

// retorna o numero de arestas do caminho mais longo da raiz ate uma folha
int verificarAltura(No* no) {
    if (no == NULL) return -1;
    int altEsq = verificarAltura(no->esquerda);
    int altDir = verificarAltura(no->direita);
    if (altEsq > altDir) return altEsq + 1;
    return altDir + 1;
}

// retorna true se as duas arvores tem estrutura e valores identicos
bool compararArvores(No* a, No* b) {
    if (a == NULL && b == NULL) return true;
    if (a == NULL || b == NULL) return false;
    if (a->valor != b->valor) return false;
    return compararArvores(a->esquerda, b->esquerda) &&
           compararArvores(a->direita, b->direita);
}

int main() {
    cout << "\n-- Inicio app.cpp --\n\n";

    Arvore* arvore = new Arvore();
    arvore->raiz = NULL;

    arvore->raiz = inserirNo(arvore->raiz, 10);
    arvore->raiz = inserirNo(arvore->raiz, 15);
    arvore->raiz = inserirNo(arvore->raiz, 20);
    arvore->raiz = inserirNo(arvore->raiz, 5);

    cout << "Folhas: " << contarFolhas(arvore->raiz) << "\n";
    cout << "E BST valida: " << verificarSeBinaria(arvore->raiz) << "\n";
    cout << "Entre 5 e 15: ";
    listarEntre(arvore->raiz, 5, 15);
    cout << "\n";
    cout << "Altura: " << verificarAltura(arvore->raiz) << "\n";

    // segunda arvore pra comparar
    Arvore* arvore2 = new Arvore();
    arvore2->raiz = NULL;
    arvore2->raiz = inserirNo(arvore2->raiz, 10);
    arvore2->raiz = inserirNo(arvore2->raiz, 15);
    arvore2->raiz = inserirNo(arvore2->raiz, 20);
    arvore2->raiz = inserirNo(arvore2->raiz, 5);

    cout << "Arvores iguais: " << compararArvores(arvore->raiz, arvore2->raiz) << "\n";

    return 0;
}