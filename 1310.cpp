#include <iostream>
#define CWC 50
using namespace std;

int SHOWDEBOLA( int arr[CWC], int n )
{
    int max1 = 0;
    int max2 = -1000;
    for(int i = 0; i < n; ++i )
    {
        max1 = max( arr[i], arr[i] + max1 );
        if( max1 > max2 )
            max2 = max1;
    }
    if(max2 < 0)
        max2 = 0;
    return max2;
}

int main()
{
    int n, c, i, aux, resposta;
    int receita[CWC];

    while (cin >> n)
    {
        resposta = 0;
        scanf("%d", &c);
        for ( i = 0; i < n; ++i )
        {
            scanf("%d", &aux);
            receita[i] = aux - c;
        }
        resposta = SHOWDEBOLA(receita,n);

        printf("%d\n", resposta);

    }
}
