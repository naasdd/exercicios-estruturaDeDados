#include <iostream>

using namespace std;

struct Node{
    string value;
    Node* next;
};

struct linkedList{
    Node* head;
    Node* tail;
};

void queue(linkedList* lista, string valor){
    Node* novoValor = new Node();
    novoValor->value = valor;

    if(lista->head == nullptr){
        lista->tail = novoValor;
        lista->head = novoValor;
        return;
    }

    Node* temp = lista->head;
    novoValor->next = temp;
    lista->head = novoValor;
} 

void imprimirProximo(linkedList* lista){
    if(lista->tail == NULL) return;

    cout << "> Imprimindo: " << lista->tail->value << endl;

    Node* atual = lista->head;
    while(atual->next->next != nullptr){
        atual = atual->next;
    }

    free(lista->tail);
    lista->tail = atual;
    lista->tail->next = nullptr;
}

void exibirFila(linkedList* lista){
    Node* atual = lista->head;
    if(atual == nullptr) return;

    while (atual != nullptr)
    {
        cout << "Arquivo: " << atual->value << endl;
        atual = atual->next;
    }
    
}

int main(){
    linkedList* lista = new linkedList();
    queue(lista, "pagina1");
    queue(lista, "pagina2");
    queue(lista, "pagina3");
    queue(lista, "pagina4");

    exibirFila(lista);

    imprimirProximo(lista);

    exibirFila(lista);
    
    imprimirProximo(lista);

    exibirFila(lista);

    return 0;
}