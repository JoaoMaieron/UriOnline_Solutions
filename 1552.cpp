#include <iostream>
#include <bits/stdc++.h>
#define MAXB 100
#define MAXT 600
using namespace std;

int mochila(int W, int n, int val[], int tp[])
{
    int dp[W+1];
    memset(dp, 0, sizeof dp);

    for (int i=0; i<=W; i++)
      for (int j=0; j<n; j++)
         if (tp[j] <= i)
            dp[i] = max(dp[i], dp[i-tp[j]] + val[j]);

    return dp[W];
}

int main()
{
    int duracao[MAXB+1], pontos[MAXB+1];
    int n, t, h, i, resultado;

    while ( cin >> n >> t )
    {
        if ( n == 0 && t == 0 )
            break;
        else
        {
            resultado = 0;
            ++h;
            for ( i = 0; i < n; ++i )
            {
                scanf("%d %d", &duracao[i], &pontos[i]);
                if( duracao[i] == 0 )
                    --i;
            }
            resultado = mochila(t, n, pontos, duracao);
            printf("Instancia %d\n%d\n\n", h, resultado);
        }
    }
    return 0;
}
