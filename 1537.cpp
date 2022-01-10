#include <iostream>
#define CWC 100001

using namespace std;

long long fat[CWC];
void fatorial(){
    fat[2] = 2;
    for(int i = 3; i <= CWC; ++i)
        fat[i] =  (i * fat[i-1])  % 1000000009;
}

int main(){
    int n;
    fatorial();

    while(cin >> n){
        if(n == 0)
            break;
        else
            printf("%lld\n", (fat[n] * 833333341) % 1000000009);
    }
    return 0;
}