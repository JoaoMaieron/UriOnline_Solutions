#include <iostream>
#include <vector>
#define CWC 1001
#define IBA 4001
using namespace std;

void dfs( int vertice, bool vis[], int *var, char notas[], vector<int> grafo[]){
    size_t i;
    vis[vertice] = true;

    //vai contando quantos B tem no grafo conexo
    if ( notas[vertice] == 'B')
        *var += 1;

    for (i=0;i<grafo[vertice].size();++i){
            int adjacente = grafo[vertice][i];
            if ( !vis[adjacente] )
                dfs(adjacente,vis,var,notas,grafo);
    }
}

int main()
{
    int n, m, i, a, b, contador;
    size_t CCSonichu1982;
    char notas[CWC] = {' '};

    while(cin >> n >> m){
        bool nao_da = false;
        for(i=1;i<=n;++i){
            cin >> notas[i];
        }

        vector<int> grafo[IBA];
        for (i=m; i!=0; --i){     //enche o grafo, fiz ida e volta pq sl
            scanf("%d %d", &a, &b);
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }

        for (i=1;i<=n;++i){
            if ( notas[i] == 'B' ){//quando encontra um B, chama o DFS pra percorrer a partir daquele no
                bool vis[IBA] = {false};
                int quantos_B_denovo = 0;
                dfs(i,vis,&quantos_B_denovo,notas,grafo);
//                printf("Achou B no vertice %d, contou %d Bs nessa parte\n", i, quantos_B_denovo);
                if ( quantos_B_denovo > 0 && quantos_B_denovo % 2 != 0 ){
                    nao_da = true;//todo B tem que estar numa seçao onde tem numero par de B
                    break;
                }
            }
        }

        if (nao_da)
            printf("N\n");
        else
            printf("Y\n");

    }
    return 0;
}