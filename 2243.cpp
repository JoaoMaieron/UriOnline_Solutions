#include <iostream>
using namespace std;
#define CWC 50000

bool alt(int muro[], int indice, int tam, int dir){
    if(tam == 1)
        return true;
    else {if(indice >= 0 && indice <= CWC && muro[indice] >= tam)
            return alt(muro, indice + dir, tam - 1, dir);
          else
            return false;
    }
}

bool shablaus(int muro[], int indice, int altura){
    if(muro[indice] >= altura){
        return alt(muro, indice - 1, altura - 1, -1) && alt(muro, indice + 1, altura - 1, 1);
    }
    return false;
}

int main(){
    int n, i, j;
    int muro[CWC];
    int maior = 1;
    int meior = 1;

    scanf("%d", &n);
    int limite = n / 2 + 1;

    for(i = 0; i < n; ++i)
        scanf("%d", &muro[i]);

    for(i = 2; i <= n; ++i){
        for(j = i - 1; j <= n-i; ++j ){
            if(shablaus(muro, j, i)){
                meior = i;
                break;
            }
        }
        if(maior == meior){
            break;
        }
        maior = meior;

    }
    printf("%d\n", maior);

    return 0;
}
