#include <iostream>
#include <math.h>

using namespace std;

long long mdc(long long m, long long n){
    if(m == 0)
        return n;
    return mdc(n%m,m);
}

long long mmc(int a, int b){
    return (a / mdc(a, b)) * b;
}

int main(){
    long long n, a, b, aux;

    while(cin >> n >> a >> b){
        if(n == 0 && a == n && b == n)
            break;
        else{
            aux = floor(n/a) + floor(n/b);

            cout << aux - n / (mmc(a,b)) << endl;

        }
    }

    return 0;
}