#include <iostream>
#include<cmath>

using namespace std;

long long fib[42];

void fibonacci(){
    fib[0] = 0;
    fib[1] = 2;
    fib[2] = 3;
    for(int i = 3; i < 42; ++i)
        fib[i] = fib[i-1] + fib[i-2];
}

long long mdc(long long m, long long n){
    if(m == 0)
        return n;
    return mdc(n%m,m);
}

int main()
{
    int n;
    long long var, silvio_luiz;
    fibonacci();
    while(cin >> n){
        silvio_luiz = pow(2,n);
        var = mdc(fib[n],silvio_luiz);
        printf("%lld/%lld\n", fib[n]/var, silvio_luiz/var);
    }
    return 0;
}