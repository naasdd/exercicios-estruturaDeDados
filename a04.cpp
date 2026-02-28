#include <iostream>

using namespace std;

int main(){
    cout << "-- Sistema escolar --" << endl;

    int alunosAcimaDaMedia = 0;
    int somaNotas = 0;

    int qtdAlunos;
    cout << "Insira a quantidade de alunos na sala: ";
    cin >> qtdAlunos;

    int notaAlunos[qtdAlunos];
    for(int i = 1; i <= qtdAlunos; i++){
        cout << "Insira a nota do aluno " << i << ": ";
        cin >> notaAlunos[i-1];
        if(notaAlunos[i-1] >= 7) alunosAcimaDaMedia++;
        somaNotas = somaNotas + notaAlunos[i-1];
    }

    int media = somaNotas/qtdAlunos;

    cout << "Média da turma: " << media << endl;
    cout << "Alunos acima da média: " << alunosAcimaDaMedia << endl;

    return 0;
}