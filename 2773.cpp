#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ponto;

double distancia(ponto inicio, ponto fim){
    return sqrt(pow(fim.first - inicio.first,2) + pow(fim.second - inicio.second,2) );
}

int main()
{
    ponto caminho[2];
    ponto terreno[4];
    int v, largura;
    double dist;

    while(cin >> caminho[0].first >> caminho[0].second >> caminho[1].first >> caminho[1].second >> v){
        scanf("%d %d %d %d", &terreno[0].first, &terreno[0].second, &terreno[1].first, &terreno[1].second);

        largura = abs(terreno[1].first - terreno[0].first);
        terreno[2] = make_pair(terreno[1].first,terreno[0].second);//canto inferior direito
        terreno[3] = make_pair(terreno[0].first,terreno[1].second);//canto superior esquerdo

        dist = min(distancia(caminho[0],terreno[0]) + largura + distancia(terreno[2],caminho[1]),
                   distancia(caminho[0],terreno[3]) + largura + distancia(terreno[1],caminho[1]));

        printf("%.1f\n", dist / v);
    }

    return 0;
}