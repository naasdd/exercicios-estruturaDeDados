
#include <iostream>
#include "g3.h"
using namespace std;

int main() {
    // Inicialização da lista
    ListaControle *minhaLista = new ListaControle();

    cout << "--- TESTE 1: Inserção no Fim (10, 20) ---" << endl;
    inserir_Fim(minhaLista, 10);
    inserir_Fim(minhaLista, 20);
    exibir_Direto(minhaLista); // Esperado: 10 20
    cout << endl;
    cout << "--- TESTE 2: Inserção no Início (5, 2) ---" << endl;
    inserir_Inicio(minhaLista, 5);
    inserir_Inicio(minhaLista, 2);
    cout << endl;

    cout << "Esperado (Direto): 2 5 10 20"<< endl;
    printf("Resultado:         ");
    exibir_Direto(minhaLista);
    cout << endl;
    cout << "Esperado (Reverso): 20 10 5 2"<< endl;
    cout << "Resultado:          ";
    exibir_Reverso(minhaLista);
    cout << endl;
    cout << "--- TESTE 3: Limpeza de Memória ---"<< endl;
    destruir(minhaLista);
    cout << endl;
    if (minhaLista->head == NULL) {
        cout << "[OK] Ponteiro inicio da struct de controle foi aterrado (NULL)."<< endl;
    } else {
        cout << "[ERRO] O campo inicio ainda aponta para algum lugar!"<< endl;
    }
    cout << endl;
    cout << "--- TESTE 4: Teste de Estresse (Lista Vazia) ---"<< endl;
    exibir_Direto(minhaLista);
    cout << endl;
    exibir_Reverso(minhaLista);
    cout << endl;
    cout << "Fim do teste. Se não houve erro de segmentação, o grupo venceu!"<< endl;

    return 0;
}