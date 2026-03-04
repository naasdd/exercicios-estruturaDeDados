#ifndef VETOR_H
#define VETOR_H

struct vetor {
    float* elem;
    int cap;
    int tam;
};

struct vetor* vet_cria(int cap);
void vet_insere(struct vetor* v, float valor);
float vet_acessa(struct vetor* v, int i);
int vet_tamanho(struct vetor* v);
void vet_libera(struct vetor* v);

#endif
