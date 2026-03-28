#include <cstdlib>
#include <iostream>
#include <iterator>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 11

using namespace std;

struct Aluno {
  int matricula;
  char nome[50];
};

struct No {
  Aluno aluno;
  No *proximo;
};

struct TabelaHash {
  No *dados[TAMANHO];
  int tamanho;
};

int funcaoHash(int chave) { return chave % TAMANHO; }

void inserirExterior(TabelaHash *tabela, Aluno alunoNovo) {
  int id = funcaoHash(alunoNovo.matricula);

  No *novoNo = (No *)calloc(1, sizeof(No));
  novoNo->aluno = alunoNovo;

  novoNo->proximo = tabela->dados[id];
  tabela->dados[id] = novoNo;

  cout << "Aluno " << alunoNovo.nome << " inserido no índice " << id << endl;
}

void exibirExterior(TabelaHash *tabela) {
  cout << "\n-- Exibindo Lista --" << endl;

  for (int i = 0; i < tabela->tamanho; i++) {
    if (tabela->dados[i] == NULL)
      continue;
    No *atual = tabela->dados[i];
    cout << "\n";
    do {

      cout << "[" << i << "] ";
      cout << "Aluno: " << atual->aluno.nome << "      ";
      atual = atual->proximo;
    } while (atual != NULL);
  }
  cout << endl;
}

Aluno *buscarExterior(TabelaHash *tabela, int matricula) {
  int id = funcaoHash(matricula);

  No *atual = tabela->dados[id];
  while (atual != NULL) {
    if (atual->aluno.matricula == matricula) {
      return &(atual->aluno);
    }

    atual = atual->proximo;
  }
  return NULL;
}

void inserirAberto(TabelaHash *tabela, Aluno alunoNovo) {
  int id = funcaoHash(alunoNovo.matricula);
  int i = 0;
  while (i < TAMANHO) {
    int pos = (id + 1) % TAMANHO;
    if (tabela->dados[pos] == NULL) {
      No *novoNo = (No *)calloc(1, sizeof(No));
      novoNo->aluno = alunoNovo;

      tabela->dados[id] = novoNo;
    }
    i++;
  }
  cout << "Tabela cheia! Nao foi possivel inserir o aluno " << alunoNovo.nome
       << endl;
}

void imprimirAberto(TabelaHash *tabela) {
  cout << "\n-- Tabela Hash Aberto --" << endl;

  for (int i = 0; i < TAMANHO; i++) {
    cout << "[" << i << "] ";
    if (tabela->dados[i] == NULL) {
      cout << "Livre" << endl;
    } else {
      cout << "Aluno: " << tabela->dados[i]->aluno.nome << " | Matricula: " << tabela->dados[i]->aluno.matricula << endl;
    }
  }
}

int main() {
  TabelaHash *tabela = (TabelaHash *)calloc(1, sizeof(TabelaHash));
  tabela->tamanho = TAMANHO;

  Aluno joao = {123, "joao"};
  Aluno alice = {12, "alice"};
  Aluno neymarJr = {23, "neymarJr"};
  Aluno felipe = {10, "Felipe"};

  inserirExterior(tabela, joao);
  inserirExterior(tabela, alice);
  inserirExterior(tabela, neymarJr);
  inserirExterior(tabela, felipe);

  exibirExterior(tabela);

  Aluno *buscaDaAlice = buscarExterior(tabela, 12);
  Aluno *buscaNula = buscarExterior(tabela, 67);

  cout << "\n";
  cout << "Matricula: " << buscaDaAlice->matricula
       << " | Nome: " << buscaDaAlice->nome << endl;

  if (buscaNula == NULL) {
    cout << "Aluno não encontrado." << endl;
  } else {
    cout << "Matricula: " << buscaNula->matricula
         << " | Nome: " << buscaNula->nome << endl;
  }


  TabelaHash* tabelaAberto = (TabelaHash*) calloc(1, sizeof(TabelaHash));
  Aluno jorge = {46, "jorge"};
  Aluno lucas = {38, "lucas"};
  Aluno maria = {49, "maria"};
  
  // V era pra ta imprimindo, mas nao ta 
  inserirAberto(tabela, jorge); 
  inserirAberto(tabela, lucas);
  inserirAberto(tabela, maria);

  return 0;
}