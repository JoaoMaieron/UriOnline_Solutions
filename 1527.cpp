#include <iostream>
#define MAXN 100000
using namespace std;

int pontos[MAXN+1] = {0};
int conjuntos[MAXN] = {0};

void constroi(int n){
    int i;
    for(i=0;i<n+1;i++){
        conjuntos[i] = i;
    }
}
int busca(int i){
    if (i != conjuntos[i]){
        conjuntos[i] = busca(conjuntos[i]);
    }
    return conjuntos[i];
}
void une(int i, int j){
    int cade_i = busca(i);
    int cade_j = busca(j);
    if (cade_i != cade_j){
        if(pontos[cade_i]>=pontos[cade_j]){
            pontos[cade_i] += pontos[cade_j];
            conjuntos[cade_j] = cade_i;
        }
        else{
            pontos[cade_j] += pontos[cade_i];
            conjuntos[cade_i] = cade_j;
        }
    }
}

int main()
{
    int n, m, q, a, b, i, vitorias;
    while (true){
        cin >> n >> m;
        if(n == 0 && m == 0)
            break;
        else{
            for(i=0;i<n;i++)
                cin >> pontos[i+1];
            constroi(n);
            vitorias = 0;

            for(i=0;i<m;i++){
                cin >> q >> a >> b;
                if(q == 1){
                    une(a,b);
                }
                else{
                    if(q == 2){
                        int aa = busca(a);
                        int bb = busca(b);
                        if(pontos[aa] > pontos[bb] && aa == busca(1))
                            vitorias++;
                        else{
                            if(pontos[bb] > pontos[aa] && bb == busca(1))
                                vitorias++;
                        }
                    }
                }
            }
        }
        printf("%d\n", vitorias);
    }
    return 0;
}