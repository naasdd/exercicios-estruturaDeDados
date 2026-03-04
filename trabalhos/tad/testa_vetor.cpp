#include <iostream>
#include <cstdlib>

using namespace std;

#include "vetor.h"

int main() {
    cout << "Testando TAD Vetor" << endl;
    
    struct vetor* v = vet_cria(3);
    cout << "Vetor criado. Tamanho: " << vet_tamanho(v) << endl;
    
    vet_insere(v, 10.5f);
    cout << "Inserido 10.5. Tamanho: " << vet_tamanho(v) << endl;
    
    vet_insere(v, 20.3f);
    cout << "Inserido 20.3. Tamanho: " << vet_tamanho(v) << endl;
    
    vet_insere(v, 30.7f);
    cout << "Inserido 30.7. Tamanho: " << vet_tamanho(v) << endl;
    
    vet_insere(v, 40.2f);
    cout << "Inserido 40.2. Tamanho: " << vet_tamanho(v) << endl;
    
    vet_insere(v, 50.8f);
    cout << "Inserido 50.8. Tamanho: " << vet_tamanho(v) << endl;
    
    cout << "Elementos:" << endl;
    for (int i = 0; i < vet_tamanho(v); i = i + 1) {
        float valor = vet_acessa(v, i);
        cout << "Posicao " << i << ": " << valor << endl;
    }
    
    cout << "Acesso invalido:" << endl;
    float valor1 = vet_acessa(v, -1);
    cout << "Indice -1: " << valor1 << endl;
    
    float valor2 = vet_acessa(v, 10);
    cout << "Indice 10: " << valor2 << endl;
    
    vet_libera(v);
    cout << "Teste concluido!" << endl;
    
    return 0;
}
