#include <iostream>
using namespace std;

struct Node {
    string chave;
    string valor;
    Node* proximo;
};

struct HashTable {
    Node* tabela[10];
    int tamanho;
};

int hashModular(string chave, int tamanho) {
    int soma = 0;
    for (int i = 0; i < chave.size(); i++) {
        soma += chave[i];
    }
    return soma % tamanho;
}

HashTable* criarHashTable() {
    HashTable* ht = (HashTable*) calloc(1, sizeof(HashTable));
    ht->tamanho = 10;
    for (int i = 0; i < 10; i++) {
        ht->tabela[i] = nullptr;
    }
    return ht;
}

void inserir(HashTable* ht, string chave, string valor) {
    Node* novoValor = (Node*) calloc(1, sizeof(Node));
    novoValor->chave = chave;
    novoValor->valor = valor;
    novoValor->proximo = nullptr;

    int indice = hashModular(chave, ht->tamanho);

    novoValor->proximo = ht->tabela[indice];
    ht->tabela[indice] = novoValor;
}

string buscar(HashTable* ht, string chave) {
    int indice = hashModular(chave, ht->tamanho);

    Node* atual = ht->tabela[indice]; 

    while(atual != nullptr && atual->chave != chave ){
        atual = atual->proximo;
    }

    if(atual == nullptr) return "";
    return atual->valor;
}

void exibir(HashTable* ht) {
    for (int i = 0; i < ht->tamanho; i++) {
        cout << "[" << i << "]: ";
        Node* atual = ht->tabela[i];
        while (atual != nullptr) {
            cout << atual->chave << ":" << atual->valor << " -> ";
            atual = atual->proximo;
        }
        cout << "nullptr" << endl;
    }
}

int main() {
    HashTable* ht = criarHashTable();

    inserir(ht, "Jose", "99999-1111");
    inserir(ht, "Maria", "98888-2222");
    inserir(ht, "Carlos", "97777-3333");
    inserir(ht, "Ana", "96666-4444");
    inserir(ht, "Pedro", "95555-5555");
    inserir(ht, "Lucas", "94444-6666");
    inserir(ht, "Julia", "93333-7777");
    inserir(ht, "Marcos", "92222-8888");
    inserir(ht, "Fernanda", "91111-9999");
    inserir(ht, "Rafael", "90000-0000");
    inserir(ht, "Beatriz", "89999-1111");
    inserir(ht, "Thiago", "88888-2222");

    exibir(ht);

    cout << "\n--- Buscas ---" << endl;
    cout << "Jose: "     << buscar(ht, "Jose")     << endl;
    cout << "Fernanda: " << buscar(ht, "Fernanda") << endl;
    cout << "Thiago: "   << buscar(ht, "Thiago")   << endl;
    cout << "Beatriz: "  << buscar(ht, "Beatriz")  << endl;
    cout << "Inexistente: " << buscar(ht, "Inexistente") << endl;

    return 0;
}