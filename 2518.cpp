#include <iostream>
#include<cmath>

using namespace std;

int main()
{
    int n, h, c, l;
    while(cin >> n){
        scanf("%d %d %d", &h, &c, &l);
        printf("%.4f\n", (hypot(h,c) * l * n) / 10000 );
    }
    return 0;
}