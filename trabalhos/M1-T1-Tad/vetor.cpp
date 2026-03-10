#include <iostream>
#include <cstdlib>

using namespace std;

struct vetor {
    float* elem;
    int cap;
    int tam;
};

struct vetor* vet_cria(int cap) {
    struct vetor* v = (struct vetor*) malloc(sizeof(struct vetor));
    v->elem = (float*) malloc(cap * sizeof(float));
    v->cap = cap;
    v->tam = 0;
    return v;
}

void vet_insere(struct vetor* v, float valor) {
    if (v->tam >= v->cap) {
        v->cap = v->cap * 2;
        v->elem = (float*) realloc(v->elem, v->cap * sizeof(float));
    }
    v->elem[v->tam] = valor;
    v->tam = v->tam + 1;
}

float vet_acessa(struct vetor* v, int i) {
    if (i < 0 || i >= v->tam) {
        return 0.0f;
    }
    return v->elem[i];
}

int vet_tamanho(struct vetor* v) {
    return v->tam;
}

void vet_libera(struct vetor* v) {
    free(v->elem);
    free(v);
}
