#include <iostream>
#define CWC 101
using namespace std;

int mdc(int m, int n){
    if(m == 0)
        return n;
    return mdc(n%m, m);
}

int main (){
    int lala[CWC], n, i, atual, aux;
    long long saida = 1;

    scanf("%d", &n);
    for(i = 1; i <=n; ++i)
        scanf("%d", &lala[i]);
    for(i = 1; i <=n; ++i){
        aux = 1;
        atual = lala[i];
        while(atual != i){
            atual = lala[atual];
            ++aux;
        }
        saida = (saida * aux) / mdc(saida, aux);
    }

    cout << saida << endl;

    return 0;
}