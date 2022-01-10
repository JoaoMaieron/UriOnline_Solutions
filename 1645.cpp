#include <iostream>
#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

long long ednaldoPereira(long long num[], int n, int k)
{
    long long seq[k][n];
    memset(seq,0,sizeof(seq));

    for(int i = 0; i < n; ++i)
        seq[0][i] = 1;

    for(int l = 1; l < k; ++l)
    {
        for(int i = l; i < n; ++i)
        {
            seq[l][i] = 0;
            for(int j = l-1; j < i; ++j)
            {
                if(num[j] < num[i])
                    seq[l][i] += seq[l-1][j];
            }
        }
    }
    long long ans = 0;
    for(int i = k - 1; i < n; ++i)
        ans += seq[k-1][i];

    return ans;

}

int main()
{
    int n, k;
    long long num[MAXN], ans;

    while(cin >> n >> k)
    {
        if(n == 0 && k == 0)
            break;
        else
        {
            for(int i = 0; i < n; ++i)
                cin >> num[i];

            ans = ednaldoPereira(num, n, k);

            cout << ans << endl;

        }
    }
    return 0;
}
