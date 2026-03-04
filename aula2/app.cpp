#include <iostream>
#include "ponto.h"

using namespace std;

int main()
{
    cout << "\n----- Inicio do app.cpp -----\n\n";

    Ponto *ponto1 = criar(0.0, 0.0);
    Ponto *ponto2 = criar(3.0, 4.0);

    float calcularDistancia = distancia(ponto1, ponto2);
    cout << "A distância entre os pontos é: " << calcularDistancia;


    return 0;
}