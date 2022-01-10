#include <iostream>
#include<math.h>

using namespace std;

int divisores(int num){
    int result = 0;
    if(num == 1)
      return result;
    for (int i=2; i<=sqrt(num); i++){
        if (num%i==0){
            if (i==(num/i))
                result += i;
            else
                result += (i + num/i);
        }
    }
    return (result + 1);
}

void silvio_luiz(int n, int m, int n1, int m1 ){
    int ans[3] = {0};

    if(m % n1 == 0)//n ama m
        ans[0] = 1;
    if(n % m1 == 0)//m ama n
        ans[1] = 1;
    if(n1 == m1)
        ans[2] = 1;

    if(ans[0] + ans[1] == 1){//só um ama o outro
        if(ans[2])//ver se é caso de quase
            printf("Almost lovers!\n");
        else{
            if(ans[0])
                printf("%d friendzoned %d!\n", m, n);
            else
                printf("%d friendzoned %d!\n", n, m);
        }
    }
    else{
        if(ans[0] + ans[1] == 2)
            printf("Friends and lovers <3\n");
        else{
            if(ans[2])
                printf("Almost lovers!\n");
            else
                printf("No connection.\n");
        }
    }
}

int main(){
    int n, m, n1, m1;

    while(cin >> n >> m){
        if(n == 0 && m == 0)
            break;
        else{
            n1 = divisores(n);
            m1 = divisores(m);

            silvio_luiz(n, m, n1, m1);
        }
    }
    return 0;
}