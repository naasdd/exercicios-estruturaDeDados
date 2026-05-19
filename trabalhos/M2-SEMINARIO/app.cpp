#include <iostream>
using namespace std;

struct No {
    int *chaves;
    No **filhos;
    int numChaves;
    int folha;
};

struct ArvoreB {
    No *raiz;
    int M;
};

No *criarNo(int M, int ehFolha)
{
    No *no = new No;
    no->chaves = new int[M - 1];
    no->filhos = new No*[M];
    no->numChaves = 0;
    no->folha = ehFolha;
    for (int i = 0; i < M; i++)
        no->filhos[i] = NULL;
    return no;
}

ArvoreB *criarArvoreB(int M)
{
    ArvoreB *arvore = new ArvoreB;
    arvore->M = M;
    arvore->raiz = criarNo(M, 1);
    return arvore;
}

No *buscar(No *no, int chave)
{
    int i = 0;
    while (i < no->numChaves && chave > no->chaves[i])
        i++;
    if (i < no->numChaves && chave == no->chaves[i])
        return no;
    if (no->folha)
        return NULL;
    return buscar(no->filhos[i], chave);
}

int antecessor(No *no)
{
    while (!no->folha)
        no = no->filhos[no->numChaves];
    return no->chaves[no->numChaves - 1];
}

int sucessor(No *no)
{
    while (!no->folha)
        no = no->filhos[0];
    return no->chaves[0];
}

void rotacionarDireita(No *no, int i)
{
    No *filho = no->filhos[i];
    No *irmaoEsq = no->filhos[i - 1];

    for (int j = filho->numChaves - 1; j >= 0; j--)
        filho->chaves[j + 1] = filho->chaves[j];
    if (!filho->folha)
    {
        for (int j = filho->numChaves; j >= 0; j--)
            filho->filhos[j + 1] = filho->filhos[j];
    }

    filho->chaves[0] = no->chaves[i - 1];
    if (!filho->folha)
        filho->filhos[0] = irmaoEsq->filhos[irmaoEsq->numChaves];

    no->chaves[i - 1] = irmaoEsq->chaves[irmaoEsq->numChaves - 1];

    filho->numChaves++;
    irmaoEsq->numChaves--;
}

void rotacionarEsquerda(No *no, int i)
{
    No *filho = no->filhos[i];
    No *irmaoDir = no->filhos[i + 1];

    filho->chaves[filho->numChaves] = no->chaves[i];
    if (!filho->folha)
        filho->filhos[filho->numChaves + 1] = irmaoDir->filhos[0];

    no->chaves[i] = irmaoDir->chaves[0];

    for (int j = 0; j < irmaoDir->numChaves - 1; j++)
        irmaoDir->chaves[j] = irmaoDir->chaves[j + 1];
    if (!irmaoDir->folha)
    {
        for (int j = 0; j < irmaoDir->numChaves; j++)
            irmaoDir->filhos[j] = irmaoDir->filhos[j + 1];
    }

    filho->numChaves++;
    irmaoDir->numChaves--;
}

void mergeFilhos(ArvoreB *arvore, No *no, int i)
{
    No *filhoEsq = no->filhos[i];
    No *filhoDir = no->filhos[i + 1];
    int pos = filhoEsq->numChaves;

    filhoEsq->chaves[pos] = no->chaves[i];

    for (int j = 0; j < filhoDir->numChaves; j++)
        filhoEsq->chaves[pos + 1 + j] = filhoDir->chaves[j];
    if (!filhoEsq->folha)
    {
        for (int j = 0; j <= filhoDir->numChaves; j++)
            filhoEsq->filhos[pos + 1 + j] = filhoDir->filhos[j];
    }

    filhoEsq->numChaves += filhoDir->numChaves + 1;

    for (int j = i; j < no->numChaves - 1; j++)
        no->chaves[j] = no->chaves[j + 1];
    for (int j = i + 1; j < no->numChaves; j++)
        no->filhos[j] = no->filhos[j + 1];
    no->numChaves--;

    delete[] filhoDir->chaves;
    delete[] filhoDir->filhos;
    delete filhoDir;
}

void splitFilho(ArvoreB *arvore, No *pai, int i, No *filho)
{
    int M = arvore->M;
    int meio = M / 2 - 1;

    No *novoNo = criarNo(M, filho->folha);
    novoNo->numChaves = M - meio - 2;

    for (int j = 0; j < novoNo->numChaves; j++)
        novoNo->chaves[j] = filho->chaves[j + meio + 1];
    if (!filho->folha)
    {
        for (int j = 0; j <= novoNo->numChaves; j++)
            novoNo->filhos[j] = filho->filhos[j + meio + 1];
    }

    filho->numChaves = meio;

    for (int j = pai->numChaves; j >= i + 1; j--)
        pai->filhos[j + 1] = pai->filhos[j];
    pai->filhos[i + 1] = novoNo;

    for (int j = pai->numChaves - 1; j >= i; j--)
        pai->chaves[j + 1] = pai->chaves[j];
    pai->chaves[i] = filho->chaves[meio];
    pai->numChaves++;
}

void inserirNaoCheio(ArvoreB *arvore, No *no, int chave)
{
    int i = no->numChaves - 1;

    if (no->folha)
    {
        while (i >= 0 && chave < no->chaves[i])
        {
            no->chaves[i + 1] = no->chaves[i];
            i--;
        }
        no->chaves[i + 1] = chave;
        no->numChaves++;
        return;
    }

    while (i >= 0 && chave < no->chaves[i])
        i--;
    i++;

    if (no->filhos[i]->numChaves == arvore->M - 1)
    {
        splitFilho(arvore, no, i, no->filhos[i]);
        if (chave > no->chaves[i])
            i++;
    }

    inserirNaoCheio(arvore, no->filhos[i], chave);
}

void inserir(ArvoreB *arvore, int chave)
{
    if (arvore->raiz->numChaves == arvore->M - 1)
    {
        No *novaRaiz = criarNo(arvore->M, 0);
        novaRaiz->filhos[0] = arvore->raiz;
        splitFilho(arvore, novaRaiz, 0, arvore->raiz);
        arvore->raiz = novaRaiz;
    }
    inserirNaoCheio(arvore, arvore->raiz, chave);
}

void removerNo(ArvoreB *arvore, No *no, int chave)
{
    int minChaves = arvore->M / 2 - 1;
    int i = 0;

    while (i < no->numChaves && chave > no->chaves[i])
        i++;

    if (i < no->numChaves && chave == no->chaves[i])
    {
        if (no->folha)
        {
            for (int j = i; j < no->numChaves - 1; j++)
                no->chaves[j] = no->chaves[j + 1];
            no->numChaves--;
        }
        else
        {
            if (no->filhos[i]->numChaves > minChaves)
            {
                int pred = antecessor(no->filhos[i]);
                no->chaves[i] = pred;
                removerNo(arvore, no->filhos[i], pred);
            }
            else if (no->filhos[i + 1]->numChaves > minChaves)
            {
                int suc = sucessor(no->filhos[i + 1]);
                no->chaves[i] = suc;
                removerNo(arvore, no->filhos[i + 1], suc);
            }
            else
            {
                mergeFilhos(arvore, no, i);
                removerNo(arvore, no->filhos[i], chave);
            }
        }
    }
    else
    {
        if (no->folha)
        {
            cout << "Chave " << chave << " nao encontrada." << endl;
            return;
        }

        if (no->filhos[i]->numChaves == minChaves)
        {
            if (i > 0 && no->filhos[i - 1]->numChaves > minChaves)
                rotacionarDireita(no, i);
            else if (i < no->numChaves && no->filhos[i + 1]->numChaves > minChaves)
                rotacionarEsquerda(no, i);
            else
            {
                if (i < no->numChaves)
                    mergeFilhos(arvore, no, i);
                else
                {
                    mergeFilhos(arvore, no, i - 1);
                    i--;
                }
            }
        }

        removerNo(arvore, no->filhos[i], chave);
    }
}

void remover(ArvoreB *arvore, int chave)
{
    removerNo(arvore, arvore->raiz, chave);

    if (arvore->raiz->numChaves == 0 && !arvore->raiz->folha)
    {
        No *antigaRaiz = arvore->raiz;
        arvore->raiz = arvore->raiz->filhos[0];
        delete[] antigaRaiz->chaves;
        delete[] antigaRaiz->filhos;
        delete antigaRaiz;
    }
}

void imprimir(No *no, int nivel)
{
    cout << "Nivel " << nivel << ": ";
    for (int i = 0; i < no->numChaves; i++)
        cout << no->chaves[i] << " ";
    cout << endl;

    if (!no->folha)
    {
        for (int i = 0; i <= no->numChaves; i++)
            imprimir(no->filhos[i], nivel + 1);
    }
}

int main()
{
    ArvoreB *arvore = criarArvoreB(4);

    int valores[] = {10, 20, 5, 6, 12, 30, 7, 17};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++)
        inserir(arvore, valores[i]);

    cout << "Arvore apos insercoes:" << endl;
    imprimir(arvore->raiz, 0);

    remover(arvore, 6);
    cout << "\nArvore apos remover 6:" << endl;
    imprimir(arvore->raiz, 0);

    int chave = 12;
    No *resultado = buscar(arvore->raiz, chave);
    if (resultado != NULL)
        cout << "\nChave " << chave << " encontrada!" << endl;
    else
        cout << "\nChave " << chave << " nao encontrada." << endl;

    return 0;
}