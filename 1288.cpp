#include <iostream>

using namespace std;

int knapSack(int W, int n, int wt[], int val[]){
    int i, w;
    int K[n + 1][W + 1];

    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

int main(){
    int wt[51], val[51];
    int SHOW, n, j, k, r;

    scanf("%d", &SHOW);
    for(int i = 0; i < SHOW; ++i){
        scanf("%d", &n);
        for(j = 0; j < n; ++j)
            scanf("%d %d", &val[j], &wt[j]);
        scanf("%d", &k);
        scanf("%d", &r);

        if(knapSack(k,n,wt,val) >= r)
            printf("Missao completada com sucesso\n");
        else
            printf("Falha na missao\n");
    }
    return 0;
}