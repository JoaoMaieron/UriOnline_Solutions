#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ponto;

double distancia(ponto inicio, ponto fim){
    return sqrt(pow(fim.first - inicio.first,2) + pow(fim.second - inicio.second,2) );
}

double determinante(ponto inicio, ponto fim, ponto meio){
    return (inicio.first - meio.first) * (fim.second - meio.second) - (fim.first - meio.first) * (inicio.second - meio.second);
}

int main()
{
    ponto lala[2];
    ponto pontos;
    int i, n[3] = {0}, cont[4] = {0}, hab;
    double aux;
    // n[1] = esquerda; n[2] = direita; n[3] = colineares;

    scanf("%d %d %d %d", &lala[0].first, &lala[0].second, &lala[1].first, &lala[1].second);
    scanf("%d", &n[0]);

    for(i = 0; i < n[0]; ++i){
        scanf("%d %d %d", &pontos.first, &pontos.second, &hab);
        aux = determinante(lala[0],lala[1],pontos);
        if(aux > 0){
            n[1] += hab;
            ++cont[1];
        }
        else{
            if(aux < 0){
                n[2] += hab;
                ++cont[2];
            }
            else
                ++cont[3];
        }
    }

    printf("Relatorio Vogon #35987-2\nDistancia entre referencias: %.2lf anos-luz\n", distancia(lala[0],lala[1]));
    printf("Setor Oeste:\n- %d planeta(s)\n- %d bilhao(oes) de habitante(s)\n", cont[1], n[1]);
    printf("Setor Leste:\n- %d planeta(s)\n- %d bilhao(oes) de habitante(s)\n", cont[2], n[2]);
    printf("Casualidades: %d planeta(s)\n", cont[3]);


    return 0;
}