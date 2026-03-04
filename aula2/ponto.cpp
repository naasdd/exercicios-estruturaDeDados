#include <iostream>
#include <math.h>
#include "ponto.h"

using namespace std;

struct ponto
{
    float x;
    float y;
};

Ponto *criar(float x, float y)
{
    Ponto *ponto = (Ponto *)malloc(sizeof(Ponto));

    ponto->x = x;
    ponto->y = y;

    return ponto;
}

void destruir(Ponto *ponto)
{
    delete ponto;
}

void definir(Ponto *ponto, float x, float y){
    ponto->x = x;
    ponto->y = y; 

}

void exibir(Ponto *ponto){
    cout << "ponto: " << ponto << " | ponto->x: " << ponto->x << " | ponto->y: " << ponto->y << endl;


}


float distancia(Ponto *ponto1, Ponto *ponto2)
{
    float dx = ponto1->x - ponto2->x;
    float dy = ponto1->y - ponto2->y;

    return sqrt(dx * dx + dy * dy);
}
